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
	vector<vector<int>> combinationSum3(int k, int n) {
		this->k = k;
		this->n = n;

		if (k == 0 || k > 9) return ans;

		vector<int> cur;
		for (int i = 1; i <= 9; i++)
		{
			vector<int> cur;
			backTrack(0, i, 1, cur);
		}

		return ans;
		


	}
private:
	vector<vector<int>> ans;
	int k;
	int n;
	
	// step为当前步数
	//
	void backTrack(int sum, int num, int step,vector<int>& cur)
	{		
		if (sum + num == n)
		{
			if (step == k) {
				cur.push_back(num);
				ans.push_back(cur); //不用再继续搜索
				cur.pop_back();
			}
			else return;
		}
		else if (sum + num < n) {
			if (step == k) return;

			cur.push_back(num);
			for (int i = num+1; i <= 9; i++)
			{
				backTrack(sum + num, i, step + 1, cur);
			}
			cur.pop_back();
		}
		else return;
	}
};



int main()
{
	Solution s;
	vector<vector<int>> ans;

	ans = s.combinationSum3(3, 9);

	cin.get();
}
