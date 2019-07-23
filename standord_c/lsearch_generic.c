#include<stdio.h>
#include<string.h>

void* lsearch(void *key,void *base,int n,int elemSize, int (*cmpFunc)(void*,void*));
int intCmp(void*,void*);
int strCmp(void *, void*);

int main() {
   
   int x[7] = {1,2,3,4,5,6,7};
   int *elem;
   int  key;
   char *str_array[10] = {"hitesh","rakesh","rajesh"};
   char *key_string = "itesh";  

   printf("sizeof(int):%d,sizeof(char*):%d\n",sizeof(int),sizeof(char**)); 
//   printf("Search Element:");
   //scanf("%d",&key);
   printf("\n");
   //elem = (int *) lsearch(&key,x,7,sizeof(int),intCmp); 
   if(elem != NULL)
       printf("Element Found:<%d>\n",*elem);    


   elem = (int *) lsearch(key_string,str_array,3,sizeof(char *),strCmp);

} 

void* lsearch(void *key,void *base,int n,int elemSize,int (*cmpFunc)(void*,void*)) {
     
    for(int i=0;i <n;i++) {
        void *elemAddr = (char *) base + (i*elemSize);
        if(cmpFunc(elemAddr,key)==0) 
           return elemAddr; 
    } 
    return NULL;

}

int intCmp(void *key1,void *key2) {

   int *k1 = key1;
   int *k2 = key2;

   return (*k1 - *k2);

}


int strCmp(void *key1,void *key2) {

    char **s = key1;
    char *t = key2;

    printf("Search Loop:%s\n",*s); 
    return 1;
} 
