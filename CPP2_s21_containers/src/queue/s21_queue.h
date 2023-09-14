#ifndef CPP2_S21_CONTAINER_2_SRC_QUEUE_QUEUE_H_
#define CPP2_S21_CONTAINER_2_SRC_QUEUE_QUEUE_H_

#include "../list/s21_list.h"
namespace S21 {

template <class T, class Container = S21::list<T>>
class queue {
 public:
  // ============ Queue Member type ==============

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  // ============ Queue Member functions =========

  queue() : objQueue() {}

  queue(std::initializer_list<value_type> const &items) : objQueue(items) {}

  queue(const queue &q) : objQueue(q.objQueue) {}

  queue(queue &&q) : objQueue(std::move(q.objQueue)) {}

  ~queue() {}

  queue &operator=(queue &&q) {
    objQueue = std::move(q.objQueue);
    return *this;
  }

  queue &operator=(queue &q) {
    objQueue = q.objQueue;
    return *this;
  }

  // ============ Queue Element access ===========

  const_reference front() { return objQueue.front(); }
  const_reference back() { return objQueue.back(); }

  // ============ Queue Capacity =================

  bool empty() { return objQueue.empty(); }

  size_type size() { return objQueue.size(); }

  // ============ Queue Modifiers ================

  void push(const_reference value) { objQueue.push_back(value); }
  void pop() { objQueue.pop_front(); }

  void swap(queue &other) { objQueue.swap(other.objQueue); }

  // ============ insert_many ================

  template <class... Args>
  void insert_many_back(Args &&...args) {
    for (auto &q : {std::forward<Args>(args)...}) {
      push(q);
    }
  }

  // ============ Other ================

  void operator=(const int &i) { objQueue.crutch_overload(i); }

 private:
  Container objQueue;
};

};  // namespace S21

#endif  // CPP2_S21_CONTAINER_2_SRC_QUEUE_QUEUE_H_