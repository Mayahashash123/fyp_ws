#!/usr/bin/env python3
import rospy
from mybot_pkg.srv import ComputeCircleArea, ComputeCircleAreaRequest, ComputeCircleAreaResponse
import sys

rospy.init_node('service_client')
rospy.wait_for_service('computeArea')
circle_radius = rospy.ServiceProxy('computeArea', ComputeCircleArea)

radius = float(input("enter radius: "))
response = circle_radius(radius)
print(response)