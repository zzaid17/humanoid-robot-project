# Humanoid Robot Project: Autonomous Navigation

## Summary

The current prototype can receive and process laser scan data, gather location data using an MPU6050 gyroscope/accelerometer in conjunction with an Arduino ESP32 Wroom, convert this data to IMU data over a serial port which can then be converted to odometry data, and generate a map based on the robot’s surroundings. The next step would be implementing pathing and navigation functionality with this map by using the ROS 2 navigation stack.

The following is a list of all the packages. Note that these packages, along with the particular versions and edited parameters needed for the project, can also be found in the main GitHub repository as submodules.

- **urg_node2**: [https://github.com/Hokuyo-aut/urg_node2/tree/main](https://github.com/Hokuyo-aut/urg_node2/tree/main)
  - Responsible for gathering and publishing laser scan data over the `/scan` topic
- **transport_drivers**: [https://github.com/ros-drivers/transport_drivers/tree/main](https://github.com/ros-drivers/transport_drivers/tree/main)
  - Translates Arduino output to serial input for ROS 2
- **imu_publisher_cpp**:
  - Converts serial Arduino data to a message over the `/imu` topic
- **robot_localization**: [https://github.com/cra-ros-pkg/robot_localization](https://github.com/cra-ros-pkg/robot_localization)
  - Converts IMU data to odometry data over the `/odom` topic for mapping
- **slam_gmapping**: [https://github.com/Project-MANAS/slam_gmapping](https://github.com/Project-MANAS/slam_gmapping)
  - Generates a map based on laser and location data
- **BehaviorTree.CPP**: [https://github.com/BehaviorTree/BehaviorTree.CPP](https://github.com/BehaviorTree/BehaviorTree.CPP)
  - Dependency for other packages
- **navigation2**: [https://github.com/ros-navigation/navigation2](https://github.com/ros-navigation/navigation2)
  - Responsible for autonomous navigation using mapping and location data

A static transform must be implemented for the map to generate properly. A custom package for this can be found under `s_tf_pub`, within the main repository. The Arduino script for gathering gyroscope and acceleration data can be found in the repository as well.

One major issue is that the ethernet connection for the laser scanner seems to drop after approximately 20 minutes of use. This is likely due to a hardware issue and the scanner may need to be replaced, but further investigation should be done. Additionally, the `robot_localization` package does not build properly due to a dependency issue involving the Python tool `em`.

## ROS 2 Installation

The ROS 2 setup can be found on the official ROS website. The current setup for this project uses version Humble, but any version should do provided the correct branches are used for each package.

[https://docs.ros.org/en/humble/Installation.html](https://docs.ros.org/en/humble/Installation.html)

## Workspace Setup and Package Installation

By cloning the project repository, all of the necessary packages and files should automatically download. On Ubuntu, this can be done by pasting the following into the terminal:

`git clone https://github.com/zzaid17/hokuyo_laser_scanner_ws`

### Dependencies

`rosdep` can be used to handle dependencies automatically. It seems that `rosdep` misses the `BehaviorTree.CPP` dependency, which is why this is included as a separate package in the repository. `rosdep` should be updated before attempting to install any dependencies.

`rosdep update`  
`rosdep install -q -y -r --from-paths src --ignore-src --rosdistro humble`

Replace `humble` with whichever ROS 2 distribution is being used.

### Source and Build

The workspace can be built using `colcon`:

`colcon build --symlink-install`

Failing to source the proper bash files may cause compilation and build issues. Specifically, the following files must be sourced (these require folders that may not be generated until after building):

`source /opt/ros/humble/setup.bash`  
`source /workspace/install/local_setup.bash`  
`source /workspace/install/package/share/package/local_setup.bash`

Step 3 should be repeated for each package, replacing `package` with the package name.

### Running Nodes

The file launch_nodes.py will automatically launch all of the nodes when executed. For testing or troubleshooting purposes, the individual nodes can be launched using the following terminal commands. Make sure to run the included Arduino script first in either case.

`ros2 launch urg_node2 urg_node2.launch.py`  
`ros2 launch slam_toolbox online_sync_launch.py`  
`ros2 launch serial_bridge_node serial_driver_bridge_node.launch.py`  
`ros2 launch imu_publisher_cpp imu_publisher_launch.py`  
`ros2 launch s_tf_pub mapping_launch.py`  
`ros2 launch robot_localization ekf.launch.py`

Additionally, `rviz` can be used to visualize the scanner data to ensure that the map generated by `slam_toolbox` is satisfactory:

`ros2 run rviz2 rviz2`

Upon launching `rviz2`, the user must go to **Add -> Create visualization > By topic** and select the necessary topics (i.e., `/map`, `/scan`).

## Additional Information

One of the issues faced was connecting the laser scanner via an ethernet interface. The initial value of the IP address for the scanner is `192.168.0.10`, so the network settings on the computer being used to run the setup should match as per the following:

- IP Address: `192.168.0.15`
- Subnet Mask: `255.255.255.0`
- Default Gateway: `192.168.0.1`

Failure to follow this step may result in the error “could not open ethernet port” when attempting to run the scanner node.

## Pending Issues / TODO

Despite using the correct network settings, network issues persist. Specifically, the ethernet connection between the scanner and the computer consistently drops after 20-30 minutes of use. The same problem was reproduced using a different ethernet cable and computer. Several other troubleshooting steps were also followed. These included restarting and reinstalling the network manager and disabling the USB auto-suspend setting (which is on by default).

The physical connection of the laser scanner was investigated and looked fine, though defective hardware could still be a factor. Another potential cause is the scanner overheating since it becomes warm to the touch after leaving it on for an extended period.

Using the generated map, autonomous navigation can be implemented with the ROS 2 navigation stack. The `robot_localization` package should be fixed so that it builds properly. It can then be used to convert IMU data to odometry data for the map using the `ekf.launch` node, which also implements a Kalman filter for noise reduction in the gyroscope and acceleration data.
