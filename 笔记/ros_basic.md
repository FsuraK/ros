自定义 话题消息：
在learning_topic下创建msg文件夹，消息相关定义放置于此
比如，需要创建一个person.msg
为了能够使用这个文件，需要定义规则：
1. 在package.xml中添加功能包依赖
<build_depand>message_generation</build_depand>
<exec_depand>message_runtime</exec_depand>
2. 在CMakeLists.txt中添加编译选项  
3. 初始化一个节点后，节点名称"node"，节点所在命名空间为/xxx，则节点所在--->/xxx/node，若该节点发布了一个话题，话题名词--->位置：
"topic" ---> /xxx/topic 私有
"yyy/topic" ---> "/xxx/yyy/topic" 相对
"/topic" ---> "/topic" 全局
4. 坐标msg信息：  
在坐标转换中常用的：geometry_msg/TransformStamped和geometry_msg/PointStamped
前者传输坐标系相关位置信息，后者用于传输某个坐标系内坐标点的信息。
静态坐标信息，除了按照publisher和subscriber创建cpp文件，还可以直接使用终端命令（更推荐）。
roscore
rosrun tf2_ros staticransform_publisher 0.1 0.0 0.3 0.0 0.0 0.0 /base_link /camera
详细见5.1.2静态坐标变幻补充1



