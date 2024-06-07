<h1>In case of missing dependencies, incorrect file paths, or other issues, go through the following steps when porting between PCs or to the robot.</h1>

<h2>Remove and reinstall packages from root directory</h2>

``` rm -rf src/urg_node2 ```\
``` rm -rf src/slam_toolbox ``` \
``` rm -rf src/navigation2 ```\
``` rm -rf src/BehaviorTree.CPP ```\
``` rm -rf build/ install/ log/ ```

<h2>Reinstall packages from src directory</h2>

``` git clone https://github.com/Hokuyo-aut/urg_node2 ```\
``` git clone https://github.com/SteveMacenski/slam_toolbox ```\
``` git clone https://github.com/ros-navigation/navigation2/tree/humble ```\
``` git clone https://github.com/BehaviorTree/BehaviorTree.CPP.git -b v3.8 ```

<h2>Install dependencies</h2>

``` rosdep update ```\
``` rosdep install -i --from-paths urg_node2 ```\
``` rosdep install -q -y -r --from-paths src --ignore-src ```

<h2>Source and build</h2>

``` source /opt/ros/<distro>/setup.bash ```, where <distro> is the current ROS 2 distribution.\
``` source /hokuyo_laser_scanner_ws/install/local_setup.bash ```\
``` source /hokuyo_laser_scanner_ws/install/urg_node2/share/urg_node2/local_setup.bash ```\
``` source /hokuyo_laser_scanner_ws/install/slam_toolbox/share/slam_toolbox/local_setup.bash ```

``` colcon build --symlink-install ```

``` source /hokuyo_laser_scanner_ws/install/urg_node2/share/urg_node2/local_setup.bash ```\
``` source /hokuyo_laser_scanner_ws/install/slam_toolbox/share/slam_toolbox/local_setup.bash ```

<h2>Run nodes</h2>

``` ros2 launch urg_node2 urg_node2.launch.py ```\
``` ros2 launch slam_toolbox online_sync_launch.py ```
