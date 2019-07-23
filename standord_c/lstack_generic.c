#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct stack {
   void *elem;
   int   current_count;
   int   total_count; 
}Stack;

void defineStack(Stack*);
void destroyStack(Stack*);
void push(Stack*,void*,int);
void pop(Stack*);
void printStack(Stack*,int,int);
int main() {
   
   int choice;
   int value;
   char string[100];
   Stack stack; 
   do{

    printf("select option: ");
    scanf("%d",&choice);
     
   switch(choice) {
       case 0:
           break;
       case 1:
           defineStack(&stack);      
           printf("Stack Created: current Count:%d and total Count:%d\n",stack.current_count,stack.total_count);
           break;
       case 2:
            printf("Enter Element: ");
            //scanf("%d",value); 
	    scanf("%s",string);
            push(&stack,string,sizeof(string)); 
            break; 
       case 3:
            //printStack(&stack,4,1);
            printStack(&stack,4,2);
	    break;
       case 4:
            pop(&stack);
            break;
       case 5:
            destroyStack(&stack);
            break;
       default:
            choice=0;
   }


   }while(choice); 

}

void defineStack(Stack *stack) {
 
   stack->total_count = 4;
   stack->current_count = 0;
   stack->elem = (char*) malloc(4 * sizeof(char*));
   
    //return stack;
}

void push(Stack *stack,void* value,int size) {
    char* next_element;
    if(stack->current_count == stack->total_count) {
        printf("stack full. Time for reassignment\n"); 

        stack->elem = realloc(stack->elem,sizeof(char*) * stack->total_count *2);
        if(stack->elem !=NULL) {
            stack->total_count *=2; 
            printf("Reallocation successful\n");
        }
    } 
 
    next_element =(char*) stack->elem + (sizeof(char*) * stack->current_count);
    //printf("Current Element Address:%d and next element address:%d\n",stack->elem,next_element);
    memcpy(next_element,value,size);
    stack->current_count++;
}

void pop(Stack *stack) {
    if(stack->current_count ==0) {
        printf("Stack is empty. Nothing to pop\n");
    } else {
        stack->current_count--; 
        if(stack->current_count*2 <= stack->total_count) {
            printf("Stack can be shrinked now. Current Count:%d and Total Count:%d\n",stack->current_count,stack->total_count);
            stack->elem = realloc(stack->elem,sizeof(char*)*(stack->total_count / 2));
            if(stack->elem != NULL) {
                stack->total_count /= 2;
                printf("Stack reallocation successfull\n"); 
            }
        }
    }
}


void destroyStack(Stack *stack) {

    if(stack->elem !=NULL) {
        free(stack->elem);
        stack->current_count=0;
        stack->total_count=0;
        printf("Stack is destroyed. For re-creation enter-3\n");
    }
} 

void printStack(Stack *stack,int size,int type) {
    char *int_type = strdup("integer");
    printf("Total Count:%d,Current Count:%d and elements are:\n",stack->total_count,stack->current_count);
    for(int i=0;i<stack->current_count;i++) {
            char* str = (char *) stack->elem + sizeof(char*) * i;
            if(type == 1)
                printf("%d=>",*str);
	   if(type ==2) {
               printf("%s=>",str); 
	   } 
   }
   printf("\n");
}

