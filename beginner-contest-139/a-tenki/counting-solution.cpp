#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	/* time: O(1), space: O(1) */
	int tenki(const string& S, const string& T) {
		int ans = 0;
		for (int i = 0; i < 3; ++i) {
			if (S[i] == T[i])
				++ans;
		}
		return ans;
	}
};

int main() {
	int a;
	string S, T;
	cin >> S >> T;

	Solution sol;
	int ans = sol.tenki(S, T);
	cout << ans << endl;
	return 0;
}
