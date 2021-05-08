#include "go_through_interface.h"

/* The implementation of RPTutorial.h */
namespace KCL_rosplan {

	/* constructor */
	GoThroughInterface::GoThroughInterface(ros::NodeHandle &nh) {

		//no setup needed
		clear_costmaps_client_ = nh.serviceClient<std_srvs::Empty>("/move_base/clear_costmaps");

	}

	/* action dispatch callback */
	bool GoThroughInterface::concreteCallback(const rosplan_dispatch_msgs::ActionDispatch::ConstPtr& msg) {

		// The action implementation goes here.
		std::string door = "";
		std::string from = "";
		for (int i = 0; i < msg->parameters.size(); i++)
		{
			if (msg->parameters[i].key.compare("from") == 0) {
				from = msg->parameters[i].value;
			}
		}
		std_srvs::Empty emptySrv;
        clear_costmaps_client_.call(emptySrv);

		//tell the action client that we want to spin a thread by default
  		actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> ac("move_base", true);

		//wait for the action server to come up
		while(!ac.waitForServer()) {
			ROS_INFO("Waiting for the move_base action server to come up");
		}

  		move_base_msgs::MoveBaseGoal goal;

  		//we'll send a goal to the robot to move 1 meter forward
  		goal.target_pose.header.frame_id = "base_link";
  		goal.target_pose.header.stamp = ros::Time::now();

  		goal.target_pose.pose.position.x = 1.0;
		goal.target_pose.pose.orientation.w = 1.0;

  		ROS_INFO("PDDL: (%s) Sending goal", msg->name.c_str());
  		ac.sendGoal(goal);

  		ac.waitForResult();

		if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
			ROS_INFO("PDDL: (%s) completed", msg->name.c_str());
			return true;
		} else {
			ROS_ERROR("PDDL: (%s) The base failed to move through %s", msg->name.c_str(), door.c_str());
			return false;
		}
	}

} // close namespace

	/*-------------*/
	/* Main method */
	/*-------------*/

int main(int argc, char **argv) {

    ros::init(argc, argv, "go_through_action",    ros::init_options::AnonymousName);
    ros::NodeHandle nh("~");

    // create PDDL action subscriber
    KCL_rosplan::GoThroughInterface rpti(nh);

    rpti.runActionInterface();

    return 0;
}