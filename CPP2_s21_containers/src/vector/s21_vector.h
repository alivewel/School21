#ifndef CPP2_S21_CONTAINERS_2_SRC_VECTOR_VECTOR_H_
#define CPP2_S21_CONTAINERS_2_SRC_VECTOR_VECTOR_H_

#include <initializer_list>
#include <iostream>
#include <limits>
#include <stdexcept>

namespace s21 {
template <typename T>
class Vector {
 public:
  using value_type = T;
  using reference = value_type&;
  using const_reference = const T&;
  using iterator = T*;
  using const_iterator = const T*;
  using size_type = size_t;

  Vector() : m_size(0), m_capacity(0), m_data(nullptr) {}

  explicit Vector(size_type n) : m_size(n), m_capacity(n), m_data(new T[n]) {}

  Vector(std::initializer_list<value_type> const& items)
      : m_size(items.size()),
        m_capacity(items.size()),
        m_data(new T[items.size()]) {
    for (size_type i = 0; i < m_size; ++i) {
      m_data[i] = *(items.begin() + i);
    }
  }

  Vector(const Vector& v)
      : m_size(v.m_size),
        m_capacity(v.m_capacity),
        m_data(new T[v.m_capacity]) {
    for (size_type i = 0; i < m_size; ++i) {
      m_data[i] = v.m_data[i];
    }
  }

  Vector(Vector&& v)
      : m_size(v.m_size), m_capacity(v.m_capacity), m_data(v.m_data) {
    v.m_size = 0;
    v.m_capacity = 0;
    v.m_data = nullptr;
  }

  ~Vector() { clear_m_data(); }

  Vector& operator=(const Vector& v) {
    if (this != &v) {
      Vector tmp(v);
      swap(tmp);
    }
    return *this;
  }

  Vector& operator=(Vector&& v) {
    if (this != &v) {
      clear_m_data();
      m_size = v.m_size;
      m_capacity = v.m_capacity;
      m_data = v.m_data;
      v.m_size = 0;
      v.m_capacity = 0;
      v.m_data = nullptr;
    }
    return *this;
  }

  reference at(size_type pos) {
    if (pos >= m_size) {
      throw std::out_of_range("Index out of range");
    }
    return m_data[pos];
  }

  const_reference at(size_type pos) const {
    if (pos >= m_size) {
      throw std::out_of_range("Index out of range");
    }
    return m_data[pos];
  }

  reference operator[](size_type pos) { return m_data[pos]; }

  const_reference operator[](size_type pos) const { return m_data[pos]; }

  const_reference front() const { return m_data[0]; }

  const_reference back() const { return m_data[m_size - 1]; }

  T* data() { return m_data; }

  iterator begin() { return m_data; }

  iterator end() { return m_data + m_size; }

  const_iterator begin() const { return m_data; }

  const_iterator end() const { return m_data + m_size; }

  bool empty() const { return m_size == 0; }

  size_type size() const { return m_size; }

  size_type max_size() const {
    return std::numeric_limits<size_type>::max() / sizeof(size_type);
  }

  void reserve(size_type size) {
    if (size > m_capacity) {
      resize(size);
    }
  }

  size_type capacity() const { return m_capacity; }

  void shrink_to_fit() {
    if (m_size < m_capacity) {
      resize(m_size);
    }
  }

  void clear() { m_size = 0; }

  void insert(iterator pos, const_reference value) {
    size_type index = pos - m_data;
    if (m_size >= m_capacity) {
      size_type newCapacity = 1;
      if (m_capacity != 0) {
        newCapacity = m_capacity * 2;
      }
      resize(newCapacity);
    }
    for (size_type i = m_size; i > index; --i) {
      m_data[i] = m_data[i - 1];
    }
    m_data[index] = value;
    ++m_size;
  }

  void erase(iterator pos) {
    size_type index = pos - m_data;
    for (size_type i = index; i < m_size - 1; ++i) {
      m_data[i] = m_data[i + 1];
    }
    --m_size;
  }

  void push_back(const_reference value) {
    if (m_size >= m_capacity) {
      size_type newCapacity;
      if (m_capacity == 0) {
        newCapacity = 1;
      } else {
        newCapacity = m_capacity * 2;
      }
      resize(newCapacity);
    }
    m_data[m_size] = value;
    ++m_size;
  }

  void pop_back() {
    if (m_size > 0) {
      --m_size;
    }
  }

  void swap(Vector& v) {
    std::swap(m_size, v.m_size);
    std::swap(m_capacity, v.m_capacity);
    std::swap(m_data, v.m_data);
  }

  // Part 3. Дополнительно

  template <typename... Args>
  iterator insert_many(const_iterator pos, Args&&... args) {
    size_type index = pos - m_data;
    size_type numArgs = sizeof...(Args);
    reserve(m_size + numArgs);

    iterator insertionPoint = m_data + index;

    size_type i = 0;
    (insert(insertionPoint + i++, args), ...);

    m_size += numArgs;

    return insertionPoint;
  }

  template <typename... Args>
  void insert_many_back(Args&&... args) {
    size_type numArgs = sizeof...(Args);
    reserve(m_size + numArgs);

    (push_back(args), ...);
  }

 private:
  void resize(size_type newCapacity) {
    T* newData = new T[newCapacity];
    for (size_type i = 0; i < m_size; ++i) {
      newData[i] = m_data[i];
    }
    delete[] m_data;
    m_data = newData;
    m_capacity = newCapacity;
  }

  void clear_m_data() {
    if (m_data != nullptr) {
      delete[] m_data;
      m_data = nullptr;
      m_size = 0;
      m_capacity = 0;
    }
  }

  size_type m_size;
  size_type m_capacity;
  T* m_data;
};
}  // namespace s21
#endif  // CPP2_S21_CONTAINERS_2_SRC_VECTOR_VECTOR_H_