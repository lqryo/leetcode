
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		if (all_of(nums.begin(), nums.end(), [](int x) {return x == 0; })) {
			return string("0");
		}

		vector<string> strNums(nums.size());
		std::transform(nums.begin(), nums.end(), strNums.begin(), [](int x) {
			return std::to_string(x);
		});

		std::sort(strNums.begin(), strNums.end(), [](const string& x, const string&y) {
			return x + y > y + x;

		});

		return std::accumulate(strNums.begin(), strNums.end(), string());

	}
};


int main()
{


	cin.get();

	return 0;
}

