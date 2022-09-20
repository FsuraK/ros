# include <ros/ros.h>
# include <turtlesim/Spawn.h>

int main(int argc,char** argv)
{
    ros::init(argc,argv,"turtle_spawn");
    ros::NodeHandle n;

    ros::service::waitForService("/spawn");
    ros::ServiceClient add_turtle = n.serviceClient<turtlesim::Spawn>("/spawn");

    turtlesim::Spawn srv;
    srv.request.x = 2.5;
    srv.request.x = 2.5;
    srv.request.name = "turtle2";

    ROS_INFO("call service to spawn tutle[x:%0.6f  y:%0.6f  name:%s]",srv.request.x,srv.request.x,srv.request.name.c_str() );
    add_turtle.call(srv);

    ROS_INFO("service sucess [name : %s]",srv.request.name.c_str() );
    return 0;

}
