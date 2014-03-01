/*
5. given a single(not sorted) linked list,
 and a value, delete the value from the linked list. 
 the value may exist or may not exist in the list*/
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
	int del_num(int num);
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
int linkl :: del_num(int num){
	node *q,*old;
	q=p;
	while(q!=NULL){
		if(q->data==num){
			if(q==p)
				p=p->link;
			else
				old->link=q->link;
			delete q;
			return num;
		}
		else{
			old=q;
			q=q->link;
		}
	}
	cout<<"\nNumber not found\n";
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
	int n,k;
//	cout<<"Enter number of nodes in list"<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		l.add(x);
	}
//	cout<<"Enter number to delete:"<<endl;
	cin>>k;
	l.display();
	cout<<endl;
	l.del_num(k);
	l.display();
	return 0;
}
/*
Case-1:
Input:
8
1 4 9 3 7 41 6 8
41
Output:
1->4->9->3->7->41->6->8
1->4->9->3->7->6->8

Case-2:
Input:
8
1 4 9 3 7 41 6 8
10
Output:
1->4->9->3->7->41->6->8
Number not found
1->4->9->3->7->41->6->8
*/