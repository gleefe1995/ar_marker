# ar_marker


track_marker launch는 turtlebot3의 raspicam에서 ar_marker를 detection하는 launch파일입니다.

pose.cpp는 ar_marker detection 후 ar_pose_marker msg를 받아 cmd_vel msg를 publish하는 node입니다.

<turtlebot3>
roslaunch turtlebot3_bringup rpicamera.launch
  
<remote PC>
roslaunch ar_marker track_marker.launch
  
roslaunch ar_marker printpose
