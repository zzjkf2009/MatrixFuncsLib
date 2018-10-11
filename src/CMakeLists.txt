# Bring the header files into the library build environment.
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)
# Can manually add the sources files using set command, set a variable (libsrc) that contains the name values of all of the source files
# For convenience, only one source files is created for this sample project, more source file can be added as the library expends
 set(libsrc MatrixFuncsLib.cpp)

# The library is built as a shared library using the SHARED flag, and the MatrixfuncLib is used as the name of the shared library.
add_library(MatrixfuncShareLib SHARED ${libsrc})
# Set the properties for this library, more properties can be added
#set_target_properties(MatrixfuncShareLib PROPERTIES VERSION ${MatrixfuncLib_VERSION})


install (TARGETS MatrixfuncShareLib DESTINATION ${CMAKE_SOURCE_DIR})
install (FILES MatrixfuncShareLib.h DESTINATION ${CMAKE_SOURCE_DIR}/include)

# Create a executable file which is a user interface that can let user type their own matrix and doing calculations
add_executable(MatrixMultiplication MatrixMultiplication.cpp)
add_executable(MatrixTranspose MatrixTranspose.cpp)
# Link the created library to the executable
target_link_libraries (MatrixMultiplication MatrixfuncShareLib)
target_link_libraries (MatrixTranspose MatrixfuncShareLib)
