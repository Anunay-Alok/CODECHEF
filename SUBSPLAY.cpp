#include<bits/stdc++.h>
using namespace std;

typedef struct record{
	int last;
}record;

int main(){
	int t,a,n,jhanda,maxima;
	record all[26];
	char stringa[100001];
	cin>>t;
	while(t--){
		maxima = 0;
		jhanda=0;
		cin>>n>>stringa;
		for(int i=0;i<26;i++){
			all[i].last=-1;
		}
		for(int i=0;i<n;i++){
			if(all[stringa[i]-'a'].last!=-1 && (all[stringa[i]-'a'].last + n - i)>maxima){
				maxima = all[stringa[i]-'a'].last + n - i;
			}
			all[stringa[i]-'a'].last = i;
		}
		cout<<maxima<<"\n";
	}
}
