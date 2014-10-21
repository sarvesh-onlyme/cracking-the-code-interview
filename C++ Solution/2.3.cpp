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
		void delKthNode(int);
		void delNodeByValue(int);
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

void SLL :: delKthNode(int k){
	if(head==NULL || k<1)
		return;
	if(k==1){
		node *del = head;
		head = head->next;
		delete del;
		return;
	}
	node *ptr = head;
	node *pre;
	while(ptr && --k){
		pre = ptr;
		ptr = ptr->next;
	}
	if(k!=0){
		cout<<"k is greater than no. of nodes"<<'\n';
		return;
	}
	if(ptr->next == NULL){
		pre->next = NULL;
		delete ptr;
	}
	else{
		pre->next = ptr->next;
		delete ptr;
	}
}

void SLL :: delNodeByValue(int val){
	if(head==NULL)
		return;
	if(head->data==val){
		node *del = head;
		head = head->next;
		delete del;
		delNodeByValue(val);
		return;
	}
	node *ptr = head->next;
	node *pre = head;
	while(ptr){
		if(ptr->data==val){
			node *del = ptr;
			if(ptr->next ==NULL){
				pre->next = NULL;
				delete del;
			}
			else{
				pre->next = ptr->next;
				ptr = pre;
			}
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
	list.delKthNode(5);
	list.delNodeByValue(2);
	list.displayNode();
}
