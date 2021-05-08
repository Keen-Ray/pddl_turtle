#include <ros/ros.h>
#include <ros/package.h>
#include <rosplan_action_interface/RPActionInterface.h>
#include <gazebo_msgs/SpawnModel.h>
#include <gazebo_msgs/DeleteModel.h>
#include <geometry_msgs/PoseStamped.h>
#include <iostream>
#include <fstream>
#include <string>

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