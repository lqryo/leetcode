//������https://leetcode-cn.com/problems/first-missing-positive/solution/que-shi-de-di-yi-ge-zheng-shu-by-leetcode/

#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
	int firstMissingPositive(vector<int>& nums);
};


int Solution::firstMissingPositive(vector<int>& nums)
{
	int n = nums.size();

	//�������
	int contains = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (nums[i] == 1) {
			contains++;
			break;
		}
	}

	if (contains == 0) return 1;
	if (n == 1) return 2;

	//��1�滻������0�ʹ���n����
	//��ת���Ժ�numsֻ���������
	for (size_t i = 0; i < n; i++)
	{
		if (nums[i] <= 0 || nums[i] > n)
			nums[i] = 1;
	}

	//ʹ�����������ַ�����Ϊ�����
	//���磬���nums[1]�Ǹ�����ʾ�������г���������1
	//���nums[2]����������ʾ����2û�г���
	for (size_t i = 0; i < n; i++)
	{
		int a = abs(nums[i]);

		//���������һ������a���ı��a��Ԫ�صĺ���
		//ע���ظ�Ԫ��ֻ�����һ��

		if (a == n)
			nums[0] = -abs(nums[0]);
		else
			nums[a] = -abs(nums[a]);
	}

	//���ڵ�һ���������±�
	//���ǵ�һ��ȱʧ����
	for (size_t i = 1; i < n; i++)
	{
		if (nums[i] > 0)
			return i;
	}

	if (nums[0] > 0)
		return n;

	return n + 1;
}