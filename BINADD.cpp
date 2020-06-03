#include<bits/stdc++.h>
using namespace std;
int maxof(int a,int b){
	if(a>b)
		return a;
	return b;
}

int main(){
	int t,count;
	cin>>t;
	string a,b,string1,string2;
	while(t--){
		cin>>a;
		cin>>b;
		int len1 = a.length(),len2 = b.length(),jhanda1=0,jhanda2=0,agar2hoto=0;
		for(int i=0;i<len2;i++){
			if(b[i]=='1'){
				jhanda2 = 1;
				break;
			}
		}
		if(jhanda2==0)
			cout<<0<<"\n";
		else{
			for(int i=0;i<len1;i++){
				if(b[i]=='1'){
					jhanda1 = 1;
					break;
				}
			}
			if(jhanda1==0)
				cout<<1<<"\n";
			else{
				string1="";
				int badawala = maxof(len2,len1);
				int min = (badawala^len2)^len1;
				for(int i=0;i<badawala-min;i++){
					string1+='0';
				}
				if(min==len2){
					b = '0'+string1+b;
					a = '0'+a;
				}
				else{
					a = '0'+string1+a;
					b = '0'+b;
				}
				string2 = "";
				for(int i=0;i<=badawala;i++){
					string2 += (char)(a[i]+b[i]-48);
					if(string2[i]=='2')
						agar2hoto=1;
				}
				if(agar2hoto==0)
					cout<<1<<"\n";
				else{
					int akhiri=INT_MAX,sabsebada=0;
					for(int i=badawala;i>=0;i--){
						if(akhiri != i && string2[i]!='1'){
							if(akhiri-i-1>sabsebada && akhiri!=INT_MAX){
								sabsebada = akhiri-i-1;
							}
							if(string2[i]=='2')
								akhiri=i;
							else akhiri = INT_MAX;
						}
					}
					cout<<sabsebada+2<<"\n";
				}
			}
		}
	}
}
