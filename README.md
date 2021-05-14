# PDDL_Turtle
## Setup
First, follow the instructions at https://github.com/KCL-Planning/ROSPlan to install ROSPlan

Second, follow the instructions at https://emanual.robotis.com/docs/en/platform/turtlebot3/simulation/#gazebo-simulation to install the Gazebo turtlebot simulation.

Third, clone this repository. Then call:
```catkin_make```

## To Run
```source devel/setup.sh```

In one terminal:
```roslaunch pddl_turtle turtlebot3_house.launch```

In another terminal
```In another terminal run, rosrun pddl_turtle rosplan.bash```

