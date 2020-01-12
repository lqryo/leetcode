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
#include <stack>


using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int start = 0;
		int end = numbers.size() - 1;
		int sum;
		while (start < end)
		{
			sum = numbers[start] + numbers[end];
			if (sum == target) break;
			else {
				if (sum < target) start++;
				else end--;
			}
		}

		vector<int> ans{ start + 1,end + 1 };
		return ans;
	}
};



 


int main()
{
	Solution s;

	cin.get();
}
