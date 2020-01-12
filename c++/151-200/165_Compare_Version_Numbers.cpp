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
	int compareVersion(string version1, string version2) {
		vector<int> v1;
		vector<int> v2;

		istringstream s1(version1);

		string num;
		while (getline(s1,num,'.'))
		{
			v1.push_back(atoi(num.c_str()));
		}

		istringstream s2(version2);

		while (getline(s2,num,'.'))
		{
			v2.push_back(atoi(num.c_str()));
		}

		int loop = max(v1.size(), v2.size()) - 1;

		// 长度不相等补零
		while (v1.size() != v2.size()) {
			if (v1.size() < v2.size()) {
				v1.push_back(0);
			}
			else v2.push_back(0);
		}

		return compare(v1, v2, 0);

	}

private:
	int compare(vector<int>&a, vector<int>& b, int i) {
		
		if (a[i] > b[i]) return 1;
		else if (a[i] < b[i]) return -1;
		else {
			if (i == a.size() - 1) return 0;
			else return compare(a, b, i + 1);
		}
	}



};



 


int main()
{
	Solution s;
	cout << s.compareVersion("1.0", "1") << endl;
//	cout << s.compareVersion("1.0.1", "1") << endl;
	cin.get();
}
