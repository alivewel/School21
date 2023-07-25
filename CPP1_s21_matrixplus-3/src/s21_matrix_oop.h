#ifndef MATRIX_SRC_S21_MATRIX_H_
#define MATRIX_SRC_S21_MATRIX_H_

#include <cmath>
#include <iostream>

class S21Matrix {
 public:
  S21Matrix() = default;
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  ~S21Matrix();

  int GetRows() const;
  void SetRows(int rows);
  int GetCols() const;
  void SetCols(int cols);
  bool EqMatrix(const S21Matrix& other) const;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix operator*(double num);
  friend S21Matrix operator*(double num, S21Matrix& other);
  bool operator==(const S21Matrix& other) const;
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other) noexcept;
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double num);
  double& operator()(int i, int j);
  const double& operator()(int i, int j) const;

 private:
  int rows_ = 0;
  int cols_ = 0;
  double** matrix_ = nullptr;
  void CreateMatrix();
  void FreeMatrix();
  void CopyMatrix(const S21Matrix& other);
  void MoveMatrix(S21Matrix&& other) noexcept;
  void ResizeMatrix(int rows, int cols);
  S21Matrix CreateSmallMatrixMinor(int remove_rows, int remove_columns);
};

#endif  // MATRIX_SRC_S21_MATRIX_H_
