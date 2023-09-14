#ifndef CPP2_S21_CONTAINERS_2_SRC_STACK_STACK_H_
#define CPP2_S21_CONTAINERS_2_SRC_STACK_STACK_H_

#include "../list/s21_list.h"

namespace S21 {

template <class T, class Container = S21::list<T>>
class stack {
 public:
  // ============ Stack Member type ==============

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  // ============ Stack Member functions =========

  stack() : objStack(){};
  stack(std::initializer_list<value_type> const &items) : objStack(items){};
  stack(const stack &s) : objStack(s.objStack){};
  stack(stack &&s) noexcept : objStack(std::move(s.objStack)) {}
  ~stack() {}
  stack &operator=(stack &&s) noexcept {
    objStack = std::move(s.objStack);
    return *this;
  }
  stack &operator=(stack &s) {
    objStack = s.objStack;
    return *this;
  }

  // ============ Stack Element access ===========

  const_reference top() { return objStack.back(); }

  // ============ Stack Capacity =================

  bool empty() { return objStack.empty(); }
  size_type size() { return objStack.size(); }

  // ============ Stack Modifiers ================

  void push(const_reference value) { objStack.push_back(value); };
  void pop() { objStack.pop_back(); };
  void swap(stack &other) { objStack.swap(other.objStack); };

  // ============ insert_many ================

  template <typename... Args>
  void insert_many_front(Args &&...args) {
    for (auto &q : {std::forward<Args>(args)...}) {
      push(q);
    }
  }

  // ============ Other ================

  void operator=(const int &i) { objStack.crutch_overload(i); }

 private:
  Container objStack;
};

};  // namespace S21

#endif  // CPP2_S21_CONTAINERS_2_SRC_STACK_STACK_H_