#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	/* time: O(n), space: O(1) */
	int lower(const vector<int>& h) {
		const int n = h.size();
		int ans = 0, L = 0;
		for (int R = 0; R < n; ++R) {
			ans = max(ans, R - L);
			if (R < n - 1 && h[R] < h[R + 1])
				L = R + 1;
		}
		return ans;
	}
};

int main() {
	int n;
	cin >> n;

	vector<int> h(n);
	for (int i = 0; i < n; ++i)
		cin >> h[i];

	Solution sol;
	int ans = sol.lower(h);
	cout << ans << endl;
	return 0;
}
