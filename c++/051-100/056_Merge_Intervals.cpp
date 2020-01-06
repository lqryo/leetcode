

#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;


bool cmp(vector<int>& a, vector<int>& b)
{
	if (a[0] < b[0]) { return true; }
	else if (a[0] > b[0]) { return false; }
	else {
		if (a[1] < b[1]) { return true; }
		else { return false; }
	}
}

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals);

};

vector<vector<int>> Solution::merge(vector<vector<int>>& intervals)
{
	vector<vector<int>> ans;

	int length = intervals.size();
	if (length == 0) return ans;

	sort(intervals.begin(), intervals.end(), cmp);

	vector<int> cur(2);
	cur = intervals[0];

	for (size_t i = 1; i < length; i++)
	{
		if (intervals[i][0] <= cur[1]) { 
			cur[1] = max(cur[1], intervals[i][1]);
		}
		else {  
			ans.push_back(cur);
			cur = intervals[i];
		}
	}

	ans.push_back(cur);


	return ans;
}



int main()
{

	vector<vector<int>> nums{ {2,3},{4,5},{6,7},{8,9},{1,10} };

	Solution s;
	s.merge(nums);
	
	


	cin.get();
	return 0;
}


