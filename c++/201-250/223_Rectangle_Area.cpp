
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>

using namespace std;



class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		long long S1 = (D - B)*(C - A);
		long long S2 = (G - E)*(H - F);

		long long S3 = overlay(A, C, E, G) * overlay(F,H,B,D);  //×¢Òâ²ÎÊýË³Ðò

		return S1 + S2 - S3;
	}

private:
	int overlay(int a1, int a2, int b1, int b2)
	{
		if (a2 <= b1 || b2 <= a1) return 0;

		if (a1 <= b1) {
			return min(a2, b2) - b1;
		}
		else {
			return min(a2, b2) - a1;
		}
	}
};

int main()
{
	Solution s;

	cout << s.computeArea(-3, 0, 3, 4, 0, -1, 9, 2);

	cin.get();

	return 0;
}
