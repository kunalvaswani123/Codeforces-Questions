#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
#define american_pie 3.1415926535
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define qq queue
#define pqq priority_queue
ll power(ll x,ll y,ll p) 
{ 
    ll res=1;  
    x=x%p;
    while (y > 0) 
    { 
        if(y&1) 
            res=(res*x)%p; 
        y=y>>1;
        x=(x*x)%p;   
    } 
    return res; 
}
const ll L = 1e5;
ll arr[L];
ll marked[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll n, i;
	cin >> n;
	for(i=1;i<=n;i++)
		cin>>arr[i];
	ll ans = 0;
	ll next = 0;
	for(i=1;i<=n;i++)
	{
		next = max(next, arr[i]);
		if(i == next)
			ans++;
	}
	cout << ans << endl;
	return 0;
}