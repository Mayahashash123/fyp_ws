#ifndef __ROS_NODE_HPP__
#define __ROS_NODE_HPP__

#include <iostream>
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include "navigateToGoal.hpp"

class rosNode
{
private:
    ros::NodeHandle *_nh;
    ros::Subscriber _goalPoseSub,
        _goalNameSub,
        _odomSub;

    ros::Publisher _navigationStatePub;
    /* data */
    std::string _goal_type, // "pose" or "name"
        _book_name_topic,
        _book_pose_topic;

    geometry_msgs::Pose _goalPose;
    nav_msgs::Odometry _odom;
    std::string _bookName;
    std::string navigatoon_state;
    std_msgs::String status;
    bool _goalReached,
        _newGoal;

    navigation *_nav;
    void getPoseFromName(const std::string &name);
    void getParams();
    void getRosParam(std::string paramName, auto &paramValue);

public:
    void update();
    rosNode(/* args */);
    ~rosNode();
};

#endif //__ROS_NODE_HPP__