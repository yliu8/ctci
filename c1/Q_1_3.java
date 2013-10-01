/**
 * Given two strings, write a method to decide if one is a permutation of 
 * the other.
 *
 * Time: 
 * space: 
 *
 * author: Diwei Jiang
 * date: 10/01/2012
 */

public class Q_1_3 {

  public static void main(String[] args){

    System.out.println("********************Start********************");
    System.out.println("*********************************************\n\n");

    Solution so = new Solution();

    /*
     * add test case
     */
    String str1 = "234abcdefghijklmn";
    String str2 = "cade4bmgk3fhij2ln";

    System.out.println(str1);
    System.out.println(str2);

    if(so.permutation1(str1, str2)) {
      System.out.println("\nThey are permutation.\n");
    } else {
      System.out.println("\nThey are not permutation.\n");
    }

    // if(so.permutation2(str1, str2)) {
    //   System.out.println("\nThey are permutation.\n");
    // } else {
    //   System.out.println("\nThey are not permutation.\n");
    // }

    System.out.println("\n\n*********************************************");
    System.out.println("*********************End*********************");
  }

}

/**
 * 
 * solution
 *
 * tips:
 * 1. compare length first
 * 2. the permutation2 can also be used when compare combinations
 * 
 */
class Solution {

  /**
   * contructor
   */
  public Solution() {

  }

  /*
   * add function
   */
  String sort(String s){
    char[] content = s.toCharArray();
    java.util.Arrays.sort(content);
    return new String(content);
  }  

  /**
   * 1. sort by char
   * 2. compare
   * @param  s 
   * @param  t 
   * @return true/false
   */
  boolean permutation1(String s, String t) {
    if (s.length() != t.length()) {
      return false;
    }
    return this.sort(s).equals(this.sort(t));
  }

  /**
   * assume the string is ASCII
   * count number of the 256 chars
   * @param  s 
   * @param  t 
   * @return true/false
   */
  boolean permutation2(String s, String t) {
    if (s.length() != t.length()) {
      return false;
    }
    int[] charNum = new int[256];
    char[] s_array = s.toCharArray();

    for (char c : s_array) {
      charNum[c]++;
    }
    for (int i = 0; i < t.length(); i++) {
      int c = (int) t.charAt(i);
      if(--charNum[c] < 0) {
        return false;
      }
    }

    return true;
  }
}