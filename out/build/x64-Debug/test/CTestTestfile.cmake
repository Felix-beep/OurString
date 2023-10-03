# CMake generated Testfile for 
# Source directory: C:/Users/wisdom/source/repos/OurString/test
# Build directory: C:/Users/wisdom/source/repos/OurString/out/build/x64-Debug/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[string_test]=] "C:/Users/wisdom/source/repos/OurString/out/build/x64-Debug/test/string_test_Tests.exe")
set_tests_properties([=[string_test]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/wisdom/source/repos/OurString/test/CMakeLists.txt;86;add_test;C:/Users/wisdom/source/repos/OurString/test/CMakeLists.txt;0;")
subdirs("../_deps/googletest-build")
