# include <ros/ros.h>
# include <tf2_ros/static_transform_broadcaster.h>
# include <geometry_msgs/TransformStamped.h>
# include <tf2/LinearMath/Quaternion.h>

int main(int argc,char ** argv)
{
    ros::init(argc,argv,"node_tf_static_pub");
    ros::NodeHandle n;
    //创建发布对象,tf2_ros
    tf2_ros::StaticTransformBroadcaster pub;
    //组织被发布的消息,
    geometry_msgs::TransformStamped msg;
    msg.header.stamp = ros::Time::now();  //消息的头部是时间戳，ros::Time::now()获取当前时间
    msg.header.frame_id = "base_link";      //相对坐标系中被参考的那一个
    msg.child_frame_id = "laser";
    msg.transform.translation.x=0.2;
    msg.transform.translation.y=0.0;
    msg.transform.translation.z=0.5;

    tf2::Quaternion qtn; //创建四元数 对象
    // 向该对象设置欧拉角，这个对象可以将欧拉角转换成四元数
    qtn.setRPY(0,0,0);

    msg.transform.rotation.x =qtn.getX();
    msg.transform.rotation.y =qtn.getY();
    msg.transform.rotation.z =qtn.getZ();
    msg.transform.rotation.w =qtn.getW();
        //发布数据
    pub.sendTransform(msg);
    ROS_INFO("TF_STATIC_SUCCESS!");
    ros::spin();

    return 0;
}