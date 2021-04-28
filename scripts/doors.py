#!/usr/bin/env python

from __future__ import print_function

import sys
import rospy
import rospkg
from gazebo_msgs.srv import (
    SpawnModel,
    DeleteModel,
    GetModelState,
    GetLinkState,
)
from geometry_msgs.msg import (
    PoseStamped,
    Pose,
    Point,
    Quaternion,
)
from std_msgs.msg import (
    Header,
    Empty,
    Bool,
)

def load_door():
    rospy.wait_for_service('/gazebo/spawn_sdf_model')
    spawn_sdf = rospy.ServiceProxy('/gazebo/spawn_sdf_model', SpawnModel)


    model_path = rospkg.RosPack().get_path('pddl_turtle')+"/models/"
    with open (model_path + "door1/model.sdf", "r") as door:
            door_xml=door.read().replace('\n', '')
    namespace = "/"

    door_info = {"door1" : Pose(position=Point(x=-6.330, y=.822, z=.73),
                                orientation=Quaternion(x=0.0, y=0.0, z=.712, 
                                                       w=.701)),
                 "door2" : Pose(position=Point(x=1.128, y=-.0952, z=.73),    
                                orientation=Quaternion(x=0.0, y=0.0, z=.712, 
                                                       w=.701)),
                 "door4" : Pose(position=Point(x=2.44, y=4.61, z=.73)),
                 "door5" : Pose(position=Point(x=2.20, y=0.441, z=.73)),
                 "door6" : Pose(position=Point(x=6.1735, y=-0.0653, z=.73),  
                                orientation=Quaternion(x=0.0, y=0.0, z=.712, 
                                                       w=.701)),
                  }
    for door_name in door_info.keys():
        pose = door_info[door_name]
        print("Addding model: %s"%door_name)

        try:
            spawn_sdf(door_name, door_xml, namespace, pose, "world")
        except rospy.ServiceException as e:
            print("Service call failed: %s"%e)

if __name__ == "__main__":
    print("Requesting door load")
    load_door()