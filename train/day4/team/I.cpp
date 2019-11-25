#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define fi first
#define se second
#define po pop
#define pu push
#define ety empty
#define tp top
#define ft front
#define bk back
#define ll long long
 
map<ll, ll> memoList;
map<ll, bool> leaf;
vector< vector<ll> > lst;
ll n, l;
 
ll MOD = 1000000000 + 7;
 
ll add(ll val1, ll val2){
	if((val1+val2) >= MOD)
		return (val1+val2)%MOD;
	return (val1+val2);
}
 
ll dfs(vector<ll> cur){
	ll lf = 0;
	for(ll i = 0; i < cur.size(); i++){
		if(cur[i] > l){
			lf++;
			leaf[cur[i]] = true;
		}
		else{
			if(memoList[cur[i]] == 0){
				memoList[cur[i]] = dfs(lst[cur[i]])%MOD;
			}
			lf = add(lf, memoList[cur[i]]);
		}
	}
	return (lf%MOD);
}
 
int main()
{
    ios::sync_with_stdio(false);
	cin >> n >> l;
	ll tmp1;
	vector<ll> padding(0);
	lst.push_back(padding);
	for(ll i = 0; i < l; i++){
		cin >> tmp1;
		vector<ll> tmp(tmp1);
		for(ll j = 0; j < tmp1; j++)
			cin >> tmp[j];
		lst.push_back(tmp);
	}
	cout << dfs(lst[1]) << " ";
	ll check = 0;
	for(ll i = 1; i<= n; i++)
		if(leaf[i])
		check++;
	cout << check;
}
