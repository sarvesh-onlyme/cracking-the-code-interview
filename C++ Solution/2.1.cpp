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
		void removeDuplicates();
		void removeDuplicates1();
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

//Question 2.1.1
bool ha[100];
void SLL :: removeDuplicates(){
	node *ptr = head;
	node *pre;
	if(head==NULL)
		return;
	while(ptr){
		if(ha[ptr->data]){
			node *del = ptr;
			pre->next = ptr->next;
			ptr = ptr->next;
			delete del;
		}
		else{
			ha[ptr->data] = true;
			pre = ptr;
			ptr = ptr->next;
		}
	}
}

//Question 2.1.2
void SLL :: removeDuplicates1(){
	node *ptr = head;
	node *iter, *iter_p;
	while(ptr){
		iter = ptr->next;
		iter_p = ptr;
		while(iter){
			if(iter->data==ptr->data){
				node *del = iter;
				iter_p->next = iter->next;
				iter = iter->next;
				delete del;
			}
			else{
				iter_p = iter;
				iter = iter->next;
			}
		}
		ptr = ptr->next;
	}
}

int main(){
	SLL list;
	memset(ha, false, sizeof(ha));
	int arr[10] = {1, 2, 3, 4, 3, 4, 2, 5, 6, 2};
	for(int i=0; i<10; i++)
		list.appendNode(arr[i]);
	list.displayNode();
//	list.removeDuplicates();
	list.removeDuplicates1();
	list.displayNode();
}
