cmake_minimum_required(VERSION 3.7.0)

set(KernelArch x86 CACHE STRING "" FORCE)
set(KernelSel4Arch ${PLATFORM} CACHE STRING "" FORCE)
set(KernelPlatform pc99 CACHE STRING "" FORCE)

include(kernel/tools/helpers.cmake)

set(GenerateSimulateScript true)
