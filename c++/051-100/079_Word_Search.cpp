#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 参考：https://leetcode-cn.com/problems/word-search/solution/zai-er-wei-ping-mian-shang-shi-yong-hui-su-fa-pyth/

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		m = board.size();
		if (m == 0) {
			return false;
		}
		n = board[0].size();
		_word = word;
		_board = board;

		vector<vector<bool>> marked(m, vector<bool>(n,false));
		
		for (size_t i = 0; i < m; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				if (dfs(i, j, 0, marked)) {
					return true;
				}
			}
		}
		return false;

	}

private:
//	vector<vector<bool>> marked;

	vector<vector<int>> direction{ {-1,0},{0,-1},{0,1},{1,0} };
	
	int m; //行
	int n; //列
	std::string _word;
	vector<vector<char>> _board;
	
	bool dfs(int i, int j, int start, vector<vector<bool>>& marked) {
		if (start == _word.length() - 1) {
			return _board[i][j] == _word[start];
		}
		if (_board[i][j] == _word[start]) {
			marked[i][j] = true;
			for (size_t k = 0; k < 4; k++)
			{
				int newX = i + direction[k][0];
				int newY = j + direction[k][1];
				if (inArea(newX, newY) && !marked[newX][newY]) {
					if (dfs(newX, newY, start + 1, marked)) {
						return true;
					}
				}
			}
			marked[i][j] = false;
		}
		return false;
	}


	bool inArea(int x, int y)
	{
		return x >= 0 && x < m && y >= 0 && y < n;
	}

};



int main()
{
	Solution s;

	


	std::cin.get();
}
