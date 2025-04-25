
# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html.
# For more examples on how to use CMake, see https://github.com/android/ndk-samples.

# Sets the minimum CMake version required for this project.
cmake_minimum_required(VERSION 3.22.1)

project("native-lib")

#add_library(native-lib SHARED test/main.cpp)
#add_library(other-lib SHARED comm/other.cpp)
#find_library(log-lib log)
#
#target_link_libraries(native-lib ${log-lib})
#target_link_libraries(other-lib ${log-lib})
add_subdirectory(comm)
add_subdirectory(test)
