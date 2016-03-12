#include<stdio.h>
#include<stdlib.h>

int main(){
 char c;
 FILE *fp = fopen("lena.jpg","r");
 while((c = fgetc(fp))!=NULL) putchar(c);
 fclose(fp);
 return 0;
}
