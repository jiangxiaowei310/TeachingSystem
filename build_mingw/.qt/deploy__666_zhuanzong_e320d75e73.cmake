include("D:/qt 2302/666_zhuanzong/build_mingw/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/666_zhuanzong-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE "D:/qt 2302/666_zhuanzong/build_mingw/666_zhuanzong.exe"
    GENERATE_QT_CONF
)
