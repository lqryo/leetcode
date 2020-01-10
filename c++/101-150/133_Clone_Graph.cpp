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


using namespace std;



// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}
};

class Solution {
public:
	Node* cloneGraph(Node* node) {
		if (node == NULL) return NULL;

		// 利用队列实现BFS
		queue<Node*> m_queue;
		map<Node*, Node*> m_map;
		unordered_set<Node*> m_set;
		Node *temp, *p;

		m_queue.push(node);
		m_set.insert(node);

		// 首先BFS所有节点，创建新节点，并保存新节点与原节点的映射关系
		while (!m_queue.empty())
		{
			// 出队元素
			temp = m_queue.front();
			m_queue.pop();

			//创建新节点
			p = new Node(temp->val);
			m_map.insert({ temp,p });


			// 入队元素
			for (auto neighbor : temp->neighbors) {
				if (m_set.count(neighbor) == 0) { // neighbor不在m_map中
					m_set.insert(neighbor);
					m_queue.push(neighbor);
				}
			}
		}

		// 遍历所有节点，完成边的链接
		for (auto x : m_map) {
			for (auto neighbor : x.first->neighbors) {
				x.second->neighbors.push_back(m_map.find(neighbor)->second);
			}
		}

		return m_map.find(node)->second;
	}
	
};



int main(int argc, char* argv[])
{
	Solution S;


	std::cin.get();
}
