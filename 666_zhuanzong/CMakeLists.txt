cmake_minimum_required(VERSION 3.19)
project(666_zhuanzong LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Sql)

qt_standard_project_setup()

qt_add_executable(666_zhuanzong
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    loginwindow.cpp
    loginwindow.h
    loginwindow.ui
    homepage.cpp
    homepage.h
    homepage.ui
    studentpage.cpp
    studentpage.h
    studentpage.ui
    teacherpage.cpp
    teacherpage.h
    teacherpage.ui
    classpage.cpp
    classpage.h
    classpage.ui
    majorpage.cpp
    majorpage.h
    majorpage.ui
    collegepage.cpp
    collegepage.h
    collegepage.ui
    userpage.cpp
    userpage.h
    userpage.ui
    databasemannager.h databasemannager.cpp
    teachermainwindow.cpp
    teachermainwindow.h
    teachermainwindow.ui
    teacherhomepage.cpp
    teacherhomepage.h
    teacherhomepage.ui
    teachermystudentspage.cpp
    teachermystudentspage.h
    teachermystudentspage.ui
    teachercoursepage.cpp
    teachercoursepage.h
    teachercoursepage.ui
    teachergradepage.cpp
    teachergradepage.h
    teachergradepage.ui
    teacherinfopage.cpp
    teacherinfopage.h
    teacherinfopage.ui
    studentmainwindow.cpp
    studentmainwindow.h
    studentmainwindow.ui
    studenthomepage.cpp
    studenthomepage.h
    studenthomepage.ui
    studentcoursepage.cpp
    studentcoursepage.h
    studentcoursepage.ui
    studentgradepage.cpp
    studentgradepage.h
    studentgradepage.ui
    studentschedulepage.cpp
    studentschedulepage.h
    studentschedulepage.ui
    studentinfopage.cpp
    studentinfopage.h
    studentinfopage.ui
    addstudentdialog.h addstudentdialog.cpp addstudentdialog.ui
    addteacherdialog.h addteacherdialog.cpp addteacherdialog.ui
    addcollegedialog.h addcollegedialog.cpp addcollegedialog.ui
    addmajordialog.h addmajordialog.cpp addmajordialog.ui
    addclassdialog.h addclassdialog.cpp addclassdialog.ui
    adduserdialog.h adduserdialog.cpp adduserdialog.ui
    batchimportdialog.h batchimportdialog.cpp batchimportdialog.ui
)

target_link_libraries(666_zhuanzong
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Sql
)

include(GNUInstallDirs)

install(TARGETS 666_zhuanzong
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET 666_zhuanzong
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
