#include <ros/ros.h>
#include <ar_track_alvar_msgs/AlvarMarkers.h>
#include <tf/tf.h>
#include <tf/transform_datatypes.h>
#include "geometry_msgs/Twist.h"

ros::Publisher pub;

void printPose(const ar_track_alvar_msgs::AlvarMarkers req)
{
    geometry_msgs::Twist velocity;
    if (!req.markers.empty()) {
          //tf::Quaternion q(req.markers[0].pose.pose.orientation.x, req.markers[0].pose.pose.orientation.y, req.markers[0].pose.pose.orientation.z, req.markers[0].pose.pose.orientation.w);
          //tf::Matrix3x3 m(q);
          double x, y, z;
          x = req.markers[0].pose.pose.position.x;
          y = req.markers[0].pose.pose.position.y;
          z = req.markers[0].pose.pose.position.z;
          //m.getRPY(roll, pitch, yaw);
          ROS_INFO("x, y, z = %1.2f  %1.2f  %1.2f", x, y, z);
          // roll  --> rotate around vertical axis
          // pitch --> rotate around horizontal axis
          // yaw   --> rotate around depth axis
          /*
          if (z>0.1){
              velocity.linear.x = 0.1;
              pub.publish(velocity);
          }
          */

          if(x>-0.06){
              velocity.angular.z = -0.1;
              pub.publish(velocity);
          }
          else if (x<-0.12){
              velocity.angular.z = 0.1;
              pub.publish(velocity);
          }

          if (z>0.3){
              velocity.linear.x = 0.04;
              pub.publish(velocity);
          }

        } // if



}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "pose");

    ros::NodeHandle nh;
    pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 10);
    ros::Subscriber pose_sub = nh.subscribe("ar_pose_marker", 1000, printPose);

    ros::spin();

    return 0;

}
