/*
9. given a single, sorted linked list,
 find the median of the linked list
*/
#include <iostream>
#include <stdio.h>
using namespace std;
int count=0;
class linkl{
	private:
	struct node{
		int data;
		node *link;
	}*p;
	public:
	linkl();
	void add(int num);
	void disp_med();
	void display();
	~linkl();
};
linkl :: linkl(){
	p=NULL;
}
linkl :: ~linkl(){
	delete p;
}
void linkl :: add(int num){
	node *r,*q;
	r=new node;
	r->data=num;
	r->link=NULL;
	if(p==NULL){
		p=r;
		count++;
	}
	else{
		q=p;
		while(q->link!=NULL)
			q=q->link;
		q->link=r;
		count++;
	}
 
}
void linkl :: disp_med(){
	node *q;
	q=p;
	if(count>0) {
		for(int i=1;i<(count/2);i++){
			q=q->link;
		}
		if((count%2)!=0)
		cout<<q->link->data<<endl;
		else{
			float x=(q->data+q->link->data);
			x=x/2;
			cout<<x<<endl;
		}
	}
}
void linkl :: display(){
	node *temp;
	if(p==NULL)
	cout<<"\nlist is empty";
	else{
		temp=p;
		while(temp!=NULL){
			if(temp->link==NULL)
			cout<<temp->data;
			else
			cout<<temp->data<<"->";
			temp=temp->link;
		}
	}
}
int main(){
	linkl l;
	int n;
	//cout<<"Enter number of nodes in list"<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		l.add(x);
	}
	l.display();
	cout<<endl;
	l.disp_med();
	return 0;
}
/*
Case 1:
Input:
6
1 3 5 7 8 10
Output:
1->3->5->7->8->10
6

Case 2:
Input:
5
1 3 5 7 8 
Output:
1->3->5->7->8
5
*/