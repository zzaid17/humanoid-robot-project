from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='imu_publisher_cpp',
            executable='imu_publisher',
            name='imu_publisher',
            output='screen',
        ),
    ])
