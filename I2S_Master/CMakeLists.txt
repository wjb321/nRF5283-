# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(i2s_master)

target_sources(app PRIVATE src/main.c
           src/configure.c)

#add_executable(app src/main.c)
target_compile_definitions(app PRIVATE NRF52832_XXAA)
target_link_libraries(app PRIVATE -lc)
target_link_options(app PRIVATE -T ${CMAKE_CURRENT_SOURCE_DIR}/linker_script.ld)