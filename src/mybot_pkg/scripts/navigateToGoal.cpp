#include "navigateToGoal.hpp"

// navigation::navigation(std::string goal_type) : _goal_type(goal_type)
navigation::navigation(std::string goal_type)
{
    _goal_type = goal_type;
    this->_ac = new MoveBaseClient("move_base", true);
    ROS_WARN("Waiting for the move_base action server to come up");
    while (!this->_ac->waitForServer(ros::Duration(5.0)))
        ;
    ROS_INFO("move_base action server is up");
}

void navigation::fillTargetPose(geometry_msgs::Pose &pose)
{
    this->_goal.target_pose.header.frame_id = "map";
    this->_goal.target_pose.header.stamp = ros::Time::now();

    this->_goal.target_pose.pose.position.x = pose.position.x;
    this->_goal.target_pose.pose.position.y = pose.position.y;
    this->_goal.target_pose.pose.position.z = pose.position.z;
    this->_goal.target_pose.pose.orientation.x = pose.orientation.x;
    this->_goal.target_pose.pose.orientation.y = pose.orientation.y;
    this->_goal.target_pose.pose.orientation.z = pose.orientation.z;
    this->_goal.target_pose.pose.orientation.w = pose.orientation.w;
}

std_msgs::String navigation::getStatus()
{
    _prevStatus = status;
    if (this->_ac->getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    {
        status.data = "SUCCEEDED";
    }
    else if (this->_ac->getState() == actionlib::SimpleClientGoalState::ACTIVE)
    {
        status.data = "MOVING";
    }
    else if (this->_ac->getState() == actionlib::SimpleClientGoalState::ABORTED)
    {
        status.data = "ABORTED";
    }
    else if (this->_ac->getState() == actionlib::SimpleClientGoalState::LOST)
    {
        status.data = "READY";
    }

    if (status == _prevStatus && (status.data == "SUCCEEDED" || status.data == "ABORTED"))
        statusCounter++;

    else if (status != _prevStatus)
        statusCounter = 0;

    if (statusCounter > 10)
    {
        std_msgs::String s;
        s.data = "READY";
        return s;
    }
    ROS_INFO(status.data.c_str());
    return status;
}

void navigation::sendGoal(geometry_msgs::Pose &pose)
{
    fillTargetPose(pose);
    this->_ac->sendGoal(this->_goal);
}

navigation::~navigation()
{
}
