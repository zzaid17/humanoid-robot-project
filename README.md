In case of missing dependencies, incorrect file paths, or other issues, go through the following steps when porting to the robot.

Remove and reinstall packages from root directory

Remove urg_node2: ``` rm -rf src/urg_node2 ```\
Remove slam_toolbox: ``` rm -rf src/slam_toolbox ```
Remove build, install, log files: ``` rm -rf build/ install/ log/ ```

Reinstall packages from src directory

Install urg_node2: ``` git clone https://github.com/Hokuyo-aut/urg_node2 ```
Install slam_toolbox package: ``` git clone https://github.com/SteveMacenski/slam_toolbox ```

Install dependencies
Update rosdep: ``` rosdep update ```
Install urg_node2 dependencies: ``` rosdep install -i --from-paths urg_node2 ```
Install slam_toolbox dependencies: ``` rosdep install -q -y -r --from-paths src --ignore-src ```
