#include <iostream>
#include <vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
  vector<int> result;
  int m = matrix.size();
  int n = matrix[0].size();
  int sRow = 0;
  int eRow = m - 1;
  int sCol = 0;
  int eCol = n - 1;
  while (sRow <= eRow && sCol <= eCol)
  {
    // imagine you have matrix
    // 1 2 3 4

    // 9 10 11 12
    // 13 14 15 16
    //  top spiral should be 1 2 3 4 in first
    for (int i = sCol; i <= eCol; i++)
    {
      result.push_back(matrix[sRow][i]);
    }
    // right spiral 8 12 16 2nd row er last colum theke suru kore last row col
    for (int i = sRow + 1; i <= eRow; i++)
    {
      result.push_back(matrix[i][eCol]);
    }
    
    // bottom spiral should be from lastColumn -1 15 to sCol 13
    for (int i = eCol - 1; i >= sCol; i--)
    {
       if(sRow==eRow){
            break;
        }
      result.push_back(matrix[eRow][i]);
    }
    // left spiral should be from fistCol lastRow -1 9 to sCol+1 5
    for (int i = eRow - 1; i > sRow; i--)
    {
      if(sCol==eCol){
            break;
        }
      result.push_back(matrix[i][sCol]);
    }
    sRow++;
    eRow--;
    sCol++;
    eCol--;
  }

  return result;
}
int main()
{
  vector<vector<int>> matrix = {{1, 2, 3, 4},  {9, 10, 11, 12}, {13, 14, 15, 16}};
  vector<int> result = spiralOrder(matrix);
  cout << "spiral matrix" << endl;
  for (int i : result)
  {
    cout << i << endl;
  }
  return 0;
}