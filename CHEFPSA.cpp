#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
 
int modExFa(int a,int b,int m){
    int res=1;
    if(b==0)
        return 1;
    while(b>0){
        if(b&1)
            res=(res%m * a%m)%m;
        a=(a%m * a%m)%m;
        b=b>>1;
    }
    return res%m;
}
int factorials[100001];
int32_t main(){
    int t,n;
    scanf("%lld", &t);
    factorials[0]=1;
    for(int i=1;i<100001;i++){
        factorials[i]=(factorials[i-1]%mod * i%mod)%mod;
    }
    while(t--){
        scanf("%lld", &n);
        int input[2*n],sum_total=0;
        unordered_map<int,int> take_count;
        for(int i=0;i<2*n;i++){
            scanf("%lld", input+i);
            sum_total+=input[i];
            take_count[input[i]]++;
        }
        if(double(sum_total)/(n+1)!=(sum_total/(n+1))){
            printf("0\n");
            continue;
        }
        int sum=(sum_total/(n+1));
        if(take_count[sum]<2){
            printf("0\n");
            continue;
        }
        take_count[sum]-=2;
        if(take_count[sum]==0){
            take_count.erase(sum);
        }
        map<pair<int,int>,int> sudo_pairs;
        bool f=0;
        for(auto v : take_count){
            int k=v.first;
            if((sum&1)==0 && k==(sum/2)){
                if(v.second & 1){
                    f=1;
                    break;
                }
                else{
                    sudo_pairs[{k,k}]=v.second/2;
                    v.second=0;
                }
            }
            if(v.second!=0){
                int val=min(take_count[k],take_count[sum-k]);
                if(take_count.find(sum-k)!=take_count.end() && take_count[sum-k]!=0){
                    if(sudo_pairs.find({k,sum-k})!=sudo_pairs.end()){
                        sudo_pairs[{k,sum-k}]+=val;
                    }
                    else if(sudo_pairs.find({sum-k,k})!=sudo_pairs.end()){
                        sudo_pairs[{sum-k,k}]+=val;
                    }
                    else{
                        sudo_pairs[{k,sum-k}]=val;
                    }
                    take_count[k]-=val;
                    take_count[sum-k]-=val;
                }
                else{
                    f=1;
                    break;
                }
            }
        }
        if(f){
            printf("0\n");
            continue;
        }
        int count2s=0,divBy=1;
        for(auto p : sudo_pairs){
            auto f=p.first;
            if(f.first!=f.second){
                count2s+=p.second;
            }
            if(p.second>1){
                divBy=(divBy%mod * modExFa(factorials[p.second],mod-2,mod)%mod)%mod;
            }
        }
        int mul_by=factorials[n-1];
        int twos=modExFa(2,count2s,mod);
        int ans=(mul_by%mod * twos%mod * divBy%mod)%mod;
        printf("%lld\n", ans);
    }
    return 0;
}
