cmake_minimum_required(VERSION 3.10.0)
project(1MobilePhone VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(1MobilePhone)

target_sources(1MobilePhone PRIVATE
  src/main.cpp
  src/function.cpp
  src/phone.cpp
  src/contact.cpp
  src/phoneNumber.cpp
  )

