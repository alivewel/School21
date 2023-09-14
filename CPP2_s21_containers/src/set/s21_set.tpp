
namespace s21 {

template <typename Key>
set<Key>::set() {}

template <typename Key>
set<Key>::set(std::initializer_list<Key> const &items) {
  for (auto i = items.begin(); i != items.end(); i++) {
    binaryTree.insert(*i);
  }
}

template <typename Key>
set<Key>::set(const set &other) : binaryTree(other.binaryTree) {}

template <typename Key>
set<Key>::set(set &&other) : binaryTree(std::move(other.binaryTree)) {}

template <typename Key>
set<Key>::~set() {}

template <typename Key>
set<Key> &set<Key>::operator=(const set &other) {
  binaryTree = other.binaryTree;
  return *this;
}

template <typename Key>
set<Key> &set<Key>::operator=(set &&other) {
  binaryTree = std::move(other.binaryTree);
  return *this;
}

template <typename Key>
typename set<Key>::iterator set<Key>::begin() {
  return binaryTree.begin();
}

template <typename Key>
typename set<Key>::iterator set<Key>::end() {
  return binaryTree.end();
}

template <typename Key>
bool set<Key>::empty() {
  return binaryTree.empty();
}

template <typename Key>
typename set<Key>::size_type set<Key>::size() {
  return binaryTree.size();
}

template <typename Key>
typename set<Key>::size_type set<Key>::max_size() {
  return binaryTree.max_size();
}

template <typename Key>
void set<Key>::clear() {
  binaryTree.clear(binaryTree.getRoot());
}

template <typename Key>
std::pair<typename set<Key>::iterator, bool> set<Key>::insert(
    const value_type &value) {
  return binaryTree.insert(value);
}

template <typename Key>
void set<Key>::erase(iterator pos) {
  binaryTree.removeNode(binaryTree.getRoot(), *pos);
}

template <typename Key>
void set<Key>::swap(set &other) {
  std::swap(binaryTree, other.binaryTree);
  ;
}

template <typename Key>
void set<Key>::merge(set &other) {
  binaryTree.merge(other.binaryTree);
}

template <typename Key>
typename set<Key>::iterator set<Key>::find(const Key &key) {
  return binaryTree.find(key);
}

template <typename Key>
bool set<Key>::contains(const Key &key) {
  return binaryTree.contains(key);
}

};  // namespace s21
