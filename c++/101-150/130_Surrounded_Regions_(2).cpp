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

// 参考：https://leetcode-cn.com/problems/surrounded-regions/solution/bfsdi-gui-dfsfei-di-gui-dfsbing-cha-ji-by-ac_pipe/
// 并查集

class UnionFind {
public:
	UnionFind(int totalNodes) {
		for (size_t i = 0; i < totalNodes; i++)
		{
			parents.push_back(i);
		}
	};

	int find(int node) {
		while (parents[node]!=node)
		{
			// 当前节点的父节点，指向父节点的父节点
			// 保证一个连通区域最终的parents只有一个
			parents[node] = parents[parents[node]];
			node = parents[node];
		}
		return node;
	};

	bool isConnected(int node1, int node2) {
		return find(node1) == find(node2);
	};

	// 合并连通区域是通过find来操作，即看这两个节点是不是在一个连通区域内
	void myunion(int node1, int node2) {
		int root1 = find(node1);
		int root2 = find(node2);
		if (root1 != root2) {
			parents[root2] = root1;
		}
	};

private:
	vector<int> parents;
};


class Solution {
public:
	// 从最外层开始遍历
	void solve(vector<vector<char>>& board) {
		if (board.size() == 0) return;

		this->rows = board.size();
		this->cols = board[0].size();

		// 用一个虚拟节点，边界上的0的父节点都是这个虚拟节点
		UnionFind uf(rows*cols + 1);
		int dummyNode = rows * cols;

		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
				if (board[i][j] == 'O') {
					// 遇到0进行并查集操作合并
					if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
						// 边界上的0，把它和dummyNode合并成一个连通区域
						uf.myunion(node(i, j), dummyNode);
					}
					else {
						// 和上下左右合并成一个连通区域
						if (i > 0 && board[i - 1][j] == 'O')
							uf.myunion(node(i, j), node(i - 1, j));
						if (i < rows - 1 && board[i + 1][j] == 'O')
							uf.myunion(node(i, j), node(i + 1, j));
						if (j > 0 && board[i][j - 1] == 'O')
							uf.myunion(node(i, j), node(i, j - 1));
						if (j < cols - 1 && board[i][j + 1] == 'O')
							uf.myunion(node(i, j), node(i, j + 1));
					}
				}
			}
		}

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (uf.isConnected(node(i, j), dummyNode)) {
					// 和dummyNode 在一个连通区域的,那么就是O；
					board[i][j] = 'O';
				}
				else {
					board[i][j] = 'X';
				}
			}
		}
}

private:
	int rows;
	int cols;
	int node(int i, int j) {
		return i * cols + j;
	}

};



int main(int argc, char* argv[])
{
	Solution S;
	std::cin.get();
}
