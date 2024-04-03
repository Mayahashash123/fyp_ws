#include "odomNode.hpp"

odomNode::odomNode()
{
    this->_nh = new ros::NodeHandle();

    //! Get the parameters from the ROS parameter server
    this->getParams();

    // this->_poseSub = this->_nh->subscribe<geometry_msgs::Pose, odomNode>(this->_poseTopic, 1, &odomNode::poseCallback, this);
    // this->_twistSub = this->_nh->subscribe<geometry_msgs::Twist, odomNode>(this->_twistTopic, 1, &odomNode::twistCallback, this);

    // * Using lambda functions to subscribe to the topics instead of callback functions
    this->_poseSub = this->_nh->subscribe<geometry_msgs::Pose>(this->_poseTopic, 1, [&](const geometry_msgs::Pose::ConstPtr &msg)
                                                               {
                                                                this->_pose.position = msg->position;
                                                                this->_pose.orientation = msg->orientation; });

    this->_twistSub = this->_nh->subscribe<geometry_msgs::Twist>(this->_twistTopic, 1, [&](const geometry_msgs::Twist::ConstPtr &msg)
                                                                 {
                                                                            this->_twist.linear = msg->linear;
                                                                            this->_twist.angular = msg->angular; });

    this->_odomPub = this->_nh->advertise<nav_msgs::Odometry>(this->_odomTopic, 1);
}

void odomNode::getParams()
{
    this->getRosParam("/odom_node/odom_frame", this->_odomFrame);
    this->getRosParam("/odom_node/base_frame", this->_baseFrame);

    this->getRosParam("/odom_node/pose_topic", this->_poseTopic);
    this->getRosParam("/odom_node/twist_topic", this->_twistTopic);
    this->getRosParam("/odom_node/odom_topic", this->_odomTopic);
    this->getRosParam("/odom_node/publish_rate", this->loopRate);
    this->getRosParam("/odom_node/print_on_terminal", this->_printOnTerminalFlag);
}

void odomNode::getRosParam(std::string paramName, auto &paramValue)
{
    if (!this->_nh->getParam(paramName, paramValue))
    {
        ROS_ERROR("[PARAM] %s is not set", paramName.c_str());
        exit(1);
    }
    std::stringstream strg;
    strg << paramValue;
    std::string s = strg.str();
    ROS_INFO("[PARAM] %s = %s", paramName.c_str(), s.c_str());
}

// * Callback functions for the subscribers already replaced with lambda functions
// void odomNode::poseCallback(const geometry_msgs::Pose::ConstPtr &msg)
// {
//     this->_pose.position = msg->position;
//     this->_pose.orientation = msg->orientation;
// }
// void odomNode::twistCallback(const geometry_msgs::Twist::ConstPtr &msg)
// {
//     this->_twist.linear = msg->linear;
//     this->_twist.angular = msg->angular;
// }

bool odomNode::checkForPublishers()
{
    if (this->_poseSub.getNumPublishers() == 0)
    {
        ROS_WARN("No publishers for pose topic");
        return false;
    }
    if (this->_twistSub.getNumPublishers() == 0)
    {
        ROS_WARN("No publishers for twist topic");
        return false;
    }
    return true;
}

void odomNode::publishOdomWithTf()
{
    if (!this->checkForPublishers())
        return;

    this->_odom.header.stamp = ros::Time::now();
    this->_odom.header.frame_id = this->_odomFrame;
    this->_odom.child_frame_id = this->_baseFrame;

    this->_odom.pose.pose = this->_pose;
    this->_odom.pose.pose.position.z = 0.08; // wheel radius 8cm
    this->_odom.twist.twist = this->_twist;

    this->_odomPub.publish(this->_odom);

    geometry_msgs::TransformStamped _odomTrans;
    _odomTrans.header.stamp = ros::Time::now();
    _odomTrans.header.frame_id = this->_odomFrame;
    _odomTrans.child_frame_id = this->_baseFrame;

    _odomTrans.transform.translation.x = this->_pose.position.x;
    _odomTrans.transform.translation.y = this->_pose.position.y;
    _odomTrans.transform.translation.z = this->_pose.position.z;
    _odomTrans.transform.rotation = this->_pose.orientation;

    this->_tf.sendTransform(_odomTrans);

    printOnTerminal(this->_printOnTerminalFlag);
}

void odomNode::printOnTerminal(bool printFlag)
{
    if (!printFlag)
        return;

    system("clear");
    // print the pose and twist on the terminal
    std::cout << "------- Print Robot Odometry -------" << std::endl;
    std::cout << "Pose: \n"
              << "\t Position: \n"
              << "\t \t x: " << this->_odom.pose.pose.position.x << "\n"
              << "\t \t y: " << this->_odom.pose.pose.position.y << "\n"
              << "\t \t z: " << this->_odom.pose.pose.position.z << "\n"
              << "\t Orientation: \n"
              << "\t \t x: " << this->_odom.pose.pose.orientation.x << "\n"
              << "\t \t y: " << this->_odom.pose.pose.orientation.y << "\n"
              << "\t \t z: " << this->_odom.pose.pose.orientation.z << "\n"
              << "\t \t w: " << this->_odom.pose.pose.orientation.w << "\n\n";
    // print the twist on the terminal
    std::cout << "Twist: \n"
              << "\t Linear: \n"
              << "\t \t x: " << this->_odom.twist.twist.linear.x << "\n"
              << "\t Angular: \n"
              << "\t \t z: " << this->_odom.twist.twist.angular.z << "\n\n";
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "odom_publisher_node");
    odomNode odom;

    ros::Rate loop_rate(odom.loopRate); // rate in Hz

    while (ros::ok())
    {
        odom.publishOdomWithTf();
        ros::spinOnce();

        loop_rate.sleep();
    }

    return 0;
}
