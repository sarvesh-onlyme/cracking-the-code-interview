#include<iostream>
#include<stack>
using namespace std;

struct node{
	int data;
	node *next;
};

void displayNode(node *head){
	node *ptr = head;
	while(ptr){
		cout<<"->"<<ptr->data;
		ptr = ptr->next;
	}
	cout<<"\n";
}

//Reverse and compare
bool nodePalindrome(node *head){
	if(head==NULL){
		return true;
	}
	node *head1;
	node *p = new node;
	p->data = head->data;
	p->next = NULL;
	head1 = p;
	node *pre = head1;
	node *ptr = head->next;
	int count = 1;
	while(ptr){
		node *p = new node;
		p->data = ptr->data;
		p->next = NULL;
		pre->next = p;
		pre = p;
		count++;
		ptr = ptr->next;
	}
	ptr = head;
	pre = head1;
	count = int(count/2);
	while(count--){
		if(ptr->data != pre->data)
			return false;
		ptr = ptr->next;
		pre = pre->next;
	}
	return true;
}

//Using stack
bool nodePalindrome1(node *head){
	node *slowptr = head;
	node *fastptr = head;
	stack<int> st;
	while(fastptr && fastptr->next){
		st.push(slowptr->data);
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;
	}
	if(fastptr){
		slowptr = slowptr->next;
	}
	while(slowptr){
		if(slowptr->data != st.top())
			return false;
		st.pop();
		slowptr = slowptr->next;
	}
	return true;
}

int main(){

	node *head = new node;
	int arr[3] = {0, 1, 0};
	head->data = arr[0];
	head->next = NULL;
	node *pre;
	pre = head;
	for(int i=1; i<3; i++){
		node *ptr = new node;
		ptr->data = arr[i];
		ptr->next = NULL;
		pre->next = ptr;
		pre = ptr;
	}
	pre = head;
	nodePalindrome1(head);
	return 0;
}
