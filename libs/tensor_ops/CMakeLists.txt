
add_library(tensor-ops
    src/tensor_ops.cpp
)
target_include_directories(tensor-ops PUBLIC inc)
target_compile_options(tensor-ops PRIVATE
  -Wall -Wextra -Wpedantic -Werror
)
