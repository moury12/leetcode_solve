
#include <iostream>
#include <vector>
// #include <utility>
using namespace std;
// pair<int, int> linearSearch(int matrix[3][3], int rows, int cols)

// {
//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < cols; j++)
//         {
//             if (matrix[i][j] == 8)
//             {
//                 return {i, j};
//             }
//         }
//         cout << endl;
//     }
//     return {0, 0};
// }

///--------------------------- time complexity O(Log(M)+Log(N))

bool binarySearchMatrix(vector<vector<int>> &matrix, int target)
{ // length of row
    int m = matrix.size();
    // length of columns for each row
    int n = matrix[0].size();
    int startRow = 0;
    int endRow = m - 1;
    // ai loop ta jotokhn start row er value end row er theke choto ba soman thakbe
    while (startRow <= endRow)
    {
        //majkhane row er index ber kora
        int midRow = (startRow + endRow) / 2;
        // target jodi mid row er first column r value er theke boro ba somman hoy &&
        // target jodi mid row er last column r value er theke choto ba soman hoy tahole ai condition cholbe
        if (target >= matrix[midRow][0] && target <= matrix[midRow][n - 1])
        {
            int stCol = 0;
            int endCol = n - 1;
// oi selected row er moidhe stCol index the endCol index projntto loop cholbe 
            while (stCol <= endCol)
            {
                // selected row er mid colum index ber kora hoilo
                int midColumn = (stCol + endCol) / 2;
                // jodi targer val mid row er midcolumn e thake tahole traget found
                if (target == matrix[midRow][midColumn])
                {
                    return true;
                }
                //kintu jodi target selected row er midColum r val theke boro hoy
                // stCol update hoy midcol er porer index hobe 
                else if (target > matrix[midRow][midColumn])
                {
                    stCol = midColumn + 1;
                }
                else
                {
                    // jodi target choto hoy endCol k midColumn er ager index e niye jabe 
                    endCol = midColumn - 1;
                }
            }

            // cout << " right row" << matrix[startRow][0] << "-" << matrix[midRow][n - 1];
            // return true;
            //jodi ai range e target na thake tahole 
              return false;
        }
        // target er val jodi midRow er lats column index er val theke boro hoy stRow update hoy next row te jabe
        else if (target > matrix[midRow][n - 1])
        {
            startRow = midRow + 1;
        }
        // target choto hole endRow previous row te jabe
        else
        {
            endRow = midRow - 1;
        }
    }
    return false;
}

int main()
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> mat = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 31;
    int rows = 3;
    int cols = 3;
    // pair<int, int> result = linearSearch(matrix, rows, cols);
    bool optimizedResult = binarySearchMatrix(mat, target);
    cout << optimizedResult << endl;
    // cout << "Element found at Row: " << result.first << ", Col: " << result.second << endl;
    return 0;
}