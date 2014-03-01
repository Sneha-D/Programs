/*
6. given a single linked list, print
the N element from the end of the linked list. 
example 1->2->3->4->5 and 2, output is 4
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
	void disp_n(int n);
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
void linkl :: disp_n(int n){
	node *q,*temp;
	q=p;
	if(count>=n) {
		for(int i=0;i<(count-n);i++){
			q=q->link;
		}
		cout<<q->data<<endl;
	}
	else{
		cout<<"The N value u entered is greater than number of elements in list"<<endl;
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
	int x;
	cin>>x;
	l.display();
	cout<<endl;
	l.disp_n(x);
	return 0;
}
/*
Case-1:
Input:
4
1 3 5 6 
2
Output:
1->3->5->6
5

Case-2:
Input:
4
1 3 5 6 
5
Output:
1->3->5->6
The N value u entered is greater than number of elements in list
*/