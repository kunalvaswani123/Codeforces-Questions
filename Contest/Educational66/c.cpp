#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;
#define pival 3.14159265359
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pqq priority_queue
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
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
const ll L = 2e5 + 5;
ll arr[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,t,n,k;
 	cin >> t;
 	while(t--)
 	{
 		cin >> n >> k;
 		for(i=0;i<n;i++)
 			cin >> arr[i];
 		ll mn = 1e18;
 		ll val;
 		for(i=k;i<n;i++)
 		{
 			if(arr[i] - arr[i-k] < mn)
 			{
 				mn = arr[i] - arr[i-k];
 				val = (arr[i] + arr[i-k]) / 2;
 			}
 		}
 		cout << val << endl;
 	}   
	return 0;
}