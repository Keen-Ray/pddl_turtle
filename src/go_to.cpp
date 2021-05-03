#include "go_to.h"

/* The implementation of RPTutorial.h */
namespace KCL_rosplan {

	/* constructor */
	GoToInterface::GoToInterface(ros::NodeHandle &nh) {
		// perform setup
	}

	/* action dispatch callback */
	bool GoToInterface::concreteCallback(const rosplan_dispatch_msgs::ActionDispatch::ConstPtr& msg) {

		// The action implementation goes here.

		// complete the action
		ROS_INFO("PDDL: (%s) TUTORIAL Action completing.", msg->name.c_str());
		return true;
	}
} // close namespace

	/*-------------*/
	/* Main method */
	/*-------------*/

int main(int argc, char **argv) {

    ros::init(argc, argv, "rosplan_tutorial_action",    ros::init_options::AnonymousName);
    ros::NodeHandle nh("~");

    // create PDDL action subscriber
    KCL_rosplan::GoToInterface rpti(nh);

    rpti.runActionInterface();

    return 0;
}