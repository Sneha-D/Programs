/*
7. given a single linked list and value N, 
delete the last N nodes of the linked list.
 for example 1->2->3->4 and 2, 
 output should be 1->2->NULL
*/
#include <iostream>
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
	int del_num(int n);
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
int linkl :: del_num(int n){
	node *q,*temp;
	q=p;
	if(count>=n) {
		for(int i=0;i<(count-n)-1;i++){
			q=q->link;
		}
		temp=q->link;
		q->link=NULL;
		while(temp->link!=NULL){
			node *r = temp;
			temp=temp->link;
			delete r;
		}
		if(count==n){
			p=NULL;
			//delete temp;
			cout<<"NULL";
			
		}
		delete temp;
	}
	else{
		cout<<"The N value u entered is greater than number of elements in list"<<endl;
	}
	return n;
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
	int x;
	cin>>x;
	l.display();
	cout<<endl;
	l.del_num(x);
	l.display();
	return 0;
}
/*
Case - 1:
Input:
8
1 4 9 3 7 41 6 8
4

Output:
1->4->9->3->7->41->6->8
1->4->9->3

Case-2:
Input:
8
1 4 9 3 7 41 6 8
8
Output:
1->4->9->3->7->41->6->8
NULL
list is empty

Case-3:
Input:
8
1 4 9 3 7 41 6 8
9
Output:
1->4->9->3->7->41->6->8
The position u entered is greater than numbers in list
1->4->9->3->7->41->6->8
*/