#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long convertDecimalToBinary(int n);

int main(void)
{
char *data;
long long number;

printf("%s%c%c\n",
"Content-Type:text/html;charset=iso-8859-1",13,10);

printf("<TITLE>Binary result</TITLE>\n");
data = getenv("QUERY_STRING");
if(data == NULL) {
  printf("<P>Error! Error in passing data from form to script.</P>");
  exit(0);
}

if (sscanf(data,"number=%lld",&number)!=1) {
  printf("<P>Error! Invalid data. Data must be numeric.</P>");
}

else {

  printf("<P>The number %lld in binary is: ",number);

  int binaryNumber[1024];
  int remainder, i = 0;

  while (number!=0)
  {
    remainder = number%2;
    number /= 2;
    binaryNumber[i] = remainder;
    i++;
  }

  for (int j = i-1; j>=0; j--) 
  {
    printf("%d",binaryNumber[j]);
  }
  printf("</P>");
}
return 0;
}


