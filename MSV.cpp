#include<bits/stdc++.h>
using namespace std;

vector<int> factor(int toBe){
	vector<int>factors;
	for(int i=1;i*i<=toBe;i++){
		if(!(toBe%i))
			if(i*i == toBe)
				factors.emplace_back(i);
			else{
				factors.emplace_back(i);
				factors.emplace_back(toBe/i);
			}
	}
	return factors;
}

int main(){
	int t,n,temp;
	cin>>t;
	while(t--){
		cin>>n;
		vector<pair<int,bool>> v_base;
		int max = 0;
		for(int i=0;i<n;i++){
			scanf("%d", &temp);
			v_base.emplace_back(make_pair(temp,false));
			if(max < temp)
				max = temp;
		}
		vector<pair<int,bool>> v(max+1,make_pair(0,true));
		for(int i=n-1;i>=0;i--){
			if((v[v_base[i].first].second))
				v[v_base[i].first].second = false;
			else v_base[i].second = true;
		}
		for(int i=0;i<n;i++){
			if(v_base[i].second == false)
				v[v_base[i].first].second =true;
			vector<int>factors = factor(v_base[i].first);
			int SIZE = factors.size();
			// for(int j=0;j<SIZE;j++)
			// 	cout<<factors[j]<<" ";
			// cout<<"\n";
			for(int j=0;j<SIZE;j++){
				// cout<<factors[j]<<v[factors[j]].second<<"\n";
				if(v[factors[j]].second == false)
					v[factors[j]].first+=1;
			}
			factors.clear();
		}
		int MX = -1;
		// for(int i=1;i<=max;i++){
		// 	cout<<i<<". "<<v[i].first<<"\n";
		// }
		for(int i=0;i<n;i++){
			if(v[v_base[i].first].first > MX)
				MX = v[v_base[i].first].first;
		}
		cout<<MX<<"\n";
		v.clear();
		v_base.clear();
	}
}
