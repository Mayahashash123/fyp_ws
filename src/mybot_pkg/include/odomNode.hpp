#ifndef __ODOMNODE_HPP__
#define __ODOMNODE_HPP__

#include "ros/ros.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/TransformStamped.h"
#include "nav_msgs/Odometry.h"
#include "tf/transform_broadcaster.h"
#include <cstdlib>

class odomNode
{
private:
    ros::NodeHandle *_nh;
    ros::Subscriber _poseSub,
        _twistSub;
    ros::Publisher _odomPub;

    geometry_msgs::Pose _pose;
    geometry_msgs::Twist _twist;
    nav_msgs::Odometry _odom;
    
    tf::TransformBroadcaster _tf;

    std::string _poseTopic, _twistTopic, _odomTopic;
    std::string _odomFrame, _baseFrame;

    bool _printOnTerminalFlag;
    void getParams();

    // void poseCallback(const geometry_msgs::Pose::ConstPtr &msg);
    // void twistCallback(const geometry_msgs::Twist::ConstPtr &msg);
    void getRosParam(std::string paramName, auto &paramValue);
    bool checkForPublishers();
    void printOnTerminal(bool printFlag);

public:
    int loopRate;

    void publishOdomWithTf();

    odomNode(/* args */);
    ~odomNode();
};

odomNode::~odomNode()
{
    ros::shutdown();
}
#endif // __ODOMNODE_HPP__