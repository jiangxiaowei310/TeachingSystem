include("D:/qt 2302/666_zhuanzong/build/Desktop_Qt_6_10_2_MinGW_64_bit-Debug/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/666_zhuanzong-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE "D:/qt 2302/666_zhuanzong/build/Desktop_Qt_6_10_2_MinGW_64_bit-Debug/666_zhuanzong.exe"
    GENERATE_QT_CONF
)
