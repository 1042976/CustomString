# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/xiaodongliu/Documents/interview/ESRI/CustomString/cmake-build-debug/_deps/googletest-src"
  "/Users/xiaodongliu/Documents/interview/ESRI/CustomString/cmake-build-debug/_deps/googletest-build"
  "/Users/xiaodongliu/Documents/interview/ESRI/CustomString/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix"
  "/Users/xiaodongliu/Documents/interview/ESRI/CustomString/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/Users/xiaodongliu/Documents/interview/ESRI/CustomString/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/Users/xiaodongliu/Documents/interview/ESRI/CustomString/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/Users/xiaodongliu/Documents/interview/ESRI/CustomString/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/xiaodongliu/Documents/interview/ESRI/CustomString/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
