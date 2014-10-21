#include<iostream>
#include<cstring>
using namespace std;

struct node {
	node* next;
	int data;
};

void initList(node *head, int data){
	head->data = data;
	head->next = NULL;
}

void appendNode(node *head, int data){
	node *ptr = head;
	while(ptr->next){
		ptr = ptr->next;
	}
	node *p = new node;
	p->data = data;
	ptr->next = p;
	p->next = NULL;
}

void displayNode(node *head){
	node *ptr =head;
	while(ptr){
		cout<<"->"<<ptr->data;
		ptr = ptr->next;
	}
	cout<<"\n";
}

//head contains unit place;
node *addList(node *head1, node *head2){
	node *ptr1 = head1, *ptr2 = head2;
	node *head, *ptr, *pre; 
	int carry=0,sum;
	bool initHead = true;
	while(ptr1 && ptr2){
		sum = ptr1->data + ptr2->data + carry;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
		carry = int(sum/10);
		ptr = new node;
		ptr->data = sum%10;
		ptr->next = NULL;
		if(initHead){
			head = ptr;
			pre = ptr;
			initHead = false;
			continue;
		}
		pre->next = ptr;
		pre = ptr;
	}
	if(ptr2)
		ptr1 = ptr2;
	while(ptr1){
		sum = ptr1->data + carry;
		ptr1 = ptr1->next;
		carry = int(sum/10);
		ptr = new node;
		ptr->data = sum%10;
		ptr->next = NULL;
		if(initHead){
			head = ptr;
			pre = ptr;
			initHead = false;
			continue;
		}
		pre->next = ptr;
		pre = ptr;
	}
	if(carry){
		ptr = new node;
		ptr->data = 1;
		ptr->next = NULL;
		pre->next = ptr;
	}
	return head;
}

int nodeLen(node *head){
	node *ptr = head;
	int len = 0;
	while(ptr){
		len++;
		ptr = ptr->next;
	}
	return len;
}

//for 2 equall list
node *addEqualList(node *head1, node *head2, int* carry){
	if(head1==NULL){
		return NULL;
	}
	node *ptr = addEqualList(head1->next, head2->next, carry);
	int sum = head1->data + head2->data + *carry;
	node *p = new node;
	p->data = sum%10;
	p->next = ptr;
	*carry = int(sum/10);
	node *head = p;
	return head;
}

//for 1 list and carry bit
node *addCarryToList(node *ptr, int k, int* carry){
	if(k<=0 || ptr==NULL){
		return NULL;
	}
	node *p = addCarryToList(ptr->next, k-1, carry);
	node *pp = new node;
	int sum = ptr->data + *carry;
	pp->data = sum%10;
	pp->next = p;
	*carry = int(sum/10);
	return pp;
}

//Head contains msb
node *addList1(node *head1, node *head2){
	int len1 = nodeLen(head1);
	int len2 = nodeLen(head2);
	int min, max;
	node *head, *ptr1, *ptr2;	
	if(len1<len2){
		ptr1 = head2;
		ptr2 = head1;
		min = len1;
		max = len2;
	}
	else{
		ptr1 = head1;
		ptr2 = head2;
		min = len2;
		max = len1;
	}
	node *head_ = ptr1;
	int diff = max-min;
	while(diff>0){
		diff--;
		ptr1=ptr1->next;
	}
	int carry=0;
	node* inter_head = addEqualList(ptr1, ptr2, &carry);
	head = addCarryToList(head_, max-min, &carry);
	node *ptr = head;
	while(ptr && ptr->next){
		ptr = ptr->next;
	}
	if(ptr){
		ptr->next = inter_head;
	}
	else{
		head = inter_head;
	}
	if(carry){
		node *ptr = new node;
		ptr->data = carry;
		carry = 0;
		ptr->next = head;
		head = ptr;
	}
	return head;
}

int main(){
	node *head1 = new node, *head2 = new node;
	initList(head1, 9);
	appendNode(head1, 3);
	//appendNode(head1, 4);
	initList(head2, 9);
	appendNode(head2, 9);
	appendNode(head2, 5);
	displayNode(head1);
	displayNode(head2);
	node* res_head = addList1(head1, head2);
	displayNode(res_head);
}
