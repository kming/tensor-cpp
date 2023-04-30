#pragma once

#include <vector>

namespace tensor {
using DataType = float;
class Tensor {
 public:
  struct Index {
    unsigned int c = 0;
    unsigned int r = 0;
    unsigned int z = 0;
    unsigned int w = 0;
  };
  struct Shape : Index {
    unsigned int volume() const { return this->w * this->z * this->r * this->c; }
  };
  struct Stride : Index {
    unsigned int at(const Index& index) {
      return this->w * index.w + this->z * index.z + this->r * index.r + this->c * index.c;
    }
  };

  Tensor(){};
  Tensor(const Tensor::Shape& shape, const Tensor::Stride& stride)
      : __shape(shape), __stride(stride), __data(std::vector<DataType>(shape.volume(), 0.0f)){};

  ~Tensor(){};

  const Tensor::Shape& get_shape() const;
  void set_shape(const Tensor::Shape& shape);

  const Tensor::Stride& get_stride() const;
  void set_stride(const Tensor::Stride& stride);

  DataType& operator[](const Tensor::Index& index);

  typename std::vector<DataType>::iterator begin();
  typename std::vector<DataType>::iterator end();

 private:
  Tensor::Shape __shape = {};
  Tensor::Stride __stride = {};
  std::vector<DataType> __data = {};
};
}  // namespace tensor
