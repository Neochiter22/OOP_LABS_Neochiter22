# CMake generated Testfile for 
# Source directory: /workspaces/MEGA-SUPER-PUPER
# Build directory: /workspaces/MEGA-SUPER-PUPER/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(MyProjectTests "/workspaces/MEGA-SUPER-PUPER/build/tests")
set_tests_properties(MyProjectTests PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/MEGA-SUPER-PUPER/CMakeLists.txt;36;add_test;/workspaces/MEGA-SUPER-PUPER/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
