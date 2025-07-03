file(GLOB_RECURSE TEST_FILES CONFIGURE_DEPENDS
    "test_vecteur/*.cxx"
)

foreach(test_file IN LISTS TEST_FILES)
    # Extrait le nom sans extension pour nommer l'exécutable
    get_filename_component(test_name ${test_file} NAME_WE)
    
    add_executable(${test_name} ${test_file})
    
    target_link_libraries(${test_name} PRIVATE particules Catch2::Catch2WithMain)
    
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()
