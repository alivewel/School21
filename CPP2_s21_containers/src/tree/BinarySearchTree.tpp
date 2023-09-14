namespace s21 {

template <typename Key, typename Value>
BinarySearchTree<Key, Value>::BinarySearchTree(
    std::initializer_list<value_type> const& items) {
  for (const value_type& item : items) {
    insert(item);
  }
}

template <typename Key, typename Value>
BinarySearchTree<Key, Value>::BinarySearchTree(const BinarySearchTree& other) {
  if (this != &other) {
    root_ = copyTree(other.root_, nullptr);
  }
}

template <typename Key, typename Value>
BinarySearchTree<Key, Value>::BinarySearchTree(BinarySearchTree&& other) {
  root_ = other.root_;
  other.root_ = nullptr;
}

template <typename Key, typename Value>
BinarySearchTree<Key, Value>::~BinarySearchTree() {
  clear(root_);
}

template <typename Key, typename Value>
typename BinarySearchTree<Key, Value>::BinarySearchTree&
BinarySearchTree<Key, Value>::operator=(const BinarySearchTree& other) {
  if (this != &other) {
    clear(root_);
    root_ = copyTree(other.root_, nullptr);
  }
  return *this;
}

template <typename Key, typename Value>
typename BinarySearchTree<Key, Value>::BinarySearchTree&
BinarySearchTree<Key, Value>::operator=(BinarySearchTree&& other) {
  if (this != &other) {
    clear(root_);
    root_ = other.root_;
    other.root_ = nullptr;
  }
  return *this;
}

template <typename Key, typename Value>
typename BinarySearchTree<Key, Value>::Node*
BinarySearchTree<Key, Value>::copyTree(const Node* node, Node* parent) {
  if (node == nullptr) {
    return nullptr;
  }
  Node* new_node = new Node(node->key);
  new_node->left = copyTree(node->left, new_node);
  new_node->right = copyTree(node->right, new_node);
  new_node->parent = parent;
  return new_node;
}

template <typename Key, typename Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::at(const key_type& key) {
  Node* node = findNode(root_, key);
  if (node == nullptr) {
    throw std::out_of_range("Found no mapped value stored by given key");
  }
  return iterator(node, root_);
}

// template<typename Key, typename Value>
// typename BinarySearchTree<Key, Value>::const_iterator BinarySearchTree<Key,
// Value>::at(const key_type& key) const {
//     Node* node = findNode(root_, key);
//     if (node == nullptr) {
//         throw std::out_of_range("Found no mapped value stored by given key");
//     }
//     return const_iterator(node, root_);
// }

template <typename Key, typename Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::begin() {
  Node* node = findMin(root_);
  if (node != nullptr) {
    return iterator(node, root_);
  } else {
    return iterator(nullptr);
  }
}

template <typename Key, typename Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::end() {
  return iterator(nullptr, root_);
}

template <typename Key, typename Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::cbegin() const {
  Node* node = findMin(root_);
  if (node != nullptr) {
    return iterator(node, root_);
  } else {
    return iterator(nullptr);
  }
}

template <typename Key, typename Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::cend() const {
  return iterator(nullptr, root_);
}

template <typename Key, typename Value>
bool BinarySearchTree<Key, Value>::empty() const {
  return root_ == nullptr;
}

template <typename Key, typename Value>
typename BinarySearchTree<Key, Value>::size_type
BinarySearchTree<Key, Value>::size() const {
  return countNodes(root_);
}

template <typename Key, typename Value>
typename BinarySearchTree<Key, Value>::size_type
BinarySearchTree<Key, Value>::countNodes(Node* node) const {
  if (node == nullptr) {
    return 0;
  }
  return 1 + countNodes(node->left) + countNodes(node->right);
}

template <typename Key, typename Value>
typename BinarySearchTree<Key, Value>::size_type
BinarySearchTree<Key, Value>::max_size() const {
  return std::numeric_limits<size_type>::max() / sizeof(Node) / 2;
}

template <typename Key, typename Value>
void BinarySearchTree<Key, Value>::clear(Node* node) {
  if (node == nullptr) {
    return;
  }
  clear(node->left);
  clear(node->right);
  delete node;
  root_ = nullptr;
}

template <typename Key, typename Value>
std::pair<typename BinarySearchTree<Key, Value>::iterator, bool>
BinarySearchTree<Key, Value>::insert(const_reference key) {
  return insert(root_, key, nullptr);
}

template <typename Key, typename Value>
std::pair<typename BinarySearchTree<Key, Value>::iterator, bool>
BinarySearchTree<Key, Value>::insert(Node*& node, const_reference key,
                                     Node* parent) {
  if (node == nullptr) {
    node = new Node(key, nullptr, nullptr, parent);
    if (root_ == nullptr) {
      root_ = node;  // Обновляем указатель root для первого узла
    }
    return {
        iterator(node),
        true};  // Возвращаем итератор на новый узел и флаг успешного добавления
  }
  if (key < node->key) {
    // Рекурсивно вставляем элемент в левое поддерево
    auto result = insert(node->left, key, node);
    return {
        iterator(node->left),
        result.second};  // Возвращаем текущий узел и флаг успешного добавления
  } else if (key > node->key) {
    // Рекурсивно вставляем элемент в правое поддерево
    auto result = insert(node->right, key, node);
    return {
        iterator(node->right),
        result.second};  // Возвращаем текущий узел и флаг успешного добавления
  }
  return {iterator(node),
          false};  // Узел с таким ключом уже существует, возвращаем текущий
                   // узел и флаг неуспешного добавления
}

template <typename Key, typename Value>
typename BinarySearchTree<Key, Value>::Node*
BinarySearchTree<Key, Value>::removeNode(Node* node, const_reference key) {
  if (node == nullptr) {
    return nullptr;
  }
  if (key < node->key.first) {
    node->left = removeNode(node->left, key);
  } else if (key > node->key.first) {
    node->right = removeNode(node->right, key);
  } else {
    // Нашли узел для удаления
    // Узел без потомков или с одним потомком
    if (node->left == nullptr) {
      Node* temp = node->right;
      if (node == root_) {
        root_ = temp;
      }
      delete node;
      return temp;
    } else if (node->right == nullptr) {
      Node* temp = node->left;
      if (node == root_) {
        root_ = temp;
      }
      delete node;
      return temp;
    }
    // Узел с двумя потомками
    Node* successor = findMin(node->right);
    node->key.first = successor->key;
    node->right = removeNode(node->right, successor->key);
  }

  return node;
}

template <typename Key, typename Value>
void BinarySearchTree<Key, Value>::merge(BinarySearchTree& other) {
  if (this == &other) {
    return;  // Нельзя объединять дерево с самим собой
  }

  if (other.root_ == nullptr) {
    return;  // Дерево other пустое, ничего объединять не нужно
  }

  if (root_ == nullptr) {
    root_ = other.root_;  // Если текущее дерево пустое, просто заменяем его
                          // корень корнем other
  } else {
    // Иначе вставляем элементы из other в текущее дерево
    for (auto it = other.begin(); it != other.end(); ++it) {
      insert(*it);
    }
  }
  // Очищаем other, чтобы избежать двойного удаления
  other.clear(other.root_);
}

template <typename Key, typename Value>
bool BinarySearchTree<Key, Value>::contains(const Key& key) const {
  Node* node = root_;
  while (node != nullptr) {
    if (key == node->key) {
      return true;
    } else if (key < node->key) {
      node = node->left;
    } else {
      node = node->right;
    }
  }
  return false;
}

template <typename Key, typename Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::find(const_reference key) const {
  Node* node = root_;
  while (node != nullptr) {
    if (key == node->key) {
      return BinarySearchTreeIterator(node, root_);
    } else if (key < node->key) {
      node = node->left;
    } else {
      node = node->right;
    }
  }
  return BinarySearchTreeIterator(nullptr, root_);
}

template <typename Key, typename Value>
typename BinarySearchTree<Key, Value>::Node*
BinarySearchTree<Key, Value>::getRoot() const {
  return root_;
}

template <typename Key, typename Value>
void BinarySearchTree<Key, Value>::inorderTraversal(
    Node* node) {  // метод обхода бинарного дерева поиска (BST), который
                   // посещает узлы в порядке возрастания ключей.
  if (node != nullptr) {
    std::cout << node->key << " ";
    inorderTraversal(node->left);
    inorderTraversal(node->right);
  }
}

template <typename Key, typename Value>
void BinarySearchTree<Key, Value>::printInorder() {
  inorderTraversal(root_);
  std::cout << "\n";
}

template <typename Key, typename Value>
typename BinarySearchTree<Key, Value>::Node*
BinarySearchTree<Key, Value>::findMin(Node* node) {
  if (node == nullptr) return nullptr;

  while (node->left != nullptr) {
    node = node->left;
  }
  return node;
}

template <typename Key, typename Value>
typename BinarySearchTree<Key, Value>::Node*
BinarySearchTree<Key, Value>::findMax(Node* node) {
  if (node == nullptr) return nullptr;

  while (node->right != nullptr) {
    node = node->right;
  }
  return node;
}

template <typename Key, typename Value>
typename BinarySearchTree<Key, Value>::Node*
BinarySearchTree<Key, Value>::findNode(Node* node, const key_type& key) const {
  if (node == nullptr || node->key.first == key) {
    return node;
  }
  if (key < node->key.first) {
    return findNode(node->left, key);
  } else {
    return findNode(node->right, key);
  }
}

};  // namespace s21
