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
    ll a[4],b[4],x[4],y[4];
    pair <ll,ll> pq(ll num,ll type){
    	switch (type){
    		case 0:return mp(x[num],y[num]); break;
    		case 1:return mp(a[num]+b[num]-y[num],-a[num]+b[num]+x[num]); break;
    		case 2:return mp(a[num]+a[num]-x[num],b[num]+b[num]-y[num]); break;
    		case 3:return mp(a[num]-b[num]+y[num],a[num]+b[num]-x[num]);  break;
    	}
    }
     
    ll d2(pair <ll,ll> x,pair <ll,ll> y){
    	return (x.fi-y.fi)*(x.fi-y.fi) + (x.se-y.se)*(x.se-y.se);
    }
    ll f(ll x){
    	ll t[4]={},o,c[6]={};
    	pair <ll,ll> v[4]={};
    	t[0] = x%(1<<2);
    	t[1] = x%(1<<4)/(1<<2);
    	t[2] = x%(1<<6)/(1<<4);
    	t[3] = x%(1<<8)/(1<<6);
    //	cout<<t[0]<<" "<<t[1]<<" "<<t[2]<<" "<<t[3]<<endl;
    	v[0] = pq(0ll,t[0]);
    	v[1] = pq(1ll,t[1]);
    	v[2] = pq(2ll,t[2]);
    	v[3] = pq(3ll,t[3]);
    //	for (int i=0;i<4;i++){
    //		cout<<v[i].fi<<"*"<<v[i].se<<" ";
    //	}
    	o=0;
    	for (int i=0;i<3;i++)
    		for (int j=i+1;j<4;j++)
    			c[o++]=d2(v[i],v[j]);
    	sort(c,c+6);
    //	for (int i=0;i<6;i++)
    //		cout<<c[i]<<" ";
    //	cout<<endl;
    	if (c[0]!=0 and c[0]==c[1] and c[1]==c[2] and c[2]==c[3] and c[3]*2==c[4] and c[4]==c[5]){
    //		for (int i=0;i<4;i++){
    //			cout<<v[i].fi<<"*"<<v[i].se<<" ";
    //		}
    //		cout<<" "<<t[0]<<" "<<t[1]<<" "<<t[2]<<" "<<t[3]<<endl;
    		return t[0]+t[1]+t[2]+t[3];
    	}
    	else
    		return 16;
    }
    int main()
    {
        ios::sync_with_stdio(false);
    	ll n,ans=16;
    	cin>>n;
    	for (int i=0;i<n;i++){
    		ans = 16;
    		for (int j=0;j<4;j++)
    			cin>>x[j]>>y[j]>>a[j]>>b[j];
    		for (int j=0;j<(1<<8);j++)
    			ans = min(f(j),ans);
    		if (ans==16)
    			cout<<-1<<endl;
    		else
    			cout<<ans<<endl;
    	}
    }
