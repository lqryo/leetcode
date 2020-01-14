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

// 厄拉多筛选法
 
 class Solution {
 public:
	 int countPrimes(int n) {
		 vector<bool> isPrime(n + 1, true);
		 isPrime[0] = false;
		 isPrime[1] = false;
		 for (size_t i = 2; i <= n; i++)
		 {
			 if (isPrime[i]) {
				 int m = 2;
				 int j = m * i;
				 while (j <= n)
				 {
					 isPrime[j] = false;
					 j = (++m) * i;
				 }
			 }
		 }

		 return std::count(isPrime.begin(), isPrime.end(), true);

	 }
 };


 


int main()
{
	Solution s;
	
	cout << s.countPrimes(10);

	cin.get();
}
