#include<stdio.h>
#define ll long long 
int main(){
	ll t;
	scanf("%lld", &t);
	while(t--){
		ll n,m,result=0;
		scanf("%lld%lld", &n,&m);
		ll ar[n][m];
		result+=n*m;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				scanf("%lld", &ar[i][j]);
			}
		}
		if(n<3 && m<3){
			printf("%lld\n", n*m);
		}
		else{
			for(ll i=1;i<n-1;++i){
				for(ll j=1;j<m-1;++j){
					for(ll k=1;;++k){
						if(i-k<=-1 || j-k<=-1 || i+k>=n || j+k>=m){
							goto cont;
						}
						else if(ar[i][j-k]==ar[i][j+k] && ar[i-k][j]==ar[i+k][j]){
							++result;
						}
						else{
							goto cont;
						}
					}
					cont:
					continue;
				}
			}
			printf("%lld\n", result);
		}
	}
}
