#ifndef __NAVIGATE_TO_GOAL_HPP__
#define __NAVIGATE_TO_GOAL_HPP__

#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>
#include <std_msgs/String.h>

class navigation
{
private:
    typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

    move_base_msgs::MoveBaseGoal _goal;
    std::string _goal_type; // "name" or "pose"
    std_msgs::String status,
                    _prevStatus;
    int statusCounter;

    MoveBaseClient *_ac;
    void fillTargetPose(geometry_msgs::Pose &pose);

public:
    void sendGoal(geometry_msgs::Pose &pose);
    std_msgs::String getStatus();

    navigation(std::string goal_type);
    ~navigation();
};

#endif // __NAVIGATE_TO_GOAL_HPP__