add_test([=[DateTest.ConstructorAndGetTest]=]  [==[/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date/g_date_test]==] [==[--gtest_filter=DateTest.ConstructorAndGetTest]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DateTest.ConstructorAndGetTest]=]  PROPERTIES WORKING_DIRECTORY [==[/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[DateTest.NextDateTest]=]  [==[/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date/g_date_test]==] [==[--gtest_filter=DateTest.NextDateTest]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DateTest.NextDateTest]=]  PROPERTIES WORKING_DIRECTORY [==[/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[DateTest.InStreamTest]=]  [==[/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date/g_date_test]==] [==[--gtest_filter=DateTest.InStreamTest]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DateTest.InStreamTest]=]  PROPERTIES WORKING_DIRECTORY [==[/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[DateTest.FailingInStreamTest]=]  [==[/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date/g_date_test]==] [==[--gtest_filter=DateTest.FailingInStreamTest]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DateTest.FailingInStreamTest]=]  PROPERTIES WORKING_DIRECTORY [==[/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[DateTest.OutStreamTest]=]  [==[/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date/g_date_test]==] [==[--gtest_filter=DateTest.OutStreamTest]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DateTest.OutStreamTest]=]  PROPERTIES WORKING_DIRECTORY [==[/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[DateTest.HarderOutStreamTest]=]  [==[/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date/g_date_test]==] [==[--gtest_filter=DateTest.HarderOutStreamTest]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DateTest.HarderOutStreamTest]=]  PROPERTIES WORKING_DIRECTORY [==[/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  g_date_test_TESTS DateTest.ConstructorAndGetTest DateTest.NextDateTest DateTest.InStreamTest DateTest.FailingInStreamTest DateTest.OutStreamTest DateTest.HarderOutStreamTest)