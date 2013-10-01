/*
 * Implement a function void reverse(char* str) in C or C++ which reverse a 
 * null terminated string.
 *
 * Time: 1/2
 * space: 1
 *
 * author: Diwei Jiang
 * date: 10/01/2013
 */
#include <stdio.h>

void reverse(char* str);

int main(int argc, char* argv[]) {

  printf("********************Start********************\n");
  printf("*********************************************\n\n\n");

  /*
   * add test case
   */
  char str[] = "123456789";
  printf("%s\n", str);

  reverse(str);
  printf("%s\n", str);

  printf("\n\n*********************************************\n");
  printf("*********************End*********************\n");

  return 0;
}

/**
 * reverse function
 * @param str, the string pointer
 */
void reverse(char* str) {
  char* end = str;
  char tmp;

  if (str){
    while (*end) {    /* find the end of str */
      end++;
    }
    end--;            /* back on step, point to the last char */
  }

  while (str < end) {
    tmp = *str;
    *str++ = *end;
    *end-- = tmp;
  }
}