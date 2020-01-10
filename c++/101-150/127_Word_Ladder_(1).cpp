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


using namespace std;

// BFS 100ms

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList)
	{
		unordered_set<string> dict(wordList.begin(),wordList.end());
		if (!dict.count(endWord)) return 0;

		queue<string> q;
		q.push(beginWord);

		int l = beginWord.length();
		int step = 0;

		while (!q.empty())
		{
			++step;
			for (size_t size = q.size(); size > 0; size--)
			{
				string w = q.front();
				q.pop();   // remove the first element
				for (size_t i = 0; i < l; i++)
				{
					char ch = w[i];
					for (size_t j = 'a'; j <= 'z'; j++)
					{
						w[i] = j;
						// Found the solution
						if (w == endWord) return step + 1;
						// Not in dict,skip it
						if (!dict.count(w)) continue;
						// Remove new word from dict
						dict.erase(w);
						// Add new word into queue
						q.push(w);
					}
					w[i] = ch;
				}
			}
		}
		return 0;

	}

};




int main(int argc, char* argv[])
{



	Solution S;

	

	std::cin.get();
}
