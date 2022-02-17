cmake_minimum_required(VERSION 3.7.0)

set(KernelArch x86 CACHE STRING "" FORCE)
set(KernelSel4Arch ${PLATFORM} CACHE STRING "" FORCE)
set(KernelPlatform pc99 CACHE STRING "" FORCE)

set(musllibc_DIR ${CMAKE_SOURCE_DIR}/libc)
