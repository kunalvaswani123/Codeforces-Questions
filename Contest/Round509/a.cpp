#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
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
const ll L=1e5;
ll arr[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll n,i;
 	cin>>n;
 	ll min=INT_MAX;
 	ll max=INT_MIN;
 	for(i=0;i<n;i++)
 	{
 		cin>>arr[i];
 	}
 	ll j;
 	ll count=1;
 	sort(arr,arr+n);
	for(j=1;j<n;j++)
		count+=(arr[j]-arr[j-1]);
 	cout<<count-n<<endl;
	return 0;
}