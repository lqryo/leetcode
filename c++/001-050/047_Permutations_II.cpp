

#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums);


private:
	//ªÿÀ›+ºÙ÷¶
	void DFS(vector<int>& nums, vector<int>& temp, vector<vector<int>>& res,
		int cursize, vector<bool>& visited) {
		if (cursize == nums.size()) {
			res.push_back(temp);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (!visited[i]) {
				if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
					continue;
				temp.push_back(nums[i]);
				visited[i] = true;
				DFS(nums, temp, res, cursize + 1, visited);
				temp.pop_back();
				visited[i] = false;

			}
		}
	}

};

vector<vector<int>> Solution::permuteUnique(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	int n = nums.size();

	vector<int> temp;
	vector<vector<int>> res;
	vector<bool> visited(n, false);
	DFS(nums, temp, res, 0, visited);
	return res;
}




int main()
{

	cin.get();
	return 0;
}


