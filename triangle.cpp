#include<iostream>
#include<math.h>
using namespace std;
int trian(int a,int b,int c)
{
 
		if((a+b>c)&&(b+c>a)&&(a+c>b))
		return 0;
		else
		return 1;
}
int main()
{
	int x1,x2,x3,y1,y2,y3;
	cout<<"enter X1 :";
    cin>>x1>>y1;
	cout<<"\nenter X2 :";
    cin>>x2>>y2;
    cout<<"\nenter X3 :";
    cin>>x3>>y3;
	if(((x1==x2)&&(x2==x3))||((y1==y2)&&(y2==y3)))
    cout<<"Triangle cannot be formed";
	else{
		float a=sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
		float b=sqrt(((x2-x3)*(x2-x3))+((y2-y3)*(y2-y3)));
		float c=sqrt(((x3-x1)*(x3-x1))+((y3-y1)*(y3-y1)));
		if(a==0 || b==0 || c==0)
			cout<<"Triangle cannot be formed";
		else{
			if(trian(a,b,c)==0){
				if((a==b)&&(b==c))
					cout<<"Equilateral ";
				else if(((a==b)&&(b!=c))||((c==b)&&(a!=c))||((a==c)&&(b!=c)))
					cout<<"Isosceles ";
				else if((a!=b)&&(b!=c)&&(c!=a))
				cout<<"Scalane ";
			int x=((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2));
			int y=((x2-x3)*(x2-x3))+((y2-y3)*(y2-y3));
			int z=((x3-x1)*(x3-x1))+((y3-y1)*(y3-y1));
			if(((x+y)==z)||((y+z)==x)||((z+x)==y))
				cout<<"Right Angled Triangle";
			else
				cout<<"Triangle";
			}
			else
				cout<<"Triangle cannot be formed";
		}
	}
    return 0;
}