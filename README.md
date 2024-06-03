In case of missing dependencies, incorrect file paths, or other issues, go through the following steps when porting to the robot.

1. Remove and reinstall packages from root directory
   a) Remove urg_node2: ``` rm -rf src/urg_node2 ```
   b) Remove slam_toolbox: rm -rf src/slam_toolbox
   c) Remove build, install, log files: rm -rf build/ install/ log/

2. Reinstall packages from src directory
   a) Install urg_node2: git clone https://github.com/Hokuyo-aut/urg_node2
   b) Install slam_toolbox package: git clone https://github.com/SteveMacenski/slam_toolbox

3. Install dependencies
   a) Update rosdep: rosdep update
   b) Install urg_node2 dependencies: rosdep install -i --from-paths urg_node2
   c) Install slam_toolbox dependencies: rosdep install -q -y -r --from-paths src --ignore-src
