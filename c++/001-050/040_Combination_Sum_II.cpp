//≤Œøº£∫https://leetcode-cn.com/problems/combination-sum-ii/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-3/

#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {

private:
	vector<int> candidates;
	vector<vector<int>> res;
	vector<int> path;

public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target);

	//ªÿÀ›À„∑®+ºÙ÷¶
	void DFS(int start, int target) {
		if (target == 0) {
			res.push_back(path);
			return;
		}

		for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++)
		{
			//ºÙ÷¶
			if (i > start && candidates[i] == candidates[i - 1])
				continue;
			path.push_back(candidates[i]);
			DFS(i + 1, target - candidates[i]);
			path.pop_back();
		}

	}
};

vector<vector<int>> Solution::combinationSum2(vector<int>& candidates, int target)
{
	sort(candidates.begin(), candidates.end());
	this->candidates = candidates;
	DFS(0, target);
	return res;


}


int main()
{

}



