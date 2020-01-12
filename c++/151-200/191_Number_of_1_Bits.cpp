
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
	int hammingWeight(uint32_t n) {
		int ans = 0;
		for (size_t i = 0; i < 32; i++)
		{
			if (n % 2 == 1) {
				ans++;
			}
			n /= 2;
		}
		return ans;
	}
};


int main()
{


	cin.get();

	return 0;
}

