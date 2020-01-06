//²Î¿¼£ºhttps://leetcode-cn.com/problems/rotate-image/solution/c-yang-cong-xun-huan-fa-you-fen-xi-you-tu-jie-you-/

#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix);
};

void Solution::rotate(vector<vector<int>>& matrix)
{
	int n = matrix.size();
	for (int loop = 0; loop < n / 2; loop++) { //Íâ²ãÑ­»·
		for (int i = loop, j = loop; i < n - 1 - loop; i++) {
			int pre = matrix[i][j];
			for (int time = 1; time <= 4; time++) {
				int tmpi = i;
				i = j;
				j = n - 1 - tmpi;
				swap(pre, matrix[i][j]);
			}

		}
	}
}


int main()
{
	vector<vector<int>> matrix{ {1,2}, {3,4} };
	Solution s;
	s.rotate(matrix);



	cin.get();
	return 0;
}


