#include<bits/stdc++.h>
using namespace std;
#define n 1000000007
#define m 1000000
typedef unsigned long long llu; 
vector<llu>vec(m+1,0);
void do_it_first(){
	vec[1]=1;
	for(int i=2;i<=m;i++){
		vec[i]=(vec[i-1]*i)%n;
	}
}

int main(){
	do_it_first();
	ios_base::sync_with_stdio(false);
	int t,a;cin>>t;
	while(t--){
		cin>>a;
		cout<<(vec[a+1]-1)%n<<"\n";
	}	
}
