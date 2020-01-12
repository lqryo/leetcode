
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		vector<uint16_t> bit;

		for (size_t i = 0; i < 32; i++)
		{
			bit.push_back(n % 2);
			n /= 2;
		}

		uint64_t ans = 0;
		for (auto x : bit) {
			ans = 2 * ans + x;
		}

		return ans;
	}
};


int main()
{


	cin.get();

	return 0;
}

