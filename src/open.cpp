#include "open_interface.h"

/* the implimentation of the open door action 8? */
namespace KCL_rosplan {

	/* constructor */
	openInterface::openInterface(ros::NodeHandle &node_handle) {

		nh = node_handle;
		ROS_INFO("PDDL: Finished open setup");
		/* start on code to load the doors here instead of python 
		//needs a wait for server
		//spawn all the doors
		ros::ServiceClient client = nh.serviceClient<gazebo_msgs::SpawnModel>("/gazebo/spawn_sdf_model");

		gazebo_msgs::SpawnModel spawner;
		std::string model_path = ros::package::getPath("pddl_turtle");
		model_path += "/models/door1/model.sdf";
		ROS_INFO("PDDL: Door model path: %s", model_path.c_str());

		//read in the xml
		std::string model_xml = "";
		std::ifstream xml_file;
		xml_file.open(model_path.c_str());
		std::string temp;
		while (xml_file >> temp) {
			model_xml += temp;
		}


		spawner.request.model_name = "door1";
		spawner.request.model_xml = model_xml;
		spawner.request.robot_namespace = "/";
		spawner.request.reference_frame = "world";
		spawner.request.initial_pose.position.x = -6.330;
		spawner.request.initial_pose.position.y = .822;
		spawner.request.initial_pose.position.z = .73;
		spawner.request.initial_pose.orientation.z = .707;
		spawner.request.initial_pose.orientation.w = .707;

		if (client.call(spawner)) {
			ROS_INFO("PDDL: spawned %s", "door1");
		} else {
			ROS_ERROR("PDDL: could not spawn %s", "door1");
		};
		*/

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
		ROS_INFO("PDDL: (%s) requested %s", msg->name.c_str(), door.c_str());

		ros::ServiceClient client = nh.serviceClient<gazebo_msgs::DeleteModel>("/gazebo/delete_model");
		gazebo_msgs::DeleteModel deleter;

		deleter.request.model_name = door;

		if (client.call(deleter)) {
  			ROS_INFO("PDDL: (%s) %s complete", msg->name.c_str(), door.c_str());
			return true;
		} else {
			ROS_ERROR("PDDL: could not open %s", door.c_str());
		};
  		
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