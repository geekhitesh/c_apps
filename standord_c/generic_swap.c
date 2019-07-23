#include<stdio.h>
#include<string.h>

void swap(void *x, void *y,int size);

int main() {
    
    int x=10;
    int y=20;
    char *s = strdup("hello");
    char *t = strdup("buffallow");

    printf("Before Swap: <%d> and <%d>\n",x,y);

    swap(&x,&y,sizeof(x));  
     printf("After Swap: <%d> and <%d>\n",x,y); 

    printf("Before Swap %s and %s",s,t);
    swap(&s,&t, sizeof(&s));
    printf("After Swap %s and %s \n",s,t);
    return 0;
}

void swap(void *x,void *y,int size) {
    char temp[256];
    memcpy(temp,x,size);
    memcpy(x,y,size);
    memcpy(y,temp,size);
}
