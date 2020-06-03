#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int MAXN = 2222222;
 
int fac[MAXN], inv[MAXN], Tn;
 
int power (int x, int y) {
	if (y == 1)
		return x;
	int q = power(x, y / 2);
	q = (q * 1LL * q) % MOD;
	if (y & 1)
		q = (q * 1LL * x) % MOD;
	return q;
}
 
int C (int n, int k) {
	inv[k] = power(fac[k], MOD - 2);
	inv[n - k] = power(fac[n - k], MOD - 2);
	return (((fac[n] * 1LL * inv[k]) % MOD) * 1LL * inv[n - k]) % MOD;
}
int main(){
	fac[0] = inv[0] = 1;
	for(int i = 1; i <= 2000000; i++) {
		fac[i] = (fac[i - 1] * 1LL * i) % MOD;
	}
	int t,n,fmeonekitna,smeonekitna;
	string string1,string2;
	cin>>t;
	while(t--){
		fmeonekitna=smeonekitna=0;
		cin>>n;
		cin>>string1>>string2;
		for(int i=0;i<n;i++){
			if(string1[i]=='1')
				fmeonekitna++;
			if(string2[i]=='1')
				smeonekitna++;
		}
		int jod=0,shunyaKitna,ekKitna;
		int i = abs(fmeonekitna-smeonekitna);
		if(i!=0){
			shunyaKitna = n-min(fmeonekitna,smeonekitna)-i;
			ekKitna = max(fmeonekitna,smeonekitna)-i;
		}
		else{
			ekKitna =  fmeonekitna;
			shunyaKitna = n-fmeonekitna;
		}
		jod+=C(n,min(i,(n-i)));
		jod = jod%1000000007;
		if(i==n)
			cout<<1<<"\n";
		else{
			while(shunyaKitna && ekKitna){
				i+=2;
				shunyaKitna--;
				ekKitna--;
				jod+=C(n,min(i,(n-i)));
				jod = jod%1000000007;
			}
			cout<<jod<<"\n";
		}
	}
}
