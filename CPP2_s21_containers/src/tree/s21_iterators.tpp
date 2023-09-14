namespace s21 {
template <typename Key, typename Value>
class BinarySearchTree<Key, Value>::BinarySearchTreeIterator {
 public:
  BinarySearchTreeIterator() = default;
  BinarySearchTreeIterator(Node* node, Node* root) : node_(node), root_(root){};
  BinarySearchTreeIterator(Node* node) : node_(node), root_(nullptr){};

  bool operator==(const BinarySearchTreeIterator& other) const;
  bool operator!=(const BinarySearchTreeIterator& other) const;

  BinarySearchTreeIterator& operator++();
  BinarySearchTreeIterator operator++(int);
  BinarySearchTreeIterator& operator--();
  BinarySearchTreeIterator operator--(int);
  reference operator*() const;

 private:
  Node* node_{nullptr};
  Node* root_{nullptr};
};

template <typename Key, typename Value>
class BinarySearchTree<Key, Value>::BinarySearchTreeConstIterator
    : public BinarySearchTreeIterator {
 public:
  BinarySearchTreeConstIterator() = default;
  BinarySearchTreeConstIterator(Node* node, Node* root) : it(node, root){};
  BinarySearchTreeConstIterator(const BinarySearchTreeIterator) : it(it){};

  bool operator==(const BinarySearchTreeConstIterator& other) const;
  bool operator!=(const BinarySearchTreeConstIterator& other) const;

  BinarySearchTreeConstIterator& operator++();
  BinarySearchTreeConstIterator operator++(int);
  BinarySearchTreeConstIterator& operator--();
  BinarySearchTreeConstIterator operator--(int);
  const_reference operator*() const;

 private:
  BinarySearchTreeIterator it;
};

/* ============ Iterator =============== */

template <typename Key, typename Value>
bool BinarySearchTree<Key, Value>::BinarySearchTreeIterator::operator==(
    const BinarySearchTreeIterator& other) const {
  return node_ == other.node_;
}

template <typename Key, typename Value>
bool BinarySearchTree<Key, Value>::BinarySearchTreeIterator::operator!=(
    const BinarySearchTreeIterator& other) const {
  return !(*this == other);
}

template <typename Key, typename Value>
typename BinarySearchTree<Key, Value>::reference
BinarySearchTree<Key, Value>::BinarySearchTreeIterator::operator*() const {
  if (node_ != nullptr) {
    return node_->key;
  } else {
    static Value dummy_value{};
    return dummy_value;  // Возвращаем ссылку на статический объект-заглушку
  }
}

template <typename Key, typename Value>
typename BinarySearchTree<Key, Value>::BinarySearchTreeIterator&
BinarySearchTree<Key, Value>::BinarySearchTreeIterator::operator++() {
  if (node_ != nullptr) {
    if (node_->right) {
      // Если у узла есть правый потомок, переходим к минимальному элементу в
      // правом поддереве
      node_ = BinarySearchTree::findMin(node_->right);
    } else {
      // Иначе, идем вверх по родительским узлам до тех пор, пока мы не станем
      // правым потомком или не дойдем до корня
      Node* parent = node_->parent;
      while (parent && node_ == parent->right) {
        node_ = parent;
        parent = parent->parent;
      }
      // Если мы остановились на левом потомке или дошли до корня, то это будет
      // следующий элемент
      node_ = parent;
    }
  }
  return *this;
}

template <typename Key, typename Value>
typename BinarySearchTree<Key, Value>::BinarySearchTreeIterator
BinarySearchTree<Key, Value>::BinarySearchTreeIterator::operator++(int) {
  BinarySearchTreeIterator temp =
      *this;  // Создаем временный итератор с текущим значением
  ++(*this);  // Инкрементируем текущий итератор с помощью префиксного
              // инкремента
  return temp;  // Возвращаем временный итератор с предыдущим значением
}

template <typename Key, typename Value>
typename BinarySearchTree<Key, Value>::BinarySearchTreeIterator&
BinarySearchTree<Key, Value>::BinarySearchTreeIterator::operator--() {
  if (node_ != nullptr) {
    if (node_->left) {
      node_ = node_->left;
      while (node_->right) {
        node_ = node_->right;
      }
    } else {
      Node* prev = nullptr;
      Node* current = root_;
      while (current != node_) {
        if (node_->key > current->key) {
          prev = current;
          current = current->right;
        } else {
          current = current->left;
        }
      }
      node_ = prev;
    }
  }

  return *this;
}

template <typename Key, typename Value>
typename BinarySearchTree<Key, Value>::BinarySearchTreeIterator
BinarySearchTree<Key, Value>::BinarySearchTreeIterator::operator--(int) {
  BinarySearchTreeIterator temp =
      *this;  // Создаем временный итератор с текущим значением
  --(*this);  // Инкрементируем текущий итератор с помощью префиксного
              // инкремента
  return temp;  // Возвращаем временный итератор с предыдущим значением
}

/* ============ ConstIterator =============== */

template <typename Key, typename Value>
bool BinarySearchTree<Key, Value>::BinarySearchTreeConstIterator::operator==(
    const BinarySearchTreeConstIterator& other) const {
  return it == other.it;
}

template <typename Key, typename Value>
bool BinarySearchTree<Key, Value>::BinarySearchTreeConstIterator::operator!=(
    const BinarySearchTreeConstIterator& other) const {
  return !(it == other.it);
}

template <typename Key, typename Value>
typename BinarySearchTree<Key, Value>::const_reference
BinarySearchTree<Key, Value>::BinarySearchTreeConstIterator::operator*() const {
  return *it;
}

template <typename Key, typename Value>
typename BinarySearchTree<Key, Value>::BinarySearchTreeConstIterator
BinarySearchTree<Key, Value>::BinarySearchTreeConstIterator::operator++(int) {
  BinarySearchTreeConstIterator temp =
      *this;  // Создаем временный итератор с текущим значением
  ++it;  // Инкрементируем текущий итератор с помощью префиксного инкремента
  return temp;  // Возвращаем временный итератор с предыдущим значением
}

template <typename Key, typename Value>
typename BinarySearchTree<Key, Value>::BinarySearchTreeConstIterator&
BinarySearchTree<Key, Value>::BinarySearchTreeConstIterator::operator--() {
  --it;
  return *this;
}

template <typename Key, typename Value>
typename BinarySearchTree<Key, Value>::BinarySearchTreeConstIterator
BinarySearchTree<Key, Value>::BinarySearchTreeConstIterator::operator--(int) {
  BinarySearchTreeConstIterator temp =
      *this;  // Создаем временный итератор с текущим значением
  --(*this);  // Инкрементируем текущий итератор с помощью префиксного
              // инкремента
  return temp;  // Возвращаем временный итератор с предыдущим значением
}

};  // namespace s21
