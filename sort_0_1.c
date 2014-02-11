// sort  0/1 array .
#include<stdio.h>
void sort(int *l,int *r) {
	while(l < r ) {
		while(*l == 0 )
			l++;
		while(*r == 1 )
			r--;
		if(l < r) {
			*l = 0;
			*r = 1;
			l++;
			r--;
		}
	}
}
int main( int show_me_how,char *args[]) {
	int i,n;
	int *a,*b;
	printf("Enter size:\n");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	b=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(&a[0],&a[n-1]);
	for(i=0 ; i<n ; i++)
		printf("%d",a[i]);
	printf("\n");
	return 0;
}