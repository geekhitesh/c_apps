#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct stack {
   int *elem;
   int  current_count;
   int  total_count; 
}Stack;

void defineStack(Stack*);
void destroyStack(Stack*);
void push(Stack*,int);
void pop(Stack*);
void printStack(Stack*);
int main() {
   
   int choice;
   int value;
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
            scanf("%d",&value);
            push(&stack,value); 
            break; 
       case 3:
            printStack(&stack);
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
   stack->elem = (int*) malloc(4 * sizeof(int));
   
    //return stack;

}

void push(Stack *stack,int value) {

    int* next_element;
    if(stack->current_count == stack->total_count) {
        printf("stack full. Time for reassignment\n"); 

        stack->elem = realloc(stack->elem,sizeof(int) * stack->total_count *2);
        if(stack->elem !=NULL) {
            stack->total_count *=2; 
            printf("Reallocation successful\n");
        }
    } 
 
    next_element = stack->elem + stack->current_count;
    printf("Current Element Address:%d and next element address:%d\n",stack->elem,next_element);
    memcpy(next_element,&value,sizeof(int));
    stack->current_count++;
    
}

void pop(Stack *stack) {
    if(stack->current_count ==0) {
        printf("Stack is empty. Nothing to pop\n");
    } else {
        stack->current_count--; 
        if(stack->current_count*2 <= stack->total_count) {
            printf("Stack can be shrinked now. Current Count:%d and Total Count:%d\n",stack->current_count,stack->total_count);
            stack->elem = realloc(stack->elem,sizeof(int)*(stack->total_count / 2));
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

void printStack(Stack *stack) {

    printf("Total Count:%d,Current Count:%d and elements are:\n",stack->total_count,stack->current_count);
    for(int i=0;i<stack->current_count;i++) {
        printf("%d#",*((stack->elem)+i));
   }
   printf("\n");
}
