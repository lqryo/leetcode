#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;




class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		if (len == 0 || len == 1) return 0;
		
		int maxprofit = 0;
		for (size_t i = 1; i < len; i++)
		{
			if (prices[i] > prices[i - 1]) {
				maxprofit += (prices[i] - prices[i - 1]);
			}
		}

		return maxprofit;

	}
};





int main(int argc, char* argv[])
{



	Solution s;

	vector<int> m{ 7,1,5,3,6,4 };
	std::cout << s.maxProfit(m) << std::endl;

	std::cin.get();
}
