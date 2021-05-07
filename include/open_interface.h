#include <ros/ros.h>
#include <rosplan_action_interface/RPActionInterface.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <vector>
#include <map>

#ifndef PDDL_OPEN
#define PDDL_OPEN

/**
 * This file defines an action interface created in tutorial 10.
 */
namespace KCL_rosplan {

	class openInterface: public RPActionInterface
	{

	private:
		



	public:

		/* constructor */
		openInterface(ros::NodeHandle &nh);

		/* listen to and process action_dispatch topic */
		bool concreteCallback(const rosplan_dispatch_msgs::ActionDispatch::ConstPtr& msg);
	};
}
#endif