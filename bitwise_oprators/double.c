/* 					Single Linked List	 						*/

#include<stdio.h>
#include<malloc.h>
#include<string.h>
/* Self Referential Structure to implement Dynamic Data Structure */
struct List_data {
	int a;
	struct List_data *next;
	struct List_data *prev;
};

/* typedef names for struct List_data */

typedef struct List_data **Pointer_Pointer;
typedef struct List_data *Pointer;
typedef struct List_data Data;

/* Double Linked List Operations */

/* Init Function */
Pointer init(int a)	/* Init Function */ 
{
	Pointer ptr;
	ptr = (Pointer) malloc (sizeof(Data));
	if(ptr)			
	{
		ptr->a=a;
		ptr->next = NULL;
		ptr->prev = NULL;
		return ptr; 
	}	
	return ptr;	
}

/* Function to insert the new node as first node in the list */
void insert_first(Pointer_Pointer pptr,Pointer ptr)	
{
	if(*pptr == NULL)	/* Check whether list is empty */		
		*pptr = ptr;	/* Make new node as first node if list in empty */	
	else
	{
		ptr->next = *pptr; /* Make new node as first node if list is not empty */
		ptr->prev = NULL;
		(*pptr)->prev=ptr;
		*pptr = ptr;
	}	
}

/* Function to insert the new node in the middle or end of the list */
void insert_middle(Pointer_Pointer pptr,Pointer ptr,int pos)
{
	int i=1;
	Pointer start=*pptr; 	
	if(start==NULL || pos==1)		
	{
		ptr->next = *pptr;
		ptr->prev = NULL;
		(*pptr)->prev=ptr;
		*pptr = ptr;	/* Make new node as first node if list in empty or positions in one*/	
		return;
	}
	else
	{
		while((i<pos-1) && start )	/* Navigate upto position-1 node */
		{
			start=start->next;
			i++;
		}
	}
	if(start!=NULL)		/* Make new node as part of list */
	{
		ptr->next = start->next; 	
		start->next = ptr;
		ptr->prev = start;
		ptr->next->prev = ptr;
	}
	else
		printf("\n Not A Valied Position \n");
		 
}

/* Print all nodes data in the list */
void print_list(Pointer ptr)	/* Print all nodes data in the list */
{
	Pointer cur;
	printf("\n");
	while(ptr)
	{
		printf("%d -> ",ptr->a);
		cur = ptr;
		ptr = ptr->next;
	}
	printf(" NULL \n");
	while(cur)
        {
                printf("%d -> ",cur->a);
                cur = cur->prev;
        }

	printf(" NULL \n");
}


/* Function to delete a node for the list */
void delete_node(Pointer_Pointer pptr,int data )		/* Function to delete a node for the list */	
{
	Pointer temp,start = *pptr,prev = *pptr;
	printf("\n Before Delection \n");
	print_list(*pptr);
	if(start==NULL)		/* Check if list is empty */	
	{
		printf("\n List is Empty \n");
		return;
	}
	if(start->a == data)	/* Delete first element */
	{
		temp = start;
		*pptr = start->next;
		start->next->prev=NULL;
		free(temp);
		printf("\n After Delection \n");
	        print_list(*pptr);
		return;	
	}
	else
	{
		while( (start->a!=data) && start)	/* Search for the node to delete */
		{
			prev = start;
			start = start->next;
		}
		if(start != NULL)		/* Delete node */	
		{
			prev->next = start->next;
			start->next->prev = prev;
			printf("\n After Delection \n");
		        print_list(*pptr);

			free(start);
		}
		else
			printf("\n Node not Found \n");
	}
	
}

/* Function to count total number of elements in the list */
int count_node(Pointer start)
{
	int count=1;
	while(start->next)
	{
		start=start->next;
		count++;	
	}
	return count;
}

/* Function to retrive Nth node from the list */
Pointer get_Nth_node(Pointer start,int index)
{
	int i=1;
	while(i++<index)
		start=start->next;
	return start;
}	

/* Function to Delete dulicates */

int delete_Duplicates(Pointer_Pointer pptr)
{
	Pointer prev, curr = *pptr,temp;
	if(curr)		/* Check List is empty */
	{	
		while(curr && curr->next)	
		{
			prev=curr->next;
			temp = curr;
			while(prev)
			{
				
				if(curr->a==prev->a)
				{
					temp->next = prev->next;
					prev->next->prev = prev->prev;
					free(prev);
					prev = temp->next;
					
				}else{		
					temp = prev;
					prev = temp->next;
				}
			}
			curr = curr->next;
		}
	}
	
}
/* find mid number without counting number of elements*/

void mid_element(Pointer start)
{
	Pointer temp = start;
	if(start->next)
	{
		while(temp && temp->next)	
		{
			temp = temp->next->next;	/* temp jump to next to next elemets */
			start=start->next;		/* start jumps to next element  */
		}
		printf("\n %d \n",start->a);
	}
}	


/* Reverse the List */
Pointer reverse_list(Pointer curr,Pointer prev)
{
        Pointer revh;
        if(!curr)
                revh = prev;
        else{
                        revh = reverse_list(curr->next,curr);
                curr->next=prev;
        }
        return revh;


}

int main()
{
	int a,pos;
	int cho;			/* Object to hold choice */		
	Pointer start=NULL;			/* Pointer pointing to first node in the list */
	Pointer ptr;
	while(1)
	{
		printf("\n 1. First Node ");
		printf("\n 2. Middle Node ");
		printf("\n 3. Print List ");
		printf("\n 4. Delete Node ");
		printf("\n 5. Count Node ");
		printf("\n 6. Get Nth Node ");
		printf("\n 7. Delete Duplicates ");
		printf("\n 8. Middle Element ");
		printf("\n 9. Reverse List ");
		printf("\n 10. Exit ");
		
		printf("\n Enter Your Choice : ");
		scanf("%d",&cho);
		switch(cho)
		{
			case 1:				
				printf("\n Enter data : ");
				 scanf("%d",&a);
				ptr = init(a);	/* Try to allocate memory to new node */
				if(ptr==NULL)		/* Check memory is allocated or not */
					printf("\nFail to create a node \n");
				else
					insert_first(&start,ptr);	/* Insert new node as first node */		
				break;
			case 2:
				printf("\n Enter data : ");
				 scanf("%d",&a);
				ptr = init(a);	/* Try to allocate memory to new node */
				if(ptr==NULL)		/* Check memory is allocated or not */
					printf("\nFail to create a node \n");
				printf("\n Enter Position to Insert : ");
				 scanf("%d",&pos);
				insert_middle(&start,ptr,pos);	/* Insert new node as middle node */
				break;	
			case 3:
				print_list(start);
				break;
			case 4:
				printf("\n Enter data to Delete : ");
				 scanf("%d",&a);
				delete_node(&start,a);
				break;	
			case 5:
				printf("\n Total Number of Elements : %d \n",count_node(start));
				break;
			case 6:
			{
				int index;
				Pointer nth;
				printf("\n Enter Index of the node To Retrive : ");
				scanf("%d",&index);
				nth = get_Nth_node(start,index);
				if(nth!=NULL)
					printf("\n Data : %d",nth->a);			
				else
					printf("Not Valied Index");
				break;
			}
			case 7:
				delete_Duplicates(&start);
				break;
			case 8:
				 mid_element(start);
				break;
			case 9:
				start = reverse_list(start,NULL);
				break;
				
			case 10:
				return 0;
		}
	}
}





	



