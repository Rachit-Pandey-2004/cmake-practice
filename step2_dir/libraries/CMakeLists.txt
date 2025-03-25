add_library(MathLib mysqrt.cpp MathFunctions.cpp)
target_include_directories(MathLib PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/libraries")