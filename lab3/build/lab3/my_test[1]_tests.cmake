add_test([=[TestTopic.TrivialEquality]=]  [==[/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/my_test]==] [==[--gtest_filter=TestTopic.TrivialEquality]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TestTopic.TrivialEquality]=]  PROPERTIES WORKING_DIRECTORY [==[/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  my_test_TESTS TestTopic.TrivialEquality)
