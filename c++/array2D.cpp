#include <iostream>

int** Malloc2DArray(int rows, int cols)
{
  std::cout << __func__ << std::endl;
  int** rowPtr = (int**) malloc(rows * sizeof(int*));
  if (rowPtr == NULL) {
    return NULL;
  }
  std::cout << "Address: " << rowPtr << std::endl;

  for (int row = 0; row < rows; row++) {
    rowPtr[row] = (int*) malloc(cols * sizeof(int));
    if (rowPtr[row] == NULL) {
      return NULL;
    }
    std::cout << "Address: " << rowPtr[row] << std::endl;
  }

  return rowPtr;
}

void Free2DArray(int** rowPtr, int rows)
{
  for (int row = 0; row < rows; row++) {
    free(rowPtr[row]);
  }
  free(rowPtr);
  std::cout << __func__ << std::endl;
}

int** Malloc2DArrayContiguous(int rows, int cols)
{
  std::cout << __func__ << std::endl;
  int header = rows * sizeof(int*);
  int data   = rows * cols * sizeof(int);
  int** rowPtr = (int**) malloc(header + data);
  if (rowPtr == NULL) {
    return NULL;
  }
  std::cout << "Address: " << rowPtr << std::endl;

  int* buf = (int*) (rowPtr + rows);
  for (int row = 0; row < rows; row++) {
    rowPtr[row] = buf + row * cols;
    std::cout << "Address: " << rowPtr[row] << std::endl;
  }

  return rowPtr;
}

void Free2DArrayContiguous(int** rowPtr, int rows)
{
  free(rowPtr);
  std::cout << __func__ << std::endl;
}

int** New2DArray(int rows, int cols)
{
  std::cout << __func__ << std::endl;
  int** rowPtr = new int*[rows];
  if (rowPtr == nullptr) {
    return nullptr;
  }
  std::cout << "Address: " << rowPtr << std::endl;

  for (int row = 0; row < rows; row++) {
    rowPtr[row] = new int[cols];
    if (rowPtr[row] == nullptr) {
      return nullptr;
    }
    std::cout << "Address: " << rowPtr[row] << std::endl;
  }

  return rowPtr;
}

void Delete2DArray(int** rowPtr, int rows)
{
  for (int row = 0; row < rows; row++) {
    delete rowPtr[row];
  }
  delete rowPtr;
  std::cout << __func__ << std::endl;
}

void Write2DArray(int** arr, int rows, int cols)
{
  static int data;

  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      arr[row][col] = data++;
    }
  }
}

void Read2DArray(int** arr, int rows, int cols)
{
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      std::cout << "\t" << arr[row][col];
    }
    std::cout << std::endl;
  }
}

int main()
{
  int rows = 2;
  int cols = 2;

  int **cpp = New2DArray(rows, cols);
  Write2DArray(cpp, rows, cols);
  Read2DArray(cpp, rows, cols);
  
  int **c = Malloc2DArray(rows, cols);
  Write2DArray(c, rows, cols);
  Read2DArray(c, rows, cols);

  int **cg = Malloc2DArrayContiguous(rows, cols);
  Write2DArray(cg, rows, cols);
  Read2DArray(cg, rows, cols);

  Delete2DArray(cpp, rows);
  Free2DArray(c, rows);
  Free2DArrayContiguous(cg, rows);

  return 0;
}