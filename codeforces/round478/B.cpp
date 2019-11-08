#include <bits/stdc++.h>

typedef int64_t ll;
typedef uint64_t ull;

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define el "\n"

ll getScore(vector<ll> cur){
	ll ans = 0;
	for(auto i : cur)
		if(i%2 == 0)
			ans += i;
	return ans;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// freopen("in", "r", stdin);

	vector<ll> board(14);
	ll ans = -1;
	for(auto &i : board)
		cin >> i;
	// for(ll i = 0; i < 14; i++)
	// 	cin >> board[i];
	for(ll i = 0; i < board.size(); i++){
		vector<ll> cur = board;
		ll dis = cur[i];
		if(dis == 0)
			continue;
		cur[i] = 0;
		ll idx = 1;
		while(idx <= 14){
			// (idx + i)%14;
			if(idx <= dis)
				cur[(idx+i)%14]++;
			cur[(idx+i)%14] += (dis - idx)/14;
			idx++;
		}
		ans = max(ans, getScore(cur));
	}
	cout << ans;
	return 0;
}
