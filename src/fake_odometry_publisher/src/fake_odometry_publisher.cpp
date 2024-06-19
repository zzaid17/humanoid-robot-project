#include <chrono>
#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2/LinearMath/Quaternion.h>

using namespace std::chrono_literals;

class FakeOdomPublisher : public rclcpp::Node
{
public:
    FakeOdomPublisher()
    : Node("fake_odom_publisher"), x_(0.0), y_(0.0), th_(0.0), vx_(0.1), vy_(0.0), vth_(0.1)
    {
        odom_publisher_ = this->create_publisher<nav_msgs::msg::Odometry>("odom", 10);
        timer_ = this->create_wall_timer(100ms, std::bind(&FakeOdomPublisher::publish_odometry, this));
        tf_broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(this);
    }

private:
    void publish_odometry()
    {
        auto current_time = this->get_clock()->now();

        // Update the pose
        double dt = 0.1;
        double delta_x = vx_ * cos(th_) * dt;
        double delta_y = vx_ * sin(th_) * dt;
        double delta_th = vth_ * dt;

        x_ += delta_x;
        y_ += delta_y;
        th_ += delta_th;

        // Create quaternion from yaw
        tf2::Quaternion odom_quat;
        odom_quat.setRPY(0, 0, th_);

        // Publish the transform over tf
        geometry_msgs::msg::TransformStamped odom_trans;
        odom_trans.header.stamp = current_time;
        odom_trans.header.frame_id = "odom";
        odom_trans.child_frame_id = "base_footprint";

        odom_trans.transform.translation.x = x_;
        odom_trans.transform.translation.y = y_;
        odom_trans.transform.translation.z = 0.0;
        odom_trans.transform.rotation.x = odom_quat.x();
        odom_trans.transform.rotation.y = odom_quat.y();
        odom_trans.transform.rotation.z = odom_quat.z();
        odom_trans.transform.rotation.w = odom_quat.w();

        tf_broadcaster_->sendTransform(odom_trans);

        // Publish the odometry message over ROS
        nav_msgs::msg::Odometry odom;
        odom.header.stamp = current_time;
        odom.header.frame_id = "odom";

        // Set the position
        odom.pose.pose.position.x = x_;
        odom.pose.pose.position.y = y_;
        odom.pose.pose.position.z = 0.0;
        odom.pose.pose.orientation.x = odom_quat.x();
        odom.pose.pose.orientation.y = odom_quat.y();
        odom.pose.pose.orientation.z = odom_quat.z();
        odom.pose.pose.orientation.w = odom_quat.w();

        // Set the velocity
        odom.child_frame_id = "base_footprint";
        odom.twist.twist.linear.x = vx_;
        odom.twist.twist.linear.y = vy_;
        odom.twist.twist.angular.z = vth_;

        odom_publisher_->publish(odom);
    }

    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    std::shared_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;

    double x_, y_, th_, vx_, vy_, vth_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<FakeOdomPublisher>());
    rclcpp::shutdown();
    return 0;
}