#ifndef CPP2_S21_CONTAINER_2_SRC_LIST_LIST_H_
#define CPP2_S21_CONTAINER_2_SRC_LIST_LIST_H_

#include <iostream>
#include <limits>

namespace S21 {

template <class T>
class node {
 public:
  T data_;
  node<T> *next_;
  node<T> *prev_;
  node(T value = T()) : data_(value), next_(this), prev_(this) {}
};

template <class T>
class list {
 public:
  // ============ List Member type ===============
  class ListIterator;
  class ListConstIterator;

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = ListIterator;
  using const_iterator = ListConstIterator;
  using size_type = size_t;

  // ============ Itterators ===============

  class ListIterator {
   public:
    node<value_type> *ptr_;

    ListIterator() { ptr_ = nullptr; }
    ListIterator(node<value_type> *obj) { ptr_ = obj; }
    reference operator*() { return ptr_->data_; }
    iterator &operator++() {
      ptr_ = ptr_->next_;
      return *this;
    }
    iterator &operator--() {
      ptr_ = ptr_->prev_;
      return *this;
    }
    bool operator==(const iterator &obj) { return ptr_ == obj.ptr_; }
    bool operator!=(const iterator &obj) { return ptr_ != obj.ptr_; }
  };

  class ListConstIterator {
   public:
    node<value_type> *cptr_;

    ListConstIterator() : cptr_(nullptr) {}

    ListConstIterator(node<value_type> *obj) : cptr_(obj) {}

    const_reference operator*() { return cptr_->data_; }
    const_iterator &operator++() {
      cptr_ = cptr_->next_;
      return *this;
    }
    const_iterator &operator--() {
      cptr_ = cptr_->prev_;
      return *this;
    }
    bool operator==(const const_iterator &obj) { return cptr_ == obj.cptr_; }
    bool operator!=(const const_iterator &obj) { return cptr_ != obj.cptr_; }
    node<value_type> *get_ptr() { return cptr_; }
  };
  // ============ List Functions ===============

  list() : head_(nullptr), tail_(nullptr), count_(0) { add_end(); }

  list(size_type n) : head_(nullptr), tail_(nullptr), count_(0) {
    if (n >= max_size()) throw "Error max limit";
    add_end();
    while (n--) {
      push_back(value_type());
    }
  }

  list(std::initializer_list<value_type> const &items)
      : head_(nullptr), tail_(nullptr), count_(0) {
    add_end();
    for (auto &obj : items) {
      push_back(obj);
    }
  }

  list(const list<value_type> &l) : head_(nullptr), tail_(nullptr), count_(0) {
    add_end();
    s21_copy(l);
  }

  list(list<value_type> &&l) : head_(nullptr), tail_(nullptr), count_(0) {
    add_end();
    swap(l);
  }

  ~list() {
    clear();
    delete end_;
  };

  list<value_type> &operator=(list<value_type> &&l) {
    clear();
    delete end_;
    zeroing();
    add_end();
    swap(l);
    return *this;
  }

  // ============ List Element access =============

  const_reference front() {
    if (!count_) return end_->data_;
    return head_->data_;
  };

  const_reference back() {
    if (!count_) return end_->data_;
    return tail_->data_;
  };

  //============ List Iterators ==================

  iterator begin() {
    if (!head_) return iterator(end_);
    return iterator(head_);
  };

  iterator end() { return iterator(end_); };

  const_iterator cbegin() {
    if (!head_) return const_iterator(end_);
    return const_iterator(head_);
  };

  const_iterator cend() { return const_iterator(end_); };

  // ============ List Capacity ===================

  bool empty() {
    if (count_ == 0) return true;
    return false;
  };

  size_type size() { return count_; };

  size_type max_size() {
    return std::numeric_limits<size_type>::max() / sizeof(node<value_type>) / 2;
  }

  // ============ List Modifiers ==================

  void clear() {
    if (count_ != 0) {
      while (count_) {
        pop_back();
      }
    }
  };

  iterator insert(iterator pos, const_reference value) {
    if (pos == head_) {
      push_front(value);
    } else if (pos == end_) {
      push_back(value);
    } else {
      node<value_type> *new_obj = new (std::nothrow) node<value_type>;
      if (!new_obj) throw "bad alloc";
      new_obj->data_ = value;
      node<value_type> *prev_pos = pos.ptr_->prev_;
      prev_pos->next_ = new_obj;
      new_obj->prev_ = prev_pos;
      new_obj->next_ = pos.ptr_;
      pos.ptr_->prev_ = new_obj;
      end_->data_ = ++count_;
    }
    return --pos;
  }

  void erase(iterator pos) {
    if (pos == head_) {
      pop_front();
    } else if (pos == tail_) {
      pop_back();
    } else {
      pos.ptr_->next_->prev_ = pos.ptr_->prev_;
      pos.ptr_->prev_->next_ = pos.ptr_->next_;
      delete pos.ptr_;
      end_->data_ = --count_;
    }
  }

  void push_back(const_reference value) {
    node<value_type> *new_obj = new (std::nothrow) node<value_type>(value);
    if (!new_obj) throw "bad alloc";
    if (!head_ && !tail_) {
      head_ = tail_ = new_obj;
    } else {
      new_obj->prev_ = tail_;
      tail_->next_ = new_obj;
      tail_ = new_obj;
    }
    pushes_script();
  }

