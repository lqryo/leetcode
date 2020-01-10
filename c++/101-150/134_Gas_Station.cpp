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
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int len = gas.size();
		vector<int> diff;

		for (size_t i = 0; i < len; i++)
		{
			int tmp = gas[i] - cost[i];
			diff.push_back(tmp);
		}

		int start = len - 1;
		int end = 0;
		int sum = diff[start];
		for (size_t i = 0; i < len - 1; i++)
		{
			if (sum >= 0) {
				sum += diff[end++];
			}
			else {
				sum += diff[--start];
			}
		}

		if (sum < 0) return -1;
		else return start;

	}
};



int main(int argc, char* argv[])
{
	Solution S;
	vector<int> gas{ 1, 2, 3, 4, 3, 2, 4, 1, 5, 3, 2, 4 };
	vector<int> cost{ 1, 1, 1, 3, 2, 4, 3, 6, 7, 4, 3, 1 };
	cout << S.canCompleteCircuit(gas, cost) << endl;

	std::cin.get();

}
