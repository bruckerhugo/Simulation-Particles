
add_executable(demo_solar_system particuleDemo.cxx)

target_link_libraries(demo_solar_system
    PRIVATE particules
)


add_executable(demo_univers demo_univers.cxx)
target_link_libraries(demo_univers particules)