  void pop_back() {
    if (!count_) throw "error. empty list";
    node<value_type> *buffer = tail_;
    if (head_ == tail_) {
      head_ = tail_ = nullptr;
      end_->prev_ = end_->next_ = end_;
    } else {
      tail_ = tail_->prev_;
      tail_->next_ = end_;
      end_->prev_ = tail_;
    }
    delete buffer;
    end_->data_ = --count_;
  }

  void push_front(const_reference value) {
    node<value_type> *new_obj = new (std::nothrow) node<value_type>(value);
    if (!new_obj) throw "bad alloc";
    if (!head_ && !tail_) {
      head_ = tail_ = new_obj;
    } else {
      new_obj->next_ = head_;
      head_->prev_ = new_obj;
      head_ = new_obj;
    }
    pushes_script();
  }

  void pop_front() {
    if (!count_) throw "error. empty list";
    node<value_type> *buffer = head_;
    head_ = head_->next_;
    head_->prev_ = end_;
    end_->next_ = head_;
    delete buffer;
    end_->data_ = --count_;
  }

  void swap(list &other) {
    std::swap(this->head_, other.head_);
    std::swap(this->tail_, other.tail_);
    std::swap(this->count_, other.count_);
    std::swap(this->end_, other.end_);
  }

  void merge(list &other) {
    if (this != &other) {
      auto itt_this = begin();
      auto itt_other = other.begin();
      while (itt_this != end() && itt_other != other.end()) {
        if (*itt_this >= *itt_other) {
          insert(itt_this, itt_other.ptr_->data_);
          ++itt_other;
          if (*itt_this <= *itt_other) {
            ++itt_this;
          }
          other.pop_front();
        } else {
          ++itt_this;
        }
      }
      if (other.size()) {
        for (size_type j = 1; j <= other.size(); j++) {
          push_back(*itt_other);
          ++itt_other;
        }
      }
      other.clear();
    }
  }

  void splice(const_iterator pos, list &other) {
    auto itt = other.begin();
    iterator p(pos.get_ptr());
    for (size_type i = 1; i <= other.size(); i++, ++itt) {
      insert(p, *itt);
    }
    other.clear();
  }

  void reverse() {
    if (count_ > 1) {
      int rev_count_ = count_ / 2;
      node<value_type> *buff_head_ = head_;
      node<value_type> *buff_tail_ = tail_;
      while (rev_count_--) {
        std::swap(buff_head_->data_, buff_tail_->data_);
        buff_head_ = buff_head_->next_;
        buff_tail_ = buff_tail_->prev_;
      }
    }
  }

  void unique() {
    auto itt_ = begin();
    for (int i_ = 1; i_ < count_; i_++, ++itt_) {
      if (itt_.ptr_->data_ == itt_.ptr_->next_->data_) {
        erase(itt_.ptr_->next_);
      }
    }
  }

  void sort() {
    int flag_ = 0;
    for (int i_ = 1; i_ < count_; i_++) {
      auto itt_ = begin();
      auto itt_next_ = ++begin();
      flag_ = 0;
      for (int j_ = 1; j_ < count_; j_++, ++itt_, ++itt_next_) {
        if (*itt_ > *itt_next_) {
          std::swap(itt_.ptr_->data_, itt_next_.ptr_->data_);
          flag_ = 1;
        }
      }
      if (flag_ == 0) break;
    }
  }

  // ============ insert_many ============

  template <class... Args>
  iterator insert_many(const_iterator pos, Args &&...args) {
    iterator p(pos.get_ptr());

    for (auto &q : {std::forward<Args>(args)...}) {
      insert(p, q);
    }

    return p;
  }

  template <class... Args>
  void insert_many_back(Args &&...args) {
    insert_many(cend(), args...);
  }

  template <class... Args>
  void insert_many_front(Args &&...args) {
    insert_many(cbegin(), args...);
  }

  // ============ Other ==================

  list<value_type> &operator=(list<value_type> &l) {
    clear();
    delete end_;
    zeroing();
    add_end();
    s21_copy(l);
    return *this;
  }

  value_type &operator=(const int &i) { return crutch(i); }

  value_type &crutch_overload(const int &i) { return crutch(i); }

 private:
  void add_end() {
    end_ = new (std::nothrow) node<value_type>();
    if (!end_) throw "bad alloc";
  }

  void zeroing() {
    head_ = tail_ = nullptr;
    count_ = 0;
  }

  void s21_copy(const list<value_type> &l) {
    node<value_type> *buff = l.head_;
    int n = l.count_;
    while (n--) {
      push_back(buff->data_);
      buff = buff->next_;
    }
  }

  void pushes_script() {
    end_->next_ = head_;
    end_->prev_ = tail_;
    end_->data_ = ++count_;
    head_->prev_ = end_;
    tail_->next_ = end_;
  }

  value_type &crutch(const int &i) {
    count_ = i;
    return end_->data_ = value_type();
  }

 private:
  node<value_type> *head_;
  node<value_type> *tail_;
  node<value_type> *end_;
  int count_;
};

};  // namespace S21

#endif  // CPP2_S21_CONTAINER_2_SRC_LIST_LIST_H_