#include <gtest/gtest.h>

#include <iostream>

#include "../3DViewer/model/model.h"

std::string GetWorkingDirectory() {
  char current_working_directory[1024];
  getcwd(current_working_directory, sizeof(current_working_directory));
  return std::string(current_working_directory);
}

TEST(test1, not_file) {
  std::string current_directory = GetWorkingDirectory();
  std::string file_path = current_directory + "/nofile.txt";
  int error = 0;
  s21::Model model;
  model.StartParsingFile(file_path, &error);
  EXPECT_TRUE(error);
}

TEST(test_, existing_file) {
  std::string current_directory = GetWorkingDirectory();
  std::string file_path = current_directory + "/tests/cube.txt";
  int error = 0;
  s21::Model model;
  model.StartParsingFile(file_path, &error);
  EXPECT_FALSE(error);
}

TEST(test3, GetVertexes) {
  std::string current_directory = GetWorkingDirectory();
  std::string file_path = current_directory + "/tests/cube.txt";
  int error = 0;
  s21::Model model;
  model.StartParsingFile(file_path, &error);
  const std::vector<double>& vertexes = model.GetVertexes();
  EXPECT_TRUE(vertexes[0] == -0.5);
  EXPECT_TRUE(vertexes[1] == -0.5);
  EXPECT_TRUE(vertexes[2] == 0.5);
}

TEST(test4, GetFacets) {
  std::string current_directory = GetWorkingDirectory();
  std::string file_path = current_directory + "/tests/cube.txt";
  int error = 0;
  s21::Model model;
  model.StartParsingFile(file_path, &error);
  const std::vector<int>& facets = model.GetFacets();
  EXPECT_TRUE(facets[0] == 0);
  EXPECT_TRUE(facets[1] == 1);
  EXPECT_TRUE(facets[2] == 1);
  EXPECT_TRUE(facets[3] == 3);
  EXPECT_TRUE(facets[4] == 3);
  EXPECT_TRUE(facets[5] == 0);
}

TEST(test5, getVerticesAmount) {
  std::string current_directory = GetWorkingDirectory();
  std::string file_path = current_directory + "/tests/cube.txt";
  int error = 0;
  s21::Model model;
  model.StartParsingFile(file_path, &error);
  int verticesAmount = model.GetVerticesAmount();
  EXPECT_TRUE(verticesAmount == 8);
}

TEST(test6, GetFacetsAmount) {
  std::string current_directory = GetWorkingDirectory();
  std::string file_path = current_directory + "/tests/cube.txt";
  int error = 0;
  s21::Model model;
  model.StartParsingFile(file_path, &error);
  int facetsAmount = model.GetFacetsAmount();
  EXPECT_TRUE(facetsAmount == 36);
}

TEST(test7, GetCountEdge) {
  std::string current_directory = GetWorkingDirectory();
  std::string file_path = current_directory + "/tests/cube.txt";
  int error = 0;
  s21::Model model;
  model.StartParsingFile(file_path, &error);
  int countEdge = model.GetCountEdge();
  EXPECT_TRUE(countEdge == 18);
}

TEST(test8, ResetInfo) {
  std::string current_directory = GetWorkingDirectory();
  std::string file_path = current_directory + "/tests/cube.txt";
  int error = 0;
  s21::Model model;
  model.StartParsingFile(file_path, &error);
  model.ResetInfo();
  int verticesAmount = model.GetVerticesAmount();
  int countEdge = model.GetCountEdge();
  int facetsAmount = model.GetFacetsAmount();
  EXPECT_TRUE(verticesAmount == 0);
  EXPECT_TRUE(countEdge == 0);
  EXPECT_TRUE(facetsAmount == 0);
}

TEST(test9, MoveModel) {
  std::string current_directory = GetWorkingDirectory();
  std::string file_path = current_directory + "/tests/cube.txt";
  int error = 0;
  s21::Model model;
  model.StartParsingFile(file_path, &error);
  model.MoveModel(1, 0);
  model.MoveModel(1, 1);
  model.MoveModel(1, 2);
  const std::vector<double>& vertexes = model.GetVertexes();
  EXPECT_TRUE(vertexes[0] == 0.5);
  EXPECT_TRUE(vertexes[1] == 0.5);
  EXPECT_TRUE(vertexes[2] == 1.5);
}

TEST(test10, Rotate) {
  std::string current_directory = GetWorkingDirectory();
  std::string file_path = current_directory + "/tests/cube.txt";
  int error = 0;
  s21::Model model;
  model.StartParsingFile(file_path, &error);
  model.Rotate(1, 0);
  model.Rotate(1, 1);
  model.Rotate(1, 2);
  const std::vector<double>& vertexes = model.GetVertexes();
  EXPECT_NEAR(vertexes[0], 0.366935, 1e-6);
  EXPECT_NEAR(vertexes[1], -0.707237, 1e-6);
  EXPECT_NEAR(vertexes[2], 0.339374, 1e-6);
}

TEST(test11, Zoom) {
  std::string current_directory = GetWorkingDirectory();
  std::string file_path = current_directory + "/tests/cube.txt";
  int error = 0;
  s21::Model model;
  model.StartParsingFile(file_path, &error);
  model.Zoom(1.1);
  const std::vector<double>& vertexes = model.GetVertexes();
  EXPECT_NEAR(vertexes[0], -0.4, 1e-6);
  EXPECT_NEAR(vertexes[1], -0.4, 1e-6);
  EXPECT_NEAR(vertexes[2], 0.6, 1e-6);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
