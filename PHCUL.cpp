#include<bits/stdc++.h>
using namespace std;
#define uli unsigned long long int
typedef struct zaroori{
	uli coX;
	uli coY;
}zaroori;

int main(){
	// cout<<"2";
	uli t,x,y,a,b,n,m,k;
	zaroori inmi[5001],inni[5001],inki[5001];
	double inn[5001],inm[5001],innk[5001],inmk[5001];
	double len;
	cin>>t;
	while(t--){
		cin>>x>>y>>n>>m>>k;
		double arnm[n][m];
		for(uli i=0;i<n;i++){
			cin>>a>>b;
			inni[i] = (zaroori){a,b};
			inn[i]=sqrt((x-a)*(x-a)+(y-b)*(y-b));
		}
		for(uli i=0;i<m;i++){
			cin>>a>>b;
			inmi[i] = (zaroori){a,b};
			inm[i]=sqrt((x-a)*(x-a)+(y-b)*(y-b));
		}
		for(uli i=0;i<k;i++){
			cin>>a>>b;
			inki[i] = (zaroori){a,b};
		}
		for(uli i=0;i<n;i++){
			x = inni[i].coX;
			y = inni[i].coY;
			for(uli j=0;j<m;j++){
				a = inmi[j].coX;
				b = inmi[j].coY;
				arnm[i][j]=sqrt((x-a)*(x-a)+(y-b)*(y-b));
			}
		}
		for(uli i=0;i<n;i++){
			double min = DBL_MAX;
			x = inni[i].coX;
			y = inni[i].coY;
			for(uli j=0;j<k;j++){
				a = inki[j].coX;
				b = inki[j].coY;
				len = sqrt((x-a)*(x-a)+(y-b)*(y-b));
				if(min>len){
					min = len;
				}	
			}
			innk[i] = min;
		}
		for(uli i=0;i<m;i++){
			double min = DBL_MAX;
			x = inmi[i].coX;
			y = inmi[i].coY;
			for(uli j=0;j<k;j++){
				a = inki[j].coX;
				b = inki[j].coY;
				len = sqrt((x-a)*(x-a)+(y-b)*(y-b));
				if(min>len){
					min = len;
				}	
			}
			inmk[i] = min;
		}
		double min = DBL_MAX;
		for(uli i=0;i<n;i++){
			for(uli j=0;j<m;j++){
				len = inn[i]+arnm[i][j]+inmk[j];
				if(len<min)
					min = len;
			}
		}
		for(uli i=0;i<m;i++){
			for(uli j=0;j<n;j++){
				len = inm[i]+arnm[j][i]+innk[j];
				if(len<min)
					min = len;
			}
		}
		cout.precision(10);
		cout<<fixed<<min<<"\n";
	}
}
