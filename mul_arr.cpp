/*
multipler array:
eg:
input: 1 2 3 4 5
output: 120 60 40 30 24
*/

#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	int n;
	cin>>n;
	int a[n];
	int b[n];
	int c[n];
 
	for(int i=0;i<n;i++)
		cin>>a[i];
 
		b[0]=1;
		c[n-1]=1;
 
 
	for(int i=1;i<n;i++) 
		b[i]=b[i-1]*a[i-1];
 
 
	for(int i=n-2;i>-1;i--)
		c[i]=c[i+1]*a[i+1];
 
 
	for(int i=0;i<n;i++)
		cout<<(b[i]*c[i])<<" ";
 
 
	return 0;
}