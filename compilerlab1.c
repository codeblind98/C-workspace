#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(){
    char str[50],temp[10];
    char blank[10]="          ";
    int i,check,num,alpha,op,other;
    i=0;
    printf("\nEnter a string :");
    gets(str);
    while(i<strlen(str)){
        num=0;alpha=0;op=0;other=0;check=0;
        strcpy(temp,blank);
        puts(temp);
        while((str[i] != 32)&&(i<=strlen(str)-1)){
          temp[check]=str[i];
          if(str[i]>='0'&&str[i]<='9')     //Write conditions here
            num++;
          else if((str[i]>='A'&&str[i]<='Z')||(str[i]>='a'&&str[i]<='z')||str[i]=='_')
            alpha++;
          else if((str[i]=='!')||(str[i]=='%')||(str[i]=='&')||(str[i]=='*')||(str[i]=='+')||(str[i]=='-')||(str[i]=='/')||(str[i]=='<')||(str[i]=='>')||(str[i]=='='))
           op++;
          else{
		    other++;}
          
         i++;
         check++;
        // printf("\n%d",i);
        }
    
        //Check and print the token here
      if(other>0)
       printf("\n%s is other",temp);
      else if(op>0&&alpha==0&&num==0)
       printf("\n%s is an operator",temp);
      else if(num>0&&alpha==0&&op==0)
       printf("\n%s is a number",temp);
      else{
       printf("\n%s is an identifier",temp);}
     i++;
     
    }
   return 0;
}
