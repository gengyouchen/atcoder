#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	/* time: O(n), space: O(1), where n = |S| */
	bool tapDance(const string& s) {
		const int n = s.size();
		for (int i = 1; i <= n; ++i) {
			const char c = s[i - 1];
			if (i % 2) {
				if (c == 'L')
					return false;
			} else {
				if (c == 'R')
					return false;
			}
		}
		return true;
	}
};

int main() {
	string s;
	cin >> s;

	Solution sol;
	bool ans = sol.tapDance(s);
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
