#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// 二分查找

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0) return false;
		
		int row = matrix.size();
		int col = matrix[0].size();
		int start = 0;
		int end = row * col - 1;
		while (start <= end) {
			int mid = (start + end) / 2;
			int tmp = getValue(matrix, mid);
			if (tmp == target) {
				return true;
			}
			else if (tmp > target) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
			
		}
		return false;
	}

private:
	int getValue(vector<vector<int>>& matrix,int num) {
		int row = matrix.size();
		int col = matrix[0].size();

		int row_ = num / col;
		int col_ = num % col;
		return matrix[row_][col_];
	}

};

int main()
{
	Solution s;




	std::cin.get();
}
