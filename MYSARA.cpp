#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX_SIZE 1000001
#define f ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define file freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define vi(vec,n) vector<ll>vec(n)
#define vio(vec,n,a) vector<ll>vec(n,a)
#define FOR(i,a,b) for(ll i=a;(a<b)?i<(ll)b:i>=(ll)b;(a<b)?i+=1:i-=1)
#define eb emplace_back
#define mod (ll)(1e9+7)
#define all(a,b) memset(a,b,sizeof(a));

string decToBinary(int n) 
{ 
	string s = "";
    for (int i = 31; i >= 0; i--) { 
        int k = n >> i; 
        if (k & 1) 
            s+="1"; 
        else
            s+="0"; 
    }
    return s;
} 


int main(){
    // clock_t tStart = clock();
    // file;
    f;
    int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	int ar[n];
    	vio(dp,n,1);
    	FOR(i,0,n) cin>>ar[i];
    	FOR(i,1,n){
    		string a = decToBinary(ar[i]);
    		string b = decToBinary(ar[i-1]);
    		FOR(j,0,32){
    			if(a[j]=='0' && b[j]=='1'){
    				dp[i]=0;
    				break;
    			}
    			if(a[j]=='1' && b[j]=='1') dp[i]*=2;
    		}
    	}
    	ll x = 1;
    	FOR(i,1,n) x = (x%mod * dp[i]%mod)%mod;
    	cout<<(x%mod)<<"\n";
    }
    // printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
