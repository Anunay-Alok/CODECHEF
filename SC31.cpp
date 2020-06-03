#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,t,count;
	cin>>t;
	while(t--){
	cin>>n;
	char ar[10],arr[10];
	for(int i=0;i<10;i++)
		cin>>ar[i];
	if(n==1){
		count=0;
	}
	else{
		n--;
		count=0;
		while(n--){
			for(int i=0;i<10;i++){
				cin>>arr[i];
				if((ar[i]-'0')^(arr[i]-'0'))
					ar[i]='1';
				else ar[i]='0';
			}
		}
	}
	for(int i=0;i<10;i++){
		if(ar[i]=='1')
			count++;
	}
	cout<<count<<"\n";
	}
}
