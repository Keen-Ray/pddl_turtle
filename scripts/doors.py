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
    position: 
    x: 0.950391173363
    y: 0.0417707748711
    z: 0.730000019073
  orientation: 
    x: 0.0
    y: 0.0
    z: 0.712463617325
    w: 0.701709151268

    door_info = {"door1" : Pose(position=Point(x=0.0, y=0.0, z=.73)),
                 "door2" : Pose(position=Point(x=0.0, y=0.0, z=.73), orientation=Quaternion(x=0.0, y=0.0, z=.712, w=.701)),
                 "door3" : Pose(position=Point(x=0.0, y=0.0, z=0.0)),
                 "door4" : Pose(position=Point(x=2.44, y=4.61, z=.73)),
                 "door5" : Pose(position=Point(x=2.20, y=0.441, z=.73)),
                  }
    model_path = rospkg.RosPack().get_path('pddl_turtle')+"/models/"
    pose = Pose(position=Point(x=2.20, y=0.441, z=.73))
    name = "door1"
    with open (model_path + "door1/model.sdf", "r") as door:
            door_xml=door.read().replace('\n', '')
    namespace = "/"


    rospy.wait_for_service('/gazebo/spawn_sdf_model')
    spawn_sdf = rospy.ServiceProxy('/gazebo/spawn_sdf_model', SpawnModel)
    try:
        spawn_sdf(name, door_xml, namespace, pose, "world")
    except rospy.ServiceException as e:
        print("Service call failed: %s"%e)

if __name__ == "__main__":
    print("Requesting door load")
    load_door()