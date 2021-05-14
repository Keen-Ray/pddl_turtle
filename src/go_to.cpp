#include "go_to_interface.h"

/* The implementation of RPTutorial.h */
namespace KCL_rosplan {

	/* constructor */
	GoToInterface::GoToInterface(ros::NodeHandle &nh) {

		//get the frame refrence for the points

		// set the door initial position by hard coding
		// for a bigger project we could build an automated system
		// to do this

		//TODO extend so that the robot take into account which room it is 
		//coming from when choosing a nav point
		door_loc door1;
		//door1.x     = -7.85;
		//door1.y     = 0.8;
		door1.x     = -6.33;
		door1.y     = 0.15;
		door1.qz    = 0.707;
		door1.w     = 0.707;

		door_loc door2;
		door2.x     = 1.0;
		door2.y     = 0.5;
		door2.qz    = -0.707;
		door2.w     = 0.707;

		door_loc door3;
		door3.x     = 6.1735;
		door3.y     = 0.6;
		door3.qz    = -0.707;
		door3.w     = 0.707;

		door_loc door4;
		door4.x     = 2.70;
		door4.y     = 4.61;
		door4.qz    = 1.0;
		door4.w     = 0.0;
		door_loc door5;
		door5.x     = 1.6;
		door5.y     = .5;
		door5.qz     = 0.0;
		door5.w     = 1.0;

		database.insert(std::pair<std::string, door_loc>("door1", door1));
		database.insert(std::pair<std::string, door_loc>("door2", door2));
		database.insert(std::pair<std::string, door_loc>("door3", door3));
		database.insert(std::pair<std::string, door_loc>("door4", door4));
		database.insert(std::pair<std::string, door_loc>("door5", door5));

	}

	/* action dispatch callback */
	bool GoToInterface::concreteCallback(const rosplan_dispatch_msgs::ActionDispatch::ConstPtr& msg) {

		// The action implementation goes here.
		std::string door = "";
		std::string from = "";
		for (int i = 0; i < msg->parameters.size(); i++)
		{
			if (msg->parameters[i].key.compare("from") == 0) {
				from = msg->parameters[i].value;
			}
			if (msg->parameters[i].key.compare("d") == 0) {
				door = msg->parameters[i].value;
			}
		}
		

		//tell the action client that we want to spin a thread by default
  		actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> ac("move_base", true);

		//wait for the action server to come up
		while(!ac.waitForServer(ros::Duration(5.0))) {
			ROS_INFO("Waiting for the move_base action server to come up");
		}

  		move_base_msgs::MoveBaseGoal goal;

  		//we'll send a goal to the robot to move 1 meter forward
  		goal.target_pose.header.frame_id = "map";
  		goal.target_pose.header.stamp = ros::Time::now();

		door_loc door_info = database.find(door)->second;

  		goal.target_pose.pose.position.x = door_info.x;
		goal.target_pose.pose.position.y = door_info.y;
  		goal.target_pose.pose.orientation.z = door_info.qz;
  		goal.target_pose.pose.orientation.w = door_info.w;

  		ROS_INFO("PDDL: (%s) Sending goal x = %f, y = %f", msg->name.c_str(), door_info.x, door_info.y);
  		ac.sendGoal(goal);

  		ac.waitForResult();

		if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
			ROS_INFO("PDDL: (%s) TUTORIAL from: %s to %s completing.", msg->name.c_str(), from.c_str(), door.c_str());
			return true;
		} else {
			ROS_ERROR("PDDL: (%s) The base failed to move to %s", msg->name.c_str(), door.c_str());
			return false;
		}
	}

} // close namespace

	/*-------------*/
	/* Main method */
	/*-------------*/

int main(int argc, char **argv) {

    ros::init(argc, argv, "go_to_action",    ros::init_options::AnonymousName);
    ros::NodeHandle nh("~");

    // create PDDL action subscriber
    KCL_rosplan::GoToInterface rpti(nh);

    rpti.runActionInterface();

    return 0;
}