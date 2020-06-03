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

/*the primeFactors function is taken from geeksforgeeks*/
int primeFactors(int n){
    int count=0; 
    while (n % 2 == 0){
        count++;
        n = n/2;  
    }  
    for (int i = 3; i <= sqrt(n); i = i + 2){  
        while (n % i == 0){  
            count++;
            n = n/i;  
        }  
    }  
    if (n > 2)  
        count++;
    return count;
} 


int main(){
    // clock_t tStart = clock();
    // file;
    f;
    int t;
    cin>>t;
    while(t--){
        int x,k;
        cin>>x>>k;
        if(primeFactors(x)>=k)
            cout<<1<<"\n";
        else cout<<0<<"\n";
    }


    // printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
