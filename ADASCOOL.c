#include <stdio.h>

int main(void) {
	// your code goes here
	int d;
	scanf("%d", &d);
	for(int i=0;i<d;i++)
	{
	    int m,n;
	    scanf("%d%d", &m, &n);
	    if(m%2==0 || n%2==0)
	        printf("YES\n");
	    else printf("NO\n");
	}
	return 0;
}
