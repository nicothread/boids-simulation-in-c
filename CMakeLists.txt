cmake_minimum_required(VERSION 3.16)
project(boids C)

set(BUILDDIR, "${CMAKE_BINARY_DIR}/build")

file(MAKE_DIRECTORY "${BUILDDIR}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILDDIR}")
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

# ── Build type default ────────────────────────────────────────────────
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# ── Find SDL2 ─────────────────────────────────────────────────────────
# Supports: system install, vcpkg, Homebrew, and manual SDL2_DIR override.
find_package(SDL2 REQUIRED)

# SDL2's upstream CMake config exposes SDL2::SDL2; older distro packages
# expose plain variables (SDL2_INCLUDE_DIRS / SDL2_LIBRARIES). Handle both.
if(NOT TARGET SDL2::SDL2)
    add_library(SDL2::SDL2 INTERFACE IMPORTED)
    target_include_directories(SDL2::SDL2 INTERFACE ${SDL2_INCLUDE_DIRS})
    target_link_libraries(SDL2::SDL2 INTERFACE ${SDL2_LIBRARIES})
endif()

# ── Executable ────────────────────────────────────────────────────────
add_executable(boids src/boids/boids_agent.c src/boids/boids_sensors.c src/bird_renderer.c src/sdl_renderer.c src/main.c)
target_include_directories(boids PUBLIC include)
target_link_libraries(boids PRIVATE SDL2::SDL2 m)

# ── Compiler warnings ─────────────────────────────────────────────────
target_compile_options(boids PRIVATE
        $<$<C_COMPILER_ID:GNU,Clang,AppleClang>:-Wall -Wextra -Wpedantic>
        $<$<C_COMPILER_ID:MSVC>:/W4>
)

# ── Release optimisation ──────────────────────────────────────────────
target_compile_options(boids PRIVATE
        $<$<AND:$<CONFIG:Release>,$<C_COMPILER_ID:GNU,Clang,AppleClang>>:-O2>
)

# ── Install (optional) ────────────────────────────────────────────────
install(TARGETS boids RUNTIME DESTINATION bin)

# ── Summary ───────────────────────────────────────────────────────────
message(STATUS "Build type : ${CMAKE_BUILD_TYPE}")
message(STATUS "C compiler : ${CMAKE_C_COMPILER}")
message(STATUS "SDL2 found : ${SDL2_VERSION}")
