# CMakeList.txt : CMake project for NewTetris2, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)


# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()



project ("NewTetris2")

# Add source to this projec
add_executable (NewTetris2 
"Figura.cpp"
"Figura.h"
"Joc.cpp"
"Joc.h"
"main.cpp" 
"Tauler.h"
"Tauler.cpp"
)
include_directories("libs/")
message("DIRLIB: ${CMAKE_SOURCE_DIR}/libs/SDL2")
target_link_libraries(NewTetris2
"SDL2" 
"SDL2main" 
"SDL2test" 
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET NewTetris2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
