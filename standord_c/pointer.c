#include<stdio.h>
#include<string.h>

int main() {
    long i;
    long *j;
    char *s = strdup("hello");
    i=10;
    j=&i;

    printf("Int*:%d and Int:=%d\n",sizeof(long),sizeof(long*));
    j++;
    printf("Value=%d\n",j);

    printf("Value=%d\n",s);
    s++;
    printf("Value=%d\n",s);
    return 0;
}
