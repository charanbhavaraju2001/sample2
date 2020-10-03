#include<stdio.h>
#include<stdlib.h>
#global
struct node
{
	int data;
	struct node* link;
};
struct node* root = NULL;

void insertatbegin(int);
void insertatend(int);
void insert(int,int);
void insertbefore(int,int);
void insertafter(int,int);
int length(void);
void search(int);
void printele(void);
void deleteatbegin(void);
void deleteatend(void);
void deleteatloc(void);

void main(){
	printf("1.Insert at beginning\n");
	printf("2.Insert at the end\n");
	printf("3.Insert before a number\n");
	printf("4.Insert after a number\n");
	printf("5.Print The elements\n");
	printf("6.Print the length of Linked list\n");
	printf("7.Search for an element in the list\n");
	printf("8.Delete at beginning\n");
	printf("9.Delete at end\n");
	printf("10.Delete at a location\n");
	printf("11.Exit\n");
	while(1){
	    int n,item,ele,len,x;
		printf("Enter Your choice\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1 : 
				printf("Enter the element you want to insert\n");
				scanf("%d",&item);
				insertatbegin(item);
				break;
			case 2 :
				printf("Enter the element you want to insert\n");
				scanf("%d",&item);
				insertatend(item);
				break;
			case 3 :
				printf("Enter the element you want to insert\n");
				scanf("%d",&item);
				printf("Enter the indexing element to insert before\n");
				scanf("%d",&ele);
				insertbefore(item,ele);
				break;
			case 4 :
				printf("Enter the element you want to insert\n");
				scanf("%d",&item);
				printf("Enter the indexing element to insert after\n");
				scanf("%d",&ele);
				insertafter(item,ele);
				break;
			case 5:
			    printele();
			    break;
			case 6:
				len=length();
				printf("Length of the linked list is %d \n",len);
				break;
			case 7:
				printf("Enter the element to be searched\n");
				scanf("%d",&x);
				search(x);
				break;
			case 8 :
				deleteatbegin();
				break;
			case 9 :
				deleteatend();
				break;
			case 10 :
				deleteatloc();
				break;
			case 11 :
				exit(0);
			default : 
				printf("Wrong Input\n");
		}
	}
}

#function to print elements in SLL
void printele(){
    struct node* p;
    p=root;
    do {
        printf("%d ",p->data);
        p=p->link;
    }while(p!=NULL);
    printf("\n");
}

#function to insert element at beginning
void insertatbegin(int item) {
	struct node* temp ;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->link = root;
	root = temp;

}

#function to insert element at the end /append function
void insertatend(int item){
	struct node* temp;

	temp = (struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->link = NULL;
	if (root == NULL){
		root = temp;
	}
	else{
		struct node* p;
		p= root;
		while ( p->link != NULL){
			p=p->link;
		}
		p->link =temp;
		
	}
}

#insert function prototype
void insert(int item , int loc){
	int i=1,len;
	struct node* temp ;
	struct node* p;
	temp = (struct node*)malloc(sizeof(struct node));
	len = length();
	if (loc>len){
		printf("Error Index is exceeding\n");
	}
	else{
		p = root;
		while(i<loc){
			p=p->link;
			i++;
		}
		temp->data = item;
		temp->link = p->link;
		p->link =temp;

	}
}

#function to insert before an element 
void insertbefore(int item, int ele){
	struct node* p;
	p = root;
	int count=1;
	while (p->data != ele){
		p=p->link;
		count++;
	}
	insert(item,count-1);
}

#function to insert after an element
void insertafter(int item, int ele){
	struct node* p;
	p = root;
	int count=1;
	while (p->data != ele){
		p=p->link;
		count++;
	}
	insert(item,count);
}

#function to give the length of SLL
int length(){
    int len=1;
    struct node* p;
    p=root;
    while(p->link!=NULL){
        p=p->link;
        len++;
    }
    return len;
}

#function to search For a given element in SLL
void search(int x){
	struct node* p;
	p = root;
	int count=1,flag=0;
	while (count<=length()){
	    if(p->data==x){
		printf("Element is found at position %d\n",count);
		flag=1;
        break;
		}
		p=p->link;
		count++;
	}
	if(flag==0){
		printf("Element Not found\n");
	}

	
}

#function to delete at the starting position
void deleteatbegin(){
	struct node* p;
	p = root;
	root = p->link;
	p->link=NULL;
	free(p);
}

#function to delete at the last position
void deleteatend(){
    int loc,i=1;
    loc= length();
	struct node* p;
	struct node* q;
	p=root;
	while(i<loc-1){
		p=p->link;
		i++;
	}
	q=p->link;
	p->link=q->link;
	q->link=NULL;
	free(q);
}

#function to delete at a specified location
void deleteatloc(){
	int loc,i=1;
	printf("Enter the location to be deleted\n");
	scanf("%d",&loc);
	if(loc>length()){
		printf("Error : Limit Exceeded\n");
	}
	else{
		struct node* p;
		struct node* q;
		p=root;
		while(i<loc-1){
			p=p->link;
			i++;
		}
		q=p->link;
		p->link=q->link;
		q->link=NULL;
		free(q);

	}
}
