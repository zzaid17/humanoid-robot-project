from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='imu_publisher_cpp',
            executable='imu_node',
            name='imu_publisher',
            output='screen',
            parameters=[{'device_name': '/dev/ttyUSB0',
                         'baud_rate': 115200,
                         'flow_control': 'none',
                         'parity': 'none',
                         'stop_bits': 'one'}],
        ),
    ])