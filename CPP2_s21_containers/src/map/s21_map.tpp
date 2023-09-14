namespace s21 {

template <typename Key, typename T>
map<Key, T>::map(std::initializer_list<value_type> const& items) {
  binaryTree = BinarySearchTree<Key, value_type>(items);
}

template <typename Key, typename T>
map<Key, T>::map(const map& other) {
  binaryTree = other.binaryTree;
}

template <typename Key, typename T>
map<Key, T>::map(map&& other) {
  binaryTree = std::move(other.binaryTree);
}

template <typename Key, typename T>
typename map<Key, T>::map& map<Key, T>::operator=(const map& other) {
  if (this != &other) {
    binaryTree =
        other.binaryTree;  // Выполняем присваивание для бинарного дерева
  }
  return *this;
}

template <typename Key, typename T>
typename map<Key, T>::map& map<Key, T>::operator=(map&& other) {
  if (this != &other) {
    binaryTree =
        std::move(other.binaryTree);  // Выполняем перемещающее присваивание для
                                      // бинарного дерева
  }
  return *this;
}

template <typename Key, typename T>
T& map<Key, T>::at(const Key& key) {
  return (*binaryTree.at(key)).second;
}

template <typename Key, typename T>
T& map<Key, T>::operator[](const Key& key) {
  return at(key);
}

template <typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::begin() {
  return iterator(binaryTree.begin());
}

template <typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::end() {
  return iterator(binaryTree.end());
}

template <typename Key, typename T>
bool map<Key, T>::empty() {
  return binaryTree.empty();
}

template <typename Key, typename T>
typename map<Key, T>::size_type map<Key, T>::size() {
  return binaryTree.size();
}

template <typename Key, typename T>
typename map<Key, T>::size_type map<Key, T>::max_size() {
  return binaryTree.max_size();
}

template <typename Key, typename T>
void map<Key, T>::clear() {
  binaryTree.clear(binaryTree.getRoot());
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const value_type& value) {
  return binaryTree.insert(value);
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const Key& key, const T& obj) {
  std::pair<const Key, T> value = std::make_pair(key, obj);
  return binaryTree.insert(value);
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert_or_assign(
    const Key& key, const T& obj) {
  std::pair<Key, T> value(key, obj);
  std::pair<iterator, bool> result = insert(value);
  if (!result.second) at(key) = obj;
  return result;
}

template <typename Key, typename T>
void map<Key, T>::erase(iterator pos) {
  binaryTree.removeNode(binaryTree.getRoot(), *pos);
}

template <typename Key, typename T>
void map<Key, T>::swap(map& other) {
  std::swap(binaryTree, other.binaryTree);
}

template <typename Key, typename T>
void map<Key, T>::merge(map& other) {
  binaryTree.merge(other.binaryTree);
}

template <typename Key, typename T>
bool map<Key, T>::contains(const Key& key) {
  return binaryTree.contains(key);
}

}  // namespace s21
