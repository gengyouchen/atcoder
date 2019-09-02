#include <algorithm>
#include <functional>
#include <iostream>
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

		/* Compute the length of the topological ordering (DFS + DP) */
		vector<bool> inStack(n * n);
		vector<int> depth(n * n);
		using F = function<int(int)>;
		F dfs = [&](int u) {
			if (inStack[u])
				return -1; /* failed */
			if (depth[u])
				return depth[u];

			inStack[u] = true;
			depth[u] = 1;
			for (int v : adjLists[u]) {
				const int len = dfs(v);
				if (len == -1) {
					depth[u] = -1;
					break;
				}
				depth[u] = max(depth[u], 1 + len);
			}
			inStack[u] = false;
			return depth[u];
		};

		int ans = 0;
		for (int u = 0; u < n * n; ++u) {
			const int len = dfs(u);
			if (len == -1)
				return -1; /* failed */
			ans = max(ans, len);
		}
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
