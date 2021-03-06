/*

This program explains how to Implement Queue using self referential structures

Author  : Vivek Tiwari

Version : 1.0

*/




#include <stdio.h>
#include <stdlib.h>
 
struct queueNode   			/* self-referential structure */
{
	char data;
	struct queueNode *nextPtr;
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

/* function prototypes */
void printQueue( QueueNodePtr );
int isEmpty( QueueNodePtr );
char dequeue( QueueNodePtr *);
void enqueue( QueueNodePtr *, char );
void instructions( void );

int main()
{ 
	QueueNodePtr headPtr = NULL;
   	int choice;
   	char item;
	
   	instructions();
      	printf( "Enter Your Choice : " );
   	scanf( "%d", &choice );

   	while ( choice != 3 ) 
	{ 
      		switch( choice ) 
		{ 
 			case 1:
            			printf( "Enter a character: " );
            			scanf( "\n%c", &item );
            			enqueue( &headPtr, item );
            			printQueue( headPtr );
            			break;

         		case 2:
            			if ( !isEmpty( headPtr ) ) 
     				{ 
               				item = dequeue( &headPtr);
               				printf( "%c has been dequeued.\n", item );
            			}

            			printQueue( headPtr );
            			break;

         		default:
            			printf( "Invalid choice.\n\n" );
            			instructions();
            			break;
   		}

      		printf( "Enter Your Choice : " );
    		scanf( "%d", &choice );
   	}
   	printf( "End of run.\n" );
   	return 0;
}


void instructions( void )
{ 
	printf ( "Enter your choice:\n"
         		"   1 to add an item to the queue\n"
           		"   2 to remove an item from the queue\n"
           		"   3 to end\n" );
}


void enqueue( QueueNodePtr *headPtr,  char value )
{ 
	QueueNodePtr newPtr,cur,pre;

   	newPtr = malloc( sizeof( QueueNode ) );

   	if ( newPtr != NULL ) 
        { 
      		newPtr->data = value;
      		newPtr->nextPtr = NULL;

      		if ( isEmpty( *headPtr ) )
         		*headPtr =newPtr;
      		else
		{
		for(cur=*headPtr;cur->nextPtr!=NULL;cur=cur->nextPtr);
			cur->nextPtr=newPtr;		
		}

   	}
   	else
        	printf( "%c not inserted. No memory available.\n", value );
}


char dequeue( QueueNodePtr *headPtr)
{ 
	char value;
        QueueNodePtr tempPtr;


        value = ( *headPtr )->data;
        tempPtr = *headPtr;
        *headPtr = ( *headPtr )->nextPtr;

	
        if ( *headPtr == NULL )
		
   	free( tempPtr );
   	
	return value;
}

int isEmpty( QueueNodePtr headPtr )
{ 
	return headPtr == NULL;
}

void printQueue( QueueNodePtr currentPtr )
{ 
	if ( currentPtr == NULL )
               printf( "Queue is empty.\n\n" );
        else 
   	{ 
      		printf( "The queue is:\n" );

 		while ( currentPtr != NULL ) 
       		{ 
        		printf( "%c --> ", currentPtr->data );
         		currentPtr = currentPtr->nextPtr;
      		}
		printf( "NULL\n\n" );
   	}
}
