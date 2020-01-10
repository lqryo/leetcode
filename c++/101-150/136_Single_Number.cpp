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


using namespace std;



// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}
};

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		unordered_set<int> m_set;
		int ans;

		for (auto x : nums) {
			if (m_set.count(x) == 0) {
				m_set.insert(x);
			}
			else {
				m_set.erase(x);
			}
		}

		for (auto x : m_set) {
			ans = x;
		}
		return ans;
	}
};



int main(int argc, char* argv[])
{
	Solution S;

	vector<int> t{ 2,2,1 };

	cout << S.singleNumber(t) << endl;

	std::cin.get();

}
