/*
10. given two sorted linked lists, 
merge them into single sorted linked
 list using same nodes of bboth the lists.*/
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
	void merge(linkl &l1,linkl &l2);
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
void linkl :: merge(linkl &l1,linkl &l2){
	node *z;
	z=NULL;
	if(l1.p==NULL && l2.p==NULL)
		return;
	while(l1.p!=NULL && l2.p!=NULL){
		if(p==NULL){
			p=new node;
			z=p;
		}
		else{
			z->link=new node;
			z=z->link;
		}
		if(l1.p->data<l2.p->data){
			z->data=l1.p->data;
			l1.p=l1.p->link;
		}
		else{
			if(l2.p->data<l1.p->data){
				z->data=l2.p->data;
				l2.p=l2.p->link;
			}
			else{
				if(l1.p->data==l2.p->data){
				z->data=l2.p->data;
				l2.p=l2.p->link;
				}
			}
		}
	}
	while(l1.p!=NULL){
		z->link=new node;
		z=z->link;
		z->data=l1.p->data;
		l1.p=l1.p->link;
	}
	while(l2.p!=NULL){
		z->link=new node;
		z=z->link;
		z->data=l2.p->data;
		l2.p=l2.p->link;
	}
	z->link=NULL;
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
	linkl l1,l2,l3;
	int n,m;
	//cout<<"Enter number of nodes in list"<<endl;
	cin>>n;
	//cout<<"Enter numbers in linked list:";
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		l1.add(x);
	}
	cin>>m;
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		l2.add(x);
	}
	l1.display();
	cout<<endl;
	l2.display();
	cout<<endl;
	l3.merge(l1,l2);
	l3.display();
	return 0;
}

/*
Input:
4
1 3 5 7
4
2 4 6 8
Output:
1->3->5->7
2->4->6->8
1->2->3->4->5->6->7->8
*/