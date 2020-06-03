#include <stdio.h>
int main() {
	int n, q;
	scanf("%d%d", &n,&q);
	int r1[n], a1[n], a2[n];
	int flagi=0;
	for(int i=0;i<n;i++)
		scanf("%d",r1+i);
	int get1=0, get2=0;
	a1[0] = 0;
	for(int i=1;i<n; i++)
	{
		if(r1[i] > r1[i-1]){
			if(flagi==0){
				get1++;
				flagi=1;
			}
		}
		else if(flagi==1){
			flagi=0;
		}
		a1[i] = get1;
	}
	flagi = 0;
	a2[0]=0;
	for(int i=1;i<n; i++)
	{
		if(r1[i] < r1[i-1]){
			if(flagi==0){
				get2++;
				flagi=1;
			}
		}
		else if(flagi==1){
			flagi=0;
		}
		a2[i] = get2;
	}
	while(q--){
		int lefty,righty;
		scanf("%d%d", &lefty,&righty);
		int inc=a1[righty-1] - a1[lefty-1];
		if(a1[lefty-1] == a1[lefty] && r1[lefty]>r1[lefty-1]) inc++;
		int dec=a2[righty-1] - a2[lefty-1];
		if(a2[lefty-1] == a2[lefty] && r1[lefty]<r1[lefty-1]) dec++;
		if(inc==dec)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
