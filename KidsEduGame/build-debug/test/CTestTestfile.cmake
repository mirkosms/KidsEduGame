# CMake generated Testfile for 
# Source directory: C:/Users/HP/KidsEduGame/KidsEduGame/test
# Build directory: C:/Users/HP/KidsEduGame/KidsEduGame/build-debug/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(GameTests "C:/Users/HP/KidsEduGame/KidsEduGame/build-debug/bin/Debug/GameTests.exe")
  set_tests_properties(GameTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/HP/KidsEduGame/KidsEduGame/test/CMakeLists.txt;28;add_test;C:/Users/HP/KidsEduGame/KidsEduGame/test/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(GameTests "C:/Users/HP/KidsEduGame/KidsEduGame/build-debug/bin/Release/GameTests.exe")
  set_tests_properties(GameTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/HP/KidsEduGame/KidsEduGame/test/CMakeLists.txt;28;add_test;C:/Users/HP/KidsEduGame/KidsEduGame/test/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(GameTests "C:/Users/HP/KidsEduGame/KidsEduGame/build-debug/bin/MinSizeRel/GameTests.exe")
  set_tests_properties(GameTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/HP/KidsEduGame/KidsEduGame/test/CMakeLists.txt;28;add_test;C:/Users/HP/KidsEduGame/KidsEduGame/test/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(GameTests "C:/Users/HP/KidsEduGame/KidsEduGame/build-debug/bin/RelWithDebInfo/GameTests.exe")
  set_tests_properties(GameTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/HP/KidsEduGame/KidsEduGame/test/CMakeLists.txt;28;add_test;C:/Users/HP/KidsEduGame/KidsEduGame/test/CMakeLists.txt;0;")
else()
  add_test(GameTests NOT_AVAILABLE)
endif()
