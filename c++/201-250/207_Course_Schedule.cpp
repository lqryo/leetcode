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

 
// 拓扑排序

 class Solution {
 public:
	 bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		 vector<int> inDegree(numCourses, 0);  // 遍历边缘列表，计算入读
		 
		 // 有向无环DAG图存储，使用邻接表
		 vector<vector<int>> dirTable(numCourses, vector<int>());
		 for (auto v : prerequisites) {
			 inDegree[v[0]]++;  // dstNode入度加1
			 dirTable[v[1]].push_back(v[0]); // 存储srcNode邻接表
		 }

		 queue<int> que;
		 // 找到入度=0的索引作为起始点进行拓扑排序，使用队列queue，先将入度为0的enQueue
		 for (int i = 0; i < inDegree.size(); i++) {
			 if (inDegree[i] == 0) que.push(i);
		 }

		 vector<int> res;
		 while (!que.empty())
		 {
			 auto tmp = que.front();
			 que.pop(); //将入度为0的进行出队,每次出一个

			 res.push_back(tmp);
			 for (auto adjnode : dirTable[tmp]) {
				 if (--inDegree[adjnode] == 0)
					 que.push(adjnode);
			 }
		 }
		 return res.size() == numCourses;

	 }
 };

 


int main()
{
	Solution s;


	cin.get();
}
