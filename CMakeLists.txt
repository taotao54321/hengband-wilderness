cmake_minimum_required(VERSION 3.8)

project(hengband-wilderness)

find_package(PkgConfig REQUIRED)

pkg_check_modules(OPENCV4 REQUIRED opencv4)

set(Target wilderness)

add_executable(${Target}
    main.cpp
)

target_compile_features(${Target} PRIVATE cxx_std_17)
set_target_properties(${Target} PROPERTIES CXX_EXTENSIONS OFF)
target_compile_options(${Target} PRIVATE -Wall -Wextra)

target_include_directories(${Target} SYSTEM
    PRIVATE "Siv3D/include"
    PRIVATE "Siv3D/include/ThirdParty"
)

target_link_libraries(${Target} PRIVATE
    ${PROJECT_SOURCE_DIR}/Siv3D/lib/libSiv3D.a

    ${OPENCV4_LIBRARIES}
    -lOpenGL
    -lGLEW
    -lX11
    -lpthread
    -ldl
    -ludev
    -lfreetype
    -lharfbuzz
    -lglib-2.0
    -lgobject-2.0
    -lgio-2.0
    -lpng
    -lturbojpeg
    -lgif
    -lwebp
    -lopenal
    -logg
    -lvorbis
    -lvorbisenc
    -lvorbisfile
    -lboost_filesystem
    -lavformat
    -lavcodec
    -lavutil
    -lswresample
    -lz
)
