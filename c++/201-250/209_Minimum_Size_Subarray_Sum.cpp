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
	int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int ans = 0;

		int bound = 0;
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			if (sum >= s) {
				while(sum - nums[bound] >= s) {
					sum -= nums[bound];
					bound++;
				}
				if (ans == 0) { ans = i - bound + 1; }
				else {
					ans = min(ans, i - bound + 1);
				}
			}
		}
		return ans;

	}
};
 


int main()
{

	cin.get();
}
