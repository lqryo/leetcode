
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>

using namespace std;

// ¿ìÂýÖ¸Õë
// ²Î¿¼£ºhttps://leetcode-cn.com/problems/happy-number/solution/shi-yong-kuai-man-zhi-zhen-si-xiang-zhao-chu-xun-h/


class Solution {
public:
	bool isHappy(int n) {
		int slow = n, fast = n;
		do {
			slow = bitSquareSum(slow);
			fast = bitSquareSum(fast);
			fast = bitSquareSum(fast);
		} while (slow != fast);

		return slow == 1;
	}

private:
	int bitSquareSum(int n) {
		int sum = 0;
		while (n > 0)
		{
			int bit = n % 10;
			sum += bit * bit;
			n = n / 10;
		}
		return sum;
	}
};

int main()
{
	Solution s;

	cin.get();

	return 0;
}

