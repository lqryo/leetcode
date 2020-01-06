/*
参考：https://blog.csdn.net/Gakkis/article/details/78243170
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board);
};

bool Solution::isValidSudoku(vector<vector<char>>& board)
{
	//遍历数独的每一个已填充的数字，检查是否合法

	int row, col;
	//先分别检查每个9宫格是否合法
	for (row = 0; row < 3; row++)  //行
	{
		for (col = 0; col < 3; col++) //列
		{
			set<char> s;
			for (size_t k = 0; k < 9; k++)
			{
				char cur = board[3 * row + k / 3][3 * col + k % 3];
				if (cur == '.') continue;
				if (s.find(cur) == s.end()) { s.insert(cur); }
				else {
					return false;
				}
			}
		}
	}

	//检查每一行是否合法
	for (row = 0; row < 9; row++)
	{
		set<char> s;
		for (col = 0; col < 9; col++)
		{
			char cur = board[row][col];
			if (cur == '.') continue;
			if (s.find(cur) == s.end()) { s.insert(cur); }
			else {
				return false;
			}
		}
	}

	//检查每一列是否合法
	for ( col= 0; col < 9; col++)
	{
		set<char> s;
		for (row = 0; row < 9; row++)
		{
			char cur = board[row][col];
			if (cur == '.') continue;
			if (s.find(cur) == s.end()) { s.insert(cur); }
			else {
				return false;
			}
		}
	}

	return true;

}



int main(int argc,char* argv[])
{

	Solution solution;
	vector<vector<char>> board = { {'5','3','.',    '.','7','.',	'.','.','.'},
								   {'6','.','.',    '1','9','5',	'.','.','.'},
								   {'.','9','8',    '.','.','.',	'.','6','.'},

								   {'8','.','.',    '.','6','.',	'.','.','3'},
								   {'4','.','.',	'8','.','3',	'.','.','1'},
								   {'7','.','.',	'.','2','.',	'.','.','6'},

								   {'.','6','.',	'.','.','.',	'2','8','.'},
								   {'.','.','.',	'4','1','9',	'.','.','5'},
								   {'.','.','.',	'.','8','.',	'.','7','9'} };

	cout << solution.isValidSudoku(board) << endl;

	getchar();

	return 0;
}