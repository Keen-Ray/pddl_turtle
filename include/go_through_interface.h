#include <ros/ros.h>
#include <rosplan_action_interface/RPActionInterface.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <geometry_msgs/PoseStamped.h>
#include <actionlib/client/simple_action_client.h>
#include <vector>
#include <map>
#include <std_srvs/Empty.h>

#ifndef PDDL_GO_THROUGH
#define PDDL_GO_THROUGH

/**
 * This file defines an action interface created in tutorial 10.
 */
namespace KCL_rosplan {

	class GoThroughInterface: public RPActionInterface
	{

	private:
		// to clear costmaps if move base gets stuck
        ros::ServiceClient clear_costmaps_client_;



	public:

		/* constructor */
		GoThroughInterface(ros::NodeHandle &nh);

		/* listen to and process action_dispatch topic */
		bool concreteCallback(const rosplan_dispatch_msgs::ActionDispatch::ConstPtr& msg);
	};
}
#endif