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
	string fractionToDecimal(int numerator, int denominator) {
		long long num = numerator;
		long long den = denominator;
		string res;
		if (num * den < 0) {
			res += "-";
		}
		num = abs(num);
		den = abs(den);
		res += to_string(num / den);
		num %= den;
		if (num == 0) {
			return res;
		}

		res += ".";
		int loop_ind = -1;
		unordered_map<long, long> m; //记录余数出现的位置
		while (num != 0)
		{
			if (m.count(num)) {
				loop_ind = m[num];
				break;
			}
			else {
				m[num] = res.size();
			}
			num *= 10;
			res += to_string(num / den);
			num %= den;

		}

		if (num == 0) {
			return res;
		}
		return res.substr(0, loop_ind) + "(" + res.substr(loop_ind) + ")";

	}
};



 


int main()
{
	Solution s;

	cin.get();
}
