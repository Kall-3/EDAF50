add_test([=[StringCastTest.FromInt]=]  [==[/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date/string_cast_test]==] [==[--gtest_filter=StringCastTest.FromInt]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[StringCastTest.FromInt]=]  PROPERTIES WORKING_DIRECTORY [==[/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[StringCastTest.FromDouble]=]  [==[/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date/string_cast_test]==] [==[--gtest_filter=StringCastTest.FromDouble]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[StringCastTest.FromDouble]=]  PROPERTIES WORKING_DIRECTORY [==[/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[StringCastTest.FromDateClass]=]  [==[/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date/string_cast_test]==] [==[--gtest_filter=StringCastTest.FromDateClass]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[StringCastTest.FromDateClass]=]  PROPERTIES WORKING_DIRECTORY [==[/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[StringCastTest.ExpectExceptionThrown]=]  [==[/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date/string_cast_test]==] [==[--gtest_filter=StringCastTest.ExpectExceptionThrown]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[StringCastTest.ExpectExceptionThrown]=]  PROPERTIES WORKING_DIRECTORY [==[/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  string_cast_test_TESTS StringCastTest.FromInt StringCastTest.FromDouble StringCastTest.FromDateClass StringCastTest.ExpectExceptionThrown)