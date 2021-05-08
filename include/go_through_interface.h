#include <ros/ros.h>
#include <rosplan_action_interface/RPActionInterface.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <vector>
#include <map>

#ifndef PDDL_GO_THROUGH
#define PDDL_GO_THROUGH

/**
 * This file defines an action interface created in tutorial 10.
 */
namespace KCL_rosplan {

	class GoThroughInterface: public RPActionInterface
	{

	private:
		



	public:

		/* constructor */
		GoThroughInterface(ros::NodeHandle &nh);

		/* listen to and process action_dispatch topic */
		bool concreteCallback(const rosplan_dispatch_msgs::ActionDispatch::ConstPtr& msg);
	};
}
#endif