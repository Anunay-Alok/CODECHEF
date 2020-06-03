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
    int n,x;
    cin>>n;
    int ar[n];
    FOR(i,0,n,1){
    	cin>>ar[i];
    	if(ar[i]==2) ar[i]=-1;
    }
    x = 0;
    int mxR = 0,maxm=-1,index1,index2=-1,index3;
    FOR(i,0,n,1){
    	x+= ar[i];
    	if(x > maxm){
    		index1 = i+1;
    		maxm = x;
    	}
    	if(x == 0){
    		if(i-index2 > mxR){
    			mxR = i-index2;
    			index3 = index2+2;
    		}
    		index2 = i;
    	}
    }
    int a=0;
    FOR(i,0,1000000000,1) a++;
    cout<<maxm<<" "<<index1<<" "<<mxR<<" "<<index3<<"\n";


    // printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
