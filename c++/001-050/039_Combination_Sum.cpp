//²Î¿¼£ºhttps://leetcode-cn.com/problems/combination-sum/solution/

#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target);
};

vector<vector<int>> Solution::combinationSum(vector<int>& candidates, int target)
{
	unordered_map<int, set<vector<int>>>dict;
	for (size_t i = 0; i <= target; i++)
	{
		for (auto it:candidates)
		{
			if (i == it) dict[i].insert(vector<int>{it});
			else if(i > it)
				for (auto ivec : dict[i - it])
				{
					ivec.push_back(it);
					sort(ivec.begin(), ivec.end());
					if (dict[i].count(ivec) == 0) {
						dict[i].insert(ivec);
					}
				}			
		}
	}
	vector<vector<int>> ans;
	for (auto it : dict[target]) ans.push_back(it);
	return ans;
}


int main()
{

}



