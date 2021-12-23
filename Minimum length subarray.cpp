//Author @Harsh_xerus

#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define rep(i,n) for (int i = 0; i < n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ll long long 
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpll vector<pll>
#define INF 1e18
#define nl '\n'
const ll maxn = 2e5 + 100;
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;

//--------------------------Helper_functions-------------------------------//

//-------------------------------GCD---------------------------------------//

ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}

//-------------------------------LCM---------------------------------------//

ll lcm(ll a, ll b){return (a * b) / gcd(a, b);}

//----------------------------Factorial------------------------------------//

ll fact(ll x){if(x==0)return 1;return (x*fact(x-1))%mod;}

//-----------------------------Bin_Expo------------------------------------//

ll binpow(ll a,ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}

//-------------------------Sum/Count of digits----------------------------//

ll sd(ll x){ll temp=0;while(x>0){temp+=x%10;x/=10;}return temp;}
ll cd(ll x){ll temp=0;while(x>0){temp++;x/=10;}return temp;}

//-------------------------------START------------------------------------//

ll possible(ll arr[], int mid , int n , int k){
    ll sum=0;
    ll ans=-1;
    for(int i=0;i<n;i++){
        if(i+1<=mid){
            sum+=arr[i];
        }
        else{
            ans=max(ans,sum);
            sum-=arr[i-mid];
            sum+=arr[i];
        }
        
    }
    ans=max(ans,sum);
    if(ans>=k)
        return 1;
    else
        return 0;
}

////minimum length subarray with given target sum ,..........if possible return the minimum length else return -1

ll minsubarray(ll arr[], int n , int k){
    ll low=1;
    ll high=n;
    ll exist=false;
    while(low<high){
        ll mid=(high+low)/2;
        if(possible(arr, mid , n ,k)){
            exist=true;
            high=mid;
        }
        else
            low=mid+1;
        
    }
    if(exist)
        return low;
    else
        return -1;
}

void solve(){ 
    ll n,m,k;
    cin>>n>>k;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<minsubarray(arr,n,k)<<nl;

}

int main(){
    ll t = 1, i = 1;
    //cin >> t;
    while (t--)
    {
        //cout << "Case #" << i << ": ";   //only during google contest
        //i++;                             //only during google contest

        solve();
    }
}
