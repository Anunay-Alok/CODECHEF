#include<bits/stdc++.h>
using namespace std;
#define lli long long int

int main(){
	lli t,n,m,q,i,j;
	vector<lli> vecn(10e6+1,0),vecm(10e6+1,0);
	cin>>t;
	while(t--){
		lli countn = 0,countm = 0;
		cin>>n>>m>>q;
		while(q--){
			cin>>i>>j;
			vecn[i]+=1;
			vecm[j]+=1;
		}
		for(lli i=1;i<=n;i++)
			if(vecn[i] & 1)
				countn++;
		for(lli i=1;i<=m;i++)
			if(vecm[i] & 1)
				countm++;
		cout<<countn*m+n*countm-2*countm*countn<<"\n";
		for(int i=1;i<=m;i++)
			vecm[i]=0;
		for(int i=1;i<=n;i++)
			vecn[i]=0;
	}
}
