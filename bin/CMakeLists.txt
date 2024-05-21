
add_executable(${PROJECT_NAME}-client client/main.cc)
add_executable(${PROJECT_NAME}-server server/main.cc)

target_link_libraries(
        ${PROJECT_NAME}-client
        PRIVATE
        ${PROJECT_NAME}
)

target_link_libraries(
        ${PROJECT_NAME}-server
        PRIVATE
        ${PROJECT_NAME}
)