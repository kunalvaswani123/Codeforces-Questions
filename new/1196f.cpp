#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;
#define pival 3.14159265359
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl '\n'
#define pqq priority_queue
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define ordered_set tree <ll, null_type,less<ll>, rb_tree_tag, tree_order_statistics_node_update>
//K-th smallest
//cout << k << "kth smallest: " << *A.find_by_order(k - 1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;
ll power(ll x, ll y, ll p)
{ 
    ll res = 1;  
    x = x % p;
    while (y > 0) { 
        if (y & 1) res = (res * x) % p; 
        y = y >> 1;
        x = (x * x) % p;   
    } 
    return res; 
}
const ll L = 2e5 + 5;
bool cmp(const pll &a,const pll &b) 
{ 
    return a.se < b.se;
}
vector <pll> ad[L];
vector <pll> ad2[L];
set <ll> check[L];
map <pll,ll> ms;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m, k;
    cin >> n >> m >> k;
    ll x, y, w;
    set <pair<ll,pll> > edgs;
 	for (ll i = 0; i < m; i++) {
 		cin >> x >> y >> w;
 		ad[x].pb({y, w});
 		ad[y].pb({x, w});
 		check[x].insert(y);
 		check[y].insert(x);
 		pll temp = {min(x,y),max(x,y)}; 
 		ms[temp] = w;
 		edgs.insert({w,{min(x,y),max(x,y)}});
 	}
 	for (ll i = 1; i <= n; i++) {
 		sort(all(ad[i]), cmp);
 		for (ll j = 0; j < min((ll)500, sz(ad[i])); j++)
 			ad2[i].pb(ad[i][j]);
 	}
 	ll c = 1;
 	while (c < k) {
 		pair <ll,pll> p = *edgs.begin();
 		edgs.erase(edgs.begin());
 		ll v1 = p.se.fi;
 		ll v2 = p.se.se;
 		for (ll j = 0; j < sz(ad2[v1]); j++) {
			ll ver = ad2[v1][j].fi;
 			if (ver == v2)
 				continue;
 			else {
 				if (check[min(v2,ver)].find(max(ver,v2)) != check[min(v2,ver)].end()) {
	 				if ((p.fi + ad2[v1][j].se) < ms[{min(v2,ver),max(v2,ver)}]) {
		 				edgs.insert({p.fi + ad2[v1][j].se,{min(v2,ver),max(v2,ver)}});
		 				edgs.erase(edgs.find({ms[{min(v2,ver),max(v2,ver)}],{min(v2,ver),max(v2,ver)}}));
		 				ms[{min(v2,ver),max(v2,ver)}] = p.fi + ad2[v1][j].se;
	 				}
 				}
 				else {
 					check[min(v2,ver)].insert(max(ver,v2));
 					check[max(v2,ver)].insert(min(ver,v2));
	 				edgs.insert({p.fi + ad2[v1][j].se,{min(v2,ver),max(v2,ver)}});
	 				ms[{min(v2,ver),max(v2,ver)}] = p.fi + ad2[v1][j].se;
 				}
 			}
 		}
 		for (ll j = 0; j < sz(ad2[v2]); j++) {
			ll ver = ad2[v2][j].fi;
 			if (ver == v1)
 				continue;
 			else {
				if (check[min(v1,ver)].find(max(ver,v1)) != check[min(v1,ver)].end()) {
					if ((p.fi + ad2[v2][j].se) < ms[{min(v1,ver),max(v1,ver)}]) {
		 				edgs.insert({p.fi + ad2[v2][j].se,{min(v1,ver),max(v1,ver)}});
		 				edgs.erase(edgs.find({ms[{min(v1,ver),max(v1,ver)}],{min(v1,ver),max(v1,ver)}}));
		 				ms[{min(v1,ver),max(v1,ver)}] = p.fi + ad2[v2][j].se;
					}
 				}
 				else {
 					check[min(v1,ver)].insert(max(ver,v1));
 					check[max(v1,ver)].insert(min(ver,v1));
	 				edgs.insert({p.fi + ad2[v2][j].se,{min(v1,ver),max(v1,ver)}});
	 				ms[{min(v1,ver),max(v1,ver)}] = p.fi + ad2[v2][j].se;
 				}
 			}
 		}
 		c++;
 	}
 	cout << (*edgs.begin()).fi << endl;
	return 0;
}