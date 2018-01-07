// TOI13 : ART solution
#include <vector>
#include <utility>
#include <functional>
#include <iostream>
using namespace std;
typedef std::pair<int,int> pii;
typedef long long lli;

const int n = 1 << 20;
const int mxlen = 4e6 + 10;

int seg[n<<1]; // complete segment tree
std::vector<pii> line[mxlen]; // high, value

// binary search on prefixsum segment tree
inline int b_search (const std::function<bool(int)>& op){
	int sm = seg[1], x = 1;
	while (x < n){
		if  (op(sm - seg[x<<1])){
 			sm -= seg[x<<1];
 			x = x<<1|1;
 		}else 	x = x<<1;
 	}
 	return x - n;
}

int main(){
	cin.sync_with_stdio(false);
 	int _n, target;
 	cin >> _n >> target;
 	while(_n--){
 	int ps, hi, wi, vl;
 		cin >> ps >> hi >> wi >> vl;
 		line[ps].emplace_back(hi,vl);
		line[ps+wi].emplace_back(hi,-vl);
 	}

 	lli ans = 0;
	auto lower_f = std::bind1st (std::less      <int>(), target); // compare function
	auto upper_f = std::bind1st (std::less_equal<int>(), target);

	for (int old_val = 0, i = 0; i != mxlen; ++i){
		if (line[i].empty()){
			ans += old_val;
			continue;
		}
 		for (pii p : line[i]){ // update segment tree
			int x = p.first, v = p.second;
 			for (x += n; x != 0; x >>= 1) seg[x] += v;
 		}
		ans += (old_val = b_search(upper_f) - b_search(lower_f));
	}
	cout << ans;
}
