#!/usr/bin/env python3
import rospy
from mybot_pkg.srv import ComputeCircleArea, ComputeCircleAreaResponse, ComputeCircleAreaRequest

def compute_area(request = ComputeCircleAreaRequest):
    area = 3.14*request.radius**2
    return ComputeCircleAreaResponse(area)

rospy.init_node("service_server")
service = rospy.Service('computeArea', ComputeCircleArea, compute_area)

rospy.spin()
