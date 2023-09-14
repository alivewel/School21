#ifndef CPP2_S21_CONTAINER_2_SRC_MAP_MAP_H_
#define CPP2_S21_CONTAINER_2_SRC_MAP_MAP_H_

#include "../tree/BinarySearchTree.h"

namespace s21 {

template <typename Key, typename T>
class map {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator =
      typename BinarySearchTree<Key, value_type>::BinarySearchTreeIterator;
  using const_iterator = iterator;
  using size_type = std::size_t;

  map() = default;
  map(std::initializer_list<value_type> const& items);
  map(const map& other);
  map(map&& other);
  ~map() = default;
  map& operator=(const map& other);
  map& operator=(map&& other);

  T& at(const Key& key);
  T& operator[](const Key& key);

  iterator begin();
  iterator end();

  bool empty();
  size_type size();
  size_type max_size();

  void clear();
  std::pair<iterator, bool> insert(const value_type& value);
  std::pair<iterator, bool> insert(const Key& key, const T& obj);
  std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);
  void erase(iterator pos);
  void swap(map& other);
  void merge(map& other);

  bool contains(const Key& key);

 private:
  BinarySearchTree<Key, value_type> binaryTree;
};

}  // namespace s21

#include "s21_map.tpp"

#endif  // CPP2_S21_CONTAINER_2_SRC_MAP_MAP_H_