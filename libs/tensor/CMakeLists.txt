
add_library(tensor
    src/tensor.cpp
)

target_include_directories(tensor PUBLIC inc)
target_compile_options(tensor PRIVATE
  -Wall -Wextra -Wpedantic -Werror
)
