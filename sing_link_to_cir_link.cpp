/*
3.given a single, sorted linked list convert
 that into a single, sorted, circular linked list.
 for example 1->2->3->NULL should be 1->2->3->1*/
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
	void circular();
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
void linkl :: circular(){
	node *q;
	q=p;
	while(q->link!=NULL)
		q=q->link;
	q->link=p;
}
void linkl :: display(){
	node *temp;
	int flag=0;
	if(p==NULL)
	cout<<"ll is empty";
	else{
		temp=p;
		while(temp!=NULL){
			if(temp->link==NULL || (flag==1 && temp==p))
			cout<<temp->data;
			else
			cout<<temp->data<<"->";
			temp=temp->link;
			if(flag==1 && temp==p->link)
				break;
			if(temp==p->link){
				flag=1;
			}
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
	l.circular();
	l.display();
	return 0;
}
/*
Input:
8
1 4 9 3 7 41 6 8

Output:
1->4->9->3->7->41->6->8
1->4->9->3->7->41->6->8->1
*/