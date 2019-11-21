cmake_minimum_required( VERSION 2.8 )#cmake版本最低要求
project(data)#项目名称
 
find_package(catkin REQUIRED COMPONENTS 
roscpp 
sensor_msgs
message_generation
)
 
catkin_package(
 INCLUDE_DIRS include
   LIBRARIES ${PROJECT_NAME}
   CATKIN_DEPENDS roscpp

CATKIN_DEPENDS  roscpp  std_msgs message_runtime

)

 
include_directories(include ${catkin_INCLUDE_DIRS})
 

add_executable(data  src/main.cpp src/convert.cpp
src/receive_data.cpp
)#生成可执行文件
target_link_libraries(data ${catkin_LIBRARIES}
${roslib_LIBRARIES}
)#将目标文件与库文件进行链接,添加链接库,相同于指定-l参数

