自定义 话题消息：
在learning_topic下创建msg文件夹，消息相关定义放置于此
比如，需要创建一个person.msg
为了能够使用这个文件，需要定义规则：
1.在package.xml中添加功能包依赖
<build_depand>message_generation</build_depand>
<exec_depand>message_runtime</exec_depand>
2.在CMakeLists.txt中添加编译选项
