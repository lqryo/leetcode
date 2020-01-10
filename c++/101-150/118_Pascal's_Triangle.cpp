#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <glog/logging.h>

using namespace std;


class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ans;
		if (numRows == 0) return ans;
		ans.push_back(vector<int>{1});
		if (numRows == 1) return ans;
		ans.push_back(vector<int>{1, 1});
		if (numRows == 2) return ans;

		for (size_t i = 2; i < numRows; i++)
		{
			vector<int> tmp;
			tmp.push_back(1);

			int len = ans[i - 1].size();
			for (size_t j = 1; j < len; j++)
			{
				tmp.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
			}
			tmp.push_back(1);
			ans.push_back(tmp);
		}
		return ans;
	}
};





int main(int argc, char* argv[])
{



	Solution s;


	std::cin.get();
}
