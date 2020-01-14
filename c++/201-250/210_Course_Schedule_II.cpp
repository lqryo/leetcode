#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>
#include <stack>


using namespace std;

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> inDegree(numCourses, 0); // 保存节点入度

		// 邻接表
		vector<vector<int>> dirTable(numCourses, vector<int>());
		for (auto v : prerequisites)
		{
			inDegree[v[0]]++;
			dirTable[v[1]].push_back(v[0]);
		}

		queue<int> que;
		for (int i = 0; i < inDegree.size(); i++) {
			if (inDegree[i] == 0) que.push(i);
		}

		vector<int> res;
		while (!que.empty())
		{
			auto tmp = que.front();
			que.pop();

			res.push_back(tmp);
			for (auto adjnode : dirTable[tmp]) {
				if (--inDegree[adjnode] == 0)
					que.push(adjnode);
			}
		}

		if (res.size() == numCourses) {
			return res;
		}
		else return vector<int>();

	}
};
 


int main()
{

	cin.get();
}
