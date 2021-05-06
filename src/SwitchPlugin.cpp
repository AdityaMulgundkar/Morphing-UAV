#include <gazebo/common/Plugin.hh>
#include <ros/ros.h>

bool symmetric = 0;

namespace gazebo
{
class WorldPluginTutorial : public WorldPlugin
{
public:
  WorldPluginTutorial() : WorldPlugin()
  {
  }

  void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf)
  {
    // Make sure the ROS node for Gazebo has already been initialized
    if (!ros::isInitialized())
    {
      ROS_FATAL_STREAM("A ROS node for Gazebo has not been initialized, unable to load plugin. "
        << "Load the Gazebo system plugin 'libgazebo_ros_api_plugin.so' in the gazebo_ros package)");
      return;
    }

    ROS_INFO("Hello World!");
  }

  void switchFoilShape() {
    if(symmetric) {
      ros::ServiceClient gazebo_spawn_clt_ = node_handle_.serviceClient< gazebo_msgs::SpawnModel> ("/gazebo/clarky_model");
    }
    else {
      ros::ServiceClient gazebo_spawn_clt_ = node_handle_.serviceClient< gazebo_msgs::SpawnModel> ("/gazebo/naca0015_model");
    }
  }

};
GZ_REGISTER_WORLD_PLUGIN(WorldPluginTutorial)
}