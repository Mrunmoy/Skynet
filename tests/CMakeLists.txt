# Download and link GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(skynet_tests test_skynet.cpp ../skynet.cpp)
target_include_directories(skynet_tests PRIVATE ../)
target_link_libraries(skynet_tests gtest_main)

include(GoogleTest)
gtest_discover_tests(skynet_tests)
