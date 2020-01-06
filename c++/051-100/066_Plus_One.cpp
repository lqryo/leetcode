class Solution {
public:
	vector<int> plusOne(vector<int>& digits);
};

vector<int> Solution::plusOne(vector<int>& digits)
{
	int carry = 1; //进位
	int length = digits.size();
	vector<int> ans_inverse;
	vector<int> ans;

	for (int i = length - 1; i >= 0; i--) {
		int bit = (digits[i] + carry) % 10;
		carry = (digits[i] + carry) / 10;
		ans_inverse.push_back(bit);
	}

	if (carry == 1) ans_inverse.push_back(carry);

	length = ans_inverse.size();

	for (int i = length - 1; i >= 0; i--) {
		ans.push_back(ans_inverse[i]);
	}

	return ans;
}
