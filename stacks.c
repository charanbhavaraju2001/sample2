#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 10
int stack[CAPACITY], top=-1 ;
void push(int);
int pop(void);
void peek(void);
void print(void);
void main(){
	int n,item;
	printf("1.Push\n");
	printf("2.Pop\n");
	printf("3.Peek\n");
	printf("4.Print\n");
	printf("5.Exit\n");
	printf("Enter the value of Operation to perform\n");
	while(1){
	    printf("Enter your Choice \n");
		scanf("%d",&n);
		switch(n)
		{
			case 1 : 
				printf("Enter Element to push\n");
				scanf("%d",&item);
				push(item);
				break;
			case 2 : 
				item = pop();
				printf("%d is Popped\n",item);
				break;
			case 3 : 
				peek();
				break;
			case 4 : 
				print();
				printf("\n");
				break;
			case 5 : 
				exit(0);
			default : printf("Invalid Input\n");
		}

	}

}

void push(int x){
	if(top>CAPACITY){
		printf("Stack Overflow\n");
	}
	else{
		top++;
		stack[top]=x;
		printf("%d Pushed\n",x);		
	}
}

int pop(){
	int temp;
	if(top==-1){
		printf("Stack Underflow\n");
	}
	else{
		temp=stack[top];
		top--;
		return temp;
	}
}

void peek(){
	if (top == -1){
		printf("Stack is Empty\n");
	}
	else{
		printf("Top Element is %d\n",stack[top] );
	}
}

void print(){
	int i;
	if (top == -1){
		printf("Stack is Empty\n");
	}
	else{
		for(i=0;i<=top;i++){
			printf("%d  ",stack[i] );
		}
	}
}
