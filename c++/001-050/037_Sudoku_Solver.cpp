#include <vector>
#include <array>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>


using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board);


private:
	bool sudokuSolved = false;
	array<array<int, 9>, 10> rows;
	array<array<int, 9>, 10> cols;
	array<array<int, 9>, 10> boxes;

	bool couldPlace(int d, int row, int col)
	{
		// check if one could place a number d in (row,col) cell
		int idx = (row / 3)*3 + col / 3;
		return rows[row][d] + cols[col][d] + boxes[idx][d] == 0;
	}
	
	void placeNumber(int d, int row, int col, vector<vector<char>>& board)
	{
		// place a number d in (row,col) cell
		
		int idx = (row / 3) * 3 + col / 3;

		rows[row][d]++;
		cols[col][d]++;
		boxes[idx][d]++;
		board[row][col] = (char)(d + '0');
		

		print(board);
	}

	void removeNumber(int d, int row, int col, vector<vector<char>>& board)
	{
		// remove a number which didn't lead to a solution

		int idx = (row / 3) * 3 + col / 3;
		rows[row][d]--;
		cols[col][d]--;
		boxes[idx][d]--;
		board[row][col] = '.';

		print(board);
	}

	void placeNextNumbers(int row, int col, vector<vector<char>>& board)
	{
		if (col == 8 && row == 8) {
			sudokuSolved = true;
		}
		else {
			//if in the end of the row
			//go to the next row
			if (col == 8) backtrack(row + 1, 0, board);
			//go to the next column
			else backtrack(row, col + 1, board);
		}
	}

	void backtrack(int row, int col, vector<vector<char>>& board)
	{
		if (board[row][col] == '.') {
			//iterate over all numbers from 1 to 9
			for (int d = 1; d < 10; d++)
			{
				if (couldPlace(d, row, col)) {
					placeNumber(d, row, col, board);
					placeNextNumbers(row, col, board);
					//if sudoku is solved,there is no need to backtrack
					//since the single unique solution is promised
					if (!sudokuSolved) removeNumber(d, row, col, board);
				}
			}
		}
		else {
			placeNextNumbers(row, col, board);
		}
	}

public:
	void print(vector<vector<char>>& board)
	{
		for (size_t i = 0; i < 9; i++)
		{
			for (size_t j = 0; j < 9; j++)
			{
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
	}

};

//»ØËÝ
void Solution::solveSudoku(vector<vector<char>>& board)
{
	for (size_t i = 0; i < 9; i++)
	{
		for (size_t j = 0; j < 9; j++)
		{
			rows[i][j] = 0;
		}
	}

	for (size_t i = 0; i < 9; i++)
	{
		for (size_t j = 0; j < 9; j++)
		{
			cols[i][j] = 0;
		}
	}

	for (size_t i = 0; i < 9; i++)
	{
		for (size_t j = 0; j < 9; j++)
		{
			boxes[i][j] = 0;
		}
	}

	for (size_t i = 0; i < 9; i++)
	{
		for (size_t j = 0; j < 9; j++)
		{
			char num = board[i][j];
			if (num != '.') {
				int d = num - '0';
				placeNumber(d, i, j,board);
			}
		}
	}

	backtrack(0, 0, board);

}

/*

[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],
["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],
[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]

*/

int main()
{
	
	vector<vector<char>> board = { {'5','3','.','.','7','.','.','.','.'},
								  {'6','.','.','1','9','5','.','.','.'},
								  {'.','9','8','.','.','.','.','6','.'},
								  {'8','.','.','.','6','.','.','.','3'},
								  {'4','.','.','8','.','3','.','.','1'},
								  {'7','.','.','.','2','.','.','.','6'},
								  {'.','6','.','.','.','.','2','8','.'},
								  {'.','.','.','4','1','9','.','.','5'},
								  {'.','.','.','.','8','.','.','7','9'} };

	Solution s;
	s.print(board);

	s.solveSudoku(board);
	getchar();
	
	return 0;

}