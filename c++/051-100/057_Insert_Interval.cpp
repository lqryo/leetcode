

#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval);
};


vector<vector<int>> Solution::insert(vector<vector<int>>& intervals, vector<int>& newInterval)
{
	vector<vector<int>> ans;
	
	int length = intervals.size();
	vector<int> cur;
	cur = newInterval;


	for (int i = 0; i < length; i++)
	{
		if (intervals[i][1] < cur[0]) {
			ans.push_back(intervals[i]);
		}

		else if (intervals[i][0] > cur[1]) {
			ans.push_back(cur);
			cur = intervals[i];
		}

		else {  //cur has overlap with intervals[i]
			cur[0] = min(cur[0], intervals[i][0]);
			cur[1] = max(cur[1], intervals[i][1]);
		}
	}

	ans.push_back(cur);

	return ans;
}



int main()
{
	vector<vector<int>> intervals{ {1,2},{3,5},{6,7},{8,10},{12,16} };
	vector<int> newInterval{ 4,8 };

	Solution s;
	s.insert(intervals, newInterval);
	


	cin.get();
	return 0;
}


