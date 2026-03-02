#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isSafe(vector<vector<char>> &board, int row, int col, char dig)
{

    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == dig)
        {
            return false;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == dig)
        {
            return false;
        }
    }
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i <= startRow + 2; i++)
    {
        for (int j = startCol; j <= startCol + 2; j++)
        {
            if (board[i][j] == dig)
            {
                return false;
            }
        }
    }
    return true;
}
bool solveSudokuHelper(
    vector<vector<char>> &board, int row, int col)
{
    if (row == 9)
    {
        return true;
    }
    int nextRow = row, nextCol = col + 1;
    if (nextCol == 9)
    {
        nextRow = row + 1;
        nextCol = 0;
    }
    if (board[row][col] != '.')
    {
       return  solveSudokuHelper(board, nextRow, nextCol);
    }
    for (int i = '1'; i <= '9'; i++)
    {
        if (isSafe(board, row, col, i))
        {
            board[row][col] = i;
            if (solveSudokuHelper(board, nextRow, nextCol))
            {
                return true;
            }
            board[row][col] = '.';
        }
    }
    return false;
}
void solveSudoku(vector<vector<char>> &board)
{
    solveSudokuHelper(board, 0, 0);
}

int main()
{
    return 0;
}