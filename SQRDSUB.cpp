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

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ar[n];
        vector<ll>indices;
        vector<ll>v1,v2;
        FOR(i,0,n,1){
            cin>>ar[i];
            if(ar[i]%2==0 && ar[i]%4!=0){
                indices.eb(i);
            }
        }
        ll i=0;
        int flag=0;
        while(i<n){
            if(flag){
                if(!(ar[i]&1)){
                    v2.eb(i-1);
                    flag=0;
                }
            }
            else{
                if(ar[i]&1){
                    flag=1;
                    v1.eb(i);
                }
            }
            i++;
        }
        if(flag==1){
            if(ar[n-1]&1) v2.eb(n-1);
            else v2.eb(v1[v1.size()-1]);
        }
        ll sum=0;
        FOR(i,0,indices.size(),1){
            ll mul=1;
            int index1 = lower_bound(v1.begin(), v1.end(),indices[i]+1)-v1.begin();
            int index2 = lower_bound(v2.begin(), v2.end(),indices[i]-1)-v2.begin();
            if(index1!= v1.size() && v1[index1]==(indices[i]+1)) mul*=(v2[index1]-v1[index1]+2);
            if(index2!= v2.size() && v2[index2]==(indices[i]-1)) mul*=(v2[index2]-v1[index2]+2);
            sum+=mul;
        }
        cout<<((n*(n+1))/2-sum)<<"\n";
    }
    return 0;
}
