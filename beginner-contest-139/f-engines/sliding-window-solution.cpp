#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
using LL = long long;
using Arrow = complex<LL>;

class Solution {
public:
	/*
	 * time: O(n*log(n)), space: O(1) auxiliary (i.e. does not count input itself),
	 * assuming sqrt(x) and atan2(x) are in O(1) time
	 */
	double engines(vector<Arrow>& arrows) {
		const int n = arrows.size();
		/*
		 * Assume the final answer is v = Arrow(x, y), where len = abs(v), degree = arg(v)
		 * All the arrows within (degree - 90) ~ (degree + 90) will contribute to this len.
		 * Therefore, if we sort the array of arrows by degree, the answer is one of its subarrays.
		 */
		auto compareAngle = [](const Arrow& a, const Arrow& b) {
			return atan2(imag(a), real(a)) < atan2(imag(b), real(b));
		};
		make_heap(arrows.begin(), arrows.end(), compareAngle);
		sort_heap(arrows.begin(), arrows.end(), compareAngle);

		Arrow window(0, 0);
		LL ans = 0;
		int R = 0;
		for (int L = 0; L < n; ++L) {
			if (R < L)
				R = L, window = Arrow(0, 0);
			while (R - L < n && norm(window + arrows[R % n]) >= norm(window))
				window += arrows[R % n], ++R;
			ans = max(ans, norm(window)), window -= arrows[L % n];
		}
		return sqrt(ans);
	}
};

int main() {
	int n;
	cin >> n;

	vector<Arrow> arrows(n);
	for (int i = 0; i < n; ++i) {
		LL x, y;
		cin >> x >> y;
		arrows[i] = Arrow(x, y);
	}

	Solution sol;
	double ans = sol.engines(arrows);
	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}
