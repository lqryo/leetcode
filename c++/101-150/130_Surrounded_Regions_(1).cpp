#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>


using namespace std;

// dfs递归

class Solution {
public:
	// 从最外层开始遍历
	void solve(vector<vector<char>>& board) {
		if (board.size() == 0) return;

		int rows = board.size();
		int cols = board[0].size();
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
				// 从边缘O开始搜索
				bool isEdge;
				isEdge = i == 0 || j == 0 || i == rows - 1 || j == cols - 1;
				if (isEdge && board[i][j] == 'O') {
					dfs(board, i, j);
				}
			}
		}

		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
				if (board[i][j] == 'O') board[i][j] = 'X';
				if (board[i][j] == '#') board[i][j] = 'O';
			}

		}

	}

private:
	void dfs(vector<vector<char>>& board, int i, int j) {
		if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == 'X' || board[i][j] == '#') {
			// board[i][j]=='#'说明已经搜索过
			return;
		}
		board[i][j] = '#';
		dfs(board, i - 1, j);//上
		dfs(board, i + 1, j);//下
		dfs(board, i, j - 1);//左
		dfs(board, i, j + 1);//右
	}


};



int main(int argc, char* argv[])
{



	Solution S;

	

	std::cin.get();
}
