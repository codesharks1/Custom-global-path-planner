#ifndef NAV_GLOBAL_PLANNER_H
#define NAV_GLOBAL_PLANNER_H

#include <ros/ros.h>
#include <costmap_2d/costmap_2d_ros.h>
#include <nav_core/base_global_planner.h>
#include <vector>
#include <geometry_msgs/PoseStamped.h>

namespace nav_global_planner {
class NavGlobalPlanner : public nav_core::BaseGlobalPlanner {
    public:
        NavGlobalPlanner();
        NavGlobalPlanner(std::string name, costmap_2d::Costmap2DROS* costmap_2d);
        void initialize(std::string name, costmap_2d::Costmap2DROS* costmap_ros);
        bool makePlan(const geometry_msgs::PoseStamped& start, 
                  const geometry_msgs::PoseStamped& goal, 
                  std::vector<geometry_msgs::PoseStamped>& plan);
    private:
        costmap_2d::Costmap2D* costmap_;
        bool initialized_;

    };

}
#endif