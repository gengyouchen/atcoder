#include <iostream>

using namespace std;

class Solution {
public:
	/* time: O(1), space: O(1) */
	int powerSocket(int a, int b) {
		const int needs = (b - 1), unit = (a - 1);
		return (needs + (unit - 1)) / unit;
	}
};

int main() {
	int a, b;
	cin >> a >> b;

	Solution sol;
	int ans = sol.powerSocket(a, b);
	cout << ans << endl;
	return 0;
}
