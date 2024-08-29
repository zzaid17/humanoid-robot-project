from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            arguments=['--x', '0', '--y', '0', '--z', '0', 
                       '--qx', '0', '--qy', '0', '--qz', '0', '--qw', '1', 
                       '--frame-id', 'base_link', '--child-frame-id', 'laser'],
            name='base_link_to_laser'
        ),
    ])