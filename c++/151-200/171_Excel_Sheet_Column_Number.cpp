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
	int titleToNumber(string s) {
		reverse(s.begin(), s.end());
		long long ans = 0;
		long long rank = 1;
		for (auto x : s)
		{
			ans = ans + m_map[x] * rank;
			rank = rank * 26;
		}
		return ans;
	}
private:
	unordered_map<char, int> m_map{
	{'A',1},{'B',2},{'C',3},{'D',4},{'E',5},{'F',6},{'G',7},{'H',8},
	{'I',9},{'J',10},{'K',11},{'L',12},{'M',13},{'N',14},{'O',15},{'P',16},
	{'Q',17},{'R',18},{'S',19},{'T',20},{'U',21},{'V',22},{'W',23},{'X',24},
	{'Y',25},{'Z',26}
	};
};



 


int main()
{
	Solution s;

	cin.get();
}
