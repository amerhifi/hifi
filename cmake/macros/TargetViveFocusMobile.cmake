
macro(target_vivefocus_mobile)
    set(INSTALL_DIR ${HIFI_ANDROID_PRECOMPILED}/htc/wvr)

    # Mobile SDK
    set(WVR_MOBILE_INCLUDE_DIRS ${INSTALL_DIR}/Include)
    target_include_directories(${TARGET_NAME} PRIVATE ${WVR_MOBILE_INCLUDE_DIRS})
    set(WVR_MOBILE_LIBRARY_DIR  ${INSTALL_DIR}/Libs/armeabi-v7a)
    set(WVR_MOBILE_LIBRARY_RELEASE ${WVR_MOBILE_LIBRARY_DIR}/Release/libsvrapi.so)
    set(WVR_MOBILE_LIBRARY_DEBUG ${WVR_MOBILE_LIBRARY_DIR}/Debug/libsvrapi.so)
    select_library_configurations(WVR_MOBILE)
    target_link_libraries(${TARGET_NAME} ${WVR_MOBILE_LIBRARIES})
endmacro()
