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
#define mod (ll)1e9+7


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
    	int maxm = INT_MIN,ind1,ind2;
    	FOR(i,0,n){
    		cin>>ar[i];
    		if(ar[i]>maxm){
    			ind1 = i;
    			maxm = ar[i];
    		}
    		if(ar[i]==maxm) ind2 = i;
    	}
    	int x = ((ind2-ind1)>=n/2)?0:(n/2-ind2+ind1); 
    	cout<<x<<"\n";
    }


    // printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
