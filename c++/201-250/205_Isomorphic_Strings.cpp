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
	bool isIsomorphic(string s, string t) {
		unordered_map<char, char> m_map;
		for (size_t i = 0; i < s.length(); i++)
		{
			if (m_map.count(s[i]) == 0) {
				m_map[s[i]] = t[i];
			}
			else {
				if (m_map[s[i]] != t[i]) return false;
			}
		}

		// isomorphic is mutual
		m_map.clear();
		for (size_t i = 0; i < t.length(); i++)
		{
			if (m_map.count(t[i]) == 0) {
				m_map[t[i]] = s[i];
			}
			else {
				if (m_map[t[i]] != s[i]) return false;
			}
		}

		return true;
	}
};


 


int main()
{
	Solution s;
	

	cin.get();
}
