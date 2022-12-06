set(EXECUTABLE_NAME ${PROJECT_NAME})

file(GLOB_RECURSE cpp_files "./*.cpp")
file(GLOB_RECURSE h_files "./*.h")
file(GLOB_RECURSE hpp_files "./*.hpp")

add_executable(${EXECUTABLE_NAME}
    ${cpp_files}
    ${h_files}
    ${hpp_files}
) 

target_include_directories(${EXECUTABLE_NAME}
    PRIVATE
    ${json_SOURCE_DIR}/single_include
)