#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n,ar[129];
	int infoCount[129];
	int index[129];
	int infoPrev[129];
	for(int i=0;i<129;i++){
		infoCount[i]=-1;
		infoPrev[i]=-1;
	}
	ar[0]=0;
	infoCount[0]=0;
	index[0]=0;
	for(int i=1;i<129;i++){
		if(infoCount[ar[i-1]]==0)
			ar[i]=0;
		else
			ar[i]=i-1-infoPrev[ar[i-1]];
		if(infoCount[ar[i]]>=0)
			infoPrev[ar[i]]=index[ar[i]];
		index[ar[i]]=i;
		infoCount[ar[i]]+=1;
	}
	// for(int i=0;i<128;i++){
	// 	cout<<ar[i]<<" ";
	// }
	cin>>t;
	int count;
	while(t--){
		count=0;
		cin>>n;
		for(int i=0;i<n;i++)
			if(ar[i]==ar[n-1])
				count++;
		cout<<count<<"\n";
	}
}
