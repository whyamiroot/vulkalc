#
# MIT License
#
# Copyright (c) 2017 Lev Sizov a.k.a "ToxikCoder"
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#

project(vulkalc)
set(CMAKE_CXX_STANDARD 11)

#set(HEADER_FILES include/export.h include/Application.h include/RAII.h)
set(SOURCE_FILES Application.cpp)

include_directories($ENV{VULKAN_SDK}/Include)
include_directories(include)

if (ARCH_I386)
    if (WIN32)
        find_library(VULKAN NAMES vulkan-1 PATHS $ENV{VULKAN_SDK}/Lib32)
    elseif (UNIX)
        find_library(VULKAN NAMES vulkan PATHS $ENV{VULKAN_SDK}/lib32)
    endif (WIN32)
elseif (ARCH_AMD64)
    if (WIN32)
        find_library(VULKAN NAMES vulkan-1 PATHS $ENV{VULKAN_SDK}/Lib)
    elseif (UNIX)
        find_library(VULKAN NAMES vulkan PATHS $ENV{VULKAN_SDK}/lib)
    endif (WIN32)
else ()
    message("Attempting to find Vulkan library")
    find_library(VULKAN vulkan)
endif ()

if (VULKALC_BUILD_STATIC)
    #add_library(vulkalc STATIC ${SOURCE_FILES} ${HEADER_FILES})
    add_library(vulkalc STATIC ${SOURCE_FILES})
else ()
    #add_library(vulkalc SHARED ${SOURCE_FILES} ${HEADER_FILES})
    add_library(vulkalc STATIC ${SOURCE_FILES})
endif (VULKALC_BUILD_STATIC)

target_link_libraries(vulkalc ${VULKAN})
#TODO cmake install build artifacts and shaders