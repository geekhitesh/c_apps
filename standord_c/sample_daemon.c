#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int buffer(long**);

int main() {
     long x=10,y=20,z=30;	
     long *p[3] = {&x,&y,&z};	
     long *dp;
     buffer(&dp);
     printf("dp=%ld\n",*dp);

}

int buffer(long **data) {
   long x=4123456789,y=1934872387230,z=12349349843233,w=3982398234982342;
     //long x=1,y=2,z=3,w=4;
     	*data = (long *) malloc(sizeof(long) * 4); 
   printf("Allocated Bytes:%d", (sizeof(long) *4));
   printf("current pointer:%d\n",*data);
   memcpy(*data,&x,sizeof(long)); 
   *data = *data + 1;
   printf("current pointer:%d\n",*data);
   memcpy(*data,&y,sizeof(long));
    printf("current pointer:%d\n",*data);
   *data = *data + 1;
    printf("current pointer:%d\n",*data);
   memcpy(*data,&z,sizeof(long));	   
   *data = *data + 1;
    printf("current pointer:%d\n",*data);
   memcpy(*data,&w,sizeof(long));
    //printf("%d",*data);
}


