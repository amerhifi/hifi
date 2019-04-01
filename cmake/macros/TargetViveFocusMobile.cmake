
macro(target_vivefocus)
    set(INSTALL_DIR ${HIFI_ANDROID_PRECOMPILED}/wavesdkmobile)

    # Mobile SDK
    set(WVR_MOBILE_INCLUDE_DIRS ${INSTALL_DIR}/Include)
    target_include_directories(${TARGET_NAME} PRIVATE ${WVR_MOBILE_INCLUDE_DIRS})
    set(WVR_MOBILE_LIBRARY_DIR  ${INSTALL_DIR}/lib)
    set(WVR_MOBILE_LIBRARY_RELEASE ${WVR_MOBILE_LIBRARY_DIR}/libsvrapi.so)
    set(WVR_MOBILE_LIBRARY_DEBUG ${WVR_MOBILE_LIBRARY_DIR}/libsvrapi.so)
    select_library_configurations(WVR_MOBILE)
    target_link_libraries(${TARGET_NAME} ${WVR_MOBILE_LIBRARIES})
endmacro()
