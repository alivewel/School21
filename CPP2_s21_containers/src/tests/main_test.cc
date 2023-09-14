// #include "../map/s21_map.h"
// #include "../set/s21_set.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <array>
#include <initializer_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#include "../s21_containers.h"

// VECTOR

TEST(Vector, def_constructor_int) {
  s21::Vector<int> s21_vector;
  std::vector<int> std_vector;

  ASSERT_EQ(s21_vector.empty(), std_vector.empty());
  ASSERT_EQ(s21_vector.size(), std_vector.size());
  ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
}

TEST(Vector, def_constructor_char) {
  s21::Vector<char> s21_vector;
  std::vector<char> std_vector;

  ASSERT_EQ(s21_vector.empty(), std_vector.empty());
  ASSERT_EQ(s21_vector.size(), std_vector.size());
  ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
}

TEST(Vector, def_constructor_int_1) {
  s21::Vector<int> s21_vector(5);
  std::vector<int> std_vector(5);

  ASSERT_EQ(s21_vector.max_size(), std_vector.max_size());
  ASSERT_EQ(s21_vector.empty(), std_vector.empty());
  ASSERT_EQ(s21_vector.size(), std_vector.size());
  ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
}

TEST(Vector, def_constructor_int_2) {
  s21::Vector<int> s21_vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};

  ASSERT_EQ(s21_vector.empty(), std_vector.empty());
  ASSERT_EQ(s21_vector.size(), std_vector.size());
  ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
}

TEST(Vector, def_copy) {
  s21::Vector<int> s21_vector{1, 2, 3};
  s21::Vector<int> s21_vector_copy(s21_vector);
  std::vector<int> std_vector{1, 2, 3};
  std::vector<int> std_vector_copy(std_vector);

  ASSERT_EQ(s21_vector.size(), std_vector.size());
  ASSERT_EQ(s21_vector_copy.size(), std_vector_copy.size());
  ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
  ASSERT_EQ(s21_vector_copy.capacity(), std_vector_copy.capacity());
}

TEST(Vector, def_move) {
  s21::Vector<int> s21_vector{1, 2, 3};
  s21::Vector<int> s21_vector_move(s21_vector);
  std::vector<int> std_vector{1, 2, 3};
  std::vector<int> std_vector_move(std_vector);

  ASSERT_EQ(s21_vector.size(), std_vector.size());
  ASSERT_EQ(s21_vector_move.size(), std_vector_move.size());
  ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
  ASSERT_EQ(s21_vector_move.capacity(), std_vector_move.capacity());
}

TEST(Vector, def_destructor) {
  s21::Vector<int> s21_vector{1, 2, 3};
  s21_vector.~Vector();

  ASSERT_EQ(0, s21_vector.size());
  ASSERT_EQ(0, s21_vector.capacity());
  ASSERT_EQ(0, s21_vector.data());
}

TEST(Vector, def_at) {
  s21::Vector<int> s21_vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  s21_vector.at(1) = 100;
  std_vector.at(1) = 100;

  ASSERT_EQ(s21_vector.at(0), std_vector.at(0));
  ASSERT_EQ(s21_vector.at(1), std_vector.at(1));
  ASSERT_EQ(s21_vector.at(2), std_vector.at(2));
  ASSERT_EQ(s21_vector.size(), std_vector.size());
  ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
}

TEST(Vector, def_operator) {
  s21::Vector<int> s21_vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  s21_vector[0] = 100;
  std_vector[0] = 100;

  ASSERT_EQ(s21_vector.at(0), std_vector.at(0));
  ASSERT_EQ(s21_vector.at(1), std_vector.at(1));
  ASSERT_EQ(s21_vector.at(2), std_vector.at(2));
  ASSERT_EQ(s21_vector.size(), std_vector.size());
  ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
}

TEST(Vector, def_throw) {
  s21::Vector<int> s21_vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};

  ASSERT_ANY_THROW(s21_vector.at(5));
  ASSERT_ANY_THROW(std_vector.at(5));
}

TEST(Vector, def_front) {
  s21::Vector<int> s21_vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};

  ASSERT_EQ(s21_vector.front(), std_vector.front());
}

TEST(Vector, def_back) {
  s21::Vector<int> s21_vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};

  ASSERT_EQ(s21_vector.back(), std_vector.back());
}

TEST(Vector, def_begin) {
  s21::Vector<int> s21_vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  s21_vector.insert(s21_vector.begin() + 1, 100);
  std_vector.insert(std_vector.begin() + 1, 100);

  ASSERT_EQ(s21_vector.at(0), std_vector.at(0));
  ASSERT_EQ(s21_vector.at(1), std_vector.at(1));
  ASSERT_EQ(s21_vector.at(2), std_vector.at(2));
  ASSERT_EQ(s21_vector.at(3), std_vector.at(3));
}

TEST(Vector, def_end) {
  s21::Vector<int> s21_vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  s21_vector.insert(s21_vector.end() + 1, 100);
  std_vector.insert(std_vector.end() + 1, 100);

  ASSERT_EQ(s21_vector.at(0), std_vector.at(0));
  ASSERT_EQ(s21_vector.at(1), std_vector.at(1));
  ASSERT_EQ(s21_vector.at(2), std_vector.at(2));
  ASSERT_EQ(s21_vector.at(3), std_vector.at(3));
}

TEST(Vector, def_reserve) {
  s21::Vector<int> s21_vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  s21_vector.reserve(15);
  std_vector.reserve(15);

  ASSERT_EQ(s21_vector.empty(), std_vector.empty());
  ASSERT_EQ(s21_vector.size(), std_vector.size());
  ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
}

TEST(Vector, def_shrink_to_fit) {
  s21::Vector<int> s21_vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  s21_vector.reserve(15);
  std_vector.reserve(15);
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();

  ASSERT_EQ(s21_vector.empty(), std_vector.empty());
  ASSERT_EQ(s21_vector.size(), std_vector.size());
  ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
}

TEST(Vector, def_clear) {
  s21::Vector<int> s21_vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  s21_vector.reserve(15);
  std_vector.reserve(15);
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  s21_vector.clear();
  std_vector.clear();

  ASSERT_EQ(s21_vector.empty(), std_vector.empty());
  ASSERT_EQ(s21_vector.size(), std_vector.size());
  ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
}

TEST(Vector, def_insert) {
  s21::Vector<int> s21_vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  s21_vector.insert(s21_vector.begin() + 1, 50);
  std_vector.insert(std_vector.begin() + 1, 50);

  ASSERT_EQ(s21_vector.at(0), std_vector.at(0));
  ASSERT_EQ(s21_vector.at(1), std_vector.at(1));
  ASSERT_EQ(s21_vector.at(2), std_vector.at(2));
  ASSERT_EQ(s21_vector.at(3), std_vector.at(3));
}

TEST(Vector, def_erase) {
  s21::Vector<int> s21_vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  s21_vector.erase(s21_vector.begin() + 1);
  std_vector.erase(std_vector.begin() + 1);

  ASSERT_EQ(s21_vector.at(0), std_vector.at(0));
  ASSERT_EQ(s21_vector.at(1), std_vector.at(1));
}

TEST(Vector, def_push_back) {
  s21::Vector<int> s21_vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  s21_vector.push_back(100);
  std_vector.push_back(100);

  ASSERT_EQ(s21_vector.at(0), std_vector.at(0));
  ASSERT_EQ(s21_vector.at(1), std_vector.at(1));
  ASSERT_EQ(s21_vector.at(2), std_vector.at(2));
  ASSERT_EQ(s21_vector.at(3), std_vector.at(3));
}

TEST(Vector, def_push_back1) {
  s21::Vector<int> s21_vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  s21_vector.push_back(50);
  std_vector.push_back(50);
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  s21_vector.push_back(100);
  std_vector.push_back(100);

  ASSERT_EQ(s21_vector.at(0), std_vector.at(0));
  ASSERT_EQ(s21_vector.at(1), std_vector.at(1));
  ASSERT_EQ(s21_vector.at(2), std_vector.at(2));
  ASSERT_EQ(s21_vector.at(3), std_vector.at(3));
  ASSERT_EQ(s21_vector.at(4), std_vector.at(4));

  ASSERT_EQ(s21_vector.empty(), std_vector.empty());
  ASSERT_EQ(s21_vector.size(), std_vector.size());
  ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
}

TEST(Vector, def_push_back2) {
  s21::Vector<int> s21_vector;
  std::vector<int> std_vector;
  s21_vector.push_back(50);
  std_vector.push_back(50);
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  s21_vector.push_back(100);
  std_vector.push_back(100);

  ASSERT_EQ(s21_vector.at(0), std_vector.at(0));

  ASSERT_EQ(s21_vector.empty(), std_vector.empty());
  ASSERT_EQ(s21_vector.size(), std_vector.size());
  ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
}

TEST(Vector, def_swap) {
  s21::Vector<int> s21_vector{1, 2, 3};
  s21::Vector<int> s21_vector_swap;
  std::vector<int> std_vector{1, 2, 3};
  std::vector<int> std_vector_swap;
  s21_vector_swap.swap(s21_vector);
  std_vector_swap.swap(std_vector);

  ASSERT_EQ(s21_vector.empty(), std_vector.empty());
  ASSERT_EQ(s21_vector.size(), std_vector.size());
  ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());

  ASSERT_EQ(s21_vector_swap.empty(), std_vector_swap.empty());
  ASSERT_EQ(s21_vector_swap.size(), std_vector_swap.size());
  ASSERT_EQ(s21_vector_swap.capacity(), std_vector_swap.capacity());
}

//  Part 3. Дополнительно

TEST(Vector, insert_many) {
  s21::Vector<int> s21_vector{1, 2, 3, 5, 6};
  std::vector<int> std_vector{1, 2, 3, 5, 6};
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();

  s21_vector.insert_many(s21_vector.begin() + 3, 4);
  std_vector.insert(std_vector.begin() + 3, 4);

  ASSERT_EQ(s21_vector.at(0), std_vector.at(0));
  ASSERT_EQ(s21_vector.at(1), std_vector.at(1));
  ASSERT_EQ(s21_vector.at(2), std_vector.at(2));
  ASSERT_EQ(s21_vector.at(3), std_vector.at(3));
  ASSERT_EQ(s21_vector.at(4), std_vector.at(4));
  ASSERT_EQ(s21_vector.at(5), std_vector.at(5));
}

TEST(Vector, insert_many_back) {
  s21::Vector<int> s21_vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};

  s21_vector.insert_many_back(4, 5, 6);
  std_vector.insert(std_vector.end(), {4, 5, 6});

  ASSERT_EQ(s21_vector.at(0), std_vector.at(0));
  ASSERT_EQ(s21_vector.at(1), std_vector.at(1));
  ASSERT_EQ(s21_vector.at(2), std_vector.at(2));
  ASSERT_EQ(s21_vector.at(3), std_vector.at(3));
  ASSERT_EQ(s21_vector.at(4), std_vector.at(4));
  ASSERT_EQ(s21_vector.at(5), std_vector.at(5));
}

TEST(Vector, insert_many_back_1) {
  s21::Vector<char> s21_vector{'1', '2', '3'};
  std::vector<char> std_vector{'1', '2', '3'};

  s21_vector.insert_many_back('4', '$', '&');
  std_vector.insert(std_vector.end(), {'4', '$', '&'});

  ASSERT_EQ(s21_vector.at(0), std_vector.at(0));
  ASSERT_EQ(s21_vector.at(1), std_vector.at(1));
  ASSERT_EQ(s21_vector.at(2), std_vector.at(2));
  ASSERT_EQ(s21_vector.at(3), std_vector.at(3));
  ASSERT_EQ(s21_vector.at(4), std_vector.at(4));
  ASSERT_EQ(s21_vector.at(5), std_vector.at(5));

  ASSERT_EQ(s21_vector.empty(), std_vector.empty());
  ASSERT_EQ(s21_vector.size(), std_vector.size());
  ASSERT_EQ(s21_vector.capacity(), std_vector.capacity());
}

// LIST

