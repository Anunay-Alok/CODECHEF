#include<stdio.h>
int getmin(int a,int b){
	return (a<b)?a:b;
}

int findMin(int x,int a,int b,int c){
	int count = 0;
	if(x>=a+b+c)
		count=1;
	else if(x>=a+b)
		count=2;
	else{
		if(x>=b+c)
			count = 2;
		else count = 3;
	}
	return count;
}

int main(){
	int t,x,a,b,c;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d", &x,&a,&b,&c);
		int min = findMin(x,a,b,c);
		min = getmin(min,findMin(x,c,b,a));
		printf("%d\n", min);
	}
}
