#include<iostream>
#include<cstring>
using namespace std;

struct node {
	node* next;
	int data;
};

class SLL{
	private:
		node *head;
	public:
		SLL(){head = NULL;}
		void appendNode(int data);
		void displayNode();
		void partitionNode(int);
};

void SLL :: appendNode(int data){
	if(head==NULL){
		node *ptr = new node;
		ptr->data = data;
		ptr->next = NULL;
		head = ptr;
		return;
	}
	node *ptr;
	ptr = head;
	while(ptr->next != NULL){
		ptr = ptr->next;
	}
	node *p = new node;
	p->data = data;
	p->next = NULL;
	ptr->next = p;
}

void SLL :: displayNode(){
	node *ptr = head;
	while(ptr){
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<'\n';
}

void SLL :: partitionNode(int x){
	node *ptr = head->next;
	node *pre = head;
	while(ptr){
		if(ptr->data<x){
			pre->next = ptr->next;
			ptr->next = head;
			head = ptr;
			ptr = pre;
		}
		pre = ptr;
		ptr = ptr->next;
	}
}

int main(){
	SLL list;
	int arr[10] = {1, 2, 3, 4, 3, 4, 2, 5, 6, 2};
	for(int i=0; i<10; i++)
		list.appendNode(arr[i]);
	list.displayNode();
	list.partitionNode(3);
	list.displayNode();
}
