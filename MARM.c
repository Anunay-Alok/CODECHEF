#include<stdio.h>
#define lli long long int
int main(){
	lli t,n,k,temp,arr[10001];
	scanf("%lld", &t);
	while(t--){
		scanf("%lld%lld", &n,&k);
		for(lli i=0;i<n;i++){
			scanf("%lld", arr+i);
		}
		for(lli i=0;i<(k%(3*n));i++)
			arr[i%n] = arr[i%n]^arr[n-1-i%n];
		if(n & 1 && k/n>=1)
			arr[n/2] = 0;
		for(lli i=0;i<n;i++)
			printf("%lld ", arr[i]);
		printf("\n");
	}
}
