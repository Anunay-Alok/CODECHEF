#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int flag=0,temp;
        vector<int>take(1000001,0);
        vector<int>a(n),output(n);
        int x = 0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            x^=a[i];
        }
        for(int j=0;j<n;j++){
            cin>>temp;
            x^=temp;
            take[temp]++;
        }
        for(int i=0;i<n;i++){
            if(take[x^a[i]]){
                output[i]=x^a[i];
                take[x^a[i]]--;
            }
            else{
                cout<<-1<<"\n";
                flag=1;
                break;
            }
        }
        if(flag==0){
            for(int i=0;i<n;i++){
                cout<<output[i]<<" ";
            }
            cout<<"\n";
        }

    }
}
