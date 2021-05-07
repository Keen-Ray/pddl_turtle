#include "open_interface.h"

/* the implimentation of the open door action 8? */
namespace KCL_rosplan {

	/* constructor */
	openInterface::openInterface(ros::NodeHandle &nh) {

		//spawn all the doors

	}

	/* action dispatch callback */
	bool openInterface::concreteCallback(const rosplan_dispatch_msgs::ActionDispatch::ConstPtr& msg) {

		// The action implementation goes here.
		std::string door = "";
		for (int i = 0; i < msg->parameters.size(); i++)
		{
			if (msg->parameters[i].key.compare("d") == 0) {
				door = msg->parameters[i].value;
			}
		}
		

  		ROS_INFO("PDDL: (%s) %s complete", msg->name.c_str(), door.c_str());
  		return true;
	}

} // close namespace

	/*-------------*/
	/* Main method */
	/*-------------*/

int main(int argc, char **argv) {

    ros::init(argc, argv, "open_action", ros::init_options::AnonymousName);
    ros::NodeHandle nh("~");

    // create PDDL action subscriber
    KCL_rosplan::openInterface rpti(nh);

    rpti.runActionInterface();

    return 0;
}