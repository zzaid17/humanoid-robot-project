cmake_minimum_required(VERSION 3.5)
project(fake_odometry_publisher)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(geometry_msgs REQUIRED)

# Add the executable
add_executable(fake_odometry_publisher src/fake_odometry_publisher.cpp)

# Specify dependencies of the target
ament_target_dependencies(fake_odometry_publisher
    rclcpp
    nav_msgs
    tf2_ros
    geometry_msgs
)

# Install the executable
install(TARGETS
    fake_odometry_publisher
    DESTINATION lib/${PROJECT_NAME})

# Export the package
ament_package()
