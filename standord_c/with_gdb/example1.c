#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[]){
 char* name = malloc(4 * sizeof(int)) ;
 name = strcpy(name,"hitesh");
 printf("%s \n", name);
 return EXIT_SUCCESS;
} 
