/*
4. given a single, sorted, circular linked
 list and a value, insert the value as a 
 new node at the appropriate location 
 (to keep the linked list sorted).
 example 1->2->4->1 and value 3 
 output shoudl be 1->2->3->4->1
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
	void ins(int num);
	void add(int num);
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
	if(p==NULL){
		p=r;
		p->link=p;
	}
	else{
		q=p;
		while(q->link!=p)
			q=q->link;
		q->link=r;
		r->link=p;
	}

}
void linkl :: ins(int num){
	node *q=p,*s;
	node *r=new node;
	r->data=num;
	if(p==NULL||p->data>num){
		p=r;
		p->link=q;
		s=q;
		while(s->link!=q)
			s=s->link;
		s->link=p;
	}
	else{
		while(q->link!=p){
			if((q->data<num) && (q->link->data>num)){
				r->link=q->link;
				q->link=r;
				return;
			}
			q=q->link;
		}
		if(q->link==p){
				q->link=r;
				r->link=p;
			}
	}
}

void linkl :: display(){
	node *temp;
	int flag=0;
	if(p==NULL)
	cout<<"ll is empty";
	else{
		temp=p;
		while(temp!=NULL){
			if(temp->link==NULL || (flag==1 && temp==p)){
			cout<<temp->data;
			break;
			}
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
	int x;
	cin>>x;
	l.ins(x);
	cout<<endl;
	l.display();
	return 0;
}
/*
Case-1:
Input:
8
2 4 6 7 8 9 10 16
19
Output:
2->4->6->7->8->9->10->16->2
2->4->6->7->8->9->10->16->19->2

Case-2:
Input:
8
2 4 6 7 8 9 10 16
5
Output:
2->4->6->7->8->9->10->16->2
2->4->5->6->7->8->9->10->16->2
Case-3:
Input:
8
2 4 6 7 8 9 10 16
1
Output:
2->4->6->7->8->9->10->16->2
1->2->4->6->7->8->9->10->16->1
*/
