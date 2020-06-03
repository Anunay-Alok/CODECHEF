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
#define mod (ll)(998244353)
#define all(a,b) memset(a,b,sizeof(a))

struct expre{
    ll p;
    ll q;
    ll r;
    ll s;
};

expre solve(expre e1,expre e2,char z){
    // ll a=e1.p,b=e1.q,c=e2.r,d=e2.;
    ll a = e1.p,b = e1.q,c = e1.r, d=e1.s;
    ll t = e2.p,u = e2.q,v = e2.r, w=e2.s;
    if(z=='&')
        return (expre){((a*(t+u+v+w))+(t*(b+c+d))+(c*w)+(d*v))%mod,(b*u)%mod,((c*u)+(b*v)+(c*v))%mod,((d*w)+(d*u)+(b*w))%mod};
    if(z=='|')
        return (expre){(a*t)%mod,((b*(t+u+v+w))+(u*(a+c+d))+(c*w)+(d*v))%mod,((c*t)+(a*v)+(c*v))%mod,((d*t)+(a*w)+(d*w))%mod};
    if(z=='^')
        return (expre){((a*t)+(b*u)+(c*v)+(d*w))%mod,((b*t)+(a*u)+(d*v)+(c*w))%mod,((c*t)+(a*v)+(d*u)+(b*w))%mod,((c*u)+(b*v)+(d*t)+(a*w))%mod};
}

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
    f;
    int t;
    cin>>t;
    string s;
    while(t--){
        cin>>s;
        int n = s.length();
        stack<char>currSym;
        stack<expre>exps;
        ll x=0;
        FOR(i,0,n,1){
            if(s[i]=='#')
                exps.push((expre){1,1,1,1});
            else if(s[i]==')'){
                expre e1=exps.top();
                exps.pop();
                expre e2=exps.top();
                exps.pop();
                char x = currSym.top();
                currSym.pop();
                exps.push(solve(e1,e2,x));
            }
            else if(s[i]!='(')
                currSym.push(s[i]);
        }
        expre temp = exps.top();
        ll sum = (temp.p + temp.q + temp.r + temp.s)%mod;
        sum = invModulo(sum);
        cout<<(temp.p*sum)%mod<<" "<<(temp.q*sum)%mod<<" "<<(temp.r*sum)%mod<<" "<<(temp.s*sum)%mod<<"\n";
    }


    // printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
