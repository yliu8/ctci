/**
 * Write a method to repalce all spaces in a string with '%20'. You may assume
 * that the string has sufficient space at the end of the string to hold the 
 * additional characters, and that you are given the "true" length of the
 * string. (Note: if implementing in Java, pleasse use a character array so
 * that you can perform this operation in place.)
 *
 * Time: 
 * Space: 
 *
 * author: Diwei Jiang
 * date: 10/01/2013
 */

#include <stdio.h>
#include <string.h>
void replaceSpaces (char* str, int length);

int main(int argc, char* argv[]) {

  printf("********************Start********************\n");
  printf("*********************************************\n\n\n");

  /*
   * add test case
   */
  char str[] = "1234 5 6 7 89";
  printf("%s\n", str);

  replaceSpaces(str, strlen(str));
  printf("%s\n", str);

  printf("\n\n*********************************************\n");
  printf("*********************End*********************\n");

  return 0;
}

/**
 * 
 * Solution
 *
 * tips:
 * 1. count the _ number
 * 2. calculate the new length
 * 3. replace
 */
void replaceSpaces (char* str, int length) {
  int spaceCount = 0, newLength, i;
  for (i = 0; i < length; i++) {
    if (str[i] == ' ') {
      spaceCount++;
    }
  }
  newLength = length + spaceCount * 2;
  str[newLength] = '\0';
  for (i = length - 1; i >= 0; i--) {
    if (str[i] == ' ') {
      str[newLength - 1] = '0';
      str[newLength - 2] = '2';
      str[newLength - 3] = '%';
      newLength = newLength - 3;
    } else {
      str[newLength - 1] = str[i];
      newLength = newLength - 1;
    }
  }
}




