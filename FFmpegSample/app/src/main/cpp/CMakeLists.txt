# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

MESSAGE(STATUS "Platform is Andriod.")
SET(TARGET_ARCH_FLAG ${ANDROID_ABI})
SET(TARGET_ABI ${TARGET_ARCH_FLAG})
MESSAGE(STATUS "TARGET_ABI is ${TARGET_ABI}")

SET (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-short-enums")
SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti -fno-exceptions -fno-short-enums -Werror=non-virtual-dtor")

set(lib_name native-lib)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/FFmpeg
)

link_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/jniLibs/FFmpeg/${TARGET_ABI}
)

set(PROCESSOR_FILES native-lib.cpp)

add_library( ${lib_name}
        SHARED
        ${PROCESSOR_FILES}
        )

set(ffmpeg_lib
        avformat
        avcodec
        avfilter
        swresample
        swscale
        avutil
        )

target_link_libraries(  ${lib_name}

                        ${ffmpeg_lib}
                        log
                        GLESv3
                        z
                        )