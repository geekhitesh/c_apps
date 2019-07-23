#include<stdio.h>
#include<string.h>

typedef struct {
 int  age;
 char* name;

}mystruct;


int main() {
    mystruct first;
    first.age = 10;
    first.name = strdup("hitesh");

    printf("Name:<%s>, Age:<%d>\n",first.name,first.age);

return 0;
}
