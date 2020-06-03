#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX_SIZE 1000001
#define f ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define file freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define vi(vec,n) vector<ll>vec(n)
#define vio(vec,n,a) vector<ll>vec(n,a)
#define FOR(i,a,b,c) for(ll i=a;(c)?i<(ll)b:i>=(ll)b;(c)?i+=1:i-=1)
#define eb emplace_back
#define mod (ll)(1e9+7)
#define all(a,b) memset(a,b,sizeof(a))

int main(){
    // clock_t tStart = clock();
    // file;
    f;
    int t;
    cin>>t;
    int n;
  	while(t--){
  		cin>>n;
  		int a[n],b[n];
  		pair<int,int> c[n];
  		FOR(i,0,n,1) cin>>a[i];
  		FOR(i,0,n,1) cin>>b[i];
  		FOR(i,0,n,1) c[i] = {(a[i]+b[i]),i};
  		sort(c,c+n,greater<>());
  		int sum = 0;
  		int i=0;
  		FOR(i,0,n,1){
  			if(i&1) sum-=b[c[i].second];
  			else sum+=a[c[i].second];
  		}
  		if(sum > 0) cout<<"First";
  		else if(sum < 0) cout<<"Second";
  		else cout<<"Tie";
  		cout<<"\n";
  	}


    // printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
