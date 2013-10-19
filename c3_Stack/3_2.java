/*3.2 How could you design a stack which, in addition to push and pop, also has a function min which returns the minimum element? Push, pop and min should all operate in O(1) time */

//solution1: have each node record what the minimum beneath itself is.
public class StackWithMin extends Stack<NodeWithMin>{
  void push(int value){
    int newMin = Math.min(value, min());
    super.push(new NodeWithMin(value, newMin));
  }
  public int min(){
    if(this.isEmpty())
      return Integer.MAX_VALUE;
    else
      return peek().min();
  }
}

Class NodeWithMin{
  public int value;
  public int min;
  public NodeWithMin(int v, int m){
    this.value = v;
    this.min = m;
  }
}

/* when the stack is large, solution1 will waste a lot of space by keeping track of the min for every single element.
Solution2: create a another stack to keep track of the min
*/

public class StackWithMin2 extends Stack<Integer>{
  Stack<Integer> s2;
  public StackWithMin2(){
    s2 = new Stack<Integer>();
  }

  public void push(int value){
    super.push(value);
    if(value < min())
      s2.push(value);
  }

  public int pop(){
    int value = super.pop();
    if(value == min())
      s2.pop();
    else
      return value;
  }

  public int min(){
    if(s2.isEmpty())
      return Integer.MAX_VALUE;
    else
      return s2.peek();
  }
}