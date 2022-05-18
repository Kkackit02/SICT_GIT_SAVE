#include <iostream>
#include <string.h>
#define TRUE 1
#define FALSE 0
using namespace std;
int n; //스칼라 곱을 위한 n
int isEnd = FALSE;
class Matrix
{
private:
  int col;
  int row;
  int **matrix;
public:
  Matrix(char op);
  Matrix(int therow, int thecol, int ignore);
  Matrix(int therow, int thecol);
  ~Matrix()
  {
    for (int i = 0; i < row; i++)
    {
      delete[] matrix[i];
    }
    delete[] matrix;
  }
  void PrintMatrix() //행렬 출력
  {
    cout << "Matrix Operation Results" << endl;
    for (int i = 0; i < row; ++i)
    {
      for (int j = 0; j < col; ++j)
      {
        cout << getindex(i, j) << " ";
      }
      cout << endl;
    }
  }
  int getCol() const { return col; }
  int getRow() const { return row; }
  int getindex(int i, int j) const { return matrix[i][j]; }
  void setindex(int i, int j, int value) { matrix[i][j] = value; }
};
//3 ctors
Matrix::Matrix(char op) //m2
{
  if (op == 'x')
  {
    //스칼라 곱이면 m2가 쓸모없지만 dtors에서 delete하는 것을 위해 임의의 값 동적할당
    row = 2;
    col = 2;
    matrix = new int *[row];
    for (int i = 0; i < row; i++)
    {
      matrix[i] = new int[col];
    }
    cout << "Int : ";
    cin >> n;
  }
  else
  {
    int therow;
    int thecol;
    cout << "Matrix Shape : ";
    cin >> therow >> thecol;
    row = therow;
    col = thecol;
    matrix = new int *[row];
    for (int i = 0; i < row; i++)
    {
      matrix[i] = new int[col];
      for (int j = 0; j < col; ++j)
      {
        matrix[i][j] = 0;
      }
    }
    cout << "Matrix : ";
    char command[256];
    int values[1024];
    int valuesTop = 0;
    cin.ignore();
    scanf("%[^\n]", command);
    char *ptr = strtok(command, " ");
    while (ptr != NULL)
    {
      values[valuesTop++] = atoi(ptr);
      ptr = strtok(NULL, " ");
    }
    valuesTop = 0;
    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < col; j++)
      {
        int value = values[valuesTop++];
        setindex(i, j, value);
      }
    }
    cin.ignore();
  }
}
Matrix::Matrix(int therow, int thecol, int ignore) //동적배열만 시키는 ctors
{
  row = therow;
  col = thecol;
  matrix = new int *[row];
  for (int i = 0; i < row; i++)
  {
    matrix[i] = new int[col];
  }
}
Matrix::Matrix(int therow, int thecol) //지시문이 나오는 ctors
{
  row = therow;
  col = thecol;
  matrix = new int *[row];
  for (int i = 0; i < row; i++)
  {
    matrix[i] = new int[col];
  }
  cout << "Matrix : ";
  char command[256];
  int values[1024];
  int valuesTop = 0;
  cin.ignore();
  scanf("%[^\n]", command);
  char *ptr = strtok(command, " ");
  while (ptr != NULL)
  {
    values[valuesTop++] = atoi(ptr);
    ptr = strtok(NULL, " ");
  }
  valuesTop = 0;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      int value = values[valuesTop++];
      setindex(i, j, value);
    }
  }
  cin.ignore();
}
//operator overloading
Matrix operator+(const Matrix &ref1, const Matrix &ref2) // m3 = m1 + m2
{
  Matrix m3(ref1.getRow(), ref1.getCol(), 0);
  for (int i = 0; i < ref1.getRow(); ++i)
  {
    for (int j = 0; j < ref1.getCol(); ++j)
    {
      int value = ref1.getindex(i, j) + ref2.getindex(i, j);
      m3.setindex(i, j, value);
    }
  }
  m3.PrintMatrix();
  return m3;
}
Matrix operator-(const Matrix &ref1, const Matrix &ref2) // m3 = m1 - m2
{
  Matrix m3(ref1.getRow(), ref1.getCol(), 0);
  for (int i = 0; i < ref1.getRow(); ++i)
  {
    for (int j = 0; j < ref1.getCol(); ++j)
    {
      int value = ref1.getindex(i, j) - ref2.getindex(i, j);
      m3.setindex(i, j, value);
    }
  }
  m3.PrintMatrix();
  return m3;
}
Matrix operator*(const Matrix &ref1, const Matrix &ref2) // m3 = m1 * m2
{
  Matrix m3(ref1.getRow(), ref2.getCol(), 0);
  for (int i = 0; i < ref1.getRow(); ++i)
  {
    for (int j = 0; j < ref2.getCol(); ++j)
    {
      int sum = 0;
      for (int k = 0; k < ref1.getCol(); ++k)
      {
        sum = sum + (ref1.getindex(i, k) * ref2.getindex(k, j));
      }
      m3.setindex(i, j, sum);
    }
  }
  m3.PrintMatrix();
  return m3;
}
Matrix operator*(const Matrix &ref, int num) // m3 = m1 * n
{
  Matrix m3(ref.getRow(), ref.getCol(), 0);
  for (int i = 0; i < ref.getRow(); ++i)
  {
    for (int j = 0; j < ref.getCol(); ++j)
    {
      m3.setindex(i, j, num * ref.getindex(i, j));
    }
  }
  m3.PrintMatrix();
  return m3;
}
int main()
{
  int Maincol;
  int Mainrow;
  cout << "Matrix Shape : ";
  cin >> Mainrow >> Maincol;
  Matrix m1(Mainrow, Maincol);
  char op;
  cout << "Operation : ";
  cin >> op;
  Matrix m2(op);
  //m1 m2 계산이 가능한지 확인하는 부분
  if (op == '+')
  {
    if (m1.getCol() != m2.getCol() || m1.getRow() != m2.getRow())
    {
      cout << "Not matched shape : (" << m1.getRow() << "," << m1.getCol() << ")"
           << " + "
           << "(" << m2.getRow() << "," << m2.getCol() << ")" << endl;
      isEnd = TRUE;
    }
  }
  else if (op == '-')
  {
    if (m1.getCol() != m2.getCol() || m1.getRow() != m2.getRow())
    {
      cout << "Not matched shape : (" << m1.getRow() << "," << m1.getCol() << ")"
           << " - "
           << "(" << m2.getRow() << "," << m2.getCol() << ")" << endl;
      isEnd = TRUE;
    }
  }
  else if (op == '*')
  {
    if (m1.getCol() != m2.getRow())
    {
      cout << "Not matched shape : (" << m1.getRow() << "," << m1.getCol() << ")"
           << " * "
           << "(" << m2.getRow() << "," << m2.getCol() << ")" << endl;
      isEnd = TRUE;
    }
  }
  //m1 m2 계산이 가능한지 확인하는 부분 끝
  //고정된 부분
  if (op == '+' && isEnd == FALSE)
  {
    Matrix m3 = m1 + m2;
  }
  else if (op == '-' && isEnd == FALSE)
  {
    Matrix m3 = m1 - m2;
  }
  else if (op == '*' && isEnd == FALSE)
  {
    Matrix m3 = m1 * m2;
  }
  else if (op == 'x' && isEnd == FALSE) //op == 'X'
  {
    Matrix m3 = m1 * n;
  }
  //고정된 부분 끝
  return 0;
}



