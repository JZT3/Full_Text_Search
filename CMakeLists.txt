cmake_minimum_required(VERSION 3.5.0)
project(full_text_search VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(full_text_search full_text_search.cpp)

include(CTest)
enable_testing()

include(CPack)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

# Bring in the third party JSON library
include(FetchContent)
FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.11.3
)

FetchContent_MakeAvailable(json)

add_executable(full_text_search main.cpp)
target_link_libraries(full_text_search PRIVATE json::json)