#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using LL = long long;

class Solution {
public:
	/* time: O(n + m*log(n)), space: O(n), where n = # of items, m = # of tickets */
	LL powerfulDiscountTickets(const vector<int>& items, int m) {
		LL ans = 0;
		for (int item : items)
			ans += item;

		priority_queue<int> candidates(items.begin(), items.end());
		for (int i = 0; i < m; ++i) {
			const int before = candidates.top(), after = before / 2;
			candidates.pop(), ans -= before;
			candidates.push(after), ans += after;
		}
		return ans;
	}
};

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> items(n);
	for (int i = 0; i < n; ++i)
		cin >> items[i];

	Solution sol;
	LL ans = sol.powerfulDiscountTickets(items, m);
	cout << ans << endl;
	return 0;
}
