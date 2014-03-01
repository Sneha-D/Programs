/*
8. given a double linked list with 
head and tail pointers, find the
 middle element of the linked list
*/
#include <iostream>
#include <stdio.h>
using namespace std;
int count=0;
class linkl{
	private:
	struct node{
		int data;
		node *next;
		node *prev;
	}*p,*q;
	public:
	linkl();
	void add(int num);
	void disp_med();
	void display();
	~linkl();
};
linkl :: linkl(){
	p=NULL;
	q=NULL;
}
linkl :: ~linkl(){
	delete p;
	delete q;
}
void linkl :: add(int num){
	node *r;
	r=new node;
	r->data=num;
	r->next=NULL;
	if(p==NULL){
		p=r;
		p->prev=NULL;
		q=p;
		count++;
	}
	else{
		q->next=r;
		r->prev=q;
		q=q->next;
		count++;
	}
}

void linkl :: disp_med(){
	node *r=p,*s=q;
	if(count%2!=0){
		while(s->prev!=r->next){
			s=s->prev;
			r=r->next;
		}
		s=s->prev;
		cout<<s->data;
	}
	else{
		while((s->prev->data!=r->data) || (r->next->data!=s->data)){
			s=s->prev;
			r=r->next;
		}
		cout<<r->data<<"  "<<s->data;
	}		
}
void linkl :: display(){
	node *temp;
	if(p==NULL)
	cout<<"\nlist is empty";
	else{
		temp=p;
		while(temp!=NULL){
			if(temp->next==NULL)
			cout<<temp->data;
			else
			cout<<temp->data<<"->";
			temp=temp->next;
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
5  7

Case 2:
Input:
5
1 3 5 7 8 
Output:
1->3->5->7->8
5

*/