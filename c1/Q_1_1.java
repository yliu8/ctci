/**
 * Implement an algorithm to determine if a string has all unique characters 
 * What if you can not use additional data structures?
 *
 * Time: O(n)
 * space: O(1)
 *
 * author: Diwei Jiang
 * date: 09/27/2013
 * 
 */


public class Q_1_1 {

  public static void main(String[] args){

    System.out.println("********************Start********************");
    System.out.println("*********************************************\n\n");

    /*
     * add test case
     */
    Solution so = new Solution();

    String str1 = new String("absbsbsbsbs");
    String str2 = new String("abcdefg");

    if(so.isUniqueChars(str1))
      System.out.println("Unique!");
    else
      System.out.println("Not unique!");

    if(so.isUniqueChars(str2))
      System.out.println("Unique!");
    else
      System.out.println("Not unique!");


    System.out.println("\n\n*********************************************");
    System.out.println("*********************End*********************");
  }

}



class Solution {


  public Solution() {

  }

  /*
   * add function
   */

  boolean isUniqueChars(String str) {

    if(str.length() > 256) return false;

    // default is false
    boolean[] char_set = new boolean[256];

    for (int i=0; i < str.length() ; i++) {
      int val = str.charAt(i);
      if(char_set[val])
        return false;
      char_set[val] = true;
    }
    return true;
  }
}

