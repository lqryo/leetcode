#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <glog/logging.h>

using namespace std;

// 自底向上


class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int row = triangle.size();
		vector<int> minlen(row + 1);
		for (int level = row - 1; level >= 0; level--) {
			for (int i = 0; i <= level; i++) {
				minlen[i] = min(minlen[i], minlen[i + 1]) + triangle[level][i];
			}
		}
		return minlen[0];
	}
};





int main(int argc, char* argv[])
{



	Solution s;


	std::cin.get();
}
