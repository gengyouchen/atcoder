#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
using LL = long long;

#define MOD 1000000007

class RollingHash {
private:
	LL mod(LL x) { return (x % MOD + MOD) % MOD; }
	LL h = 0, w = 0;
public:
	template <class I>
	RollingHash(I first, I last) {
		for (auto it = first; it != last; ++it)
			h = mod(h * 256 + *it), w = w ? mod(w * 256) : 1;
	}
	void roll(char L, char R) { h = mod((h - w * L) * 256 + R); }
	operator int() const { return h; }
};

class Solution {
private:
	template <class F>
	int lowestTrue(int low, int high, F cond) {
		while (low < high) {
			const int mid = low + (high - low) / 2;
			if (cond(mid))
				high = mid;
			else
				low = mid + 1;
		}
		return low;
	}
public:
	/* time: O(n*log(n)), space: O(n), where n = |S| */
	int whoSaysAPun(const string& S) {
		const int n = S.size();
		auto cond = [&](int len) {
			unordered_map<int, int> h;
			RollingHash curr(S.begin(), S.begin() + len);
			for (int L = 0, R = len - 1; R < n; ++L, ++R) {
				const auto it = h.find(curr);
				if (it == h.end())
					h[curr] = L;
				else if (L - it->second >= len && !S.compare(it->second, len, S, L, len))
					return false; /* found */
				if (R != n - 1)
					curr.roll(S[L], S[R + 1]);
			}
			return true; /* not found */
		};
		return lowestTrue(1, n, cond) - 1;
	}
};

int main() {
	int n;
	cin >> n;

	string S;
	cin >> S;

	Solution sol;
	int ans = sol.whoSaysAPun(S);
	cout << ans << endl;
	return 0;
}
