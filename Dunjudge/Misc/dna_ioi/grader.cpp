#include "dna.h"
#include <iostream>
#include <algorithm>
#include <vector>

static std::string s;
static int tests;

bool make_test(std::string p) {
	tests++;
	std::string ss = p + "#" + s;
	std::vector<int> pr(ss.size() + 1);
	pr[0] = -1;
	bool answer = false;
	for (int i = 1; i <= ss.size(); i++) {
		int k = pr[i - 1];
		while (k >= 0 && ss[k] != ss[i - 1])
			k = pr[k];
		pr[i] = k + 1;
		if (pr[i] == p.size()) {
			answer = true;
			break;
		}
	} 
	return answer;
}


int main() {
	freopen("in.txt","r",stdin);
    int t;
    std::cin >> s >> t;
    std::string ans = analyse(s.size(), t);
    std::cout << tests << std::endl << ans << std::endl;
    return 0;
}