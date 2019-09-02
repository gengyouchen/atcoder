#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
	/* time: O(n^2), space: O(n^2) */
	int league(const vector<vector<int>>& A) {
		/* Build the dependency graph of all matches */
		const int n = A.size();
		vector<vector<int>> adjLists(n * n);
		for (int i = 1; i <= n; ++i) {
			int prevMatch = -1;
			for (int j : A[i - 1]) {
				const int playerX = min(i - 1, j - 1), playerY = max(i - 1, j - 1);
				const int currMatch = playerX * n + playerY;
				if (prevMatch != -1)
					adjLists[prevMatch].push_back(currMatch);
				prevMatch = currMatch;
			}
		}

		/* Compute the length of the topological ordering (Kahn's algorithm) */
		vector<int> inDegree(n * n);
		for (const auto& adjList : adjLists) {
			for (int v : adjList)
				++inDegree[v];
		}

		queue<int> q;
		for (int u = 0; u < n * n; ++u) {
			if (!inDegree[u])
				q.push(u);
		}

		int ans = 0, nVisited = 0;
		for (int depth = 1; !q.empty(); ++depth) {
			for (int i = q.size(); i > 0; --i) {
				const int u = q.front();
				++nVisited, q.pop();
				for (int v : adjLists[u]) {
					if (inDegree[v] && !--inDegree[v])
						q.push(v);
				}
			}
			++ans;
		}
		if (nVisited < n * n)
			return -1; /* failed */
		return ans;
	}
};

int main() {
	int n;
	cin >> n;
	vector<vector<int>> A(n, vector<int>(n - 1));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - 1; ++j)
			cin >> A[i][j];
	}

	Solution sol;
	int ans = sol.league(A);
	cout << ans << endl;
	return 0;
}
