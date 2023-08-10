#include <iostream>
#include <ostream>
#include "intvector.h"

IntVector::IntVector(const unsigned int length) {
    resize(length);
}

IntVector::~IntVector() {
    if (this->data != nullptr) {
      free(this->data);
      this->data = nullptr;
    }
    this->pos = 0;
    this->length = 0;
}

std::ostream& operator<<(std::ostream &os, const IntVector &iv) {

    os << iv.data << " [ ";
    int i;
    for (i = 0; i < iv.pos; i++) {
        os << iv.data[i] << " ";
    }
    
    os << "] (used capacity = " << iv.pos 
      << ", spare = " << iv.length - iv.pos 
      << ", total = " << iv.length << ")\n";
    
    return os;
}

void IntVector::push(const int value) {
    if (this->pos > this->length - 1) {
      resize(this->length * 2);
    }
    this->data[this->pos++] = value;
}

int IntVector::pop() {
    if (this->pos <= 0) {
      std::cout << "Cannot pop item from empty vector!\n";
      return 0;
    }
    return this->data[--(this->pos)];
}

void IntVector::resize(const unsigned int new_length) {
    this->data = (int*) realloc(this->data, sizeof(int)*new_length);
    this->length = new_length;
}