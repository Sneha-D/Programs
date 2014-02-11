#include<stdio.h>

#include<math.h>

int main(){

	int i,j,m,n,k,flag=0,s;

	scanf("%d %d",&m,&n);

	printf("%f  ",sqrt(n));

	if(m==2)
		printf("2  ");
	if(m%2==0)
		m++;		
	for(i=m;i<=n;i=i+2){

		flag=0;
		s=sqrt(i);

		for(j=2;j<=s;j++){

			if(i%j==0){

				flag=1;

				break;

			}

		}

		if(flag==0){

			printf("%d  ",i);

		}

	}

	if(n==2){
		printf("2 ");
	}
	return 0;

}

































#include <stdio.h>
#include<stdlib.h>
sort(int *left,int *right) {
 
while(left < right ) {
	while(*left == 0 )
		left++;
	while(*right == 1 )
		right--;
	if(left < right) {
		*left = 0;
		*right = 1;
		left++;
		right--;
	}
}
 
}
 
int main(void) {
	int i,n;
int *a;
printf("Enter size:\n");
scanf("%d",&n);
a=(int *)malloc(sizeof(int)*n);
for(i=0;i<n;i++){
	scanf("%d",&a[i]);
}
for(i=0 ; i<n ; i++)
	printf("%d",a[i]);
printf("\n");
 
sort(&a[0],&a[n]);
for(i=0 ; i<n ; i++)
	printf("%d",a[i]);
 
printf("\n");
	return 0;
}