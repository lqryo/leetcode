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
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int> m_map;
		for (size_t i = 0; i < nums.size(); i++)
		{
			if (m_map.count(nums[i]) == 0) {
				m_map[nums[i]] = i;
			}
			else {
				if (i - m_map[nums[i]] <= k) {
					return true;
				}
				else {
					m_map[nums[i]] = i;
				}
			}
		}

		return false;
	}
};



int main()
{
	Solution s;

	vector<int> m{ 1,2,3,1,2,3 };

	cout << s.containsNearbyDuplicate(m, 2);

	cin.get();
}
