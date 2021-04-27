#include<stdio.h>

struct node
{
	int value;
	struct node* next;
};

struct node* head;

void print_list();
void insert_node(int val,int ind);
void delete_node(int ind);

int main()
{
	head = NULL;
	printf("This program creates a linked list\n");
	while(1)
	{
		printf("Choose one of the following option by entering the corresponding number:\n");
		printf(	"1. Insert a new node in the list\n");
		printf(	"2. Delete a node \n");
		printf(	"3. Print the list\n");
		printf(	"4. Exit\n");
		int q;
		scanf("%d",&q);
		while(q<1 || q>4)
		{
			printf("INVALID INPUT! Input should be 1,2,3 or 4!\n");
			scanf("%d",&q);
		}
		switch(q)
		{
			case 4:
				return 0;
			case 1:
				int val,ind;
				printf("Enter an integer value to insert in the list: ");
				scanf("%d",&val);
				printf("Enter the index after which the value should be inserted: ");
				scanf("%d",&ind);
				while(ind<0)
				{
					printf("INVALID INPUT! The index should be non-negative\n");
					scanf("%d",&ind);
				}
				insert_node(val,ind);
				break;
			case 2:
				int ind;
				while(ind<0)
				{
					printf("INVALID INPUT! The index should be non-negative\n");
					scanf("%d",&ind);
				}
				delete_node(val,ind);
				break;
			case 3:
				print_list();
				break;
		}
	}
}

void insert_node(int val,int ind)
{
	struct node* curr = head;
	while(ind>=0)
	{
		if(curr==NULL)
		{
			printf("Index too big, value inserted at the end of the list\n");
			curr = (node*) malloc(sizeof(node));
			curr->val = val;
			curr->next = NULL;
			return;
		}
		ind--;
		curr = curr->next;
	}
	struct node* tmp = curr->next;
	struct node* newnode = (node*) malloc(sizeof(node));
	newnode->val = val;
	newnode->next = curr->next;
	curr->next = newnode;
}

void delete_node(int ind)
{
	struct node* curr = head;
	struct node* prev = head;
	while(ind>=0)
	{
		if(curr==NULL)
		{
			printf("Index too big, deletion cancelled\n");
		}
		ind--;
		prev = curr;
		curr = curr->next;
	}
	prev->next = curr->next;
	free(curr);
}

void print_list()
{
	struct node* curr = head;
	while(curr!=NULL)
	{
		printf("%d",curr->val);
		curr = curr->next;
	}
}
