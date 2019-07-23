#include<stdio.h>
#include "dependency.h"

int main() {
 int x=10;
 int y=20;
 int result;
 
 result = sum(x,y) + mul(x,y);
 printf("Result is:%d",result);
 return 1;
}
