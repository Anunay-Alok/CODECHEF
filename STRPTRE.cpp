#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX_SIZE 100001
#define f ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define file freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define vi(vec,n) vector<ll>vec(n)
#define vio(vec,n,a) vector<ll>vec(n,a)
#define FOR(i,a,b) for(ll i=a;(a<b)?i<(ll)b:i>=(ll)b;(a<b)?i+=1:i-=1)
#define eb emplace_back
#define mod (ll)(1e9+7)
#define all(a,b) memset(a,b,sizeof(a))

ll modpow(ll a,ll b){
    a%=mod;
    ll res = 1;
    while(b>0){
        if(b&1) res = res * a % mod;
        a = a*a % mod;
        b >>= 1;
    }
    return res;
}


ll invModulo(int A)
{
    return modpow(A,mod-2);
}

int main(){
    // clock_t tStart = clock();
    // file;
    // cout<<((22*invModulo(210))%mod)<<"\n";

    f;
    ll t,depth,n;
    ll pow2[2*(MAX_SIZE)+3];
    pow2[0]=1;
    FOR(i,1,2*(MAX_SIZE)+3) pow2[i]=(pow2[i-1]<<1)%mod;
    // FOR(i,0,MAX_SIZE+1) cout<<pow2[i]<<"\n";
    cin>>t;
    while(t--){
        cin>>depth;
        n = depth+1;
        ll sum=0;
        for(int i=1;i<=depth;i+=2){
            ll x = (pow2[n]-pow2[i]+mod)%mod;
            sum+=x;
            sum%=mod;
        }
        ll total = (invModulo((2+pow2[2*n]-pow2[n+1]-pow2[n]+2*mod)%mod))%mod;
        cout<<(sum*total)%mod<<"\n";
    }


    // printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
