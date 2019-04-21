//执行用时32ms，效率较低


#include <iostream>	
#include <vector>

using namespace std;
class Solution {
public:
	int maxArea(vector<int>& height);
};



int main()
{
//	cout << abs(-19) << endl;
	Solution s;
	vector<int> height{1,8,6,2,5,4,8,3,7};
	cout << s.maxArea(height) << endl;

	cin.get();
	return 0;
}

int Solution::maxArea(vector<int>& height)
{
	int length = height.size();
	int result = 0, left = 0, right = length - 1;
	int temp;
	while (left < right)
	{
		if (height[left] <= height[right])
		{
			temp = (right - left) * height[left];
			left++;
		}
		else {
			temp = (right - left) * height[right];
			right--;
		}
		result = (temp > result) ? temp : result;
	}
	return result;
}
