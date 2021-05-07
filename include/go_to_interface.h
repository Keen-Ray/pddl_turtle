#include <ros/ros.h>
#include <rosplan_action_interface/RPActionInterface.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <vector>
#include <map>

#ifndef PDDL_GO_TO
#define PDDL_GO_TO

/**
 * This file defines an action interface created in tutorial 10.
 */
namespace KCL_rosplan {

	class GoToInterface: public RPActionInterface
	{

	private:
		
		typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
		typedef struct
		{
			double x;
			double y;
			double qz;
			double w;
		} door_loc;

		std::map<std::string, door_loc> database;



	public:

		/* constructor */
		GoToInterface(ros::NodeHandle &nh);

		/* listen to and process action_dispatch topic */
		bool concreteCallback(const rosplan_dispatch_msgs::ActionDispatch::ConstPtr& msg);
	};
}
#endif