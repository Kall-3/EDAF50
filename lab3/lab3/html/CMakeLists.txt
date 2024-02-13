add_executable(html_test html_test.cc tagremover.cc)
target_link_libraries(html_test PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(html_test)

add_executable(html_tag_remover html_tag_remover.cc tagremover.cc)

# Copy test.html from html/ directory to the build directory
configure_file(test.html ${CMAKE_BINARY_DIR}/lab3/html/test.html COPYONLY)
