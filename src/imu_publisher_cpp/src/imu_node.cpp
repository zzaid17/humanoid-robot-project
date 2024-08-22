#include <memory>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <cctype>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "std_msgs/msg/u_int8_multi_array.hpp"

class ImuPublisher : public rclcpp::Node
{
public:
  ImuPublisher() : Node("imu_publisher")
  {
    publisher_ = this->create_publisher<sensor_msgs::msg::Imu>("/imu", 10);
    subscription_ = this->create_subscription<std_msgs::msg::UInt8MultiArray>(
      "serial_read", 10,
      std::bind(&ImuPublisher::topic_callback, this, std::placeholders::_1)
    );
  }

private:
  void topic_callback(const std_msgs::msg::UInt8MultiArray::SharedPtr msg)
  {
    // Convert data to string
    std::string data_str(msg->data.begin(), msg->data.end());
    RCLCPP_INFO(this->get_logger(), "Received serial data: '%s'", data_str.c_str());

    // Parsing logic
    sensor_msgs::msg::Imu imu_msg;
    std::istringstream ss(data_str);
    std::string token;

    try {
      // Example: Parse and populate the IMU message
      if (std::getline(ss, token, ',')) {
        imu_msg.linear_acceleration.x = parse_double(token);
      }
      if (std::getline(ss, token, ',')) {
        imu_msg.linear_acceleration.y = parse_double(token);
      }
      if (std::getline(ss, token, ',')) {
        imu_msg.linear_acceleration.z = parse_double(token);
      }
      if (std::getline(ss, token, ',')) {
        imu_msg.angular_velocity.x = parse_double(token);
      }
      if (std::getline(ss, token, ',')) {
        imu_msg.angular_velocity.y = parse_double(token);
      }
      if (std::getline(ss, token, ',')) {
        imu_msg.angular_velocity.z = parse_double(token);
      }
    } catch (const std::invalid_argument &e) {
      RCLCPP_WARN(this->get_logger(), "Error parsing data: %s", e.what());
    } catch (const std::out_of_range &e) {
      RCLCPP_WARN(this->get_logger(), "Data out of range: %s", e.what());
    }

    // Set covariance matrices (example: all zeros)
    imu_msg.orientation_covariance = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    imu_msg.angular_velocity_covariance = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    imu_msg.linear_acceleration_covariance = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

    publisher_->publish(imu_msg);
  }

  double parse_double(const std::string &s)
  {
    // Check if the string is non-empty and valid
    if (s.empty() || !std::isdigit(s[0]) && s[0] != '-' && s[0] != '+') {
      throw std::invalid_argument("Invalid data: " + s);
    }
    return std::stod(s);
  }

  rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr publisher_;
  rclcpp::Subscription<std_msgs::msg::UInt8MultiArray>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ImuPublisher>());
  rclcpp::shutdown();
  return 0;
}