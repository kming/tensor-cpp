#include "tensor.hpp"

#include <iostream>

namespace tensor {

const Tensor::Shape& Tensor::get_shape() const { return this->__shape; }
void Tensor::set_shape(const Tensor::Shape& shape) { this->__shape = shape; }
const Tensor::Stride& Tensor::get_stride() const { return this->__stride; }
void Tensor::set_stride(const Tensor::Stride& stride) { this->__stride = stride; }

DataType& Tensor::operator[](const Tensor::Index& index) {
  return this->__data.at(__stride.at(index));
}

typename std::vector<DataType>::iterator Tensor::begin() { return this->__data.begin(); }
typename std::vector<DataType>::iterator Tensor::end() { return this->__data.end(); }

}  // namespace tensor
