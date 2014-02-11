#include <iostream>
using namespace std;
int main(){
	int m,n,i,j,k,l;
	cin>>m>>n;
	int *a=new int[m];
	k=m+n;
	int *b=new int[k];
	for(i=0;i<m;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
		cin>>b[i];
		i=m-1;
		j=n-1;
		k=m+n-1;
	for(l=k-1;l>=0;l--){
		if(a[i]>b[j]){
			b[l]=a[i];
			i--;
		}
		else{
			b[l]=b[j];
			j--;
		}
	}
	for(i=0;i<k;i++)
		cout<<b[i]<<"  ";
    return 0;      
}