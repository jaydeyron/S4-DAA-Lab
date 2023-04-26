#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node{
		int data;
		struct node* next;
	};

struct node *head=NULL,*tail=NULL,*temp=NULL;

void insertll(int x){
	if(head==NULL){
	head=(struct node*)malloc(sizeof(struct node));
	head->data=x;
	head->next=NULL;
	tail=head;
	}
	else{
	tail->next=(struct node*)malloc(sizeof(struct node));
	tail=tail->next;
	tail->data=x;
	tail->next=NULL;
	}
}

void deletell(int del){
	temp=head;
	while(temp!=NULL){
		if((temp->next)->data)==del){
			
		}
	}
}

void largell(int del){
	mx=__INT_MAX__;
	temp=head;
	while(temp!=NULL){
		if((temp->data)>del && (temp->data)<mx){
			mx=temp->data;
		}
		temp=temp->next;
	}
	(mx==__INT_MAX__)?printf("%d was the largest number in the list\n",del):printf("\nThe next largest number is:  %d\n",mx);
}

void printll(){
	temp=head;
	while(temp!=NULL){
	printf("%d  ",temp->data);
	temp=temp->next;
	}
}

int main(){
	int n,x,del;
	printf("Enter number of elements to insert:\t");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		insertll(x);
	}
	printf("Enter element to delete:  ");
	scanf("%d",&del);
	deletell(del);
	largell(del);
	printll();
	return 0;
}