TEST(List, def_constructor_int) {
  S21::list<int> s21_list;
  std::list<int> std_list;
  ASSERT_EQ(s21_list.empty(), std_list.empty());
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(List, def_constructor_char) {
  S21::list<char> s21_list;
  std::list<char> std_list;
  ASSERT_EQ(s21_list.empty(), std_list.empty());
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(List, def_constructor_str) {
  S21::list<std::string> s21_list;
  std::list<std::string> std_list;
  ASSERT_EQ(s21_list.empty(), std_list.empty());
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(List, par_constructor_int_0) {
  S21::list<int> s21_list(0);
  std::list<int> std_list(0);
  ASSERT_EQ(s21_list.size(), std_list.size());
  S21::list<int>::iterator s21it = s21_list.begin();
  std::list<int>::iterator stdit = std_list.begin();
  for (size_t i = 0; i <= std_list.size() + 2; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, par_constructor_char_0) {
  S21::list<char> s21_list(0);
  std::list<char> std_list(0);
  ASSERT_EQ(s21_list.size(), std_list.size());
  S21::list<char>::iterator s21it = s21_list.begin();
  std::list<char>::iterator stdit = std_list.begin();
  for (size_t i = 0; i <= std_list.size() + 2; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, par_constructor_str_0) {
  //оригинал ликается, а я просто проверяю на утечки
  S21::list<std::string> s21_list(0);
  S21::list<std::string>::iterator s21it = s21_list.begin();
  for (size_t i = 0; i <= s21_list.size() + 2; i++) {
    ++s21it;
  }
}

TEST(List, par_constructor_int_1) {
  S21::list<int> s21_list(1);
  std::list<int> std_list(1);
  ASSERT_EQ(s21_list.size(), std_list.size());
  S21::list<int>::iterator s21it = s21_list.begin();
  std::list<int>::iterator stdit = std_list.begin();
  for (size_t i = 0; i <= std_list.size() + 2; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, par_constructor_char_1) {
  S21::list<char> s21_list(1);
  std::list<char> std_list(1);
  ASSERT_EQ(s21_list.size(), std_list.size());
  S21::list<char>::iterator s21it = s21_list.begin();
  std::list<char>::iterator stdit = std_list.begin();
  for (size_t i = 0; i <= std_list.size() + 2; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, par_constructor_str_1) {
  //оригинал ликается, а я просто проверяю на утечки
  S21::list<std::string> s21_list(1);
  S21::list<std::string>::iterator s21it = s21_list.begin();
  for (size_t i = 0; i <= s21_list.size() + 2; i++) {
    ++s21it;
  }
}

TEST(List, par_constructor_int_2) {
  S21::list<int> s21_list(2);
  std::list<int> std_list(2);
  ASSERT_EQ(s21_list.size(), std_list.size());
  S21::list<int>::iterator s21it = s21_list.begin();
  std::list<int>::iterator stdit = std_list.begin();
  for (size_t i = 0; i <= std_list.size() + 2; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, par_constructor_char_2) {
  S21::list<char> s21_list(2);
  std::list<char> std_list(2);
  ASSERT_EQ(s21_list.size(), std_list.size());
  S21::list<char>::iterator s21it = s21_list.begin();
  std::list<char>::iterator stdit = std_list.begin();
  for (size_t i = 0; i <= std_list.size() + 2; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, par_constructor_str_2) {
  //оригинал ликается, а я просто проверяю на утечки
  S21::list<std::string> s21_list(2);
  S21::list<std::string>::iterator s21it = s21_list.begin();
  for (size_t i = 0; i <= s21_list.size() + 2; i++) {
    ++s21it;
  }
}

TEST(List, par_constructor_int_3) {
  S21::list<int> s21_list(3);
  std::list<int> std_list(3);
  ASSERT_EQ(s21_list.size(), std_list.size());
  S21::list<int>::iterator s21it = s21_list.begin();
  std::list<int>::iterator stdit = std_list.begin();
  for (size_t i = 0; i <= std_list.size() + 2; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, par_constructor_char_3) {
  S21::list<char> s21_list(3);
  std::list<char> std_list(3);
  ASSERT_EQ(s21_list.size(), std_list.size());
  S21::list<char>::iterator s21it = s21_list.begin();
  std::list<char>::iterator stdit = std_list.begin();
  for (size_t i = 0; i <= std_list.size() + 2; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, par_constructor_str_3) {
  //оригинал ликается, а я просто проверяю на утечки
  S21::list<std::string> s21_list(3);
  S21::list<std::string>::iterator s21it = s21_list.begin();
  for (size_t i = 0; i <= s21_list.size() + 2; i++) {
    ++s21it;
  }
}

TEST(List, par_constructor_int_100) {
  S21::list<int> s21_list(100);
  std::list<int> std_list(100);
  ASSERT_EQ(s21_list.size(), std_list.size());
  S21::list<int>::iterator s21it = s21_list.begin();
  std::list<int>::iterator stdit = std_list.begin();
  for (size_t i = 0; i <= std_list.size() + 2; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, par_constructor_char_100) {
  S21::list<char> s21_list(100);
  std::list<char> std_list(100);
  ASSERT_EQ(s21_list.size(), std_list.size());
  S21::list<char>::iterator s21it = s21_list.begin();
  std::list<char>::iterator stdit = std_list.begin();
  for (size_t i = 0; i <= std_list.size() + 2; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, par_constructor_str_100) {
  //оригинал ликается, а я просто проверяю на утечки
  S21::list<std::string> s21_list(100);
  S21::list<std::string>::iterator s21it = s21_list.begin();
  for (size_t i = 0; i <= s21_list.size() + 2; i++) {
    ++s21it;
  }
}

TEST(List, list_init_constructor_int_0) {
  S21::list<int> s21_list{};
  std::list<int> std_list{};
  ASSERT_EQ(s21_list.empty(), std_list.empty());
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(List, list_init_constructor_char_0) {
  S21::list<char> s21_list{};
  std::list<char> std_list{};
  ASSERT_EQ(s21_list.empty(), std_list.empty());
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(List, list_init_constructor_str_0) {
  S21::list<std::string> s21_list{};
  std::list<std::string> std_list{};
  ASSERT_EQ(s21_list.empty(), std_list.empty());
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(List, list_init_constructor_int_1) {
  S21::list<int> s21_list{90};
  std::list<int> std_list{90};
  ASSERT_EQ(s21_list.size(), std_list.size());
  S21::list<int>::iterator s21it = s21_list.begin();
  std::list<int>::iterator stdit = std_list.begin();
  for (size_t i = 0; i <= std_list.size() + 2; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_init_constructor_char_1) {
  S21::list<char> s21_list{'a'};
  std::list<char> std_list{'a'};
  ASSERT_EQ(s21_list.size(), std_list.size());
  S21::list<char>::iterator s21it = s21_list.begin();
  std::list<char>::iterator stdit = std_list.begin();
  for (size_t i = 0; i <= std_list.size() + 2; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_init_constructor_str_1) {
  S21::list<std::string> s21_list{"text"};
  std::list<std::string> std_list{"text"};
  ASSERT_EQ(s21_list.size(), std_list.size());
  S21::list<std::string>::iterator s21it = s21_list.begin();
  std::list<std::string>::iterator stdit = std_list.begin();
  ASSERT_EQ(*s21it, *stdit);
}

TEST(List, list_init_constructor_int_2) {
  S21::list<int> s21_list{90, 100};
  std::list<int> std_list{90, 100};
  ASSERT_EQ(s21_list.size(), std_list.size());
  S21::list<int>::iterator s21it = s21_list.begin();
  std::list<int>::iterator stdit = std_list.begin();
  for (size_t i = 0; i <= std_list.size() + 2; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_init_constructor_char_2) {
  S21::list<char> s21_list{'a', 'b'};
  std::list<char> std_list{'a', 'b'};
  ASSERT_EQ(s21_list.size(), std_list.size());
  S21::list<char>::iterator s21it = s21_list.begin();
  std::list<char>::iterator stdit = std_list.begin();
  for (size_t i = 0; i <= std_list.size() + 2; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_init_constructor_str_2) {
  S21::list<std::string> s21_list{"text", "qwe"};
  std::list<std::string> std_list{"text", "qwe"};
  ASSERT_EQ(s21_list.size(), std_list.size());
  S21::list<std::string>::iterator s21it = s21_list.begin();
  std::list<std::string>::iterator stdit = std_list.begin();
  for (size_t i = 1; i <= std_list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_init_constructor_int_3) {
  S21::list<int> s21_list{90, 100, 200};
  std::list<int> std_list{90, 100, 200};
  ASSERT_EQ(s21_list.size(), std_list.size());
  S21::list<int>::iterator s21it = s21_list.begin();
  std::list<int>::iterator stdit = std_list.begin();
  for (size_t i = 0; i <= std_list.size() + 2; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_init_constructor_char_3) {
  S21::list<char> s21_list{'a', 'b', 'c'};
  std::list<char> std_list{'a', 'b', 'c'};
  ASSERT_EQ(s21_list.size(), std_list.size());
  S21::list<char>::iterator s21it = s21_list.begin();
  std::list<char>::iterator stdit = std_list.begin();
  for (size_t i = 0; i <= std_list.size() + 2; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_init_constructor_str_3) {
  S21::list<std::string> s21_list{"text", "qwe", "asd asd"};
  std::list<std::string> std_list{"text", "qwe", "asd asd"};
  ASSERT_EQ(s21_list.size(), std_list.size());
  S21::list<std::string>::iterator s21it = s21_list.begin();
  std::list<std::string>::iterator stdit = std_list.begin();
  for (size_t i = 1; i <= std_list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_init_constructor_str_3_extra) {
  // проверка на утечки на зацикленный, оригинал на енд ломается если тип
  // стринги
  S21::list<std::string> s21_list{"text", "qwe", "asd asd"};
  S21::list<std::string>::iterator s21it = s21_list.begin();
  for (size_t i = 1; i <= s21_list.size() + 3; i++) {
    ASSERT_EQ(*s21it, *s21it);
    ++s21it;
  }
}

TEST(List, list_init_constructor_int_4) {
  S21::list<int> s21_list{90, 100, 200, 300};
  std::list<int> std_list{90, 100, 200, 300};
  ASSERT_EQ(s21_list.size(), std_list.size());
  S21::list<int>::iterator s21it = s21_list.begin();
  std::list<int>::iterator stdit = std_list.begin();
  for (size_t i = 0; i <= std_list.size() + 2; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_init_constructor_char_4) {
  S21::list<char> s21_list{'a', 'b', 'c', 'd'};
  std::list<char> std_list{'a', 'b', 'c', 'd'};
  ASSERT_EQ(s21_list.size(), std_list.size());
  S21::list<char>::iterator s21it = s21_list.begin();
  std::list<char>::iterator stdit = std_list.begin();
  for (size_t i = 0; i <= std_list.size() + 2; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_init_constructor_str_4) {
  S21::list<std::string> s21_list{"text", "qwe", "asd asd", "asd asd"};
  std::list<std::string> std_list{"text", "qwe", "asd asd", "asd asd"};
  ASSERT_EQ(s21_list.size(), std_list.size());
  S21::list<std::string>::iterator s21it = s21_list.begin();
  std::list<std::string>::iterator stdit = std_list.begin();
  for (size_t i = 1; i <= std_list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_init_constructor_str_4_extra) {
  // проверка на утечки на зацикленный, оригинал на енд ломается если тип
  // стринги
  S21::list<std::string> s21_list{"text", "qwe", "asd asd", "asd asd"};
  S21::list<std::string>::iterator s21it = s21_list.begin();
  for (size_t i = 1; i <= s21_list.size() + 3; i++) {
    ASSERT_EQ(*s21it, *s21it);
    ++s21it;
  }
}

TEST(List, list_cope_constructor_int) {
  S21::list<int> s21_list{90, 100, 200};
  S21::list<int> s21_list2(s21_list);
  std::list<int> std_list{90, 100, 200};
  std::list<int> std_list2(std_list);
  ASSERT_EQ(s21_list2.size(), std_list2.size());
  S21::list<int>::iterator s21it = s21_list2.begin();
  std::list<int>::iterator stdit = std_list2.begin();
  for (size_t i = 0; i <= std_list.size() + 2; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_cope_constructor_char) {
  S21::list<char> s21_list{'a', 'b', 'c'};
  S21::list<char> s21_list2(s21_list);
  std::list<char> std_list{'a', 'b', 'c'};
  std::list<char> std_list2(std_list);
  ASSERT_EQ(s21_list2.size(), std_list2.size());
  S21::list<char>::iterator s21it = s21_list2.begin();
  std::list<char>::iterator stdit = std_list2.begin();
  for (size_t i = 0; i <= std_list.size() + 2; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_cope_constructor_str) {
  S21::list<std::string> s21_list{"text", "qwe", "asd asd"};
  S21::list<std::string> s21_list2(s21_list);
  std::list<std::string> std_list{"text", "qwe", "asd asd"};
  std::list<std::string> std_list2(std_list);
  ASSERT_EQ(s21_list2.size(), std_list2.size());
  S21::list<std::string>::iterator s21it = s21_list2.begin();
  std::list<std::string>::iterator stdit = std_list2.begin();
  for (size_t i = 1; i <= std_list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_cope_constructor_str_extra) {
  // проверка на утечки на зацикленный, оригинал на енд ломается если тип
  // стринги
  S21::list<std::string> s21_list{"text", "qwe", "asd asd"};
  S21::list<std::string> s21_list2(s21_list);
  S21::list<std::string>::iterator s21it = s21_list2.begin();
  for (size_t i = 1; i <= s21_list2.size() + 4; i++) {
    ++s21it;
  }
}

TEST(List, list_move_constructor_int) {
  S21::list<int> s21_list{90, 100, 200};
  S21::list<int> s21_list2 = std::move(s21_list);
  std::list<int> std_list{90, 100, 200};
  std::list<int> std_list2 = std::move(std_list);
  ASSERT_EQ(s21_list2.size(), std_list2.size());
  S21::list<int>::iterator s21it = s21_list2.begin();
  std::list<int>::iterator stdit = std_list2.begin();
  for (size_t i = 0; i <= std_list.size() + 2; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_move_constructor_char) {
  S21::list<char> s21_list{'a', 'b', 'c'};
  S21::list<char> s21_list2 = std::move(s21_list);
  std::list<char> std_list{'a', 'b', 'c'};
  std::list<char> std_list2 = std::move(std_list);
  ASSERT_EQ(s21_list2.size(), std_list2.size());
  S21::list<char>::iterator s21it = s21_list2.begin();
  std::list<char>::iterator stdit = std_list2.begin();
  for (size_t i = 0; i <= std_list.size() + 2; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_move_constructor_str) {
  S21::list<std::string> s21_list{"text", "qwe", "asd asd"};
  S21::list<std::string> s21_list2 = std::move(s21_list);
  std::list<std::string> std_list{"text", "qwe", "asd asd"};
  std::list<std::string> std_list2 = std::move(std_list);
  ASSERT_EQ(s21_list2.size(), std_list2.size());
  S21::list<std::string>::iterator s21it = s21_list2.begin();
  std::list<std::string>::iterator stdit = std_list2.begin();
  for (size_t i = 1; i <= std_list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_move_constructor_str_extra) {
  // проверка на утечки на зацикленный, оригинал на енд ломается если тип
  // стринги
  S21::list<std::string> s21_list{"text", "qwe", "asd asd"};
  S21::list<std::string> s21_list2 = std::move(s21_list);
  S21::list<std::string>::iterator s21it = s21_list2.begin();
  for (size_t i = 1; i <= s21_list2.size() + 4; i++) {
    ++s21it;
  }
}

TEST(List, list_move_operator_int) {
  S21::list<int> s21_list{90, 100, 200};
  S21::list<int> s21_list2{90, 100, 200};
  s21_list2 = std::move(s21_list);
  std::list<int> std_list{90, 100, 200};
  std::list<int> std_list2{90, 100, 200};
  std_list2 = std::move(std_list);
  ASSERT_EQ(s21_list2.size(), std_list2.size());
  S21::list<int>::iterator s21it = s21_list2.begin();
  std::list<int>::iterator stdit = std_list2.begin();
  for (size_t i = 0; i <= std_list.size() + 2; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_move_operator_char) {
  S21::list<char> s21_list{'a', 'b', 'c'};
  S21::list<char> s21_list2{'a', 'b', 'c'};
  s21_list2 = std::move(s21_list);
  std::list<char> std_list{'a', 'b', 'c'};
  std::list<char> std_list2{'a', 'b', 'c'};
  std_list2 = std::move(std_list);
  ASSERT_EQ(s21_list2.size(), std_list2.size());
  S21::list<char>::iterator s21it = s21_list2.begin();
  std::list<char>::iterator stdit = std_list2.begin();
  for (size_t i = 0; i <= std_list.size() + 2; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_move_operator_str) {
  S21::list<std::string> s21_list{"text", "qwe", "asd asd"};
  S21::list<std::string> s21_list2{"text", "qwe", "asd asd"};
  s21_list2 = std::move(s21_list);
  std::list<std::string> std_list{"text", "qwe", "asd asd"};
  std::list<std::string> std_list2{"text", "qwe", "asd asd"};
  std_list2 = std::move(std_list);
  ASSERT_EQ(s21_list2.size(), std_list2.size());
  S21::list<std::string>::iterator s21it = s21_list2.begin();
  std::list<std::string>::iterator stdit = std_list2.begin();
  for (size_t i = 1; i <= std_list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_move_operator_str_extra) {
  // проверка на утечки на зацикленный, оригинал на енд ломается если тип
  // стринги
  S21::list<std::string> s21_list{"text", "qwe", "asd asd"};
  S21::list<std::string> s21_list2{"text", "qwe", "asd asd"};
  s21_list2 = std::move(s21_list);
  S21::list<std::string>::iterator s21it = s21_list2.begin();
  for (size_t i = 1; i <= s21_list2.size() + 4; i++) {
    ++s21it;
  }
}

TEST(List, list_copy_operator_int) {
  S21::list<int> s21_list{90, 100, 200};
  S21::list<int> s21_list2{90, 100, 200};
  s21_list2 = s21_list;
  std::list<int> std_list{90, 100, 200};
  std::list<int> std_list2{90, 100, 200};
  std_list2 = std_list;
  ASSERT_EQ(s21_list2.size(), std_list2.size());
  S21::list<int>::iterator s21it = s21_list2.begin();
  std::list<int>::iterator stdit = std_list2.begin();
  for (size_t i = 0; i <= std_list.size() + 2; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_copy_operator_char) {
  S21::list<char> s21_list{'a', 'b', 'c'};
  S21::list<char> s21_list2{'a', 'b', 'c'};
  s21_list2 = s21_list;
  std::list<char> std_list{'a', 'b', 'c'};
  std::list<char> std_list2{'a', 'b', 'c'};
  std_list2 = std_list;
  ASSERT_EQ(s21_list2.size(), std_list2.size());
  S21::list<char>::iterator s21it = s21_list2.begin();
  std::list<char>::iterator stdit = std_list2.begin();
  for (size_t i = 0; i <= std_list.size() + 2; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_copy_operator_str) {
  S21::list<std::string> s21_list{"text", "qwe", "asd asd"};
  S21::list<std::string> s21_list2{"text", "qwe", "asd asd"};
  s21_list2 = s21_list;
  std::list<std::string> std_list{"text", "qwe", "asd asd"};
  std::list<std::string> std_list2{"text", "qwe", "asd asd"};
  std_list2 = std_list;
  ASSERT_EQ(s21_list2.size(), std_list2.size());
  S21::list<std::string>::iterator s21it = s21_list2.begin();
  std::list<std::string>::iterator stdit = std_list2.begin();
  for (size_t i = 1; i <= std_list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_copy_operator_str_extra) {
  // проверка на утечки на зацикленный, оригинал на енд ломается если тип
  // стринги
  S21::list<std::string> s21_list{"text", "qwe", "asd asd"};
  S21::list<std::string> s21_list2{"text", "qwe", "asd asd"};
  s21_list2 = s21_list;
  S21::list<std::string>::iterator s21it = s21_list2.begin();
  for (size_t i = 1; i <= s21_list2.size() + 4; i++) {
    ++s21it;
  }
}
// ==============================================
// ==============================================
// ============ List Element access =============
// ==============================================
// ==============================================

TEST(List, list_element_access_front_int_0) {
  S21::list<int> s21_list;
  std::list<int> std_list;
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(s21_list.front(), std_list.front());
}

TEST(List, list_element_access_front_char_0) {
  S21::list<char> s21_list;
  std::list<char> std_list;
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(s21_list.front(), std_list.front());
}

TEST(List, list_element_access_front_str_0) {
  // проверка на утечки, оригинал ломается, если тип стринги
  S21::list<std::string> s21_list;
  ASSERT_EQ(s21_list.size(), s21_list.size());
  ASSERT_EQ(s21_list.front(), s21_list.front());
}

TEST(List, list_element_access_back_int_0) {
  S21::list<int> s21_list;
  std::list<int> std_list;
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(s21_list.back(), std_list.back());
}

TEST(List, list_element_access_back_char_0) {
  S21::list<char> s21_list;
  std::list<char> std_list;
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(s21_list.back(), std_list.back());
}

TEST(List, list_element_access_back_str_0) {
  // проверка на утечки, оригинал ломается, если тип стринги
  S21::list<std::string> s21_list;
  ASSERT_EQ(s21_list.size(), s21_list.size());
  ASSERT_EQ(s21_list.back(), s21_list.back());
}

TEST(List, list_element_access_front_int_1) {
  S21::list<int> s21_list{100};
  std::list<int> std_list{100};
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(s21_list.front(), std_list.front());
}

TEST(List, list_element_access_front_char_1) {
  S21::list<char> s21_list{'a'};
  std::list<char> std_list{'a'};
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(s21_list.front(), std_list.front());
}

TEST(List, list_element_access_front_str_1) {
  S21::list<std::string> s21_list{"str"};
  std::list<std::string> std_list{"str"};
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(s21_list.front(), std_list.front());
}

TEST(List, list_element_access_back_int_1) {
  S21::list<int> s21_list{100};
  std::list<int> std_list{100};
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(s21_list.back(), std_list.back());
}

TEST(List, list_element_access_back_char_1) {
  S21::list<char> s21_list{'a'};
  std::list<char> std_list{'a'};
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(s21_list.back(), std_list.back());
}

TEST(List, list_element_access_back_str_1) {
  S21::list<std::string> s21_list{"str"};
  std::list<std::string> std_list{"str"};
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(s21_list.back(), std_list.back());
}

TEST(List, list_element_access_front_int_2) {
  S21::list<int> s21_list{100, 200};
  std::list<int> std_list{100, 200};
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(s21_list.front(), std_list.front());
}

TEST(List, list_element_access_front_char_2) {
  S21::list<char> s21_list{'a', 'b'};
  std::list<char> std_list{'a', 'b'};
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(s21_list.front(), std_list.front());
}

TEST(List, list_element_access_front_str_2) {
  S21::list<std::string> s21_list{"str", "qwe"};
  std::list<std::string> std_list{"str", "qwe"};
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(s21_list.front(), std_list.front());
}

TEST(List, list_element_access_back_int_2) {
  S21::list<int> s21_list{100, 200};
  std::list<int> std_list{100, 200};
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(s21_list.back(), std_list.back());
}

TEST(List, list_element_access_back_char_2) {
  S21::list<char> s21_list{'a', 'b'};
  std::list<char> std_list{'a', 'b'};
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(s21_list.back(), std_list.back());
}

TEST(List, list_element_access_back_str_2) {
  S21::list<std::string> s21_list{"str", "qwe"};
  std::list<std::string> std_list{"str", "qwe"};
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(s21_list.back(), std_list.back());
}

// ==============================================
// ==============================================
// ============ List Iterators ==================
// ==============================================
// ==============================================

TEST(List, list_iterators_begin_int_0) {
  S21::list<int> s21_list;
  std::list<int> std_list;
  S21::list<int>::iterator s21it = s21_list.begin();
  std::list<int>::iterator stdit = std_list.begin();
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(*s21it, *stdit);
}

TEST(List, list_iterators_begin_char_0) {
  S21::list<char> s21_list;
  std::list<char> std_list;
  S21::list<char>::iterator s21it = s21_list.begin();
  std::list<char>::iterator stdit = std_list.begin();
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(*s21it, *stdit);
}
TEST(List, list_iterators_begin_str_0) {
  //оригинал ликается, а я просто проверяю на утечки
  S21::list<std::string> s21_list;
  S21::list<std::string>::iterator s21it = s21_list.begin();
  ASSERT_EQ(s21_list.size(), s21_list.size());
  ASSERT_EQ(*s21it, *s21it);
}

TEST(List, list_iterators_end_int_0) {
  S21::list<int> s21_list;
  std::list<int> std_list;
  S21::list<int>::iterator s21it = s21_list.end();
  std::list<int>::iterator stdit = std_list.end();
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(*s21it, *stdit);
}

TEST(List, list_iterators_end_char_0) {
  S21::list<char> s21_list;
  std::list<char> std_list;
  S21::list<char>::iterator s21it = s21_list.end();
  std::list<char>::iterator stdit = std_list.end();
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(*s21it, *stdit);
}
TEST(List, list_iterators_end_str_0) {
  //оригинал ликается, а я просто проверяю на утечки
  S21::list<std::string> s21_list;
  S21::list<std::string>::iterator s21it = s21_list.end();
  ASSERT_EQ(s21_list.size(), s21_list.size());
  ASSERT_EQ(*s21it, *s21it);
}

TEST(List, list_iterators_begin_int_1) {
  S21::list<int> s21_list{100};
  std::list<int> std_list{100};
  S21::list<int>::iterator s21it = s21_list.begin();
  std::list<int>::iterator stdit = std_list.begin();
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(*s21it, *stdit);
}

TEST(List, list_iterators_begin_char_1) {
  S21::list<char> s21_list{'a'};
  std::list<char> std_list{'a'};
  S21::list<char>::iterator s21it = s21_list.begin();
  std::list<char>::iterator stdit = std_list.begin();
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(*s21it, *stdit);
}
TEST(List, list_iterators_begin_str_1) {
  S21::list<std::string> s21_list{"qwe"};
  std::list<std::string> std_list{"qwe"};
  S21::list<std::string>::iterator s21it = s21_list.begin();
  std::list<std::string>::iterator stdit = std_list.begin();
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(*s21it, *stdit);
}

TEST(List, list_iterators_end_int_1) {
  S21::list<int> s21_list{100};
  std::list<int> std_list{100};
  S21::list<int>::iterator s21it = s21_list.end();
  std::list<int>::iterator stdit = std_list.end();
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(*s21it, *stdit);
}

TEST(List, list_iterators_end_char_1) {
  S21::list<char> s21_list{'a'};
  std::list<char> std_list{'a'};
  S21::list<char>::iterator s21it = s21_list.end();
  std::list<char>::iterator stdit = std_list.end();
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(*s21it, *stdit);
}
TEST(List, list_iterators_end_str_1) {
  //НЕОЖИДАННО, но оригинал ликается, а я просто проверяю на утечки
  S21::list<std::string> s21_list{"qwe"};
  S21::list<std::string>::iterator s21it = s21_list.end();
  ASSERT_EQ(s21_list.size(), s21_list.size());
  ASSERT_EQ(*s21it, *s21it);
}

TEST(List, list_iterators_begin_int_2) {
  S21::list<int> s21_list{100, 200};
  std::list<int> std_list{100, 200};
  S21::list<int>::iterator s21it = s21_list.begin();
  std::list<int>::iterator stdit = std_list.begin();
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(*s21it, *stdit);
}

TEST(List, list_iterators_begin_char_2) {
  S21::list<char> s21_list{'a', 'b'};
  std::list<char> std_list{'a', 'b'};
  S21::list<char>::iterator s21it = s21_list.begin();
  std::list<char>::iterator stdit = std_list.begin();
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(*s21it, *stdit);
}
TEST(List, list_iterators_begin_str_2) {
  S21::list<std::string> s21_list{"qwe", "asd"};
  std::list<std::string> std_list{"qwe", "asd"};
  S21::list<std::string>::iterator s21it = s21_list.begin();
  std::list<std::string>::iterator stdit = std_list.begin();
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(*s21it, *stdit);
}

TEST(List, list_iterators_end_int_2) {
  S21::list<int> s21_list{100, 200};
  std::list<int> std_list{100, 200};
  S21::list<int>::iterator s21it = s21_list.end();
  std::list<int>::iterator stdit = std_list.end();
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(*s21it, *stdit);
}

TEST(List, list_iterators_end_char_2) {
  S21::list<char> s21_list{'a', 'b'};
  std::list<char> std_list{'a', 'b'};
  S21::list<char>::iterator s21it = s21_list.end();
  std::list<char>::iterator stdit = std_list.end();
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(*s21it, *stdit);
}
TEST(List, list_iterators_end_str_2) {
  //НЕОЖИДАННО, но оригинал ликается, а я просто проверяю на утечки
  S21::list<std::string> s21_list{"qwe", "asd"};
  S21::list<std::string>::iterator s21it = s21_list.end();
  ASSERT_EQ(s21_list.size(), s21_list.size());
  ASSERT_EQ(*s21it, *s21it);
}

// ==============================================
// ==============================================
// ============ List Capacity ===================
// ==============================================
// ==============================================

TEST(List, list_capacity_empty_int_0) {
  S21::list<int> s21_list;
  std::list<int> std_list;
  ASSERT_EQ(s21_list.empty(), std_list.empty());
}

TEST(List, list_capacity_empty_char_0) {
  S21::list<char> s21_list;
  std::list<char> std_list;
  ASSERT_EQ(s21_list.empty(), std_list.empty());
}
TEST(List, list_capacity_empty_str_0) {
  S21::list<std::string> s21_list;
  std::list<std::string> std_list;
  ASSERT_EQ(s21_list.empty(), std_list.empty());
}

TEST(List, list_capacity_empty_int_2) {
  S21::list<int> s21_list{100, 200};
  std::list<int> std_list{100, 200};
  ASSERT_EQ(s21_list.empty(), std_list.empty());
}

TEST(List, list_capacity_empty_char_2) {
  S21::list<char> s21_list{'a', 'b'};
  std::list<char> std_list{'a', 'b'};
  ASSERT_EQ(s21_list.empty(), std_list.empty());
}

TEST(List, list_capacity_empty_str_2) {
  S21::list<std::string> s21_list{"qwe", "asd"};
  std::list<std::string> std_list{"qwe", "asd"};
  ASSERT_EQ(s21_list.empty(), std_list.empty());
}

TEST(List, list_capacity_size_int_0) {
  S21::list<int> s21_list;
  std::list<int> std_list;
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(List, list_capacity_size_char_0) {
  S21::list<char> s21_list;
  std::list<char> std_list;
  ASSERT_EQ(s21_list.size(), std_list.size());
}
TEST(List, list_capacity_size_str_0) {
  S21::list<std::string> s21_list;
  std::list<std::string> std_list;
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(List, list_capacity_size_int_2) {
  S21::list<int> s21_list{100, 200};
  std::list<int> std_list{100, 200};
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(List, list_capacity_size_char_2) {
  S21::list<char> s21_list{'a', 'b'};
  std::list<char> std_list{'a', 'b'};
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(List, list_capacity_size_str_2) {
  S21::list<std::string> s21_list{"qwe", "asd"};
  std::list<std::string> std_list{"qwe", "asd"};
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(List, list_capacity_max_size_int) {
  S21::list<int> s21_list;
  std::list<int> std_list;
  ASSERT_EQ(s21_list.size(), std_list.size());
}

// ==============================================
// ==============================================
// ============ List Modifiers ==================
// ==============================================
// ==============================================

TEST(List, list_modifiers_clear_int) {
  S21::list<int> s21_list;
  std::list<int> std_list;
  s21_list.clear();
  std_list.clear();
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(List, list_modifiers_clear_char) {
  S21::list<char> s21_list;
  std::list<char> std_list;
  s21_list.clear();
  std_list.clear();
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(List, list_modifiers_clear_str) {
  S21::list<std::string> s21_list;
  std::list<std::string> std_list;
  s21_list.clear();
  std_list.clear();
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(List, list_modifiers_clear_int_2) {
  S21::list<int> s21_list{100, 200};
  std::list<int> std_list{100, 200};
  s21_list.clear();
  std_list.clear();
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(List, list_modifiers_clear_char_2) {
  S21::list<char> s21_list{'a', 'b'};
  std::list<char> std_list{'a', 'b'};
  s21_list.clear();
  std_list.clear();
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(List, list_modifiers_clear_str_2) {
  S21::list<std::string> s21_list{"qwe", "asd"};
  std::list<std::string> std_list{"qwe", "asd"};
  s21_list.clear();
  std_list.clear();
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(List, list_modifiers_insert_int_0) {
  S21::list<int> s21_list1;
  std::list<int> std_list1;
  s21_list1.insert(s21_list1.begin(), 100);
  std_list1.insert(std_list1.begin(), 100);
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<int>::iterator s21it = s21_list1.begin();
  std::list<int>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_insert_char_0) {
  S21::list<char> s21_list1;
  std::list<char> std_list1;
  s21_list1.insert(s21_list1.begin(), 'a');
  std_list1.insert(std_list1.begin(), 'a');
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<char>::iterator s21it = s21_list1.begin();
  std::list<char>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_insert_str_0) {
  S21::list<std::string> s21_list1;
  std::list<std::string> std_list1;
  s21_list1.insert(s21_list1.begin(), "qwe");
  std_list1.insert(std_list1.begin(), "qwe");
  ASSERT_EQ(s21_list1.size(), s21_list1.size());
  S21::list<std::string>::iterator s21it = s21_list1.begin();
  std::list<std::string>::iterator stdit = std_list1.begin();
  for (size_t i = 1; i <= s21_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_insert_int_1) {
  S21::list<int> s21_list1{200};
  std::list<int> std_list1{200};
  s21_list1.insert(s21_list1.begin(), 100);
  std_list1.insert(std_list1.begin(), 100);
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<int>::iterator s21it = s21_list1.begin();
  std::list<int>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_insert_char_1) {
  S21::list<char> s21_list1{'b'};
  std::list<char> std_list1{'b'};
  s21_list1.insert(s21_list1.begin(), 'a');
  std_list1.insert(std_list1.begin(), 'a');
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<char>::iterator s21it = s21_list1.begin();
  std::list<char>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_insert_str_1) {
  S21::list<std::string> s21_list1{"asd"};
  std::list<std::string> std_list1{"asd"};
  s21_list1.insert(s21_list1.begin(), "qwe");
  std_list1.insert(std_list1.begin(), "qwe");
  ASSERT_EQ(s21_list1.size(), s21_list1.size());
  S21::list<std::string>::iterator s21it = s21_list1.begin();
  std::list<std::string>::iterator stdit = std_list1.begin();
  for (size_t i = 1; i <= s21_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_insert_int_2) {
  S21::list<int> s21_list1{200, 300};
  std::list<int> std_list1{200, 300};
  s21_list1.insert(s21_list1.end(), 100);
  std_list1.insert(std_list1.end(), 100);
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<int>::iterator s21it = s21_list1.begin();
  std::list<int>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_insert_char_2) {
  S21::list<char> s21_list1{'b', 'b'};
  std::list<char> std_list1{'b', 'b'};
  s21_list1.insert(s21_list1.end(), 'a');
  std_list1.insert(std_list1.end(), 'a');
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<char>::iterator s21it = s21_list1.begin();
  std::list<char>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_insert_str_2) {
  S21::list<std::string> s21_list1{"asd", "asd"};
  std::list<std::string> std_list1{"asd", "asd"};
  s21_list1.insert(s21_list1.end(), "qwe");
  std_list1.insert(std_list1.end(), "qwe");
  ASSERT_EQ(s21_list1.size(), s21_list1.size());
  S21::list<std::string>::iterator s21it = s21_list1.begin();
  std::list<std::string>::iterator stdit = std_list1.begin();
  for (size_t i = 1; i <= s21_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_insert_int_3) {
  S21::list<int> s21_list1{200, 300, 400};
  std::list<int> std_list1{200, 300, 400};
  s21_list1.insert(++(s21_list1.begin()), 100);
  std_list1.insert(++(std_list1.begin()), 100);
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<int>::iterator s21it = s21_list1.begin();
  std::list<int>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_insert_char_3) {
  S21::list<char> s21_list1{'b', 'b', 'b'};
  std::list<char> std_list1{'b', 'b', 'b'};
  s21_list1.insert(++(s21_list1.end()), 'a');
  std_list1.insert(++(std_list1.end()), 'a');
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<char>::iterator s21it = s21_list1.begin();
  std::list<char>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_insert_str_3) {
  S21::list<std::string> s21_list1{"asd", "asd", "asd"};
  std::list<std::string> std_list1{"asd", "asd", "asd"};
  s21_list1.insert(s21_list1.end(), "qwe");
  std_list1.insert(std_list1.end(), "qwe");
  ASSERT_EQ(s21_list1.size(), s21_list1.size());
  S21::list<std::string>::iterator s21it = s21_list1.begin();
  std::list<std::string>::iterator stdit = std_list1.begin();
  for (size_t i = 1; i <= s21_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_erase_int_1) {
  S21::list<int> s21_list1{200};
  std::list<int> std_list1{200};
  s21_list1.erase(s21_list1.begin());
  std_list1.erase(std_list1.begin());
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<int>::iterator s21it = s21_list1.begin();
  std::list<int>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_erase_char_1) {
  S21::list<char> s21_list1{'b'};
  std::list<char> std_list1{'b'};
  s21_list1.erase(s21_list1.begin());
  std_list1.erase(std_list1.begin());
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<char>::iterator s21it = s21_list1.begin();
  std::list<char>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_erase_str_1) {
  S21::list<std::string> s21_list1{"asd"};
  std::list<std::string> std_list1{"asd"};
  s21_list1.erase(s21_list1.begin());
  std_list1.erase(std_list1.begin());
  ASSERT_EQ(s21_list1.size(), s21_list1.size());
  S21::list<std::string>::iterator s21it = s21_list1.begin();
  std::list<std::string>::iterator stdit = std_list1.begin();
  for (size_t i = 1; i <= s21_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_erase_int_2) {
  S21::list<int> s21_list1{200, 300};
  std::list<int> std_list1{200, 300};
  s21_list1.erase(++(s21_list1.begin()));
  std_list1.erase(++(std_list1.begin()));
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<int>::iterator s21it = s21_list1.begin();
  std::list<int>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_erase_char_2) {
  S21::list<char> s21_list1{'b', 'b'};
  std::list<char> std_list1{'b', 'b'};
  s21_list1.erase(++(s21_list1.begin()));
  std_list1.erase(++(std_list1.begin()));
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<char>::iterator s21it = s21_list1.begin();
  std::list<char>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_erase_str_2) {
  S21::list<std::string> s21_list1{"asd", "asd"};
  std::list<std::string> std_list1{"asd", "asd"};
  s21_list1.erase(++(s21_list1.begin()));
  std_list1.erase(++(std_list1.begin()));
  ASSERT_EQ(s21_list1.size(), s21_list1.size());
  S21::list<std::string>::iterator s21it = s21_list1.begin();
  std::list<std::string>::iterator stdit = std_list1.begin();
  for (size_t i = 1; i <= s21_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

//

TEST(List, list_modifiers_erase_int_3) {
  S21::list<int> s21_list1{200, 300, 400};
  std::list<int> std_list1{200, 300, 400};
  s21_list1.erase(++(s21_list1.begin()));
  std_list1.erase(++(std_list1.begin()));
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<int>::iterator s21it = s21_list1.begin();
  std::list<int>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_erase_char_3) {
  S21::list<char> s21_list1{'b', 'b', 'b'};
  std::list<char> std_list1{'b', 'b', 'b'};
  s21_list1.erase(++(s21_list1.begin()));
  std_list1.erase(++(std_list1.begin()));
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<char>::iterator s21it = s21_list1.begin();
  std::list<char>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_erase_str_3) {
  S21::list<std::string> s21_list1{"asd", "asd", "asd"};
  std::list<std::string> std_list1{"asd", "asd", "asd"};
  s21_list1.erase(++(s21_list1.begin()));
  std_list1.erase(++(std_list1.begin()));
  ASSERT_EQ(s21_list1.size(), s21_list1.size());
  S21::list<std::string>::iterator s21it = s21_list1.begin();
  std::list<std::string>::iterator stdit = std_list1.begin();
  for (size_t i = 1; i <= s21_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_erase_int_3_itt3) {
  S21::list<int> s21_list1{200, 300, 400};
  std::list<int> std_list1{200, 300, 400};
  s21_list1.erase(++(++(s21_list1.begin())));
  std_list1.erase(++(++(std_list1.begin())));
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<int>::iterator s21it = s21_list1.begin();
  std::list<int>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_erase_char_3_itt3) {
  S21::list<char> s21_list1{'b', 'b', 'b'};
  std::list<char> std_list1{'b', 'b', 'b'};
  s21_list1.erase(++(++(s21_list1.begin())));
  std_list1.erase(++(++(std_list1.begin())));
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<char>::iterator s21it = s21_list1.begin();
  std::list<char>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_erase_str_3_itt3) {
  S21::list<std::string> s21_list1{"asd", "asd", "asd"};
  std::list<std::string> std_list1{"asd", "asd", "asd"};
  s21_list1.erase(++(++(s21_list1.begin())));
  std_list1.erase(++(++(std_list1.begin())));
  ASSERT_EQ(s21_list1.size(), s21_list1.size());
  S21::list<std::string>::iterator s21it = s21_list1.begin();
  std::list<std::string>::iterator stdit = std_list1.begin();
  for (size_t i = 1; i <= s21_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_push_back_int_1) {
  S21::list<int> s21_list1;
  std::list<int> std_list1;
  s21_list1.push_back(100);
  std_list1.push_back(100);
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<int>::iterator s21it = s21_list1.begin();
  std::list<int>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_push_back_char_1) {
  S21::list<char> s21_list1;
  std::list<char> std_list1;
  s21_list1.push_back('a');
  std_list1.push_back('a');
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<char>::iterator s21it = s21_list1.begin();
  std::list<char>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_push_back_str_1) {
  S21::list<std::string> s21_list1;
  std::list<std::string> std_list1;
  s21_list1.push_back("qwe");
  std_list1.push_back("qwe");
  ASSERT_EQ(s21_list1.size(), s21_list1.size());
  S21::list<std::string>::iterator s21it = s21_list1.begin();
  std::list<std::string>::iterator stdit = std_list1.begin();
  for (size_t i = 1; i <= s21_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_push_back_int_2) {
  S21::list<int> s21_list1{100};
  std::list<int> std_list1{100};
  s21_list1.push_back(100);
  std_list1.push_back(100);
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<int>::iterator s21it = s21_list1.begin();
  std::list<int>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_push_back_char_2) {
  S21::list<char> s21_list1{'a'};
  std::list<char> std_list1{'a'};
  s21_list1.push_back('a');
  std_list1.push_back('a');
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<char>::iterator s21it = s21_list1.begin();
  std::list<char>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_push_back_str_2) {
  S21::list<std::string> s21_list1{"qwe"};
  std::list<std::string> std_list1{"qwe"};
  s21_list1.push_back("qwe");
  std_list1.push_back("qwe");
  ASSERT_EQ(s21_list1.size(), s21_list1.size());
  S21::list<std::string>::iterator s21it = s21_list1.begin();
  std::list<std::string>::iterator stdit = std_list1.begin();
  for (size_t i = 1; i <= s21_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_push_back_int_3) {
  S21::list<int> s21_list1{200, 300};
  std::list<int> std_list1{200, 300};
  s21_list1.push_back(100);
  std_list1.push_back(100);
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<int>::iterator s21it = s21_list1.begin();
  std::list<int>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_push_back_char_3) {
  S21::list<char> s21_list1{'q', 'w'};
  std::list<char> std_list1{'q', 'w'};
  s21_list1.push_back('a');
  std_list1.push_back('a');
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<char>::iterator s21it = s21_list1.begin();
  std::list<char>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_push_back_str_3) {
  S21::list<std::string> s21_list1{"asd", "zxc"};
  std::list<std::string> std_list1{"asd", "zxc"};
  s21_list1.push_back("qwe");
  std_list1.push_back("qwe");
  ASSERT_EQ(s21_list1.size(), s21_list1.size());
  S21::list<std::string>::iterator s21it = s21_list1.begin();
  std::list<std::string>::iterator stdit = std_list1.begin();
  for (size_t i = 1; i <= s21_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_pop_back_int) {
  S21::list<int> s21_list1{200, 300};
  std::list<int> std_list1{200, 300};
  s21_list1.pop_back();
  std_list1.pop_back();
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<int>::iterator s21it = s21_list1.begin();
  std::list<int>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_pop_back_char) {
  S21::list<char> s21_list1{'q', 'w'};
  std::list<char> std_list1{'q', 'w'};
  s21_list1.pop_back();
  std_list1.pop_back();
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<char>::iterator s21it = s21_list1.begin();
  std::list<char>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_pop_back_str) {
  S21::list<std::string> s21_list1{"asd", "zxc"};
  std::list<std::string> std_list1{"asd", "zxc"};
  s21_list1.pop_back();
  std_list1.pop_back();
  ASSERT_EQ(s21_list1.size(), s21_list1.size());
  S21::list<std::string>::iterator s21it = s21_list1.begin();
  std::list<std::string>::iterator stdit = std_list1.begin();
  for (size_t i = 1; i <= s21_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_pop_back_int_1) {
  S21::list<int> s21_list1{200, 300};
  std::list<int> std_list1{200, 300};
  s21_list1.pop_back();
  std_list1.pop_back();
  s21_list1.pop_back();
  std_list1.pop_back();
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<int>::iterator s21it = s21_list1.begin();
  std::list<int>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_pop_back_char_1) {
  S21::list<char> s21_list1{'q', 'w'};
  std::list<char> std_list1{'q', 'w'};
  s21_list1.pop_back();
  std_list1.pop_back();
  s21_list1.pop_back();
  std_list1.pop_back();
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<char>::iterator s21it = s21_list1.begin();
  std::list<char>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_pop_back_str_1) {
  S21::list<std::string> s21_list1{"asd", "zxc"};
  std::list<std::string> std_list1{"asd", "zxc"};
  s21_list1.pop_back();
  std_list1.pop_back();
  s21_list1.pop_back();
  std_list1.pop_back();
  ASSERT_EQ(s21_list1.size(), s21_list1.size());
  S21::list<std::string>::iterator s21it = s21_list1.begin();
  std::list<std::string>::iterator stdit = std_list1.begin();
  for (size_t i = 1; i <= s21_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_push_front_int_1) {
  S21::list<int> s21_list1;
  std::list<int> std_list1;
  s21_list1.push_front(100);
  std_list1.push_front(100);
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<int>::iterator s21it = s21_list1.begin();
  std::list<int>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_push_front_char_1) {
  S21::list<char> s21_list1;
  std::list<char> std_list1;
  s21_list1.push_front('a');
  std_list1.push_front('a');
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<char>::iterator s21it = s21_list1.begin();
  std::list<char>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_push_front_str_1) {
  S21::list<std::string> s21_list1;
  std::list<std::string> std_list1;
  s21_list1.push_front("qwe");
  std_list1.push_front("qwe");
  ASSERT_EQ(s21_list1.size(), s21_list1.size());
  S21::list<std::string>::iterator s21it = s21_list1.begin();
  std::list<std::string>::iterator stdit = std_list1.begin();
  for (size_t i = 1; i <= s21_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_push_front_int_2) {
  S21::list<int> s21_list1{100};
  std::list<int> std_list1{100};
  s21_list1.push_front(100);
  std_list1.push_front(100);
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<int>::iterator s21it = s21_list1.begin();
  std::list<int>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_push_front_char_2) {
  S21::list<char> s21_list1{'a'};
  std::list<char> std_list1{'a'};
  s21_list1.push_front('a');
  std_list1.push_front('a');
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<char>::iterator s21it = s21_list1.begin();
  std::list<char>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_push_front_str_2) {
  S21::list<std::string> s21_list1{"qwe"};
  std::list<std::string> std_list1{"qwe"};
  s21_list1.push_front("qwe");
  std_list1.push_front("qwe");
  ASSERT_EQ(s21_list1.size(), s21_list1.size());
  S21::list<std::string>::iterator s21it = s21_list1.begin();
  std::list<std::string>::iterator stdit = std_list1.begin();
  for (size_t i = 1; i <= s21_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_push_front_int_3) {
  S21::list<int> s21_list1{200, 300};
  std::list<int> std_list1{200, 300};
  s21_list1.push_front(100);
  std_list1.push_front(100);
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<int>::iterator s21it = s21_list1.begin();
  std::list<int>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_push_front_char_3) {
  S21::list<char> s21_list1{'q', 'w'};
  std::list<char> std_list1{'q', 'w'};
  s21_list1.push_front('a');
  std_list1.push_front('a');
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<char>::iterator s21it = s21_list1.begin();
  std::list<char>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_push_front_str_3) {
  S21::list<std::string> s21_list1{"asd", "zxc"};
  std::list<std::string> std_list1{"asd", "zxc"};
  s21_list1.push_front("qwe");
  std_list1.push_front("qwe");
  ASSERT_EQ(s21_list1.size(), s21_list1.size());
  S21::list<std::string>::iterator s21it = s21_list1.begin();
  std::list<std::string>::iterator stdit = std_list1.begin();
  for (size_t i = 1; i <= s21_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_pop_front_int) {
  S21::list<int> s21_list1{200, 300};
  std::list<int> std_list1{200, 300};
  s21_list1.pop_front();
  std_list1.pop_front();
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<int>::iterator s21it = s21_list1.begin();
  std::list<int>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_pop_front_char) {
  S21::list<char> s21_list1{'q', 'w'};
  std::list<char> std_list1{'q', 'w'};
  s21_list1.pop_front();
  std_list1.pop_front();
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<char>::iterator s21it = s21_list1.begin();
  std::list<char>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_pop_front_str) {
  S21::list<std::string> s21_list1{"asd", "zxc"};
  std::list<std::string> std_list1{"asd", "zxc"};
  s21_list1.pop_front();
  std_list1.pop_front();
  ASSERT_EQ(s21_list1.size(), s21_list1.size());
  S21::list<std::string>::iterator s21it = s21_list1.begin();
  std::list<std::string>::iterator stdit = std_list1.begin();
  for (size_t i = 1; i <= s21_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_pop_front_int_1) {
  S21::list<int> s21_list1{200, 300};
  std::list<int> std_list1{200, 300};
  s21_list1.pop_front();
  std_list1.pop_front();
  s21_list1.pop_front();
  std_list1.pop_front();
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<int>::iterator s21it = s21_list1.begin();
  std::list<int>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_pop_front_char_1) {
  S21::list<char> s21_list1{'q', 'w'};
  std::list<char> std_list1{'q', 'w'};
  s21_list1.pop_front();
  std_list1.pop_front();
  s21_list1.pop_front();
  std_list1.pop_front();
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<char>::iterator s21it = s21_list1.begin();
  std::list<char>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_pop_front_str_1) {
  S21::list<std::string> s21_list1{"asd", "zxc"};
  std::list<std::string> std_list1{"asd", "zxc"};
  s21_list1.pop_front();
  std_list1.pop_front();
  s21_list1.pop_front();
  std_list1.pop_front();
  ASSERT_EQ(s21_list1.size(), s21_list1.size());
  S21::list<std::string>::iterator s21it = s21_list1.begin();
  std::list<std::string>::iterator stdit = std_list1.begin();
  for (size_t i = 1; i <= s21_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_swap_int) {
  S21::list<int> s21_list1{200, 200};
  S21::list<int> s21_list2{300, 300};

  std::list<int> std_list1{200, 200};
  std::list<int> std_list2{300, 300};

  s21_list1.swap(s21_list2);
  std_list1.swap(std_list2);

  ASSERT_EQ(s21_list1.size(), std_list1.size());
  ASSERT_EQ(s21_list2.size(), std_list2.size());

  S21::list<int>::iterator s21it = s21_list1.begin();
  std::list<int>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }

  S21::list<int>::iterator s21it2 = s21_list2.begin();
  std::list<int>::iterator stdit2 = std_list2.begin();
  for (size_t i = 0; i <= std_list2.size(); i++) {
    ASSERT_EQ(*s21it2, *stdit2);
    ++s21it2;
    ++stdit2;
  }
}

TEST(List, list_modifiers_swap_char) {
  S21::list<char> s21_list1{'a', 'a'};
  S21::list<char> s21_list2{'b', 'b'};

  std::list<char> std_list1{'a', 'a'};
  std::list<char> std_list2{'b', 'b'};

  s21_list1.swap(s21_list2);
  std_list1.swap(std_list2);

  ASSERT_EQ(s21_list1.size(), std_list1.size());
  ASSERT_EQ(s21_list2.size(), std_list2.size());

  S21::list<char>::iterator s21it = s21_list1.begin();
  std::list<char>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }

  S21::list<char>::iterator s21it2 = s21_list2.begin();
  std::list<char>::iterator stdit2 = std_list2.begin();
  for (size_t i = 0; i <= std_list2.size(); i++) {
    ASSERT_EQ(*s21it2, *stdit2);
    ++s21it2;
    ++stdit2;
  }
}

TEST(List, list_modifiers_swap_str) {
  S21::list<std::string> s21_list1{"aaaa", "aaaa"};
  S21::list<std::string> s21_list2{"bbbb", "bbbb"};

  std::list<std::string> std_list1{"aaaa", "aaaa"};
  std::list<std::string> std_list2{"bbbb", "bbbb"};

  s21_list1.swap(s21_list2);
  std_list1.swap(std_list2);

  ASSERT_EQ(s21_list1.size(), std_list1.size());
  ASSERT_EQ(s21_list2.size(), std_list2.size());

  S21::list<std::string>::iterator s21it = s21_list1.begin();
  std::list<std::string>::iterator stdit = std_list1.begin();
  for (size_t i = 1; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }

  S21::list<std::string>::iterator s21it2 = s21_list2.begin();
  std::list<std::string>::iterator stdit2 = std_list2.begin();
  for (size_t i = 1; i <= std_list2.size(); i++) {
    ASSERT_EQ(*s21it2, *stdit2);
    ++s21it2;
    ++stdit2;
  }
}

TEST(List, list_modifiers_swap_int_1) {
  S21::list<int> s21_list1{200, 200};
  S21::list<int> s21_list2{300, 300, 300};

  std::list<int> std_list1{200, 200};
  std::list<int> std_list2{300, 300, 300};

  s21_list1.swap(s21_list2);
  std_list1.swap(std_list2);

  ASSERT_EQ(s21_list1.size(), std_list1.size());
  ASSERT_EQ(s21_list2.size(), std_list2.size());

  S21::list<int>::iterator s21it = s21_list1.begin();
  std::list<int>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }

  S21::list<int>::iterator s21it2 = s21_list2.begin();
  std::list<int>::iterator stdit2 = std_list2.begin();
  for (size_t i = 0; i <= std_list2.size(); i++) {
    ASSERT_EQ(*s21it2, *stdit2);
    ++s21it2;
    ++stdit2;
  }
}

TEST(List, list_modifiers_swap_char_1) {
  S21::list<char> s21_list1{'a', 'a'};
  S21::list<char> s21_list2{'b', 'b', 'b'};

  std::list<char> std_list1{'a', 'a'};
  std::list<char> std_list2{'b', 'b', 'b'};

  s21_list1.swap(s21_list2);
  std_list1.swap(std_list2);

  ASSERT_EQ(s21_list1.size(), std_list1.size());
  ASSERT_EQ(s21_list2.size(), std_list2.size());

  S21::list<char>::iterator s21it = s21_list1.begin();
  std::list<char>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }

  S21::list<char>::iterator s21it2 = s21_list2.begin();
  std::list<char>::iterator stdit2 = std_list2.begin();
  for (size_t i = 0; i <= std_list2.size(); i++) {
    ASSERT_EQ(*s21it2, *stdit2);
    ++s21it2;
    ++stdit2;
  }
}

TEST(List, list_modifiers_swap_str_1) {
  S21::list<std::string> s21_list1{"aaaa", "aaaa"};
  S21::list<std::string> s21_list2{"bbbb", "bbbb", "bbbb"};

  std::list<std::string> std_list1{"aaaa", "aaaa"};
  std::list<std::string> std_list2{"bbbb", "bbbb", "bbbb"};

  s21_list1.swap(s21_list2);
  std_list1.swap(std_list2);

  ASSERT_EQ(s21_list1.size(), std_list1.size());
  ASSERT_EQ(s21_list2.size(), std_list2.size());

  S21::list<std::string>::iterator s21it = s21_list1.begin();
  std::list<std::string>::iterator stdit = std_list1.begin();
  for (size_t i = 1; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }

  S21::list<std::string>::iterator s21it2 = s21_list2.begin();
  std::list<std::string>::iterator stdit2 = std_list2.begin();
  for (size_t i = 1; i <= std_list2.size(); i++) {
    ASSERT_EQ(*s21it2, *stdit2);
    ++s21it2;
    ++stdit2;
  }
}

TEST(List, list_modifiers_reverse_int) {
  S21::list<int> s21_list1{100, 200};
  std::list<int> std_list1{100, 200};
  s21_list1.reverse();
  std_list1.reverse();
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<int>::iterator s21it = s21_list1.begin();
  std::list<int>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_reverse_char) {
  S21::list<char> s21_list1{'a', 'b'};
  std::list<char> std_list1{'a', 'b'};
  s21_list1.reverse();
  std_list1.reverse();
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<char>::iterator s21it = s21_list1.begin();
  std::list<char>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_reverse_str) {
  S21::list<std::string> s21_list1{"qwe", "asd"};
  std::list<std::string> std_list1{"qwe", "asd"};
  s21_list1.reverse();
  std_list1.reverse();
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<std::string>::iterator s21it = s21_list1.begin();
  std::list<std::string>::iterator stdit = std_list1.begin();
  for (size_t i = 1; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_unique_int) {
  S21::list<int> s21_list1{100, 200, 200, 300, 300, 500};
  std::list<int> std_list1{100, 200, 200, 300, 300, 500};
  s21_list1.unique();
  std_list1.unique();
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<int>::iterator s21it = s21_list1.begin();
  std::list<int>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_unique_char) {
  S21::list<char> s21_list1{'a', 'b', 'b', 'c', 'c', 'd'};
  std::list<char> std_list1{'a', 'b', 'b', 'c', 'c', 'd'};
  s21_list1.unique();
  std_list1.unique();
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<char>::iterator s21it = s21_list1.begin();
  std::list<char>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_unique_str) {
  S21::list<std::string> s21_list1{"qwe", "asd", "asd", "zxc", "zxc", "qaz"};
  std::list<std::string> std_list1{"qwe", "asd", "asd", "zxc", "zxc", "qaz"};
  s21_list1.unique();
  std_list1.unique();
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<std::string>::iterator s21it = s21_list1.begin();
  std::list<std::string>::iterator stdit = std_list1.begin();
  for (size_t i = 1; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_sort_int) {
  S21::list<int> s21_list1{1000, 20, 200, 3000, 300, 500};
  std::list<int> std_list1{1000, 20, 200, 3000, 300, 500};
  s21_list1.sort();
  std_list1.sort();
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<int>::iterator s21it = s21_list1.begin();
  std::list<int>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_sort_char) {
  S21::list<char> s21_list1{'q', 'b', 'z', 'f', 'a', 'e'};
  std::list<char> std_list1{'q', 'b', 'z', 'f', 'a', 'e'};
  s21_list1.sort();
  std_list1.sort();
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<char>::iterator s21it = s21_list1.begin();
  std::list<char>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_sort_str) {
  S21::list<std::string> s21_list1{"qwe", "asdd", "aed", "zc", "zxc", "qaz123"};
  std::list<std::string> std_list1{"qwe", "asdd", "aed", "zc", "zxc", "qaz123"};
  s21_list1.sort();
  std_list1.sort();
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<std::string>::iterator s21it = s21_list1.begin();
  std::list<std::string>::iterator stdit = std_list1.begin();
  for (size_t i = 1; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_merge_int) {
  S21::list<int> s21_list1{1000, 20, 200, 3000, 300, 5007};
  S21::list<int> s21_list2{1001, 201, 25, 300, 3005, 500};
  std::list<int> std_list1{1000, 20, 200, 3000, 300, 5007};
  std::list<int> std_list2{1001, 201, 25, 300, 3005, 500};
  s21_list1.merge(s21_list2);
  std_list1.merge(std_list2);
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<int>::iterator s21it = s21_list1.begin();
  std::list<int>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_merge_int_1) {
  S21::list<int> s21_list1{1000, 20, 200, 3000, 300};
  S21::list<int> s21_list2{1001, 201, 25, 300, 3005, 500};
  std::list<int> std_list1{1000, 20, 200, 3000, 300};
  std::list<int> std_list2{1001, 201, 25, 300, 3005, 500};
  s21_list1.merge(s21_list2);
  std_list1.merge(std_list2);
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<int>::iterator s21it = s21_list1.begin();
  std::list<int>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_merge_int_2) {
  S21::list<int> s21_list1{1000, 20, 200, 3000, 300, 5007};
  S21::list<int> s21_list2{1001, 201, 25, 300, 3005};
  std::list<int> std_list1{1000, 20, 200, 3000, 300, 5007};
  std::list<int> std_list2{1001, 201, 25, 300, 3005};
  s21_list1.merge(s21_list2);
  std_list1.merge(std_list2);
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<int>::iterator s21it = s21_list1.begin();
  std::list<int>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_merge_char) {
  S21::list<char> s21_list1{'w', 's', 'd', 'j', 'i', 'h'};
  S21::list<char> s21_list2{'g', 'd', 'n', 'p', 'b', 'n'};
  std::list<char> std_list1{'w', 's', 'd', 'j', 'i', 'h'};
  std::list<char> std_list2{'g', 'd', 'n', 'p', 'b', 'n'};
  s21_list1.merge(s21_list2);
  std_list1.merge(std_list2);
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<char>::iterator s21it = s21_list1.begin();
  std::list<char>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_merge_char_1) {
  S21::list<char> s21_list1{'w', 's', 'd', 'j'};
  S21::list<char> s21_list2{'g', 'd', 'n', 'p', 'b', 'n'};
  std::list<char> std_list1{'w', 's', 'd', 'j'};
  std::list<char> std_list2{'g', 'd', 'n', 'p', 'b', 'n'};
  s21_list1.merge(s21_list2);
  std_list1.merge(std_list2);
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<char>::iterator s21it = s21_list1.begin();
  std::list<char>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_merge_char_2) {
  S21::list<char> s21_list1{'w', 's', 'd', 'j', 'i', 'h'};
  S21::list<char> s21_list2{'g', 'd', 'n', 'p'};
  std::list<char> std_list1{'w', 's', 'd', 'j', 'i', 'h'};
  std::list<char> std_list2{'g', 'd', 'n', 'p'};
  s21_list1.merge(s21_list2);
  std_list1.merge(std_list2);
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<char>::iterator s21it = s21_list1.begin();
  std::list<char>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_merge_str) {
  S21::list<std::string> s21_list1{"pust", "vsegda", "budet", "solnce"};
  S21::list<std::string> s21_list2{"chijik", "pusjik", "gde", "tu"};
  std::list<std::string> std_list1{"pust", "vsegda", "budet", "solnce"};
  std::list<std::string> std_list2{"chijik", "pusjik", "gde", "tu"};
  s21_list1.merge(s21_list2);
  std_list1.merge(std_list2);
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<std::string>::iterator s21it = s21_list1.begin();
  std::list<std::string>::iterator stdit = std_list1.begin();
  for (size_t i = 1; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_merge_str_1) {
  S21::list<std::string> s21_list1{"pust", "vsegda", "budet", "solnce",
                                   "pust", "vsegda", "budet", "nebo"};
  S21::list<std::string> s21_list2{"chijik", "pusjik", "gde", "tu", "bul", "?"};
  std::list<std::string> std_list1{"pust", "vsegda", "budet", "solnce",
                                   "pust", "vsegda", "budet", "nebo"};
  std::list<std::string> std_list2{"chijik", "pusjik", "gde", "tu", "bul", "?"};
  s21_list1.merge(s21_list2);
  std_list1.merge(std_list2);
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<std::string>::iterator s21it = s21_list1.begin();
  std::list<std::string>::iterator stdit = std_list1.begin();
  for (size_t i = 1; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_merge_str_2) {
  S21::list<std::string> s21_list1{"pust", "vsegda", "budet", "solnce"};
  S21::list<std::string> s21_list2{"chijik", "pusjik", "gde", "tu", "bul", "?"};
  std::list<std::string> std_list1{"pust", "vsegda", "budet", "solnce"};
  std::list<std::string> std_list2{"chijik", "pusjik", "gde", "tu", "bul", "?"};
  s21_list1.merge(s21_list2);
  std_list1.merge(std_list2);
  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<std::string>::iterator s21it = s21_list1.begin();
  std::list<std::string>::iterator stdit = std_list1.begin();
  for (size_t i = 1; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_splice_int) {
  S21::list<int> s21_list1{100, 200, 300, 400};
  S21::list<int> s21_list2{111, 222, 333, 444};
  std::list<int> std_list1{100, 200, 300, 400};
  std::list<int> std_list2{111, 222, 333, 444};

  S21::list<int>::const_iterator s21it_const = s21_list1.cbegin();
  std::list<int>::iterator stdit_const = std_list1.begin();

  s21_list1.splice(s21it_const, s21_list2);
  std_list1.splice(stdit_const, std_list2);

  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<int>::iterator s21it = s21_list1.begin();
  std::list<int>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_splice_int_1) {
  S21::list<int> s21_list1{100, 200, 300, 400};
  S21::list<int> s21_list2{111, 222, 333, 444};
  std::list<int> std_list1{100, 200, 300, 400};
  std::list<int> std_list2{111, 222, 333, 444};

  S21::list<int>::const_iterator s21it_const = s21_list1.cend();
  std::list<int>::iterator stdit_const = std_list1.end();

  s21_list1.splice(s21it_const, s21_list2);
  std_list1.splice(stdit_const, std_list2);

  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<int>::iterator s21it = s21_list1.begin();
  std::list<int>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_splice_int_2) {
  S21::list<int> s21_list1{100, 200, 300, 400};
  S21::list<int> s21_list2{111, 222, 333, 444};
  std::list<int> std_list1{100, 200, 300, 400};
  std::list<int> std_list2{111, 222, 333, 444};

  S21::list<int>::const_iterator s21it_const = s21_list1.cbegin();
  std::list<int>::iterator stdit_const = std_list1.begin();

  s21_list1.splice(++s21it_const, s21_list2);
  std_list1.splice(++stdit_const, std_list2);

  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<int>::iterator s21it = s21_list1.begin();
  std::list<int>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_splice_char) {
  S21::list<char> s21_list1{'a', 'b', 'c', 'd'};
  S21::list<char> s21_list2{'z', 'x', 'y', 'v'};
  std::list<char> std_list1{'a', 'b', 'c', 'd'};
  std::list<char> std_list2{'z', 'x', 'y', 'v'};

  S21::list<char>::const_iterator s21it_const = s21_list1.cbegin();
  std::list<char>::iterator stdit_const = std_list1.begin();

  s21_list1.splice(s21it_const, s21_list2);
  std_list1.splice(stdit_const, std_list2);

  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<char>::iterator s21it = s21_list1.begin();
  std::list<char>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_splice_char_1) {
  S21::list<char> s21_list1{'a', 'b', 'c', 'd'};
  S21::list<char> s21_list2{'z', 'x', 'y', 'v'};
  std::list<char> std_list1{'a', 'b', 'c', 'd'};
  std::list<char> std_list2{'z', 'x', 'y', 'v'};

  S21::list<char>::const_iterator s21it_const = s21_list1.cend();
  std::list<char>::iterator stdit_const = std_list1.end();

  s21_list1.splice(s21it_const, s21_list2);
  std_list1.splice(stdit_const, std_list2);

  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<char>::iterator s21it = s21_list1.begin();
  std::list<char>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_splice_char_2) {
  S21::list<char> s21_list1{'a', 'b', 'c', 'd'};
  S21::list<char> s21_list2{'z', 'x', 'y', 'v'};
  std::list<char> std_list1{'a', 'b', 'c', 'd'};
  std::list<char> std_list2{'z', 'x', 'y', 'v'};

  S21::list<char>::const_iterator s21it_const = s21_list1.cbegin();
  std::list<char>::iterator stdit_const = std_list1.begin();

  s21_list1.splice(++s21it_const, s21_list2);
  std_list1.splice(++stdit_const, std_list2);

  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<char>::iterator s21it = s21_list1.begin();
  std::list<char>::iterator stdit = std_list1.begin();
  for (size_t i = 0; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_splice_str) {
  S21::list<std::string> s21_list1{"qwe1", "qwe2", "qwe3", "qwe4"};
  S21::list<std::string> s21_list2{"asd1", "asd2", "asd3", "asd4"};
  std::list<std::string> std_list1{"qwe1", "qwe2", "qwe3", "qwe4"};
  std::list<std::string> std_list2{"asd1", "asd2", "asd3", "asd4"};

  S21::list<std::string>::const_iterator s21it_const = s21_list1.cbegin();
  std::list<std::string>::iterator stdit_const = std_list1.begin();

  s21_list1.splice(s21it_const, s21_list2);
  std_list1.splice(stdit_const, std_list2);

  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<std::string>::iterator s21it = s21_list1.begin();
  std::list<std::string>::iterator stdit = std_list1.begin();
  for (size_t i = 1; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_splice_str_1) {
  S21::list<std::string> s21_list1{"qwe1", "qwe2", "qwe3", "qwe4"};
  S21::list<std::string> s21_list2{"asd1", "asd2", "asd3", "asd4"};
  std::list<std::string> std_list1{"qwe1", "qwe2", "qwe3", "qwe4"};
  std::list<std::string> std_list2{"asd1", "asd2", "asd3", "asd4"};

  S21::list<std::string>::const_iterator s21it_const = s21_list1.cend();
  std::list<std::string>::iterator stdit_const = std_list1.end();

  s21_list1.splice(s21it_const, s21_list2);
  std_list1.splice(stdit_const, std_list2);

  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<std::string>::iterator s21it = s21_list1.begin();
  std::list<std::string>::iterator stdit = std_list1.begin();
  for (size_t i = 1; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, list_modifiers_splice_str_2) {
  S21::list<std::string> s21_list1{"qwe1", "qwe2", "qwe3", "qwe4"};
  S21::list<std::string> s21_list2{"asd1", "asd2", "asd3", "asd4"};
  std::list<std::string> std_list1{"qwe1", "qwe2", "qwe3", "qwe4"};
  std::list<std::string> std_list2{"asd1", "asd2", "asd3", "asd4"};

  S21::list<std::string>::const_iterator s21it_const = s21_list1.cbegin();
  std::list<std::string>::iterator stdit_const = std_list1.begin();

  s21_list1.splice(++s21it_const, s21_list2);
  std_list1.splice(++stdit_const, std_list2);

  ASSERT_EQ(s21_list1.size(), std_list1.size());
  S21::list<std::string>::iterator s21it = s21_list1.begin();
  std::list<std::string>::iterator stdit = std_list1.begin();
  for (size_t i = 1; i <= std_list1.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, class_list_int) {
  S21::list<int> s21_list1;
  S21::list<S21::list<int>> s21_list_class;
  s21_list_class.push_back(s21_list1);
}

TEST(List, class_list_char) {
  S21::list<char> s21_list1;
  S21::list<S21::list<char>> s21_list_class(2);
  s21_list_class.push_back(s21_list1);
}

TEST(List, class_list_str) {
  S21::list<std::string> s21_list1;
  S21::list<S21::list<std::string>> s21_list_class;
  s21_list_class.push_back(s21_list1);
}

TEST(List, class_list_int_1) {
  S21::list<int> s21_list1{10, 20, 30};
  S21::list<int> s21_list2{100, 200, 300};
  S21::list<S21::list<int>> s21_list_class;
  s21_list_class.push_front(s21_list1);
  s21_list_class.push_front(s21_list2);
  S21::list<int> s21_list3 = s21_list_class.front();

  std::list<int> std_list1{10, 20, 30};
  std::list<int> std_list2{100, 200, 300};
  std::list<std::list<int>> std_list_class;
  std_list_class.push_front(std_list1);
  std_list_class.push_front(std_list2);
  std::list<int> std_list3 = std_list_class.front();

  ASSERT_EQ(s21_list_class.size(), std_list_class.size());

  S21::list<int>::iterator s21it = s21_list3.begin();
  std::list<int>::iterator stdit = std_list3.begin();

  for (size_t i = 0; i <= s21_list3.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, class_list_char_1) {
  S21::list<char> s21_list1{'a', 'b', 'c'};
  S21::list<char> s21_list2{'z', 'y', 'x'};
  S21::list<S21::list<char>> s21_list_class;
  s21_list_class.push_front(s21_list1);
  s21_list_class.push_front(s21_list2);
  S21::list<char> s21_list3 = s21_list_class.front();

  std::list<char> std_list1{'a', 'b', 'c'};
  std::list<char> std_list2{'z', 'y', 'x'};
  std::list<std::list<char>> std_list_class;
  std_list_class.push_front(std_list1);
  std_list_class.push_front(std_list2);
  std::list<char> std_list3 = std_list_class.front();

  ASSERT_EQ(s21_list_class.size(), std_list_class.size());

  S21::list<char>::iterator s21it = s21_list3.begin();
  std::list<char>::iterator stdit = std_list3.begin();

  for (size_t i = 0; i <= s21_list3.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, class_list_str_1) {
  S21::list<std::string> s21_list1{"qwe", "asd", "zxc"};
  S21::list<std::string> s21_list2{"qaz", "wsx", "edc"};
  S21::list<S21::list<std::string>> s21_list_class;
  s21_list_class.push_front(s21_list1);
  s21_list_class.push_front(s21_list2);
  S21::list<std::string> s21_list3 = s21_list_class.front();

  std::list<std::string> std_list1{"qwe", "asd", "zxc"};
  std::list<std::string> std_list2{"qaz", "wsx", "edc"};
  std::list<std::list<std::string>> std_list_class;
  std_list_class.push_front(std_list1);
  std_list_class.push_front(std_list2);
  std::list<std::string> std_list3 = std_list_class.front();

  ASSERT_EQ(s21_list_class.size(), std_list_class.size());

  S21::list<std::string>::iterator s21it = s21_list3.begin();
  std::list<std::string>::iterator stdit = std_list3.begin();

  for (size_t i = 1; i <= s21_list3.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, class_stack_int) {
  S21::stack<int> s21_stack;
  S21::list<S21::stack<int>> s21_list_class;
  s21_list_class.push_back(s21_stack);
}

TEST(List, class_stack_char) {
  S21::stack<char> s21_list1;
  S21::list<S21::stack<char>> s21_list_class;
  s21_list_class.push_back(s21_list1);
}

TEST(List, class_stack_str) {
  S21::stack<std::string> s21_list1;
  S21::list<S21::stack<std::string>> s21_list_class;
  s21_list_class.push_back(s21_list1);
}

TEST(List, class_stack_int_1) {
  S21::stack<int> s21_stack1({10, 20, 30});
  S21::stack<int> s21_stack2({100, 200, 300});
  S21::list<S21::stack<int>> s21_list_class;
  s21_list_class.push_front(s21_stack1);
  s21_list_class.push_front(s21_stack2);
  S21::stack<int> s21_stack3 = s21_list_class.front();

  std::stack<int> std_stack1({10, 20, 30});
  std::stack<int> std_stack2({100, 200, 300});
  std::list<std::stack<int>> std_list_class;
  std_list_class.push_front(std_stack1);
  std_list_class.push_front(std_stack2);
  std::stack<int> std_stack3 = std_list_class.front();

  ASSERT_EQ(s21_list_class.size(), std_list_class.size());

  while (!s21_stack3.empty()) {
    ASSERT_EQ(s21_stack3.top(), std_stack3.top());
    s21_stack3.pop();
    std_stack3.pop();
  }
}

TEST(List, class_queue_int_1) {
  S21::queue<int> s21_queue1({10, 20, 30});
  S21::queue<int> s21_queue2({100, 200, 300});
  S21::list<S21::queue<int>> s21_list_class;
  s21_list_class.push_front(s21_queue1);
  s21_list_class.push_front(s21_queue2);
  S21::queue<int> s21_queue3 = s21_list_class.front();

  std::queue<int> std_queue1({10, 20, 30});
  std::queue<int> std_queue2({100, 200, 300});
  std::list<std::queue<int>> std_list_class;
  std_list_class.push_front(std_queue1);
  std_list_class.push_front(std_queue2);
  std::queue<int> std_queue3 = std_list_class.front();

  ASSERT_EQ(s21_list_class.size(), std_list_class.size());

  while (!s21_queue3.empty()) {
    ASSERT_EQ(s21_queue3.front(), std_queue3.front());
    s21_queue3.pop();
    std_queue3.pop();
  }
}

TEST(List, class_many_insert_int_1) {
  S21::list<int> std_list;
  std_list.insert_many(std_list.cbegin(), 1, 2, 3);
  S21::list<int> std_list2 = {1, 2, 3};

  ASSERT_EQ(std_list.size(), std_list2.size());
  S21::list<int>::iterator s21it = std_list.begin();
  S21::list<int>::iterator s21it2 = std_list2.begin();
  for (size_t i = 0; i <= std_list.size(); i++) {
    ASSERT_EQ(*s21it, *s21it2);
    ++s21it;
    ++s21it2;
  }
}

TEST(List, class_many_insert_int_2) {
  S21::list<int> std_list = {90, 80, 70};
  std_list.insert_many(std_list.cbegin(), 1, 2, 3);
  S21::list<int> std_list2 = {1, 2, 3, 90, 80, 70};

  ASSERT_EQ(std_list.size(), std_list2.size());
  S21::list<int>::iterator s21it = std_list.begin();
  S21::list<int>::iterator s21it2 = std_list2.begin();
  for (size_t i = 0; i <= std_list.size(); i++) {
    ASSERT_EQ(*s21it, *s21it2);
    ++s21it;
    ++s21it2;
  }
}

TEST(List, class_many_insert_int_3) {
  S21::list<int> std_list = {90, 80, 70};
  std_list.insert_many(++std_list.cbegin(), 1, 2, 3);
  S21::list<int> std_list2 = {90, 1, 2, 3, 80, 70};

  ASSERT_EQ(std_list.size(), std_list2.size());
  S21::list<int>::iterator s21it = std_list.begin();
  S21::list<int>::iterator s21it2 = std_list2.begin();
  for (size_t i = 0; i <= std_list.size(); i++) {
    ASSERT_EQ(*s21it, *s21it2);
    ++s21it;
    ++s21it2;
  }
}

TEST(List, class_many_insert_many_back_int_1) {
  S21::list<int> std_list;
  std_list.insert_many_back(1, 2, 3);
  S21::list<int> std_list2 = {1, 2, 3};

  ASSERT_EQ(std_list.size(), std_list2.size());
  S21::list<int>::iterator s21it = std_list.begin();
  S21::list<int>::iterator s21it2 = std_list2.begin();
  for (size_t i = 0; i <= std_list.size(); i++) {
    ASSERT_EQ(*s21it, *s21it2);
    ++s21it;
    ++s21it2;
  }
}

TEST(List, class_many_insert_many_back_int_2) {
  S21::list<int> std_list = {90, 80, 70};
  std_list.insert_many_back(1, 2, 3);
  S21::list<int> std_list2 = {90, 80, 70, 1, 2, 3};

  ASSERT_EQ(std_list.size(), std_list2.size());
  S21::list<int>::iterator s21it = std_list.begin();
  S21::list<int>::iterator s21it2 = std_list2.begin();
  for (size_t i = 0; i <= std_list.size(); i++) {
    ASSERT_EQ(*s21it, *s21it2);
    ++s21it;
    ++s21it2;
  }
}

TEST(List, class_many_insert_many_front_int_1) {
  S21::list<int> std_list;
  std_list.insert_many_front(1, 2, 3);
  S21::list<int> std_list2 = {1, 2, 3};

  ASSERT_EQ(std_list.size(), std_list2.size());
  S21::list<int>::iterator s21it = std_list.begin();
  S21::list<int>::iterator s21it2 = std_list2.begin();
  for (size_t i = 0; i <= std_list.size(); i++) {
    ASSERT_EQ(*s21it, *s21it2);
    ++s21it;
    ++s21it2;
  }
}

TEST(List, class_many_insert_many_front_int_2) {
  S21::list<int> std_list = {90, 80, 70};
  std_list.insert_many_front(1, 2, 3);
  S21::list<int> std_list2 = {1, 2, 3, 90, 80, 70};

  ASSERT_EQ(std_list.size(), std_list2.size());
  S21::list<int>::iterator s21it = std_list.begin();
  S21::list<int>::iterator s21it2 = std_list2.begin();
  for (size_t i = 0; i <= std_list.size(); i++) {
    ASSERT_EQ(*s21it, *s21it2);
    ++s21it;
    ++s21it2;
  }
}

TEST(List, class_many_insert_many_front_char_1) {
  S21::list<char> std_list = {'z', 'y', 'x'};
  std_list.insert_many_front('a', 'b', 'c');
  S21::list<char> std_list2 = {'a', 'b', 'c', 'z', 'y', 'x'};

  ASSERT_EQ(std_list.size(), std_list2.size());
  S21::list<char>::iterator s21it = std_list.begin();
  S21::list<char>::iterator s21it2 = std_list2.begin();
  for (size_t i = 0; i <= std_list.size(); i++) {
    ASSERT_EQ(*s21it, *s21it2);
    ++s21it;
    ++s21it2;
  }
}

// QUEUE

TEST(Queue, def_constructor_int) {
  S21::queue<int> s21_queue;
  std::queue<int> std_queue;
  ASSERT_EQ(s21_queue.empty(), std_queue.empty());
  ASSERT_EQ(s21_queue.size(), std_queue.size());
}

TEST(Queue, def_constructor_char) {
  S21::queue<char> s21_queue;
  std::queue<char> std_queue;
  ASSERT_EQ(s21_queue.empty(), std_queue.empty());
  ASSERT_EQ(s21_queue.size(), std_queue.size());
}

TEST(Queue, def_constructor_str) {
  S21::queue<std::string> s21_queue;
  std::queue<std::string> std_queue;
  ASSERT_EQ(s21_queue.empty(), std_queue.empty());
  ASSERT_EQ(s21_queue.size(), std_queue.size());
}

TEST(Queue, init_list_int) {
  S21::queue<int> s21_queue({10, 20, 30});
  std::queue<int> std_queue({10, 20, 30});
  ASSERT_EQ(s21_queue.empty(), std_queue.empty());
  ASSERT_EQ(s21_queue.size(), std_queue.size());
  while (!s21_queue.empty()) {
    ASSERT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST(Queue, init_list_char) {
  S21::queue<char> s21_queue({'a', 'b', 'c'});
  std::queue<char> std_queue({'a', 'b', 'c'});
  ASSERT_EQ(s21_queue.empty(), std_queue.empty());
  ASSERT_EQ(s21_queue.size(), std_queue.size());
  while (!s21_queue.empty()) {
    ASSERT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST(Queue, init_list_str) {
  S21::queue<std::string> s21_queue({"qwe", "asd", "zxc"});
  std::queue<std::string> std_queue({"qwe", "asd", "zxc"});
  ASSERT_EQ(s21_queue.empty(), std_queue.empty());
  ASSERT_EQ(s21_queue.size(), std_queue.size());
  while (!s21_queue.empty()) {
    ASSERT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST(Queue, copy_constructor_int) {
  S21::queue<int> s21_queue2({10, 20, 30});
  S21::queue<int> s21_queue(s21_queue2);
  std::queue<int> std_queue2({10, 20, 30});
  std::queue<int> std_queue(std_queue2);
  ASSERT_EQ(s21_queue.empty(), std_queue.empty());
  ASSERT_EQ(s21_queue.size(), std_queue.size());
  while (!s21_queue.empty()) {
    ASSERT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST(Queue, copy_constructor_char) {
  S21::queue<char> s21_queue2({'a', 'b', 'c'});
  S21::queue<char> s21_queue(s21_queue2);
  std::queue<char> std_queue2({'a', 'b', 'c'});
  std::queue<char> std_queue(std_queue2);
  ASSERT_EQ(s21_queue.empty(), std_queue.empty());
  ASSERT_EQ(s21_queue.size(), std_queue.size());
  while (!s21_queue.empty()) {
    ASSERT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST(Queue, copy_constructor_str) {
  S21::queue<std::string> s21_queue2({"qwe", "asd", "zxc"});
  S21::queue<std::string> s21_queue(s21_queue2);
  std::queue<std::string> std_queue2({"qwe", "asd", "zxc"});
  std::queue<std::string> std_queue(std_queue2);
  ASSERT_EQ(s21_queue.empty(), std_queue.empty());
  ASSERT_EQ(s21_queue.size(), std_queue.size());
  while (!s21_queue.empty()) {
    ASSERT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST(Queue, move_constructor_int) {
  S21::queue<int> s21_queue2({10, 20, 30});
  S21::queue<int> s21_queue = std::move(s21_queue2);
  std::queue<int> std_queue2({10, 20, 30});
  std::queue<int> std_queue = std::move(std_queue2);
  ASSERT_EQ(s21_queue.empty(), std_queue.empty());
  ASSERT_EQ(s21_queue.size(), std_queue.size());
  while (!s21_queue.empty()) {
    ASSERT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST(Queue, move_constructor_char) {
  S21::queue<char> s21_queue2({'a', 'b', 'c'});
  S21::queue<char> s21_queue = std::move(s21_queue2);
  std::queue<char> std_queue2({'a', 'b', 'c'});
  std::queue<char> std_queue = std::move(std_queue2);
  ASSERT_EQ(s21_queue.empty(), std_queue.empty());
  ASSERT_EQ(s21_queue.size(), std_queue.size());
  while (!s21_queue.empty()) {
    ASSERT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST(Queue, move_constructor_str) {
  S21::queue<std::string> s21_queue2({"qwe", "asd", "zxc"});
  S21::queue<std::string> s21_queue = std::move(s21_queue2);
  std::queue<std::string> std_queue2({"qwe", "asd", "zxc"});
  std::queue<std::string> std_queue = std::move(std_queue2);
  ASSERT_EQ(s21_queue.empty(), std_queue.empty());
  ASSERT_EQ(s21_queue.size(), std_queue.size());
  while (!s21_queue.empty()) {
    ASSERT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST(Queue, move_operator_int) {
  S21::queue<int> s21_queue2({10, 20, 30});
  S21::queue<int> s21_queue;
  s21_queue = std::move(s21_queue2);
  std::queue<int> std_queue2({10, 20, 30});
  std::queue<int> std_queue;
  std_queue = std::move(std_queue2);
  ASSERT_EQ(s21_queue.empty(), std_queue.empty());
  ASSERT_EQ(s21_queue.size(), std_queue.size());
  while (!s21_queue.empty()) {
    ASSERT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST(Queue, move_operator_char) {
  S21::queue<char> s21_queue2({'a', 'b', 'c'});
  S21::queue<char> s21_queue;
  s21_queue = std::move(s21_queue2);
  std::queue<char> std_queue2({'a', 'b', 'c'});
  std::queue<char> std_queue;
  std_queue = std::move(std_queue2);
  ASSERT_EQ(s21_queue.empty(), std_queue.empty());
  ASSERT_EQ(s21_queue.size(), std_queue.size());
  while (!s21_queue.empty()) {
    ASSERT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST(Queue, move_operator_str) {
  S21::queue<std::string> s21_queue2({"qwe", "asd", "zxc"});
  S21::queue<std::string> s21_queue;
  s21_queue = std::move(s21_queue2);
  std::queue<std::string> std_queue2({"qwe", "asd", "zxc"});
  std::queue<std::string> std_queue;
  std_queue = std::move(std_queue2);
  ASSERT_EQ(s21_queue.empty(), std_queue.empty());
  ASSERT_EQ(s21_queue.size(), std_queue.size());
  while (!s21_queue.empty()) {
    ASSERT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST(Queue, copy_operator_int) {
  S21::queue<int> s21_queue2({10, 20, 30});
  S21::queue<int> s21_queue;
  s21_queue = s21_queue2;
  std::queue<int> std_queue2({10, 20, 30});
  std::queue<int> std_queue;
  std_queue = std_queue2;
  ASSERT_EQ(s21_queue.empty(), std_queue.empty());
  ASSERT_EQ(s21_queue.size(), std_queue.size());
  while (!s21_queue.empty()) {
    ASSERT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST(Queue, copy_operator_char) {
  S21::queue<char> s21_queue2({'a', 'b', 'c'});
  S21::queue<char> s21_queue;
  s21_queue = s21_queue2;
  std::queue<char> std_queue2({'a', 'b', 'c'});
  std::queue<char> std_queue;
  std_queue = std_queue2;
  ASSERT_EQ(s21_queue.empty(), std_queue.empty());
  ASSERT_EQ(s21_queue.size(), std_queue.size());
  while (!s21_queue.empty()) {
    ASSERT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST(Queue, copy_operator_str) {
  S21::queue<std::string> s21_queue2({"qwe", "asd", "zxc"});
  S21::queue<std::string> s21_queue;
  s21_queue = s21_queue2;
  std::queue<std::string> std_queue2({"qwe", "asd", "zxc"});
  std::queue<std::string> std_queue;
  std_queue = std_queue2;
  ASSERT_EQ(s21_queue.empty(), std_queue.empty());
  ASSERT_EQ(s21_queue.size(), std_queue.size());
  while (!s21_queue.empty()) {
    ASSERT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST(Queue, back_and_push_int) {
  S21::queue<int> s21_queue;
  std::queue<int> std_queue;
  s21_queue.push(10);
  std_queue.push(10);
  ASSERT_EQ(s21_queue.back(), std_queue.back());
  s21_queue.push(20);
  std_queue.push(20);
  ASSERT_EQ(s21_queue.back(), std_queue.back());
  s21_queue.push(30);
  std_queue.push(30);
  ASSERT_EQ(s21_queue.back(), std_queue.back());

  ASSERT_EQ(s21_queue.empty(), std_queue.empty());
  ASSERT_EQ(s21_queue.size(), std_queue.size());
}

TEST(Queue, back_and_push_char) {
  S21::queue<char> s21_queue;
  std::queue<char> std_queue;
  s21_queue.push('a');
  std_queue.push('a');
  ASSERT_EQ(s21_queue.back(), std_queue.back());
  s21_queue.push('b');
  std_queue.push('b');
  ASSERT_EQ(s21_queue.back(), std_queue.back());
  s21_queue.push('c');
  std_queue.push('c');
  ASSERT_EQ(s21_queue.back(), std_queue.back());

  ASSERT_EQ(s21_queue.empty(), std_queue.empty());
  ASSERT_EQ(s21_queue.size(), std_queue.size());
}

TEST(Queue, back_and_push_str) {
  S21::queue<std::string> s21_queue;
  std::queue<std::string> std_queue;
  s21_queue.push("qwe");
  std_queue.push("qwe");
  ASSERT_EQ(s21_queue.back(), std_queue.back());
  s21_queue.push("asd");
  std_queue.push("asd");
  ASSERT_EQ(s21_queue.back(), std_queue.back());
  s21_queue.push("zxc");
  std_queue.push("zxc");
  ASSERT_EQ(s21_queue.back(), std_queue.back());

  ASSERT_EQ(s21_queue.empty(), std_queue.empty());
  ASSERT_EQ(s21_queue.size(), std_queue.size());
}

TEST(Queue, swap_int) {
  S21::queue<int> s21_queue({200, 200});
  S21::queue<int> s21_queue2({300, 300});

  std::queue<int> std_queue({200, 200});
  std::queue<int> std_queue2({300, 300});

  s21_queue.swap(s21_queue2);
  std_queue.swap(std_queue2);

  ASSERT_EQ(s21_queue.size(), std_queue.size());
  ASSERT_EQ(s21_queue2.size(), std_queue2.size());

  while (!s21_queue.empty()) {
    ASSERT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();
  }

  while (!s21_queue2.empty()) {
    ASSERT_EQ(s21_queue2.front(), std_queue2.front());
    s21_queue2.pop();
    std_queue2.pop();
  }
}

TEST(Queue, class_queue_int) {
  S21::queue<int> s21_queue;
  S21::queue<S21::queue<int>> s21_queue_class;
  s21_queue_class.push(s21_queue);
}

TEST(Queue, class_queue_char) {
  S21::queue<char> s21_queue;
  S21::queue<S21::queue<char>> s21_queue_class;
  s21_queue_class.push(s21_queue);
}

TEST(Queue, class_queue_str) {
  S21::queue<std::string> s21_queue;
  S21::queue<S21::queue<std::string>> s21_queue_class;
  s21_queue_class.push(s21_queue);
}

TEST(Queue, class_queue_int_1) {
  S21::queue<int> s21_queue1({10, 20, 30});
  S21::queue<int> s21_queue2({100, 200, 300});
  S21::queue<S21::queue<int>> s21_queue_class;
  s21_queue_class.push(s21_queue1);
  s21_queue_class.push(s21_queue2);
  S21::queue<int> s21_queue3 = s21_queue_class.front();

  std::queue<int> std_queue1({10, 20, 30});
  std::queue<int> std_queue2({100, 200, 300});
  std::queue<std::queue<int>> std_queue_class;
  std_queue_class.push(std_queue1);
  std_queue_class.push(std_queue2);
  std::queue<int> std_queue3 = std_queue_class.front();

  ASSERT_EQ(s21_queue_class.size(), std_queue_class.size());

  while (!s21_queue3.empty()) {
    ASSERT_EQ(s21_queue3.front(), std_queue3.front());
    s21_queue3.pop();
    std_queue3.pop();
  }
}

TEST(Queue, class_queue_char_1) {
  S21::queue<char> s21_queue1({'a', 'b', 'c'});
  S21::queue<char> s21_queue2({'x', 'y', 'z'});
  S21::queue<S21::queue<char>> s21_queue_class;
  s21_queue_class.push(s21_queue1);
  s21_queue_class.push(s21_queue2);
  S21::queue<char> s21_queue3 = s21_queue_class.front();

  std::queue<char> std_queue1({'a', 'b', 'c'});
  std::queue<char> std_queue2({'x', 'y', 'z'});
  std::queue<std::queue<char>> std_queue_class;
  std_queue_class.push(std_queue1);
  std_queue_class.push(std_queue2);
  std::queue<char> std_queue3 = std_queue_class.front();

  ASSERT_EQ(s21_queue_class.size(), std_queue_class.size());

  while (!s21_queue3.empty()) {
    ASSERT_EQ(s21_queue3.front(), std_queue3.front());
    s21_queue3.pop();
    std_queue3.pop();
  }
}

TEST(Queue, class_queue_str_1) {
  S21::queue<std::string> s21_queue1({"qwe", "asd", "zxc"});
  S21::queue<std::string> s21_queue2({"qaz", "wsx", "edc"});
  S21::queue<S21::queue<std::string>> s21_queue_class;
  s21_queue_class.push(s21_queue1);
  s21_queue_class.push(s21_queue2);
  S21::queue<std::string> s21_queue3 = s21_queue_class.front();

  std::queue<std::string> std_queue1({"qwe", "asd", "zxc"});
  std::queue<std::string> std_queue2({"qaz", "wsx", "edc"});
  std::queue<std::queue<std::string>> std_queue_class;
  std_queue_class.push(std_queue1);
  std_queue_class.push(std_queue2);
  std::queue<std::string> std_queue3 = std_queue_class.front();

  ASSERT_EQ(s21_queue_class.size(), std_queue_class.size());

  while (!s21_queue3.empty()) {
    ASSERT_EQ(s21_queue3.front(), std_queue3.front());
    s21_queue3.pop();
    std_queue3.pop();
  }
}

TEST(Queue, insert_many_back_char_1) {
  S21::queue<char> s21_queue({'a', 'b', 'c'});
  s21_queue.insert_many_back('z', 'y', 'x');

  S21::queue<char> s21_queue2({'a', 'b', 'c', 'z', 'y', 'x'});

  ASSERT_EQ(s21_queue.size(), s21_queue2.size());

  while (!s21_queue2.empty()) {
    ASSERT_EQ(s21_queue.front(), s21_queue2.front());
    s21_queue.pop();
    s21_queue2.pop();
  }
}

// STACK

TEST(Stack, def_constructor_int) {
  S21::stack<int> s21_stack;
  std::stack<int> std_stack;
  ASSERT_EQ(s21_stack.empty(), std_stack.empty());
  ASSERT_EQ(s21_stack.size(), std_stack.size());
}

TEST(Stack, def_constructor_char) {
  S21::stack<char> s21_stack;
  std::stack<char> std_stack;
  ASSERT_EQ(s21_stack.empty(), std_stack.empty());
  ASSERT_EQ(s21_stack.size(), std_stack.size());
}

TEST(Stack, def_constructor_str) {
  S21::stack<std::string> s21_stack;
  std::stack<std::string> std_stack;
  ASSERT_EQ(s21_stack.empty(), std_stack.empty());
  ASSERT_EQ(s21_stack.size(), std_stack.size());
}

TEST(Stack, init_stack_int) {
  S21::stack<int> s21_stack({10, 20, 30});
  std::stack<int> std_stack({10, 20, 30});
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

TEST(Stack, init_stack_char) {
  S21::stack<char> s21_stack({'a', 'b', 'c'});
  std::stack<char> std_stack({'a', 'b', 'c'});
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

TEST(Stack, init_list_str) {
  S21::stack<std::string> s21_stack({"qwe", "asd", "zxc"});
  std::stack<std::string> std_stack({"qwe", "asd", "zxc"});
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

TEST(Stack, copy_constructor_int) {
  S21::stack<int> s21_stack2({10, 20, 30});
  S21::stack<int> s21_stack(s21_stack2);
  std::stack<int> std_stack2({10, 20, 30});
  std::stack<int> std_stack(std_stack2);
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

TEST(Stack, copy_constructor_char) {
  S21::stack<char> s21_stack2({'a', 'b', 'c'});
  S21::stack<char> s21_stack(s21_stack2);
  std::stack<char> std_stack2({'a', 'b', 'c'});
  std::stack<char> std_stack(std_stack2);
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

TEST(Stack, copy_constructor_str) {
  S21::stack<std::string> s21_stack2({"qwe", "asd", "zxc"});
  S21::stack<std::string> s21_stack(s21_stack2);
  std::stack<std::string> std_stack2({"qwe", "asd", "zxc"});
  std::stack<std::string> std_stack(std_stack2);
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

TEST(Stack, move_constructor_int) {
  S21::stack<int> s21_stack2({10, 20, 30});
  S21::stack<int> s21_stack = std::move(s21_stack2);
  std::stack<int> std_stack2({10, 20, 30});
  std::stack<int> std_stack = std::move(std_stack2);
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

TEST(Stack, move_constructor_char) {
  S21::stack<char> s21_stack2({'a', 'b', 'c'});
  S21::stack<char> s21_stack = std::move(s21_stack2);
  std::stack<char> std_stack2({'a', 'b', 'c'});
  std::stack<char> std_stack = std::move(std_stack2);
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

TEST(Stack, move_constructor_str) {
  S21::stack<std::string> s21_stack2({"qwe", "asd", "zxc"});
  S21::stack<std::string> s21_stack = std::move(s21_stack2);
  std::stack<std::string> std_stack2({"qwe", "asd", "zxc"});
  std::stack<std::string> std_stack = std::move(std_stack2);
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

TEST(Stack, move_operator_int) {
  S21::stack<int> s21_stack2({10, 20, 30});
  S21::stack<int> s21_stack;
  s21_stack = std::move(s21_stack2);
  std::stack<int> std_stack2({10, 20, 30});
  std::stack<int> std_stack;
  std_stack = std::move(std_stack2);
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

TEST(Stack, move_operator_char) {
  S21::stack<char> s21_stack2({'a', 'b', 'c'});
  S21::stack<char> s21_stack;
  s21_stack = std::move(s21_stack2);
  std::stack<char> std_stack2({'a', 'b', 'c'});
  std::stack<char> std_stack;
  std_stack = std::move(std_stack2);
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

TEST(Stack, move_operator_str) {
  S21::stack<std::string> s21_stack2({"qwe", "asd", "zxc"});
  S21::stack<std::string> s21_stack;
  s21_stack = std::move(s21_stack2);
  std::stack<std::string> std_stack2({"qwe", "asd", "zxc"});
  std::stack<std::string> std_stack;
  std_stack = std::move(std_stack2);
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

TEST(Stack, copy_operator_int) {
  S21::stack<int> s21_stack2({10, 20, 30});
  S21::stack<int> s21_stack({100, 200, 300});
  s21_stack = s21_stack2;
  std::stack<int> std_stack2({10, 20, 30});
  std::stack<int> std_stack({100, 200, 300});
  std_stack = std_stack2;
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

TEST(Stack, copy_operator_char) {
  S21::stack<char> s21_stack2({'a', 'b', 'c'});
  S21::stack<char> s21_stack({'x', 'y', 'z'});
  s21_stack = s21_stack2;
  std::stack<char> std_stack2({'a', 'b', 'c'});
  std::stack<char> std_stack({'x', 'y', 'z'});
  std_stack = std_stack2;
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

TEST(Stack, copy_operator_str) {
  S21::stack<std::string> s21_stack2({"qwe", "asd", "zxc"});
  S21::stack<std::string> s21_stack({"qweqwe", "asdasd", "zxczxc"});
  s21_stack = s21_stack2;
  std::stack<std::string> std_stack2({"qwe", "asd", "zxc"});
  std::stack<std::string> std_stack({"qweqwe", "asdasd", "zxczxc"});
  std_stack = std_stack2;
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

TEST(Stack, push_int) {
  S21::stack<int> s21_stack({100, 200, 300});
  s21_stack.push(400);
  s21_stack.push(500);
  s21_stack.push(600);
  std::stack<int> std_stack({100, 200, 300});
  std_stack.push(400);
  std_stack.push(500);
  std_stack.push(600);
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

TEST(Stack, push_char) {
  S21::stack<char> s21_stack({'a', 'b', 'c'});
  s21_stack.push('d');
  s21_stack.push('e');
  s21_stack.push('f');
  std::stack<char> std_stack({'a', 'b', 'c'});
  std_stack.push('d');
  std_stack.push('e');
  std_stack.push('f');
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

TEST(Stack, push_str) {
  S21::stack<std::string> s21_stack({"qwe", "asd", "zxc"});
  s21_stack.push("rty");
  s21_stack.push("fgh");
  s21_stack.push("vbn");
  std::stack<std::string> std_stack({"qwe", "asd", "zxc"});
  std_stack.push("rty");
  std_stack.push("fgh");
  std_stack.push("vbn");
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

TEST(Stack, swap_int) {
  S21::stack<int> s21_stack2({10, 20, 30});
  S21::stack<int> s21_stack({100, 200, 300});
  s21_stack.swap(s21_stack2);
  std::stack<int> std_stack2({10, 20, 30});
  std::stack<int> std_stack({100, 200, 300});
  std_stack.swap(std_stack2);
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
  ASSERT_EQ(s21_stack2.size(), std_stack2.size());
  while (!s21_stack2.empty()) {
    ASSERT_EQ(s21_stack2.top(), std_stack2.top());
    s21_stack2.pop();
    std_stack2.pop();
  }
}

TEST(Stack, swap_char) {
  S21::stack<char> s21_stack2({'a', 'b', 'c'});
  S21::stack<char> s21_stack({'x', 'y', 'z'});
  s21_stack.swap(s21_stack2);
  std::stack<char> std_stack2({'a', 'b', 'c'});
  std::stack<char> std_stack({'x', 'y', 'z'});
  std_stack.swap(std_stack2);
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
  ASSERT_EQ(s21_stack2.size(), std_stack2.size());
  while (!s21_stack2.empty()) {
    ASSERT_EQ(s21_stack2.top(), std_stack2.top());
    s21_stack2.pop();
    std_stack2.pop();
  }
}

TEST(Stack, swap_str) {
  S21::stack<std::string> s21_stack2({"qwe", "asd", "zxc"});
  S21::stack<std::string> s21_stack({"qweqwe", "asdasd", "zxczxc"});
  s21_stack.swap(s21_stack2);
  std::stack<std::string> std_stack2({"qwe", "asd", "zxc"});
  std::stack<std::string> std_stack({"qweqwe", "asdasd", "zxczxc"});
  std_stack.swap(std_stack2);
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
  ASSERT_EQ(s21_stack2.size(), std_stack2.size());
  while (!s21_stack2.empty()) {
    ASSERT_EQ(s21_stack2.top(), std_stack2.top());
    s21_stack2.pop();
    std_stack2.pop();
  }
}

TEST(Stack, swap_int_1) {
  S21::stack<int> s21_stack2({10, 20, 30, 40});
  S21::stack<int> s21_stack({100, 200, 300});
  s21_stack.swap(s21_stack2);
  std::stack<int> std_stack2({10, 20, 30, 40});
  std::stack<int> std_stack({100, 200, 300});
  std_stack.swap(std_stack2);
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
  ASSERT_EQ(s21_stack2.size(), std_stack2.size());
  while (!s21_stack2.empty()) {
    ASSERT_EQ(s21_stack2.top(), std_stack2.top());
    s21_stack2.pop();
    std_stack2.pop();
  }
}

TEST(Stack, swap_char_1) {
  S21::stack<char> s21_stack2({'a', 'b', 'c', 'e'});
  S21::stack<char> s21_stack({'x', 'y', 'z'});
  s21_stack.swap(s21_stack2);
  std::stack<char> std_stack2({'a', 'b', 'c', 'e'});
  std::stack<char> std_stack({'x', 'y', 'z'});
  std_stack.swap(std_stack2);
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
  ASSERT_EQ(s21_stack2.size(), std_stack2.size());
  while (!s21_stack2.empty()) {
    ASSERT_EQ(s21_stack2.top(), std_stack2.top());
    s21_stack2.pop();
    std_stack2.pop();
  }
}

TEST(Stack, swap_str_1) {
  S21::stack<std::string> s21_stack2({"qwe", "asd", "zxc", "qaz"});
  S21::stack<std::string> s21_stack({"qweqwe", "asdasd", "zxczxc"});
  s21_stack.swap(s21_stack2);
  std::stack<std::string> std_stack2({"qwe", "asd", "zxc", "qaz"});
  std::stack<std::string> std_stack({"qweqwe", "asdasd", "zxczxc"});
  std_stack.swap(std_stack2);
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
  ASSERT_EQ(s21_stack2.size(), std_stack2.size());
  while (!s21_stack2.empty()) {
    ASSERT_EQ(s21_stack2.top(), std_stack2.top());
    s21_stack2.pop();
    std_stack2.pop();
  }
}

TEST(Stack, swap_int_2) {
  S21::stack<int> s21_stack2({10, 20, 30});
  S21::stack<int> s21_stack({100, 200, 300, 400});
  s21_stack.swap(s21_stack2);
  std::stack<int> std_stack2({10, 20, 30});
  std::stack<int> std_stack({100, 200, 300, 400});
  std_stack.swap(std_stack2);
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
  ASSERT_EQ(s21_stack2.size(), std_stack2.size());
  while (!s21_stack2.empty()) {
    ASSERT_EQ(s21_stack2.top(), std_stack2.top());
    s21_stack2.pop();
    std_stack2.pop();
  }
}

TEST(Stack, swap_char_2) {
  S21::stack<char> s21_stack2({'a', 'b', 'c'});
  S21::stack<char> s21_stack({'x', 'y', 'z', 's'});
  s21_stack.swap(s21_stack2);
  std::stack<char> std_stack2({'a', 'b', 'c'});
  std::stack<char> std_stack({'x', 'y', 'z', 's'});
  std_stack.swap(std_stack2);
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
  ASSERT_EQ(s21_stack2.size(), std_stack2.size());
  while (!s21_stack2.empty()) {
    ASSERT_EQ(s21_stack2.top(), std_stack2.top());
    s21_stack2.pop();
    std_stack2.pop();
  }
}

TEST(Stack, swap_str_2) {
  S21::stack<std::string> s21_stack2({"qwe", "asd", "zxc"});
  S21::stack<std::string> s21_stack({"qweqwe", "asdasd", "zxczxc", "qazqaz"});
  s21_stack.swap(s21_stack2);
  std::stack<std::string> std_stack2({"qwe", "asd", "zxc"});
  std::stack<std::string> std_stack({"qweqwe", "asdasd", "zxczxc", "qazqaz"});
  std_stack.swap(std_stack2);
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty()) {
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
  ASSERT_EQ(s21_stack2.size(), std_stack2.size());
  while (!s21_stack2.empty()) {
    ASSERT_EQ(s21_stack2.top(), std_stack2.top());
    s21_stack2.pop();
    std_stack2.pop();
  }
}

TEST(Stack, class_stack_int) {
  S21::stack<int> s21_stack1;
  S21::stack<S21::stack<int>> s21_stack_class;
  s21_stack_class.push(s21_stack1);
}

TEST(Stack, class_stack_char) {
  S21::stack<char> s21_stack1;
  S21::stack<S21::stack<char>> s21_stack_class;
  s21_stack_class.push(s21_stack1);
}

TEST(Stack, class_stack_str) {
  S21::stack<std::string> s21_stack1;
  S21::stack<S21::stack<std::string>> s21_stack_class;
  s21_stack_class.push(s21_stack1);
}

TEST(Stack, class_stack_int_1) {
  S21::stack<int> s21_stack1({10, 20, 30});
  S21::stack<int> s21_stack2({100, 200, 300});
  S21::stack<S21::stack<int>> s21_stack_class;
  s21_stack_class.push(s21_stack1);
  s21_stack_class.push(s21_stack2);
  S21::stack<int> s21_stack3 = s21_stack_class.top();

  std::stack<int> std_stack1({10, 20, 30});
  std::stack<int> std_stack2({100, 200, 300});
  std::stack<std::stack<int>> std_stack_class;
  std_stack_class.push(std_stack1);
  std_stack_class.push(std_stack2);
  std::stack<int> std_stack3 = std_stack_class.top();

  ASSERT_EQ(s21_stack_class.size(), std_stack_class.size());

  while (!s21_stack3.empty()) {
    ASSERT_EQ(s21_stack3.top(), std_stack3.top());
    s21_stack3.pop();
    std_stack3.pop();
  }
}

TEST(Stack, class_stack_char_1) {
  S21::stack<char> s21_stack1({'a', 'b', 'c'});
  S21::stack<char> s21_stack2({'x', 'y', 'z'});
  S21::stack<S21::stack<char>> s21_stack_class;
  s21_stack_class.push(s21_stack1);
  s21_stack_class.push(s21_stack2);
  S21::stack<char> s21_stack3 = s21_stack_class.top();

  std::stack<char> std_stack1({'a', 'b', 'c'});
  std::stack<char> std_stack2({'x', 'y', 'z'});
  std::stack<std::stack<char>> std_stack_class;
  std_stack_class.push(std_stack1);
  std_stack_class.push(std_stack2);
  std::stack<char> std_stack3 = std_stack_class.top();

  ASSERT_EQ(s21_stack_class.size(), std_stack_class.size());

  while (!s21_stack3.empty()) {
    ASSERT_EQ(s21_stack3.top(), std_stack3.top());
    s21_stack3.pop();
    std_stack3.pop();
  }
}

TEST(Stack, class_stack_str_1) {
  S21::stack<std::string> s21_stack1({"qwe", "asd", "zxc"});
  S21::stack<std::string> s21_stack2({"qaz", "wsx", "edc"});
  S21::stack<S21::stack<std::string>> s21_stack_class;
  s21_stack_class.push(s21_stack1);
  s21_stack_class.push(s21_stack2);
  S21::stack<std::string> s21_stack3 = s21_stack_class.top();

  std::stack<std::string> std_stack1({"qwe", "asd", "zxc"});
  std::stack<std::string> std_stack2({"qaz", "wsx", "edc"});
  std::stack<std::stack<std::string>> std_stack_class;
  std_stack_class.push(std_stack1);
  std_stack_class.push(std_stack2);
  std::stack<std::string> std_stack3 = std_stack_class.top();

  ASSERT_EQ(s21_stack_class.size(), std_stack_class.size());

  while (!s21_stack3.empty()) {
    ASSERT_EQ(s21_stack3.top(), std_stack3.top());
    s21_stack3.pop();
    std_stack3.pop();
  }
}

TEST(Stack, insert_many_front_str_1) {
  S21::stack<std::string> s21_stack1({"qwe", "asd", "zxc"});
  s21_stack1.insert_many_front("qaz", "wsx", "edc");

  std::stack<std::string> s21_stack2(
      {"qwe", "asd", "zxc", "qaz", "wsx", "edc"});

  ASSERT_EQ(s21_stack1.size(), s21_stack2.size());

  while (!s21_stack2.empty()) {
    ASSERT_EQ(s21_stack1.top(), s21_stack2.top());
    s21_stack1.pop();
    s21_stack2.pop();
  }
}

// ARRAY

TEST(ARRAY, def_constructor_int) {
  s21::Array<int, 5> s21_array;
  std::array<int, 5> std_array;

  ASSERT_EQ(s21_array.empty(), std_array.empty());
  ASSERT_EQ(s21_array.size(), std_array.size());
}

TEST(ARRAY, def_constructor_char) {
  s21::Array<char, 5> s21_array;
  std::array<char, 5> std_array;

  ASSERT_EQ(s21_array.empty(), std_array.empty());
  ASSERT_EQ(s21_array.size(), std_array.size());
}

TEST(ARRAY, def_constructor_int_1) {
  s21::Array<int, 5> s21_array{};
  std::array<int, 5> std_array{};

  ASSERT_EQ(s21_array.empty(), std_array.empty());
  ASSERT_EQ(s21_array.size(), std_array.size());
}

TEST(ARRAY, def_constructor_int_2) {
  s21::Array<int, 5> s21_array{1, 2, 3};
  std::array<int, 5> std_array{1, 2, 3};

  ASSERT_EQ(s21_array.empty(), std_array.empty());
  ASSERT_EQ(s21_array.size(), std_array.size());
}

TEST(ARRAY, def_constructor_int_3) {
  s21::Array<int, 5> s21_array{1, 2, 3, 4, 5};
  std::array<int, 5> std_array{1, 2, 3, 4, 5};

  ASSERT_EQ(s21_array.empty(), std_array.empty());
  ASSERT_EQ(s21_array.size(), std_array.size());
}

// TEST(ARRAY, def_constructor_int_throw) {
//     s21::Array<int, 3> s21_array{1,2,3,4,5};
// }

TEST(ARRAY, def_copy) {
  s21::Array<int, 3> s21_array{1, 2, 3};
  s21::Array<int, 3> s21_array_copy(s21_array);
  std::array<int, 3> std_array{1, 2, 3};
  std::array<int, 3> std_array_copy(std_array);

  ASSERT_EQ(s21_array.empty(), std_array.empty());
  ASSERT_EQ(s21_array_copy.empty(), std_array_copy.empty());
  ASSERT_EQ(s21_array.size(), std_array.size());
  ASSERT_EQ(s21_array_copy.size(), std_array_copy.size());
}

TEST(ARRAY, def_move) {
  s21::Array<int, 3> s21_array{1, 2, 3};
  s21::Array<int, 3> s21_array_move(s21_array);
  std::array<int, 3> std_array{1, 2, 3};
  std::array<int, 3> std_array_move(std_array);

  ASSERT_EQ(s21_array.empty(), std_array.empty());
  ASSERT_EQ(s21_array_move.empty(), std_array_move.empty());
  ASSERT_EQ(s21_array.size(), std_array.size());
  ASSERT_EQ(s21_array_move.size(), std_array_move.size());
}

TEST(ARRAY, def_at) {
  s21::Array<int, 3> s21_array{1, 2, 3};
  std::array<int, 3> std_array{1, 2, 3};
  s21_array.at(0) = 100;
  std_array.at(0) = 100;

  ASSERT_EQ(s21_array.at(0), std_array.at(0));
  ASSERT_EQ(s21_array.at(1), std_array.at(1));
  ASSERT_EQ(s21_array.at(2), std_array.at(2));
  ASSERT_EQ(s21_array.empty(), std_array.empty());
  ASSERT_EQ(s21_array.size(), std_array.size());
}

TEST(ARRAY, def_operator) {
  s21::Array<int, 3> s21_array{1, 2, 3};
  std::array<int, 3> std_array{1, 2, 3};
  s21_array[0] = 100;
  std_array[0] = 100;

  ASSERT_EQ(s21_array.at(0), std_array.at(0));
  ASSERT_EQ(s21_array.at(1), std_array.at(1));
  ASSERT_EQ(s21_array.at(2), std_array.at(2));
  ASSERT_EQ(s21_array.empty(), std_array.empty());
  ASSERT_EQ(s21_array.size(), std_array.size());
}

TEST(ARRAY, def_throw) {
  s21::Array<int, 3> s21_array{1, 2, 3};
  std::array<int, 3> std_array{1, 2, 3};
  s21_array[0] = 100;
  std_array[0] = 100;

  ASSERT_ANY_THROW(s21_array.at(5));
  ASSERT_ANY_THROW(std_array.at(5));
}

TEST(ARRAY, def_front) {
  s21::Array<int, 3> s21_array{1, 2, 3};
  std::array<int, 3> std_array{1, 2, 3};

  ASSERT_EQ(s21_array.front(), std_array.front());
}

TEST(ARRAY, def_back) {
  s21::Array<int, 3> s21_array{1, 2, 3};
  std::array<int, 3> std_array{1, 2, 3};

  ASSERT_EQ(s21_array.back(), std_array.back());
}

TEST(ARRAY, def_data) {
  s21::Array<int, 3> s21_array{1, 2, 3};
  std::array<int, 3> std_array{1, 2, 3};
  int *dataPtrS21 = s21_array.data();
  int *dataPtrStd = std_array.data();

  ASSERT_EQ(dataPtrS21[0], dataPtrStd[0]);
  ASSERT_EQ(dataPtrS21[1], dataPtrStd[1]);
  ASSERT_EQ(dataPtrS21[2], dataPtrStd[2]);
  ASSERT_EQ(s21_array.at(0), std_array.at(0));
  ASSERT_EQ(s21_array.at(1), std_array.at(1));
  ASSERT_EQ(s21_array.at(2), std_array.at(2));

  ASSERT_EQ(s21_array.empty(), std_array.empty());
  ASSERT_EQ(s21_array.size(), std_array.size());
}

TEST(ARRAY, def_begin) {
  s21::Array<int, 3> s21_array{1, 2, 3};
  std::array<int, 3> std_array{1, 2, 3};
  int *it1S21 = s21_array.begin() + 1;
  int *it1Std = std_array.begin() + 1;

  ASSERT_EQ(*it1S21, *it1Std);
  ASSERT_EQ(s21_array.at(0), std_array.at(0));
  ASSERT_EQ(s21_array.at(1), std_array.at(1));
  ASSERT_EQ(s21_array.at(2), std_array.at(2));
}

TEST(ARRAY, def_end) {
  s21::Array<int, 3> s21_array{1, 2, 3};
  std::array<int, 3> std_array{1, 2, 3};
  int *it1S21 = s21_array.end() - 1;
  int *it1Std = std_array.end() - 1;

  ASSERT_EQ(*it1S21, *it1Std);
  ASSERT_EQ(s21_array.at(0), std_array.at(0));
  ASSERT_EQ(s21_array.at(1), std_array.at(1));
  ASSERT_EQ(s21_array.at(2), std_array.at(2));
}

TEST(ARRAY, def_empty) {
  s21::Array<int, 3> s21_array{1, 2, 3};
  std::array<int, 3> std_array{1, 2, 3};

  ASSERT_EQ(s21_array.empty(), std_array.empty());
}

TEST(ARRAY, def_empty_1) {
  s21::Array<int, 0> s21_array{};
  std::array<int, 0> std_array{};

  ASSERT_EQ(s21_array.empty(), std_array.empty());
}

TEST(ARRAY, def_size) {
  s21::Array<int, 3> s21_array{1, 2, 3};
  std::array<int, 3> std_array{1, 2, 3};

  ASSERT_EQ(s21_array.size(), std_array.size());
}

TEST(ARRAY, def_max_size) {
  s21::Array<int, 3> s21_array{1, 2, 3};
  std::array<int, 3> std_array{1, 2, 3};

  ASSERT_EQ(s21_array.max_size(), std_array.max_size());
}

TEST(ARRAY, def_swap) {
  s21::Array<int, 3> s21_array{1, 2, 3};
  s21::Array<int, 3> s21_array_swap{4, 5, 6};
  std::array<int, 3> std_array{1, 2, 3};
  std::array<int, 3> std_array_swap{4, 5, 6};
  s21_array_swap.swap(s21_array);
  std_array_swap.swap(std_array);

  ASSERT_EQ(s21_array.at(0), std_array.at(0));
  ASSERT_EQ(s21_array.at(1), std_array.at(1));
  ASSERT_EQ(s21_array.at(2), std_array.at(2));

  ASSERT_EQ(s21_array_swap.at(0), std_array_swap.at(0));
  ASSERT_EQ(s21_array_swap.at(1), std_array_swap.at(1));
  ASSERT_EQ(s21_array_swap.at(2), std_array_swap.at(2));

  ASSERT_EQ(s21_array.size(), std_array.size());
  ASSERT_EQ(s21_array_swap.size(), std_array_swap.size());
  ASSERT_EQ(s21_array.empty(), std_array.empty());
  ASSERT_EQ(s21_array_swap.empty(), std_array_swap.empty());
}

TEST(ARRAY, def_fill) {
  s21::Array<char, 3> s21_array{'1', '2', '3'};
  std::array<char, 3> std_array{'1', '2', '3'};
  s21_array.fill('$');
  std_array.fill('$');

  ASSERT_EQ(s21_array.at(0), std_array.at(0));
  ASSERT_EQ(s21_array.at(1), std_array.at(1));
  ASSERT_EQ(s21_array.at(2), std_array.at(2));

  ASSERT_EQ(s21_array.size(), std_array.size());
  ASSERT_EQ(s21_array.empty(), std_array.empty());
}

TEST(ARRAY, def_fill_1) {
  s21::Array<float, 3> s21_array{1.5, 2.5, 3.5};
  std::array<float, 3> std_array{1.5, 2.5, 3.5};
  s21_array.fill(10.5);
  std_array.fill(10.5);

  ASSERT_EQ(s21_array.at(0), std_array.at(0));
  ASSERT_EQ(s21_array.at(1), std_array.at(1));
  ASSERT_EQ(s21_array.at(2), std_array.at(2));

  ASSERT_EQ(s21_array.size(), std_array.size());
  ASSERT_EQ(s21_array.empty(), std_array.empty());
}

TEST(ARRAY, def_fill_2) {
  s21::Array<int, 3> s21_array{1, 2, 3};
  std::array<int, 3> std_array{1, 2, 3};
  s21_array.fill(100);
  std_array.fill(100);

  ASSERT_EQ(s21_array.at(0), std_array.at(0));
  ASSERT_EQ(s21_array.at(1), std_array.at(1));
  ASSERT_EQ(s21_array.at(2), std_array.at(2));

  ASSERT_EQ(s21_array.size(), std_array.size());
  ASSERT_EQ(s21_array.empty(), std_array.empty());
}

// SET

bool setsEqual(s21::set<int> S1, std::set<int> S2) {
  if (S1.size() != S2.size()) return false;
  auto it_S1 = S1.begin();
  auto it_S2 = S2.begin();
  for (; it_S2 != S2.end(); ++it_S1, ++it_S2) {
    if (*it_S1 != *it_S2) return false;
  }
  return true;
}

TEST(CONSTRUCTORS, SET_DEFAULT_CONSTRUCTOR) {
  s21::set<int> S1;
  std::set<int> S2;
  ASSERT_EQ(setsEqual(S1, S2), true);
}

TEST(CONSTRUCTORS, SET_LIST_CONSTRUCTOR) {
  s21::set<int> S1 = {1, 2, 3};
  std::set<int> S2 = {1, 2, 3};
  ASSERT_EQ(setsEqual(S1, S2), true);
}

TEST(CONSTRUCTORS, SET_COPY_CONSTRUCTOR) {
  s21::set<int> S1 = {1, 2, 3};
  s21::set<int> S2(S1);
  std::set<int> S3 = {1, 2, 3};
  std::set<int> S4(S3);
  ASSERT_EQ(setsEqual(S2, S4), true);
  ASSERT_EQ(setsEqual(S1, S3), true);
}

TEST(CONSTRUCTORS, SET_MOVE_CONSTRUCTOR) {
  s21::set<int> S1 = {1, 2, 3};
  s21::set<int> S2(std::move(S1));
  std::set<int> S3 = {1, 2, 3};
  std::set<int> S4(std::move(S3));
  ASSERT_EQ(setsEqual(S2, S4), true);
  ASSERT_EQ(setsEqual(S1, S3), true);
}

TEST(SET, UNIQUE_TEST) {
  s21::set<int> S1 = {1, 1, 1};
  std::set<int> S2 = {1, 1, 1};
  ASSERT_EQ(setsEqual(S1, S2), true);
  S1.insert(1);
  S2.insert(1);
  ASSERT_EQ(setsEqual(S1, S2), true);
}

TEST(METHOD_SIZE, SET_SIZE_DEFAULT_CONSTRUCTOR) {
  s21::set<int> S1;
  std::set<int> S2;
  ASSERT_EQ(S1.size(), S2.size());
}

TEST(METHOD_SIZE, SET_SIZE_LIST_CONSTRUCTOR) {
  s21::set<int> S1 = {1, 2, 3};
  std::set<int> S2 = {1, 2, 3};
  ASSERT_EQ(S1.size(), S2.size());
}

TEST(METHOD_SIZE, SET_SIZE_COPY_CONSTRUCTOR) {
  s21::set<int> S1 = {1, 2, 3};
  s21::set<int> S2(S1);
  std::set<int> S3 = {1, 2, 3};
  std::set<int> S4(S3);
  ASSERT_EQ(S1.size(), S3.size());
  ASSERT_EQ(S2.size(), S4.size());
}

TEST(METHOD_SIZE, SET_SIZE_MOVE_CONSTRUCTOR) {
  s21::set<int> S1 = {1, 2, 3};
  s21::set<int> S2(std::move(S1));
  std::set<int> S3 = {1, 2, 3};
  std::set<int> S4(std::move(S3));
  ASSERT_EQ(S1.size(), S3.size());
  ASSERT_EQ(S2.size(), S4.size());
}

TEST(METHOD_MAX_SIZE, SET_MAX_SIZE) {
  s21::set<int> S1 = {1, 2, 3};
  std::set<int> S2 = {1, 2, 3};
  EXPECT_NEAR(S1.max_size() / S2.max_size(), 1, 1);
}

TEST(METHOD_EMPTY, SET_EMPTY_DEFAULT_CONSTRUCTOR) {
  s21::set<int> S1;
  std::set<int> S2;
  ASSERT_EQ(S1.empty(), S2.empty());
}

TEST(METHOD_EMPTY, SET_EMPTY_LIST_CONSTRUCTOR) {
  s21::set<int> S1 = {1, 2, 3};
  std::set<int> S2 = {1, 2, 3};
  ASSERT_EQ(S1.empty(), S2.empty());
  s21::set<int> S3 = {};
  std::set<int> S4 = {};
  ASSERT_EQ(S3.empty(), S4.empty());
  s21::set<int> S5 = {1};
  std::set<int> S6 = {1};
  ASSERT_EQ(S5.empty(), S6.empty());
}

TEST(METHOD_EMPTY, SET_EMPTY_COPY_CONSTRUCTOR) {
  s21::set<int> S1 = {1, 2, 3};
  s21::set<int> S2(S1);
  std::set<int> S3 = {1, 2, 3};
  std::set<int> S4(S3);
  ASSERT_EQ(S1.empty(), S3.empty());
  ASSERT_EQ(S2.empty(), S4.empty());
  s21::set<int> S5;
  s21::set<int> S6(S5);
  std::set<int> S7;
  std::set<int> S8(S7);
  ASSERT_EQ(S5.empty(), S7.empty());
  ASSERT_EQ(S6.empty(), S8.empty());
}

TEST(METHOD_EMPTY, SET_EMPTY_MOVE_CONSTRUCTOR) {
  s21::set<int> S1 = {1, 2, 3};
  s21::set<int> S2(std::move(S1));
  std::set<int> S3 = {1, 2, 3};
  std::set<int> S4(std::move(S3));
  ASSERT_EQ(S1.empty(), S3.empty());
  ASSERT_EQ(S2.empty(), S4.empty());
  s21::set<int> S5;
  s21::set<int> S6(std::move(S5));
  std::set<int> S7;
  std::set<int> S8(std::move(S7));
  ASSERT_EQ(S5.empty(), S7.empty());
  ASSERT_EQ(S6.empty(), S8.empty());
}

TEST(METHOD_SWAP, SET_SWAP_ONE_LIST_EMPTY1) {
  s21::set<int> S1 = {1, 2, 3};
  s21::set<int> S2 = {};
  std::set<int> S3 = {1, 2, 3};
  std::set<int> S4 = {};
  S1.swap(S2);
  S3.swap(S4);
  ASSERT_EQ(setsEqual(S1, S3), true);
  ASSERT_EQ(setsEqual(S2, S4), true);
}

TEST(METHOD_SWAP, SET_SWAP_ONE_LIST_EMPTY2) {
  s21::set<int> S1 = {};
  s21::set<int> S2 = {1, 2, 3};
  std::set<int> S3 = {};
  std::set<int> S4 = {1, 2, 3};
  S1.swap(S2);
  S3.swap(S4);
  ASSERT_EQ(setsEqual(S1, S3), true);
  ASSERT_EQ(setsEqual(S2, S4), true);
}

TEST(METHOD_SWAP, SET_SWAP_NUMBER_OF_ELEMENTS) {
  s21::set<int> S1 = {1, 2, 3};
  s21::set<int> S2 = {4, 5, 6};
  std::set<int> S3 = {1, 2, 3};
  std::set<int> S4 = {4, 5, 6};
  S1.swap(S2);
  S3.swap(S4);
  ASSERT_EQ(setsEqual(S1, S3), true);
  ASSERT_EQ(setsEqual(S2, S4), true);
}

TEST(METHOD_SWAP, SET_SWAP_DIFFERENT_NUMBER_OF_ELEMENTS1) {
  s21::set<int> S1 = {1, 2, 3, 4, 5};
  s21::set<int> S2 = {4, 5, 6};
  std::set<int> S3 = {1, 2, 3, 4, 5};
  std::set<int> S4 = {4, 5, 6};
  S1.swap(S2);
  S3.swap(S4);
  ASSERT_EQ(setsEqual(S1, S3), true);
  ASSERT_EQ(setsEqual(S2, S4), true);
}

TEST(METHOD_SWAP, SET_SWAP_DIFFERENT_NUMBER_OF_ELEMENTS2) {
  s21::set<int> S1 = {1, 2, 3};
  s21::set<int> S2 = {4, 5, 6, 128, 40};
  std::set<int> S3 = {1, 2, 3};
  std::set<int> S4 = {4, 5, 6, 128, 40};
  S1.swap(S2);
  S3.swap(S4);
  ASSERT_EQ(setsEqual(S1, S3), true);
  ASSERT_EQ(setsEqual(S2, S4), true);
}

TEST(METHOD_CLEAR, SET_CLEAR) {
  s21::set<int> S1 = {1, 2, 3};
  std::set<int> S2 = {1, 2, 3};
  S1.clear();
  S2.clear();
  ASSERT_EQ(setsEqual(S1, S2), true);
}

TEST(METHOD_INSERT, SET_INSERT_EXISTING_ELEMENT) {
  s21::set<int> S1 = {1, 2, 3};
  std::set<int> S2 = {1, 2, 3};
  S1.insert(3);
  S2.insert(3);
  ASSERT_EQ(setsEqual(S1, S2), true);
}

TEST(METHOD_INSERT, SET_INSERT_0_ELEMENTS) {
  s21::set<int> S1 = {};
  std::set<int> S2 = {};
  S1.insert(3);
  S2.insert(3);
  ASSERT_EQ(setsEqual(S1, S2), true);
}

TEST(METHOD_INSERT, SET_INSERT_MIDDLE_ELEMENT) {
  s21::set<int> S1 = {1, 2, 4};
  std::set<int> S2 = {1, 2, 4};
  S1.insert(3);
  S2.insert(3);
  ASSERT_EQ(setsEqual(S1, S2), true);
}

TEST(METHOD_FIND, SET_FIND_EXISTING_ELEMENT) {
  s21::set<int> S1 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  std::set<int> S2 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  auto it_S1 = S1.find(75);
  auto it_S2 = S2.find(75);
  ASSERT_EQ(*it_S1, *it_S2);
}

TEST(METHOD_FIND, SET_FIND_NOT_EXISTING_ELEMENT1) {
  s21::set<int> S1 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  auto it_S1 = S1.find(43);
  ASSERT_EQ(*it_S1, 0);
}

TEST(METHOD_FIND, SET_FIND_NOT_EXISTING_ELEMENT2) {
  s21::set<int> S1 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  auto it_S1 = S1.find(0);
  ASSERT_EQ(*it_S1, 0);
}

TEST(METHOD_FIND, SET_FIND_NOT_EXISTING_ELEMENT3) {
  s21::set<int> S1 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  auto it_S1 = S1.find(100);
  ASSERT_EQ(*it_S1, 0);
}

TEST(SET, SET_OPERATOR_EQUAL_COPY_NOT_EMPTY_LIST) {
  s21::set<int> S1 = {50, 25, 75, 10};
  s21::set<int> S2 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  std::set<int> S3 = {50, 25, 75, 10};
  std::set<int> S4 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  S1 = S2;
  S3 = S4;
  ASSERT_EQ(setsEqual(S1, S3), true);
  ASSERT_EQ(setsEqual(S2, S4), true);
}

TEST(SET, SET_OPERATOR_EQUAL_COPY_EMPTY_LIST) {
  s21::set<int> S1 = {50, 25, 75, 10};
  s21::set<int> S2 = {};
  std::set<int> S3 = {50, 25, 75, 10};
  std::set<int> S4 = {};
  S1 = S2;
  S3 = S4;
  ASSERT_EQ(setsEqual(S1, S3), true);
  ASSERT_EQ(setsEqual(S2, S4), true);
}

TEST(SET, SET_OPERATOR_EQUAL_COPY_SAME_SET) {
  s21::set<int> S1 = {50, 25, 75, 10};
  std::set<int> S2 = {50, 25, 75, 10};
  S1 = S1;
  S2 = S2;
  ASSERT_EQ(setsEqual(S1, S2), true);
}

TEST(SET, SET_OPERATOR_EQUAL_MOVE_NOT_EMPTY_LIST) {
  s21::set<int> S1 = {50, 25, 75, 10};
  s21::set<int> S2 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  std::set<int> S3 = {50, 25, 75, 10};
  std::set<int> S4 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  S1 = std::move(S2);
  S3 = std::move(S4);
  ASSERT_EQ(setsEqual(S1, S3), true);
  ASSERT_EQ(setsEqual(S2, S4), true);
}

TEST(SET, SET_OPERATOR_EQUAL_MOVE_EMPTY_LIST) {
  s21::set<int> S1 = {50, 25, 75, 10};
  s21::set<int> S2 = {};
  std::set<int> S3 = {50, 25, 75, 10};
  std::set<int> S4 = {};
  S1 = std::move(S2);
  S3 = std::move(S4);
  ASSERT_EQ(setsEqual(S1, S3), true);
  ASSERT_EQ(setsEqual(S2, S4), true);
}

TEST(ITERATORS, SET_PLUS_PLUS_OPERATOR) {
  s21::set<int> S1 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  std::set<int> S2 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  ASSERT_EQ(*(++S1.begin()), *(++S2.begin()));
}

TEST(ITERATORS, SET_MINUS_MINUS_OPERATOR1) {
  s21::set<int> S1 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  std::set<int> S2 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  auto it_S1 = ++S1.begin();
  auto it_S2 = ++S2.begin();
  ASSERT_EQ(*(--it_S1), *(--it_S2));
  ASSERT_EQ(*it_S1, *it_S2);
}

TEST(ITERATORS, SET_OPERATOR_PLUS_PLUS) {
  s21::set<int> S1 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  std::set<int> S2 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  auto it_S1 = S1.begin();
  auto it_S2 = S2.begin();
  ASSERT_EQ(*(it_S1++), *(it_S2++));
  ASSERT_EQ(*it_S1, *it_S2);
}

TEST(ITERATORS, SET_OPERATOR_MINUS_MINUS) {
  s21::set<int> S1 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  std::set<int> S2 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  auto it_S1 = ++S1.begin();
  auto it_S2 = ++S2.begin();
  ASSERT_EQ(*(it_S1--), *(it_S2--));
  ASSERT_EQ(*it_S1, *it_S2);
}

TEST(ITERATORS, SET_DEREFERENCE_OPERATOR_EXISTING_LIST_1) {
  s21::set<int> S1 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  std::set<int> S2 = {50, 25, 75, 10, 40, 5,  15, 35,
                      45, 80, 60, 70, 55, 90, 78};
  ASSERT_EQ(*S1.begin(), *S2.begin());
}

TEST(ITERATORS, SET_DEREFERENCE_OPERATOR_NOT_EXISTING_LIST) {
  try {
    s21::set<int>::iterator it_S1;
    *it_S1;
  } catch (const std::exception &e) {
    ASSERT_STREQ(e.what(), "Invalid index");
  }
}

TEST(ITERATORS, SET_NOT_EQUAL_OPERATOR) {
  s21::set<int> S1 = {1, 2, 3};
  std::set<int> S2 = {1, 2, 3};
  ASSERT_EQ(S1.begin() != S1.begin(), S2.begin() != S2.begin());
}

TEST(ITERATORS, SET_EQUAL_OPERATOR) {
  s21::set<int> S1 = {1, 2, 3};
  std::set<int> S2 = {1, 2, 3};
  ASSERT_EQ(S1.begin() == S1.begin(), S2.begin() == S2.begin());
}

// map

bool mapsEqual(s21::map<int, char> M1, std::map<int, char> M2) {
  if (M1.size() != M2.size()) return false;
  s21::map<int, char>::iterator it_M1 = M1.begin();
  std::map<int, char>::iterator it_M2 = M2.begin();
  for (; it_M2 != M2.end(); ++it_M1, ++it_M2) {
    if (*it_M1 != *it_M2) return false;
  }
  return true;
}

void printM1(s21::map<int, char> M1) {
  s21::map<int, char>::iterator it_M1 = M1.begin();
  std::cout << std::endl;
  for (; it_M1 != M1.end(); ++it_M1) {
    std::cout << (*it_M1).first << " " << (*it_M1).second << std::endl;
  }
  std::cout << std::endl;
}

void printM2(std::map<int, char> M2) {
  std::map<int, char>::iterator it_M2 = M2.begin();
  std::cout << std::endl;
  for (; it_M2 != M2.end(); ++it_M2) {
    std::cout << (*it_M2).first << " " << (*it_M2).second << std::endl;
  }
  std::cout << std::endl;
}

TEST(MAP_CONSTRUCTORS, MAP_DEFAULT_CONSTRUCTOR) {
  s21::map<int, char> M1;
  std::map<int, char> M2;
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(MAP_CONSTRUCTORS, MAP_LIST_CONSTRUCTOR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(MAP_CONSTRUCTORS, MAP_COPY_CONSTRUCTOR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> M2(M1);
  std::map<int, char> M3 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M4(M3);
  ASSERT_EQ(mapsEqual(M2, M4), true);
  ASSERT_EQ(mapsEqual(M1, M3), true);
}

TEST(MAP_CONSTRUCTORS, MAP_MOVE_CONSTRUCTOR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> M2(std::move(M1));
  std::map<int, char> M3 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M4(std::move(M3));
  ASSERT_EQ(mapsEqual(M2, M4), true);
  ASSERT_EQ(mapsEqual(M1, M3), true);
}

TEST(MAP_METHOD_AT, MAP_AT_IN_BOUNDS1) {
  s21::map<int, char> M1 = {{3, 'a'}, {2, 'b'}, {1, 'c'}};
  std::map<int, char> M2 = {{3, 'a'}, {2, 'b'}, {1, 'c'}};
  ASSERT_EQ(M1.at(2), M2.at(2));
}

TEST(MAP_METHOD_AT, MAP_AT_IN_BOUNDS2) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  ASSERT_EQ(M1.at(2), M2.at(2));
}

TEST(MAP_METHOD_AT, MAP_AT_OUT_OF_BOUNDS) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  ASSERT_THROW(M2.at(36), std::out_of_range);
  ASSERT_THROW(M1.at(36), std::out_of_range);
}

TEST(MAP_METHOD_AT, MAP_AT_ENTERING_VALUE) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  M1.at(2) = 'q';
  M2.at(2) = 'q';
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(MAP_METHOD_EMPTY, MAP_EMPTY_DEFAULT_CONSTRUCTOR) {
  s21::map<int, char> M1;
  std::map<int, char> M2;
  ASSERT_EQ(M1.empty(), M2.empty());
}

TEST(MAP_METHOD_EMPTY, MAP_EMPTY_LIST_CONSTRUCTOR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  ASSERT_EQ(M1.empty(), M2.empty());
  s21::map<int, char> M3 = {};
  std::map<int, char> M4 = {};
  ASSERT_EQ(M3.empty(), M4.empty());
  s21::map<int, char> M5 = {{1, 'a'}};
  std::map<int, char> M6 = {{1, 'a'}};
  ASSERT_EQ(M5.empty(), M6.empty());
}

TEST(MAP_METHOD_EMPTY, MAP_EMPTY_COPY_CONSTRUCTOR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> M2(M1);
  std::map<int, char> M3 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M4(M3);
  ASSERT_EQ(M1.empty(), M3.empty());
  ASSERT_EQ(M2.empty(), M4.empty());
  s21::map<int, char> M5;
  s21::map<int, char> M6(M5);
  std::map<int, char> M7;
  std::map<int, char> M8(M7);
  ASSERT_EQ(M5.empty(), M7.empty());
  ASSERT_EQ(M6.empty(), M8.empty());
}

TEST(MAP_METHOD_EMPTY, MAP_EMPTY_MOVE_CONSTRUCTOR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> M2(std::move(M1));
  std::map<int, char> M3 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M4(std::move(M3));
  ASSERT_EQ(M1.empty(), M3.empty());
  ASSERT_EQ(M2.empty(), M4.empty());
  s21::map<int, char> M5;
  s21::map<int, char> M6(std::move(M5));
  std::map<int, char> M7;
  std::map<int, char> M8(std::move(M7));
  ASSERT_EQ(M5.empty(), M7.empty());
  ASSERT_EQ(M6.empty(), M8.empty());
}

TEST(MAP_METHOD_SIZE, MAP_SIZE_DEFAULT_CONSTRUCTOR) {
  s21::map<int, char> M1;
  std::map<int, char> M2;
  ASSERT_EQ(M1.size(), M2.size());
}

TEST(MAP_METHOD_SIZE, MAP_SIZE_LIST_CONSTRUCTOR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  ASSERT_EQ(M1.size(), M2.size());
}

TEST(MAP_METHOD_SIZE, MAP_SIZE_COPY_CONSTRUCTOR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> M2(M1);
  std::map<int, char> M3 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M4(M3);
  ASSERT_EQ(M1.size(), M3.size());
  ASSERT_EQ(M2.size(), M4.size());
}

TEST(MAP_METHOD_SIZE, MAP_SIZE_MOVE_CONSTRUCTOR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> M2(std::move(M1));
  std::map<int, char> M3 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M4(std::move(M3));
  ASSERT_EQ(M1.size(), M3.size());
  ASSERT_EQ(M2.size(), M4.size());
}

TEST(MAP_METHOD_MAX_SIZE, MAP_MAX_SIZE) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  EXPECT_NEAR(M1.max_size() / M2.max_size(), 1, 1);
}

TEST(MAP_METHOD_CLEAR, MAP_CLEAR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  M1.clear();
  M2.clear();
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(MAP_METHOD_INSERT, MAP_INSERT_BY_PAIR_EXISTING_ELEMENT) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  M1.insert(std::pair<int, char>(3, 'c'));
  M2.insert(std::pair<int, char>(3, 'c'));
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(MAP_METHOD_INSERT, MAP_INSERT_BY_VALUE_SEPARATED_EXISTING_ELEMENT) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  M1.insert(3, 'c');
  M2.insert(std::pair<int, char>(3, 'c'));
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(MAP_METHOD_INSERT, MAP_INSERT_0_ELEMENTS) {
  s21::map<int, char> M1 = {};
  std::map<int, char> M2 = {};
  M1.insert(std::pair<int, char>(3, 'c'));
  M2.insert(std::pair<int, char>(3, 'c'));
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(MAP_METHOD_INSERT, MAP_INSERT_MIDDLE_ELEMENT) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {4, 'd'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {4, 'd'}};
  M1.insert(std::pair<int, char>(3, 'c'));
  M2.insert(std::pair<int, char>(3, 'c'));
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(MAP_METHOD_INSERT_OR_ASSIGN, MAP_INSERT_MIDDLE_ELEMENT_DOES_NOT_CONTAIN) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {4, 'd'}};
  auto res = M1.insert_or_assign(3, 'c');

  ASSERT_EQ(res.second, true);
}

TEST(MAP_METHOD_INSERT_OR_ASSIGN, MAP_INSERT_MIDDLE_ELEMENT_CONTAINS) {
  s21::map<int, char> M1 = {{1, 'a'}, {3, 'c'}, {4, 'd'}};
  auto res = M1.insert_or_assign(3, 'c');
  ASSERT_EQ(res.second, false);
}

TEST(MAP_METHOD_SWAP, MAP_SWAP_ONE_LIST_EMPTY1) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> M2 = {};
  std::map<int, char> M3 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M4 = {};
  M1.swap(M2);
  M3.swap(M4);
  ASSERT_EQ(mapsEqual(M1, M3), true);
  ASSERT_EQ(mapsEqual(M2, M4), true);
}

TEST(MAP_METHOD_SWAP, MAP_SWAP_ONE_LIST_EMPTY2) {
  s21::map<int, char> M1 = {};
  s21::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M3 = {};
  std::map<int, char> M4 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  M1.swap(M2);
  M3.swap(M4);
  ASSERT_EQ(mapsEqual(M1, M3), true);
  ASSERT_EQ(mapsEqual(M2, M4), true);
}

TEST(MAP_METHOD_SWAP, MAP_SWAP_NUMBER_OF_ELEMENTS) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> M2 = {{4, 'd'}, {5, 'e'}, {6, 'f'}};
  std::map<int, char> M3 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M4 = {{4, 'd'}, {5, 'e'}, {6, 'f'}};
  M1.swap(M2);
  M3.swap(M4);
  ASSERT_EQ(mapsEqual(M1, M3), true);
  ASSERT_EQ(mapsEqual(M2, M4), true);
}

TEST(MAP_METHOD_MERGE, MAP_MERGE_DIFFERENT_ELEMENTS) {
  s21::map<int, char> M1 = {{1, 'a'}, {3, 'c'}, {5, 'e'}};
  s21::map<int, char> M2 = {{2, 'b'}, {4, 'd'}, {6, 'f'}};
  std::map<int, char> M3 = {{1, 'a'}, {3, 'c'}, {5, 'e'},
                            {2, 'b'}, {4, 'd'}, {6, 'f'}};
  std::map<int, char> empty;
  M1.merge(M2);
  ASSERT_EQ(mapsEqual(M1, M3), true);
  ASSERT_EQ(mapsEqual(M2, empty), true);
}

TEST(MAP_OPERATOR_OVERLOADS, MAP_OPERATOR_ASSIGNMENT_COPY_SAME_SET) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  M1 = M1;
  M2 = M2;
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(MAP_OPERATOR_OVERLOADS, MAP_OPERATOR_ASSIGNMENT_COPY) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  s21::map<int, char> M2 = {{10, 'q'}, {20, 'w'}, {30, 'e'}, {40, 'r'}};
  std::map<int, char> M3 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M4 = {{10, 'q'}, {20, 'w'}, {30, 'e'}, {40, 'r'}};
  M1 = M2;
  M3 = M4;
  ASSERT_EQ(mapsEqual(M1, M3), true);
  ASSERT_EQ(mapsEqual(M2, M4), true);
}

TEST(MAP_OPERATOR_OVERLOADS, MAP_OPERATOR_ACCESS) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  ASSERT_EQ(M1[75], M2[75]);
}

TEST(MAP_OPERATOR_OVERLOADS, MAP_OPERATOR_INSERT) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(MAP_ITERATORS, MAP_PLUS_PLUS_OPERATOR) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  s21::map<int, char>::iterator it_M1 = ++M1.begin();
  std::map<int, char>::iterator it_M2 = ++M2.begin();
  ASSERT_EQ((*it_M1).first, (*it_M2).first);
  ASSERT_EQ((*it_M1).second, (*it_M2).second);
}

TEST(MAP_ITERATORS, MAP_OPERATOR_PLUS_PLUS) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  s21::map<int, char>::iterator it_M1 = M1.begin();
  std::map<int, char>::iterator it_M2 = M2.begin();
  it_M1++;
  it_M2++;
  ASSERT_EQ((*it_M1).first, (*it_M2).first);
  ASSERT_EQ((*it_M1).second, (*it_M2).second);
}

TEST(MAP_ITERATORS, MAP_DEREFERENCE_OPERATOR_EXISTING_LIST) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  ASSERT_EQ((*(M1.begin())).first, ((*M2.begin())).first);
  ASSERT_EQ((*(M1.begin())).second, ((*M2.begin())).second);
}

TEST(MAP_ITERATORS, MAP_DEREFERENCE_OPERATOR_NOT_EXISTING_LIST) {
  try {
    s21::map<int, char>::iterator it_S1;
    *it_S1;
  } catch (const std::exception &e) {
    ASSERT_STREQ(e.what(), "Invalid index");
  }
}

TEST(MAP_ITERATORS, MAP_NOT_EQUAL_OPERATOR) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  ASSERT_EQ(M1.begin() != M1.begin(), M2.begin() != M2.begin());
}

TEST(MAP_ITERATORS, MAP_EQUAL_OPERATOR) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  ASSERT_EQ(M1.begin() == M1.begin(), M2.begin() == M2.begin());
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int result = RUN_ALL_TESTS();
  free(__cxxabiv1::__cxa_get_globals());
  return result;
}