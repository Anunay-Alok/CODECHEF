#include<bits/stdc++.h>
using namespace std;

typedef struct infoStruct{
	int prev;
	int value;
	int next;
}infoStruct;

int main(){
	int t,n,m,a,max;
	vector<pair<int,int>> vec;
	vector<infoStruct> arr;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<m;i++){
			arr.emplace_back((infoStruct){-1,0,-1});
		}
		for(int i=0;i<n;i++){
			cin>>a;
			vec.emplace_back(make_pair(a,i%m));
		}
		sort(vec.begin(),vec.end());
		int sum = 0,index_min,diff_min = 1000000000,min1,min2;
		index_min = vec[0].second;
		sum++;
		arr[vec[0].second].value = vec[0].first;
		max = 0;
		// for(int i=0;i<m;i++){
		// 	cout<<arr[i].prev<<" "<<arr[i].value<<" "<<arr[i].next<<"\n";
		// }
		// cout<<"min = "<<arr[index_min].value<<", max = "<<max<<", diff_min = "<<diff_min<<", sum = "<<sum<<"\n";
		// cout<<"\n";
		for(int i=1;i<n;i++){
				if(arr[vec[i].second].value == 0){
					arr[vec[i].second].value = vec[i].first;
					arr[vec[i-1].second].next = vec[i].second;
					arr[vec[i].second].prev = vec[i-1].second;
					sum++;
				}
				else{
					if(vec[i].second == index_min){
						if(arr[index_min].next == -1){
							arr[index_min].value = vec[i].first;
						}
						else{
							arr[vec[i-1].second].next = vec[i].second;
							arr[vec[i].second].prev = vec[i-1].second;
							arr[index_min].value = vec[i].first;
							index_min = arr[vec[i].second].next;
						}
					}
					else{
						if(arr[vec[i].second].next == -1){
							arr[vec[i].second].value = vec[i].first;
						}
						else{
							arr[arr[vec[i].second].prev].next = arr[vec[i].second].next;
							arr[arr[vec[i].second].next].prev = arr[vec[i].second].prev;
							arr[vec[i-1].second].next = vec[i].second;
							arr[vec[i].second].prev = vec[i-1].second;
							arr[vec[i].second].value = vec[i].first;
						}
					}
				}
				arr[vec[i].second].next = -1;
				arr[index_min].prev = -1;
				max = vec[i].first;
				// else{
				// 	if(vec[i].second!=index_min){
				// 		if(arr[vec[i].second].next!=-1){
				// 			arr[arr[vec[i].second].prev].next = arr[vec[i].second].next;
				// 			arr[vec[i-1].second].next = vec[i].second;
				// 			arr[vec[i].second].prev = vec[i-1].second;
				// 		}
				// 	}
				// 	else{
				// 		if(arr[vec[i].second].next!=-1){
				// 			index_min = arr[vec[i].second].next;
				// 			arr[vec[i-1].second].next = vec[i].second;
				// 			arr[vec[i].second].prev = vec[i-1].second;
				// 		}
				// 	}
				// }
				// arr[vec[i].second].value = vec[i].first;
				// max = vec[i].first;
				// arr[vec[i].second].next = -1;
				if(sum == m){
					if(max - arr[index_min].value < diff_min){
						// min1 = max;
						diff_min = max - arr[index_min].value;
						// min2 = arr[index_min].value;
					}
				}
			// for(int i=0;i<m;i++){
			// 	cout<<arr[i].prev<<" "<<arr[i].value<<" "<<arr[i].next<<"\n";
			// }
			// cout<<"min = "<<arr[index_min].value<<", max = "<<max<<", diff_min = "<<diff_min<<", sum = "<<sum<<"\n";
			// cout<<"\n";

		}
		cout<<diff_min<<"\n";
		vec.clear();
		arr.clear();
	}
}
