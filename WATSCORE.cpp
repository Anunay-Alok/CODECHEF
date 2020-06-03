#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n,a,b;
	cin>>t;
	int sum;
	int arr[9];
	while(t--){
		sum=0;
		cin>>n;
		memset(arr,0,sizeof(arr));
		for(int i=0;i<n;i++){
			cin>>a>>b;
			if(a<9){
				if(b>arr[a])
					arr[a]=b;
			}
		}
		for(int k=0;k<9;k++)
			sum+=arr[k];
		cout<<sum<<"\n";
	}
}
