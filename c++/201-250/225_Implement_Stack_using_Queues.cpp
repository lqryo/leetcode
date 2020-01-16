
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



class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		nums.push(x);
		// 将前面的size-1个元素放到后面
		for (size_t i = 0; i < nums.size()-1; i++)
		{
			nums.push(nums.front());
			nums.pop();
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int num = nums.front();
		nums.pop();
		return num;
	}

	/** Get the top element. */
	int top() {
		return nums.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return nums.empty();
	}
private:
	queue<int> nums;

};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main()
{

	cin.get();

	return 0;
}
