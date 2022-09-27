# include<ros/ros.h>
# include<tf2_ros/transform_listener.h>
# include<tf2_ros/buffer.h>
# include<geometry_msgs/PointStamped.h>
# include<tf2_geometry_msgs/tf2_geometry_msgs.h>
 //转换的过程需要这个头文件

int main(int argc,char** argv)
{
    ros::init(argc,argv,"node_tf_static_sub");
    ros::NodeHandle n;                                              //对于订阅者来说，nodehandel是必须的
    tf2_ros::Buffer buffer;                                         //创建一个buffer缓存，用来存储订阅的数据

    //创建一个listener，要指名buffer，注意类型，是tf2下的TransformListener，是tf系列
    tf2_ros::TransformListener listener(buffer);  
    //组织一个坐标点数据
    geometry_msgs::PointStamped  ps;
    ps.header.frame_id = "laser";
    ps.header.stamp = ros::Time::now();
    ps.point.x = 2.0;
    ps.point.y = 3.0;
    ps.point.z = 5.0;

    ros::Rate rate(2);
    ros::Duration(2).sleep();//作用：延迟两秒先订阅到base_link，否则直接 进行转换会出现核心以转储

    while(ros::ok())
    {
        geometry_msgs::PointStamped ps_out;
        ps_out = buffer.transform(ps,"base_link");

        ROS_INFO("after transfoem:(%0.2f,%0.2f,%.2f)\ncankao:(%s)",
        ps_out.point.x,
        ps_out.point.y,
        ps_out.point.z,
        ps_out.header.frame_id.c_str()
        );
        rate.sleep();
        ros::spinOnce;
    }
//转换算法，需要调用tf内置实现
//输出
    return 0;
}