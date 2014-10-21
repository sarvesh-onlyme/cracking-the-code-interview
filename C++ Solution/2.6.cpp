#include<iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

node *firstNodeInCircle(node *head){
	if(head==NULL)
		return NULL;
	node *slowptr=head->next, *fastptr=head->next->next;
	while(slowptr && fastptr && slowptr != fastptr){
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;
	}
	slowptr = head;
	while(slowptr!=fastptr){
		slowptr = slowptr->next;
		fastptr = fastptr->next;
	}
	return fastptr;
}

int main(){
	node *ptr, *head, *pre;
	ptr = new node;
	ptr->data = 1;
	ptr->next = NULL;
	head = ptr;
	pre = ptr;
	for(int i=2; i<40; i++){
		node *ptr = new node;
		ptr->data = i;
		ptr->next = NULL;
		pre->next = ptr;
		pre = ptr;
	}
	pre->next = head->next->next->next->next->next->next->next->next->next; //10
	int t=100;
	ptr = head;
	ptr = firstNodeInCircle(head);
	cout<<ptr->data<<'\n';
	return 0;
}
