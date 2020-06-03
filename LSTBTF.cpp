#include<bits/stdc++.h>
using namespace std;
#define check(a) (sqrt(sum)-(int)sqrt(sum)==0)

int main(){
	int t,sum,n,indecCurr,indic;
	string mYstring;
	cin>>t;
	while(t--){
		indic=0;
		cin>>n;
		mYstring="";
		indecCurr = n-1;
		for(int i=0;i<=n-1;i++){
			mYstring+="1";
		}
		sum = n;
		while(indecCurr >= 0){
			if(check(sum)){
				cout<<mYstring<<"\n";
				break;
			}
			else{
				for(int i=n-1;i>=0;){
					if(mYstring[i]!='9'){
						sum+=2*(mYstring[i]-'0')+1;
						mYstring[i]+=1;
					}
					else{
						int j;
						for(j=i;j>=0;j--){
								if(mYstring[j]!='9')
									break;
						}
						char temp = mYstring[j];
						mYstring[j]+=1;
						for(int k=j+1;k<=n-1;k++){
							mYstring[k]=mYstring[j];
						}
						int r = (mYstring[j]-'0')*(mYstring[j]-'0');
						sum=sum-(81*(n-j-1))+(n-j-1)*r+2*(temp-'0')+1;
						if(i == indecCurr){
							indecCurr--;
						}
					}
					if(check(sum)){
						indic=1;
							cout<<mYstring<<"\n";
						break;
					}
				}
				if(indic==1)
					break;
				if(indecCurr<0)
					cout<<-1<<"\n";
			}
		}
	}
}
