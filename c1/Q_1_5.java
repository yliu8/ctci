/**
 * Implement a method to perform basic string compression using the counts of
 * repeated characters. For example, the string aabcccccaaa would become 
 * a2b1c5a3. If the "compressed" string would not become smaller than the 
 * original string, your method should return the original string.
 *
 * Time: 
 * Space: 
 *
 * author: Diwei Jiang
 * date: 10/01/2013
 */


public class Q_1_5 {

  public static void main(String[] args){

    System.out.println("********************Start********************");
    System.out.println("*********************************************\n\n");

    Solution so = new Solution();

    /*
     * add test case
     */
    String str = "aladsfasdfliwqkelnssssssssssjzxcklk";
    String sortedString = so.sort(str);

    System.out.println(so.countCompression(sortedString));

    System.out.println("\n\n*********************************************");
    System.out.println("*********************End*********************");
  }

}

/**
 * 
 * your solution
 * 
 */
class Solution {

  /**
   * contructor
   */
  public Solution() {}

  /*
   * add function
   */
  String compressFunction(String str) {
    /**
     * first check if compression would create a longer string
     */
    int size = countCompression(str);
    if (size >= str.length()) {
      return str;
    }

    StringBuffer newStr = new StringBuffer();
    char last  = str.charAt(0);
    int count = 1;
    for (int i = 1; i < str.length(); i++) {
      if (str.charAt(i) == last) {
        count++;
      } else {
        newStr.append(last);
        newStr.append(count);
        last = str.charAt(i);
        count = 1;
      }
    }

    newStr.append(last);
    newStr.append(count);
    return newStr.toString();
  }

  /**
   * calculate the length of the new string
   * @param  str
   * @return new size
   */
  int countCompression(String str) {
    if (str == null || str.isEmpty()) return 0;
    char last = str.charAt(0);
    int size = 0;
    int count = 1;
    for (int i = 0; i < str.length(); i++) {
      if (str.charAt(i) == last) {
        count++;
      } else {
        last = str.charAt(i);
        size += 1 + String.valueOf(count).length();
        count = 1;
      }
    }
    size += 1 + String.valueOf(count).length();
    return size;
  }

  String sort(String s){
    char[] content = s.toCharArray();
    java.util.Arrays.sort(content);
    return new String(content);
  } 
}
