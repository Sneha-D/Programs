/*
2.a)given a single linked list,
 write a program to reverse the single linked list.
 for example 1->2->3 should be converted to 3->2->1. 
 please write this program without recursion.
*/
#include <iostream>
using namespace std;
class linkl{
	private:
	struct node{
		int data;
		node *link;
	}*p;
	public:
	linkl();
	void add(int num);
	void reverse();
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
	if(p==NULL)
		p=r;
	else{
		q=p;
		while(q->link!=NULL)
			q=q->link;
		q->link=r;
		
	}

}
void linkl :: reverse(){
	node *q,*r,*s;
	q=p;
	r=NULL;
	while(q!=NULL){
		s=r;
		r=q;
		q=q->link;
		r->link=s;
	}
	p=r;
}
void linkl :: display(){
	node *temp;
	if(p==NULL)
	cout<<"ll is empty";
	else{
		temp=p;
		while(temp!=NULL)
			{
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
	//cout<<"Enter numbers in linked list:";
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		l.add(x);
	}
	l.display();
	cout<<endl;
	l.reverse();
	l.display();
	return 0;
}

/*
Input:
8
1 4 9 3 7 41 6 8 
Output:
1->4->9->3->7->41->6->8
8->6->41->7->3->9->4->1
*/