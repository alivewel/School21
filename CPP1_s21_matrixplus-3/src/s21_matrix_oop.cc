#include "s21_matrix_oop.h"

S21Matrix::S21Matrix(int rows, int cols)
    : rows_(rows), cols_(cols), matrix_(nullptr) {
  if (rows < 0 || cols < 0 || (rows == 0 && cols != 0) ||
      (rows != 0 && cols == 0))
    throw std::out_of_range("Ошибка: Некорректный размер матрицы!");
  CreateMatrix();
}

S21Matrix::~S21Matrix() { FreeMatrix(); }

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  if (this != &other) CopyMatrix(other);
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept {
  MoveMatrix(std::move(other));
}

void S21Matrix::CreateMatrix() {
  if (rows_ != 0 && cols_ != 0) {
    matrix_ = new double*[rows_]();
    for (int i = 0; i < rows_; i++) matrix_[i] = new double[cols_]();
  }
}

void S21Matrix::CopyMatrix(const S21Matrix& other) {
  matrix_ = new double*[other.rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[other.cols_]();
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

void S21Matrix::MoveMatrix(S21Matrix&& other) noexcept {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

void S21Matrix::FreeMatrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      if (matrix_[i] != nullptr) {
        delete[] matrix_[i];
      }
    }
    delete[] matrix_;
    matrix_ = nullptr;
  }
}

int S21Matrix::GetRows() const { return rows_; }

void S21Matrix::SetRows(int newRows) {
  if (newRows < 1)
    throw std::out_of_range("Ошибка: Некорректный размер строк новой матрицы!");
  if (newRows != rows_) {
    S21Matrix temp(newRows, cols_);
    for (int i = 0; i < newRows; i++) {
      for (int j = 0; j < cols_; j++) {
        if (i < rows_) temp(i, j) = matrix_[i][j];
      }
    }
    *this = std::move(temp);
  }
}

int S21Matrix::GetCols() const { return cols_; }

void S21Matrix::SetCols(int newCols) {
  if (newCols < 1)
    throw std::out_of_range(
        "Ошибка: Некорректный размер столбцов новой матрицы!");
  if (newCols != cols_) {
    S21Matrix temp(rows_, newCols);
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < newCols; j++) {
        if (j < cols_) temp(i, j) = matrix_[i][j];
      }
    }
    *this = std::move(temp);
  }
}

bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  bool status = true;
  if (rows_ == other.rows_ && cols_ == other.cols_) {
    for (int i = 0; i < rows_ && status; i++) {
      for (int j = 0; j < cols_ && status; j++) {
        if (fabs(matrix_[i][j] - other.matrix_[i][j]) >= 1e-7) status = false;
      }
    }
  } else {
    status = false;
  }
  return status;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::out_of_range("Ошибка: Размеры матриц не совпадают!");
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::out_of_range("Ошибка: Размеры матриц не совпадают!");
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_)
    throw std::out_of_range(
        "Ошибка: Число столбцов первой матрицы не равно числу строк второй "
        "матрицы!");
  S21Matrix result(rows_, other.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      double sum = 0.0;
      for (int k = 0; k < cols_; k++) {
        sum += matrix_[i][k] * other.matrix_[k][j];
      }
      result.matrix_[i][j] = sum;
    }
  }
  *this = std::move(result);
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[j][i] = matrix_[i][j];
    }
  }
  return result;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_)
    throw std::range_error("Ошибка: Матрица не является квадратной!");
  double det = 0.0;
  if (rows_ == 1) {
    det = matrix_[0][0];
  } else if (rows_ == 2) {
    det = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    for (int i = 0; i < rows_; i++) {
      S21Matrix new_small_matrix = CreateSmallMatrixMinor(0, i);
      double sign = (i % 2 == 0) ? 1.0 : -1.0;
      det += sign * matrix_[0][i] * new_small_matrix.Determinant();
    }
  }
  return det;
}

S21Matrix S21Matrix::CreateSmallMatrixMinor(int remove_rows,
                                            int remove_columns) {
  S21Matrix new_small_matrix(rows_ - 1, cols_ - 1);
  for (int i = 0, i_new = 0; i < rows_; i++) {
    for (int j = 0, j_new = 0; j < cols_; j++) {
      if (j != remove_columns && i != remove_rows) {
        new_small_matrix(i_new, j_new) = matrix_[i][j];
        j_new++;
      }
    }
    if (i != remove_rows) i_new++;
  }
  return new_small_matrix;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_)
    throw std::range_error("Ошибка: Матрица не является квадратной!");
  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      double sign = ((i + j) % 2 == 0) ? 1.0 : -1.0;
      S21Matrix new_small_matrix = CreateSmallMatrixMinor(i, j);
      double det = new_small_matrix.Determinant();
      result.matrix_[i][j] = sign * det;
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  double det = Determinant();
  if (det == 0) throw std::range_error("Ошибка: Определитель матрицы равен 0!");
  S21Matrix inverseMatrix;
  if (rows_ == 1 && cols_ == 1) {
    S21Matrix a1x1(1, 1);
    a1x1(0, 0) = (1 / det);
    inverseMatrix = a1x1;
  } else {
    inverseMatrix = CalcComplements().Transpose() * (1 / det);
  }
  return inverseMatrix;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix result(*this);
  result.MulMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(double num) {
  S21Matrix result(*this);
  result.MulNumber(num);
  return result;
}

S21Matrix operator*(double num, S21Matrix& other) {
  S21Matrix result(other);
  result.MulNumber(num);
  return result;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

bool S21Matrix::operator==(const S21Matrix& other) const {
  return EqMatrix(other);
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    FreeMatrix();
    rows_ = other.rows_;
    cols_ = other.cols_;
    CopyMatrix(other);
  }
  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) noexcept {
  if (this != &other) {
    FreeMatrix();
    MoveMatrix(std::move(other));
  }
  return *this;
}

double& S21Matrix::operator()(int i, int j) {
  if (rows_ == 0 || cols_ == 0)
    throw std::out_of_range("Ошибка: Матрица имеет размер 0 на 0!");
  if (i < 0 || j < 0 || i >= rows_ || j >= cols_)
    throw std::out_of_range("Ошибка: Индекс за пределами матрицы!");
  return matrix_[i][j];
}

const double& S21Matrix::operator()(int i, int j) const {
  if (rows_ == 0 || cols_ == 0)
    throw std::out_of_range("Ошибка: Матрица имеет размер 0 на 0!");
  if (i < 0 || j < 0 || i >= rows_ || j >= cols_)
    throw std::out_of_range("Ошибка: Индекс за пределами матрицы!");
  return matrix_[i][j];
}
