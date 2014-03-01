/*
2.b) given a single linked list, 
write a program to reverse the single linked list.
 for example 1->2->3 should be converted to 3->2->1.
 please write this program using recursion
*/
#include <iostream>
using namespace std;
class linkl{
	public:
	struct node{
		int data;
		node *link;
	}*p;
	linkl();
	void rec_rev( struct node **q);
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
void linkl :: rec_rev( struct node **q){
	node *f=NULL;
	node *r=NULL;
	node *s;
	if(q==NULL)
		return;
	f=*q;
	r=f->link;
	if(r==NULL)
		return ;
	rec_rev(&r);
	f->link->link=f;
	f->link=NULL;
	*q=r;
	return ;
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
	l.rec_rev(&l.p);
	l.display();
	return 0;
}
/*
Input:
7
4 17 3 8 3 10 2
Output:
4->17->3->8->3->10->2
2->10->3->8->3->17->4
*/