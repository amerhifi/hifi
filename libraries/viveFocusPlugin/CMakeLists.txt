#
#  Created by Amer Cerkic on 2019/4/1
#  Copyright 2013-2019 High Fidelity, Inc.
#
#  Distributed under the Apache License, Version 2.0.
#  See the accompanying file LICENSE or http:#www.apache.org/licenses/LICENSE-2.0.html
#
if (ANDROID)
    set(TARGET_NAME vivefocusplugin)
    # don't use the setup_hifi_library macro, we don't want ANY qt dependencies
    file(GLOB_RECURSE LIB_SRCS "src/*.h" "src/*.cpp" "src/*.c" "src/*.qrc")
    add_library(${TARGET_NAME} SHARED ${LIB_SRCS})
    target_glm()
    target_egl()
    target_glad()

    link_hifi_libraries(
        shared task gl shaders gpu controllers ui qml
        plugins ui-plugins display-plugins input-plugins
        audio-client networking render-utils
        render graphics
	    ${PLATFORM_GL_BACKEND}
    )

    target_link_libraries(${TARGET_NAME} android log)
endif()