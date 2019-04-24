set(TARGET_NAME focusInterface)
setup_hifi_library()
link_hifi_libraries(
    shared task networking qml
    image fbx hfm render-utils physics entities octree
    gl gpu
    vivefocusplugin
    ${PLATFORM_GL_BACKEND}
)

target_opengl()
target_bullet()
add_subdirectory("${CMAKE_SOURCE_DIR}/interface" "libraries/interface")
include_directories("${CMAKE_SOURCE_DIR}/interface/src")
add_subdirectory("${CMAKE_SOURCE_DIR}/plugins/hifiCodec" "libraries/hifiCodecPlugin")
target_link_libraries(focusInterface android log m interface)
