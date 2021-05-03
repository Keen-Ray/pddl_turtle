#include <ros/ros.h>
#include <vector>

#include "rosplan_action_interface/RPActionInterface.h"

#ifndef PDDL_GO_TO
#define PDDL_GO_TO

/**
 * This file defines an action interface created in tutorial 10.
 */
namespace KCL_rosplan {

	class GoToInterface: public RPActionInterface
	{

	private:

	public:

		/* constructor */
		GoToInterface(ros::NodeHandle &nh);

		/* listen to and process action_dispatch topic */
		bool concreteCallback(const rosplan_dispatch_msgs::ActionDispatch::ConstPtr& msg);
	};
}
#endif