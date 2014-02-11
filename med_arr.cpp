/*
given two arrays which are sorted find the median element of both the arrays

*/
#include <iostream>
using namespace std;

int max(int a,int b) {
		if(a>b) return a; else return b;
	}
int min(int a,int b) {
	if(a<b) return a; else return b;
}

// returns Median when there are three elements
float Med2(int a,int b) {
	return (a+b)/2.0 ;
}

// returns Median when there are three elements
float Med3(int a,int b,int c) {
	return a + b + c - min(a,min(b,c)) - max(a,max(c,b));
}

// returns Median when there are 4 elements.
float Med4(int a,int b,int c,int d) {
	int max=a;
	int min=a;
	if(max < b) max=b;
	if(max < c) max=c;
	if(max < d) max=d;
	
	if(min > b) min=b;
	if(min > c) min=c;
	if(min > d) min=d;
	
	return (a+b+c+d-max-min)/2.0;
	
}


float find_median(int a[],int la,int b[],int lb) {
	
	if(la==1) { // means only 1 element in a;
		if(lb==1) {
			return (a[0]+b[0])/2.0;
		}
		// if b has even number of elements then mid is 
		if(lb%2==0) {
			return Med3(a[0],b[lb/2],b[lb/2-1]);
		}
		// if b is odd then 
		else {
			return Med2(  b[lb/2], Med3( b[lb/2-1] , b[lb/2+1] , a[0]) );
		}
	}
	
	if(la==2) {
		if(lb==2) {
			return Med4(a[0],a[1],b[0],b[1]);
		}
		else if(lb%2==0) {
			return Med4(b[lb/2],b[lb/2-1],min(a[0],b[lb/2-2]) ,max(a[1],b[lb/2+1]) );
		}
		else {
			return Med3(b[lb/2],min(a[0],b[lb/2-1]),max(b[lb/2+1],a[1]));
		}
	}
	
	int midA = (la - 1) / 2;
	int midB = (lb - 1) / 2;
	
	if( a[midA] <= a[midB] ) return find_median(a+midA, la/2 + 1 , b , lb-midA); 
	else return find_median(a , la/2 + 1, b+midA,lb-midA);
}


int main() {
	
	//talking length of a and b;
	int la,lb;
	cin>>la>>lb;
	
	//taking array values;
	int a[la],b[lb];
	for(int i=0;i<la;i++) 
		cin>>a[i];
	for(int i=0;i<lb;i++) 
		cin>>b[i];
	
	//FInding Media 
	if(la<=lb)
	cout<<"median is :"<<find_median(a,la,b,lb)<<endl;
	else 
	cout<<"median is :"<<find_median(b,lb,a,la)<<endl;
	return 0;
}