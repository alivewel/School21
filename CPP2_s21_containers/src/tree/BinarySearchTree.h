#ifndef CPP2_S21_CONTAINERS_2_SRC_TREE_BINARY_SEARCH_TREE_H_
#define CPP2_S21_CONTAINERS_2_SRC_TREE_BINARY_SEARCH_TREE_H_

#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <utility>

namespace s21 {
template <typename Key, typename Value>
class BinarySearchTree {
 public:
  class Node {
   public:
    Value key;
    Node* left;
    Node* right;
    Node* parent;
    Node(const Value& key_)
        : key(key_), left(nullptr), right(nullptr), parent(nullptr) {}
    Node(const Value& key_, Node* left, Node* right, Node* parent)
        : key(key_), left(left), right(right), parent(parent) {}
  };

  class BinarySearchTreeIterator;
  class BinarySearchTreeConstIterator;

  using key_type = Key;
  using value_type = Value;
  using reference = Value&;
  using const_reference = const Value&;
  using iterator = BinarySearchTree<Key, Value>::BinarySearchTreeIterator;
  using const_iterator =
      BinarySearchTree<Key, Value>::BinarySearchTreeConstIterator;
  using size_type = std::size_t;

  BinarySearchTree() = default;
  BinarySearchTree(std::initializer_list<value_type> const& items);
  BinarySearchTree(const BinarySearchTree& other);
  BinarySearchTree(BinarySearchTree&& other);
  ~BinarySearchTree();
  BinarySearchTree& operator=(const BinarySearchTree& other);
  BinarySearchTree& operator=(BinarySearchTree&& other);

  iterator at(const key_type& key);

  iterator begin();
  iterator end();
  iterator cbegin() const;
  iterator cend() const;

  bool empty() const;
  size_type size() const;
  size_type max_size() const;

  void clear(Node* node);
  std::pair<iterator, bool> insert(const_reference key);
  std::pair<iterator, bool> insert(Node*& node, const_reference key,
                                   Node* parent);
  Node* removeNode(Node* node, const_reference key);
  void merge(BinarySearchTree& other);

  bool contains(const Key& key) const;

  iterator find(const_reference key) const;
  Node* getRoot() const;

  void inorderTraversal(Node* node);
  void printInorder();

 private:
  Node* root_{nullptr};

  Node* copyTree(const Node* node, Node* parent);
  static Node* findMin(Node* node);
  static Node* findMax(Node* node);
  Node* findNode(Node* node, const key_type& key) const;
  size_type countNodes(Node* node) const;
};

}  // namespace s21

#include "./BinarySearchTree.tpp"
#include "./s21_iterators.tpp"

#endif  // CPP2_S21_CONTAINERS_2_SRC_TREE_BINARY_SEARCH_TREE_H_
