#include <stdio.h> 
#include <string.h> 
#include <conio.h> 
#include <stdlib.h> void
main() {
 char stack[20], ip[20]; int i,
j, k, n, top = 0, col, row; 
// clrscr(); n = 6;
 char ter[] = {'i', '+', '*', '(', ')', '$'}; 
char opt[6][6] = { 
 'e' , '>', '>' , 'e' , '>' ,'>', 
 '<' , '>','<' , '<' , '>' , '>', 
 '<','>' ,'>' ,'<' , '>' , '>',
 
 '<' , '<' , '<' , '<' , '=' , 'e' , 
 'e' , '>' , '>' , 'e' , '>' , '>' ,
 
 '<','<' ,'<' , '<' , '<' , 'e' ,
 };
 // printf("\nEnter the table values :\n"); 
 printf("\n**** OPERATOR PRECEDENCE TABLE ****\n"); 
for (i = 0; i < n; i++)
 { printf("\t%c",
ter[i]); } printf("\n"); 
for (i = 0; i < n; i++)
 {
 printf("\n%c", ter[i]); 
for (j = 0; j < n; j++)
 { printf("\t%c",
opt[i][j]);
 } } stack[top]
= '$';
 printf("\nEnter the input string:"); 
scanf("%s", ip); i = 0;
 if ((ip[0] == '+' || ip[0] == '*') && ip[1] == 'i')
 {
 printf("operand is missing \n"); 
printf("\nString is not accepted"); exit(0); }
 printf("\nSTACK\t\t\tINPUT STRING\t\t\tACTION\n"); 
printf("\n%s\t\t\t%s\t\t\t", stack, ip); while (i <=
strlen(ip))
 { for (k = 0; k <
n; k++)
 {
 if (stack[top] == ter[k]) 
col = k; if (ip[i] == ter[k]) 
row = k;
 } if ((stack[top] == '$') &&
(ip[i] == '$'))
 {
 printf("String is accepted\n"); 
break; }
 else if ((opt[col][row] == '<') || (opt[col][row] == '='))
 {
 stack[++top] = opt[col][row]; 
stack[++top] = ip[i]; 
printf("Shift %c", ip[i]); i++; 
} else
 { if
(opt[col][row] == 'e')
 {
 if (ip[i] = '$')
 printf("closing parenthesis is missing \n");
 else
 printf("there is an extra charcter at %d ", i); 
printf("\nString is not accepted"); return; 
} if (opt[col][row] ==
'>')
 { while
(stack[top] != '<')
 {
 --top; 
} top = top - 1; 
printf("Reduce"); } 
else {
 if (ip[i] = '$')
 printf("closing parenthesis is missing \n"); 
printf("\nString is not accepted"); break; 
} 
} printf("\n");
 for (k = 0; k <= top; k++)
 { printf("%c",
stack[k]);
 }
 printf("\t\t\t");
 for (k = i; k < strlen(ip); k++)
 { 
printf("%c", ip[k]);
 }
 printf("\t\t\t"); 
if (i + 1 != strlen(ip))
 {
 if ((ip[i] == '+' || ip[i] == '*') && (ip[i + 1] == '+' || ip[i 
+ 1] == '*')) 
{
 printf("operand is missing \n"); 
printf("\nString is not accepted"); return;
 }
 } 
} 
getch(); }
