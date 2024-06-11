<h1>Setup:</h1>

<h2>Install dependencies</h2>

``` 
rosdep update
rosdep install -q -y -r --from-paths src --ignore-src --rosdistro humble
```

<h2>Source and build</h2>

``` 
source /opt/ros/humble/setup.bash 
source /hokuyo_laser_scanner_ws/install/local_setup.bash
source /hokuyo_laser_scanner_ws/install/urg_node2/share/urg_node2/local_setup.bash
source /hokuyo_laser_scanner_ws/install/slam_toolbox/share/slam_toolbox/local_setup.bash
```

``` 
colcon build --symlink-install
```

``` 
source /hokuyo_laser_scanner_ws/install/urg_node2/share/urg_node2/local_setup.bash 
source /hokuyo_laser_scanner_ws/install/slam_toolbox/share/slam_toolbox/local_setup.bash
```

<h2>Run nodes</h2>

```
ros2 launch urg_node2 urg_node2.launch.py
ros2 launch slam_toolbox online_sync_launch.py
```

TODO: Command for launching nav2 node
