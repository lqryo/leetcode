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

// 因为缺少0位，我们把0对应A，25对应Z，让它变成标准的26进制

class Solution {
public:
	string convertToTitle(int n) {
		string ans;
		int divident = n;
		int dividor = 26;
		while (divident != 0)
		{
			int remainder = (--divident) % 26;
			divident = divident / 26;
			ans = ans + m_map[remainder];
		}
		reverse(ans.begin(), ans.end());
		return ans;	
	}
private:
	unordered_map<int,string> m_map{
		{0,"A"},{1,"B"},{2,"C"},{3,"D"},{4,"E"},{5,"F"},{6,"G"},{7,"H"},
		{8,"I"},{9,"J"},{10,"K"},{11,"L"},{12,"M"},{13,"N"},{14,"O"},{15,"P"},
		{16,"Q"},{17,"R"},{18,"S"},{19,"T"},{20,"U"},{21,"V"},{22,"W"},{23,"X"},
		{24,"Y"},{25 ,"Z"}
	};
};



 


int main()
{
	Solution s;

	cin.get();
}
