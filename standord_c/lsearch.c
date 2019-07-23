#include<stdio.h>
#include<string.h>

void* lsearch(void *key,void *base,int n,int elemSize);

int main() {
   
   int x[7] = {1,2,3,4,5,6,7};
   int *elem;
   int  key;
   printf("Search Element:");
   scanf("%d",&key);
   printf("\n");
   elem = (int *) lsearch(&key,x,7,sizeof(int)); 
   if(elem != NULL)
       printf("Element Found:<%d>\n",*elem);    

} 

void* lsearch(void *key,void *base,int n,int elemSize) {
    
    for(int i=0;i <7;i++) {
        void *elemAddr = (char *) base + (i*elemSize); 
        if(memcmp(elemAddr,key,elemSize)==0) 
           return elemAddr;  
    }  
    return NULL;

} 
