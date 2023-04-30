#pragma once

#include <vector>

namespace tensor {
template <typename DataType>
class Tensor {
 public:
  struct Index {
    unsigned int c = 0;
    unsigned int r = 0;
    unsigned int z = 0;
    unsigned int w = 0;
  };
  struct Shape : Index {
    unsigned int volume() { return this->w * this->z * this->r * this->c; }
  };
  struct Stride : Index {};

  Tensor();
  Tensor(const Tensor::Shape& shape);

  ~Tensor();

  const Tensor::Shape& get_shape() const;
  void set_shape(const Tensor::Shape& shape);

  DataType& operator[](const Tensor::Index& index);

  typename std::vector<DataType>::iterator begin();
  typename std::vector<DataType>::iterator end();

 private:
  std::vector<DataType> __data = {};
  Tensor::Stride __stride = {};
  Tensor::Shape __shape = {};
};
}  // namespace tensor
