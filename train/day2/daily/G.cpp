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
int a[100005],x;
int main()
{
    ios::sync_with_stdio(false);
	ll n,m;
	cin>>n;
	for(int i=0;i<n;i++) { cin >> a[i]; if(i) a[i]+=a[i-1];	}
	cin>>m;
	
	while(m--){
		cin>>x;
		cout << 	(lower_bound  (a,a+n,x) -a)+1 << "\n";
	}
}
