/*
�ο���https://blog.csdn.net/NoMasp/article/details/49913627
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums);
};

void Solution::nextPermutation(vector<int>& nums)
{
	int nums_len = nums.size();
	//�ҵ��ؼ���
	for (size_t i = nums_len-1; i>=1; i--)
	{
		if (nums[i] > nums[i - 1])
		{
			int index = i-1;
			//����i�Ժ����Ϊ����,�ҳ���i��nums_len-1��Χ�ڴ���nums[i-1]���������ֵ
			int swap = i;
			while (i< nums_len)
			{
				if (nums[i] > nums[index]) {
					swap = i;
				}
				i++;
				
			}
			
			int temp = nums[swap];
			nums[swap] = nums[index];
			nums[index] = temp;

			//��i��nums_len-1��һ������
			sort(nums.begin() + index + 1, nums.end());
			return;
		}
	}
	sort(nums.begin(), nums.end());
}



int main(int argc,char* argv[])
{

	Solution solution;
	vector<int> a{ 2,3,1 };
	vector<int> b{ 3,2,1 };
	vector<int> c{ 1,1,5 };
	vector<int> d{ 2,3,1 };

	solution.nextPermutation(a);
	solution.nextPermutation(b);
	solution.nextPermutation(c);
	solution.nextPermutation(d);


	getchar();

	return 0;
}