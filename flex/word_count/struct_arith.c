#include<stdio.h>
#include<string.h>

typedef struct token_st {
   int count;
   char str[6];
}token_t;

int main() {

	token_t *tok_arry[1000];
	token_t new_tok,second_tok;

	strcpy(new_tok.str,"hitesh");
        new_tok.count=10;
	printf("base address:%d\n",*((int*)&new_tok));

	strcpy(second_tok.str,"ahuja");
        second_tok.count=20;
	printf("base address:%d\n",second_tok);
}
