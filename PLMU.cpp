#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	cin>>t;
	int total1,total2,i;
	int arr[2];
	while(t--){
		total1=0;
		total2=0;
		cin>>n;
		memset(arr,0,sizeof(arr));
		for(int j=0;j<n;j++){
			cin>>i;
			if(i==0)
				total1++;
			if(i==2)
				total2++;
		}
		total1=total1*(total1-1)/2;
		total1+=total2*(total2-1)/2;
		cout<<total1<<"\n";
	}
}
