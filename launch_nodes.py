import subprocess

commands = [["Launching urg_node2...", "ros2 launch urg_node2 urg_node2.launch.py"],
            ["Launching slam_toolbox...", "ros2 launch slam_toolbox online_sync_launch.py"],
            ["Launching serial_bridge_node...", "ros2 launch serial_bridge_node serial_driver_bridge_node.launch.py"],
            ["Launching imu_publisher_cpp...", "ros2 launch imu_publisher_cpp imu_publisher_launch.py"],
            ["Launching s_tf_pub...", "ros2 launch s_tf_pub mapping_launch.py"],
            ["Launching robot_localization", "ros2 launch robot_localization ekf.launch.py"]
]

for command in commands:
    print(command[0])
    result = subprocess.run(command[1], shell=True, capture_output=True, text=True)
    print("Output:\n", result.stdout)
    if result.stderr:
        print("Errors:\n", result.stderr)