#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>
#include <std_msgs/String.h>
#include <iostream>

using namespace std;
using namespace ros;

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

void callback();
string book_name;
ros::NodeHandle navigation_nh;
geometry_msgs::Pose goal_pose;
move_base_msgs::MoveBaseGoal goal;
ros::Subscriber goal_sub = navigation_nh.subscribe<std_msgs::String>("book_names", 10, callback);

void callback(const std_msgs::String msg)
{
    book_name = msg.data;
    
}

void checkParam(string param_name, auto &paramvalue)
{
    if (!param::get(param_name, paramvalue))
    {
        ROS_ERROR("parameter not available");
        return;
    }
    ROS_INFO("parameter available");

}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "simple_navigation_goals");

    // MoveBaseClient ac("move_base", true);
    float  x;
    checkParam("/pose/" + book_name + "/position/x", x);

    // goal.target_pose.header.frame_id = "map";
    // goal.target_pose.header.stamp = ros::Time::now();

    // goal.target_pose.pose.position.x = goal_pose.position.x;
    // goal.target_pose.pose.position.y = param::get("/pose/" + book_name + "/position/x", goal_pose.position.y);
    // goal.target_pose.pose.position.z = param::get("/pose/" + book_name + "/position/x", goal_pose.position.z);
    // goal.target_pose.pose.orientation.x = param::get("/pose/" + book_name + "/position/x", goal_pose.orientation.x);
    // goal.target_pose.pose.orientation.y = param::get("/pose/" + book_name + "/position/x", goal_pose.orientation.y);
    // goal.target_pose.pose.orientation.z = param::get("/pose/" + book_name + "/position/x", goal_pose.orientation.z);
    // goal.target_pose.pose.orientation.w = param::get("/pose/" + book_name + "/position/x", goal_pose.orientation.w);

    // ac.sendGoal(goal);

    // ac.waitForResult();

    // if (ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    //     ROS_INFO("Hooray, the base moved 1 meter forward");
    // else
    //     ROS_INFO("The base failed to move forward 1 meter for some reason");

    return 0;
}
