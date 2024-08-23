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
    buffer_ = "";
  }

private:
  void topic_callback(const std_msgs::msg::UInt8MultiArray::SharedPtr msg)
  {
    // Convert data to string and add to the buffer
    std::string data_str(msg->data.begin(), msg->data.end());
    buffer_ += data_str;

    // Process complete lines (terminated by newline)
    size_t newline_pos;
    while ((newline_pos = buffer_.find('\n')) != std::string::npos) {
      std::string complete_line = buffer_.substr(0, newline_pos);
      buffer_ = buffer_.substr(newline_pos + 1); // Remove processed data from buffer

      RCLCPP_INFO(this->get_logger(), "Received serial data: '%s'", complete_line.c_str());
      
      // Remove any trailing whitespace
      complete_line.erase(complete_line.find_last_not_of(" \n\r\t") + 1);

      // Parsing logic
      sensor_msgs::msg::Imu imu_msg;
      std::istringstream ss(complete_line);
      std::string token;
      std::vector<double> values;

      // Parse space-separated values into the vector
      while (ss >> token) {
        try {
          values.push_back(parse_double(token));
        } catch (const std::invalid_argument &e) {
          RCLCPP_WARN(this->get_logger(), "Error parsing value '%s': %s", token.c_str(), e.what());
          return; // Early exit if parsing fails
        }
      }

      // Check the size and assign values to IMU message
      if (values.size() == 6) {
        imu_msg.linear_acceleration.x = values[0];
        imu_msg.linear_acceleration.y = values[1];
        imu_msg.linear_acceleration.z = values[2];
        imu_msg.angular_velocity.x = values[3];
        imu_msg.angular_velocity.y = values[4];
        imu_msg.angular_velocity.z = values[5];

        // Set covariance matrices (example: all zeros)
        imu_msg.orientation_covariance = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
        imu_msg.angular_velocity_covariance = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
        imu_msg.linear_acceleration_covariance = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

        publisher_->publish(imu_msg);
      } else {
        RCLCPP_WARN(this->get_logger(), "Unexpected number of values: %zu", values.size());
      }
    }
  }

  double parse_double(const std::string &s)
  {
    // Check for valid string and prepend 0 if it starts with a decimal point
    if (s.empty() || (!std::isdigit(s[0]) && s[0] != '-' && s[0] != '+' && s[0] != '.')) {
      throw std::invalid_argument("Invalid data: " + s);
    }
    if (s[0] == '.') {
      return std::stod("0" + s);
    }
    if (s.size() > 1 && s[0] == '-' && s[1] == '.') {
      return std::stod("-0" + s.substr(1));
    }
    return std::stod(s);
  }

  std::string buffer_; // Buffer for storing incomplete serial data
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