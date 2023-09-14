#ifndef CPP2_S21_CONTAINERS_2_SRC_SET_SET_H_
#define CPP2_S21_CONTAINERS_2_SRC_SET_SET_H_

#include "../tree/BinarySearchTree.h"

namespace s21 {

template <typename Key>
class set {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator =
      typename BinarySearchTree<Key, Key>::BinarySearchTreeIterator;
  using const_iterator = iterator;
  using size_type = std::size_t;

  set();
  set(std::initializer_list<value_type> const& items);
  set(const set& other);
  set(set&& other);
  ~set();
  set& operator=(const set& other);
  set& operator=(set&& other);

  iterator begin();
  iterator end();

  bool empty();
  size_type size();
  size_type max_size();

  void clear();
  std::pair<iterator, bool> insert(const value_type& value);
  void erase(iterator pos);
  void swap(set& other);
  void merge(set& other);

  iterator find(const value_type& key);
  bool contains(const value_type& key);

 private:
  BinarySearchTree<key_type, value_type> binaryTree;
};
}  // namespace s21

#include "s21_set.tpp"

#endif  // CPP2_S21_CONTAINERS_2_SRC_SET_SET_H_