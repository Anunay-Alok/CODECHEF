#include<bits/stdc++.h>
using namespace std;

void printcount(vector<vector<int>> &ar,int n){
  vector<vector<int>>counts(2*n,vector<int>(n,0));
  // counts[0]=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i!=j)
        counts[ar[i][j]][i]+=1;
      counts[ar[i][j]][j]+=1;
    }
  }
  int flag=0;
  for(int i=1;i<2*n;i++){
    for(int j=0;j<n;j++){
      // if(counts[i][j]!=1)
        cout/*<<i<<" "<<j<<" "*/<<counts[i][j]<<" ";
        if(counts[i][j]!=1)
          flag=1;
    }
    cout<<"\n";
  }
  if(flag==1){
    cout<<"fault"<<"\n";
  }
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    if(n==1){
      cout<<"Hooray\n1\n";
      continue;
    }
    if(n&1){
      cout<<"Boo\n";
      continue;
    }
    else cout<<"Hooray\n";
    int maxm = 2*n-1;
    int fb = n-1;
    vector<vector<int>>ar(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
      ar[i][i]=maxm;
    for(int i=0,j=1;j<n;j++)
      ar[i][j]=j,ar[j][i]=fb+j;
    for(int i=2;i<n-1;i++){
      for(int j=1;;j++){
        ar[j][i]=(ar[j-1][i])%fb+1;
        ar[i][j]=(ar[i][j-1])%fb+n;//apply
        if(ar[i][j+1]==maxm)
          break;
      }
    }
    for(int i=n-1,j=1;j<n-1;j++){
      ar[i][j]=(ar[i][j-1]+2)%fb+fb;//appl
      ar[j][i]=(ar[j-1][i]+2)%fb;//apply
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cout<<ar[i][j]<<" ";
      }
      cout<<"\n";
    }
    // cout<<"\n";
    // printcount(ar,n);
  }
}
