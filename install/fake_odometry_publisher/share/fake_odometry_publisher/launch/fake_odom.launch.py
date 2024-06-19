from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='fake_odometry_publisher',
            executable='fake_odom_publisher',
            name='fake_odom_publisher',
            output='screen'
        ),
        # Optionally, add a static transform from base_footprint to laser
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='laser_broadcaster',
            output='screen',
            arguments=['0', '0', '0', '0', '0', '0', 'base_footprint', 'laser']
        )
    ])