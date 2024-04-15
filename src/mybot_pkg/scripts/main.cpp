#include "rosNode.hpp"

int main(int argc, char **argv)
{
   ros::init(argc, argv, "Robot_control_node");

    rosNode RosNode;
   ros::Rate r(15.0);
   while (ros::ok())
   {
      r.sleep();
      RosNode.update();
      ros::spinOnce();
   }

   ros::shutdown();
   return 0;
}
