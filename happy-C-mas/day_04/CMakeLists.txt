cmake_minimum_required(VERSION 3.10)

project(AOC-2021)

set(FIRST_TARGET_NAME "first_part")
set(PUZZLE_INPUT "puzzle_input")
#set(SECOND_TARGET_NAME "second_part")

add_executable(${FIRST_TARGET_NAME} "${FIRST_TARGET_NAME}.c")
#add_executable(${SECOND_TARGET_NAME} "${SECOND_TARGET_NAME}.c")

set_property(TARGET ${FIRST_TARGET_NAME} PROPERTY C_STANDARD 99)
#set_property(TARGET ${SECOND_TARGET_NAME} PROPERTY C_STANDARD 99)

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DPUZZLE_INPUT='\"${PUZZLE_INPUT}\"' -Wall -Wextra -Wfatal-errors")

