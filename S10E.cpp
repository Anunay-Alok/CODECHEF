#include <deque> 
#include <iostream> 
using namespace std; 
void printKMax(int arr[], int n, int k,int count) 
{ 
	std::deque<int> Qi(k); 
	int i; 
	for (i = 0; i < k; ++i) { 
		while ((!Qi.empty()) && arr[i] < arr[Qi.back()]) 
			Qi.pop_back(); 
		Qi.push_back(i); 
	} 
	for (; i < n; ++i) {  
		if(arr[Qi.front()] > arr[i])
			count++;
		while ((!Qi.empty()) && Qi.front() <= i - k) 
			Qi.pop_front(); 
		while ((!Qi.empty()) && arr[i] < arr[Qi.back()]) 
			Qi.pop_back(); 
		Qi.push_back(i); 
	} 
	if(arr[Qi.front()]>arr[n])
		count++;
	cout<<count<<"\n";
} 
int main() 
{
	int t,num,arr[100];
	cin>>t;
	while(t--){
	int count = 0;
	cin>>num;
	for(int i=0;i<num;i++)
		scanf("%d", arr+i);
	// int n = sizeof(arr) / sizeof(arr[0]); 
	int k = 5;
	int min = 751;
	for(int i=0;i<k;i++){
		if(arr[i]<min){
			count++;
			min = arr[i];
		}
	}
	// cout <<count<<"\n";
	printKMax(arr, num-1, k,count);

} 
}
