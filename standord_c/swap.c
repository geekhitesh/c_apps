#include<stdio.h>

void swap(int *x, int *y);

int main() {
    
    int x=10;
    int y=20;
    printf("Before Swap: <%d> and <%d>\n",x,y);

    swap(&x,&y);  
     printf("After Swap: <%d> and <%d>\n",x,y); 
    return 0;
}

void swap(int *x,int *y) {

    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
