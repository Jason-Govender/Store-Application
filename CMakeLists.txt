cmake_minimum_required(VERSION 3.19)
project(StoreApp LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Network)

qt_standard_project_setup()
qt_add_resources(APP_RESOURCES images.qrc)
qt_add_executable(StoreApp
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    customer.h customer.cpp
    item.h item.cpp
    inventory.h inventory.cpp
    transaction.h transaction.cpp
    ${APP_RESOURCES}
    broadcast.h broadcast.cpp


)




target_link_libraries(StoreApp
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Network
)

include(GNUInstallDirs)

install(TARGETS StoreApp
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET StoreApp
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
