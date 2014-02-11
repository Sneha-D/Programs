/*
given a number as input, create a single linked list for the number.
 example: 1234 as input you shoudl create a linked list which is in memory like 1->2->3->4 
 (you can print but you should have a linked list in the data structure as well, not just print)
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
	node *r;
	r=new node;
	r->data=num;
	r->link=p;
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
   long n;
	int rem;
	cin>>n;
	while(n!=0)
		{
		rem=n%10;
		l.add(rem);
		n=n/10;

		}
	l.display();
	return 0;

}
