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
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define pr cout
#define ii(x) << (x) <<" "
#define ln <<'\n'
ll f(ll x) {
	return (x*(x+1)/2);
} 
int main()
{
    ios::sync_with_stdio(false);
	string ss;
	ll s,n,j=-1,p;
	ll ans=0;
	cin>>ss>>s;
	n=ss.size();
	rep(i,0,n){
		if(ss[i]=='E'){
			p=0;
			j=i;
			while(ss[(i+1)%n]!='E') p++,i=(i+1)%n;
			
			if(s>=p) ans+= f(p);
			else 	ans += f(p)-f(p-s);
		}
		if(i<j) break;
	}
	
	if(j!=-1)
		pr ii(1LL*n*s -ans);
	else
		pr ii(0);
}
