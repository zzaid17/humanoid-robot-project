# CMake generated Testfile for 
# Source directory: /home/asis/hokuyo_ws/src/navigation2/nav2_system_tests/src/localization
# Build directory: /home/asis/hokuyo_ws/src/build/nav2_system_tests/src/localization
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_localization "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/asis/hokuyo_ws/src/build/nav2_system_tests/test_results/nav2_system_tests/test_localization.xml" "--package-name" "nav2_system_tests" "--generate-result-on-success" "--env" "TEST_MAP=/home/asis/hokuyo_ws/src/navigation2/nav2_system_tests/maps/map_circular.yaml" "TEST_EXECUTABLE=/home/asis/hokuyo_ws/src/build/nav2_system_tests/src/localization/test_localization_node" "TEST_WORLD=/home/asis/hokuyo_ws/src/navigation2/nav2_system_tests/worlds/turtlebot3_ros2_demo.world" "GAZEBO_MODEL_PATH=/home/asis/hokuyo_ws/src/navigation2/nav2_system_tests/models" "--command" "/home/asis/hokuyo_ws/src/navigation2/nav2_system_tests/src/localization/test_localization_launch.py")
set_tests_properties(test_localization PROPERTIES  TIMEOUT "180" WORKING_DIRECTORY "/home/asis/hokuyo_ws/src/build/nav2_system_tests/src/localization" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/home/asis/hokuyo_ws/src/navigation2/nav2_system_tests/src/localization/CMakeLists.txt;9;ament_add_test;/home/asis/hokuyo_ws/src/navigation2/nav2_system_tests/src/localization/CMakeLists.txt;0;")
