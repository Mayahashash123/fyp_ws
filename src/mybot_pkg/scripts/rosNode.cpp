#include "rosNode.hpp"

rosNode::rosNode(/* args */)
{
    this->_nh = new ros::NodeHandle();
    this->getParams();

    if (this->_goal_type == "pose")
    {
        this->_goalPoseSub = this->_nh->subscribe<geometry_msgs::Pose>(this->_book_pose_topic, 1, [&](const geometry_msgs::Pose::ConstPtr &msg)
                                                                       { this->_goalPose = *msg;
                                                                       this->_newGoal= true;
                                                                       this->_nav->sendGoal(this->_goalPose); });
    }
    else if (this->_goal_type == "name")
    {
        this->_goalNameSub = this->_nh->subscribe<std_msgs::String>(this->_book_name_topic, 1, [&](const std_msgs::String::ConstPtr &msg)
                                                                    {
                                                                        this->_bookName = msg->data;
                                                                        ROS_INFO("book name: %s", this->_bookName.c_str());
                                                                        this->getPoseFromName(this->_bookName);
                                                                        this->_newGoal= true;
                                                                        this->_nav->sendGoal(this->_goalPose); });
    }
    else
    {
        ROS_ERROR("Invalid goal type");
        exit(1);
    }
    this->_odomSub = this->_nh->subscribe<nav_msgs::Odometry>("odom", 1, [&](const nav_msgs::Odometry::ConstPtr &msg)
                                                              { this->_odom.pose = msg->pose; });
    this->_nav = new navigation(this->_goal_type);

    this->_navigationStatePub = this->_nh->advertise<std_msgs::String>("navigation_status", 1);
}

void rosNode::getPoseFromName(const std::string &name)
{
    this->getRosParam("/pose/" + name + "/position/x", this->_goalPose.position.x);
    this->getRosParam("/pose/" + name + "/position/y", this->_goalPose.position.y);
    this->getRosParam("/pose/" + name + "/position/z", this->_goalPose.position.z);
    this->getRosParam("/pose/" + name + "/orientation/x", this->_goalPose.orientation.x);
    this->getRosParam("/pose/" + name + "/orientation/y", this->_goalPose.orientation.y);
    this->getRosParam("/pose/" + name + "/orientation/z", this->_goalPose.orientation.z);
    this->getRosParam("/pose/" + name + "/orientation/w", this->_goalPose.orientation.w);
}

void rosNode::getParams()
{
    std::string ns = "/robot_node/";
    this->getRosParam(ns + "goal_type", this->_goal_type);
    this->getRosParam(ns + "book_name_topic", this->_book_name_topic);
    this->getRosParam(ns + "book_pose_topic", this->_book_pose_topic);
}

void rosNode::getRosParam(std::string paramName, auto &paramValue)
{
    if (!this->_nh->getParam(paramName, paramValue))
    {
        ROS_ERROR("[PARAM] %s is not set", paramName.c_str());
        // exit(1);
        return;
    }
    std::stringstream strg;
    strg << paramValue;
    std::string s = strg.str();
    ROS_INFO("[PARAM] %s = %s", paramName.c_str(), s.c_str());
}

void rosNode::update()
{
    _navigationStatePub.publish(this->_nav->getStatus());
    // if (!this->_newGoal)
    //     return;

    // if (status.data == "reached" || status.data == "aborted")
    //     this->_newGoal = false;
}

rosNode::~rosNode()
{
    ros::shutdown();
    std::cout << "Exiting ROS Node" << std::endl;
}