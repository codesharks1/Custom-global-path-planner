#include "nav_global_planner.h"

  

#include <pluginlib/class_list_macros.h>

PLUGINLIB_EXPORT_CLASS(nav_global_planner::NavGlobalPlanner,nav_core::BaseGlobalPlanner)

  

namespace nav_global_planner{
    NavGlobalPlanner::NavGlobalPlanner():initialized_(false){
    }

    NavGlobalPlanner::NavGlobalPlanner(std::string name, costmap_2d::Costmap2DROS* costmap_2d){

    initialize(name,costmap_2d);

    }

    void NavGlobalPlanner::initialize(std::string name, costmap_2d::Costmap2DROS* costmap_ros){

        if (!initialized_)

        {

        /* code */

        costmap_ = costmap_ros->getCostmap();

        initialized_ = true;

        }

    }

    bool NavGlobalPlanner::makePlan(const geometry_msgs::PoseStamped& start,

    const geometry_msgs::PoseStamped& goal,

    std::vector<geometry_msgs::PoseStamped>& plan){

    if (!initialized_)

        {

        ROS_ERROR("Planner is not initialized!");

        return false;

        }

        plan.clear();

        plan.push_back(start);

        plan.push_back(goal);

  

        return true;

    }

}