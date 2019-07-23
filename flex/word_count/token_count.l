%{
  #include <stdio.h>

    
    typedef struct token_st {
        char name[100];
        int count; 
    } token_t;

int addToken(char*);
int searchToken(char*);
int pos=0;
token_t *head;
%}



%%

[a-zA-Z]+    {  addToken(yytext); }


%%

int main(int argc,char **argv)
{
    int i=0;
    token_t *pointer;
    head = (token_t*) malloc(1000*sizeof(token_t));
    printf("started\n");
    if(argc > 1) {
        if(!(yyin = fopen(argv[1], "r"))) {
           perror(argv[1]);
           return (1);
        }
     }

    yylex();
    pointer = head;
    printf("Total Elements: %d\n",pos);
    while(i<pos) {
        printf("%-20s\t\t:\t%d\n",pointer->name,pointer->count);
        pointer++;
        i++;
    }
    return 0;
}

int addToken(char *name) {
   token_t *data,*deref;
   int found=0;
   found = searchToken(name);
   if(!found) {
       data = ((token_t *) head) + pos; 
       strcpy(data->name,name);
       data->count = 1;
       pos++;
   }
}

int searchToken(char *name) {
    
    token_t *pointer;
    int count=0;
    pointer = (token_t *) head;
    while(count < pos) {
        if(strcmp(pointer->name,name)==0){
            pointer->count++;
            return 1;
        }
        pointer++;
        count++;
    }
    
   return 0;
}
