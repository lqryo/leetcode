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
	int evalRPN(vector<string>& tokens) {

		stack<string> operands;
		for (auto x : tokens) {
			if (op.count(x) != 0) {
				int oprand1 = atoi(operands.top().c_str());
				operands.pop();
				int oprand2 = atoi(operands.top().c_str());
				operands.pop();
				int tmp = op[x](oprand2, oprand1); // the order of oprands matters for division operation

				operands.push(to_string(tmp));  // don't miss it

			}
			else {
				operands.push(x);
			}
		}
		int ans = atoi(operands.top().c_str());
		
		return ans;
	}
private:
	map<string, function<int(int, int)>> op = 
	{
		{"+",[](int i,int j) {return i + j; }},
		{"-",[](int i,int j) {return i - j; }},
		{"*",[](int i,int j) {return i * j; }},
		{"/",[](int i,int j) {return i / j; }}
	};
};



int main()
{
	Solution s;

	vector<string> m{ "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
	vector<string> n{ "4","13","5","/","+" };

	cout << s.evalRPN(n) << endl;


	cin.get();
}
