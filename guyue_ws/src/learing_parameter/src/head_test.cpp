# include "learing_parameter/hello.h"
# include <ros/ros.h>

namespace hello_ns{
    void myhello::run(){
        ROS_INFO("run success");
    }

}

// using namespace hello_ns;

int main(int argc,char** argv)
{
    ros::init(argc,argv,"hello_head");

    hello_ns::myhello a;
    a.run();
    return 0;
}