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
	vector<int> getRow(int rowIndex) {
		vector<int> ans;
		if (rowIndex == 0) return vector<int>{1};
		if (rowIndex == 1) return vector<int>{1,1};
		ans.push_back(1);
		ans.push_back(1);

		for (size_t i = 1; i < rowIndex; i++)
		{
			vector<int> pre;
			ans.swap(pre);
			ans.push_back(1);
			int len = pre.size();

			for (size_t j = 1; j < len; j++)
			{
				ans.push_back(pre[j - 1] + pre[j]);
			}
			ans.push_back(1);
		}

		return ans;

	}
};





int main(int argc, char* argv[])
{



	Solution s;

	vector<int> ans = s.getRow(3);

	std::cin.get();
}
