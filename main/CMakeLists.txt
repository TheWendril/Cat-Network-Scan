idf_component_register(SRCS "main.cpp" "/opt/catframework/esp32/include/Cat/loopComponent.cpp" INCLUDE_DIRS ".")
include_directories(/opt/catframework/esp32/include)
target_link_libraries(${COMPONENT_LIB} INTERFACE /opt/catframework/esp32/lib/libcat.a)
target_compile_definitions(${COMPONENT_LIB} PRIVATE ESP_PLATFORM)
