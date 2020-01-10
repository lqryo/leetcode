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
		int minprice = INT_MAX;
		int maxprofit = 0;
		for (size_t i = 0; i < prices.size(); i++)
		{
			if (prices[i] < minprice)
				minprice = prices[i];
			else if (prices[i] - minprice > maxprofit)
				maxprofit = prices[i] - minprice;
		}
		return maxprofit;
	}
};





int main(int argc, char* argv[])
{



	Solution s;


	std::cin.get();
}
