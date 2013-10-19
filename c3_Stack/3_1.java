//3.1 describe how you could use a single array to implement three stacks
//divide the array into three subarrays. use stackNum to get each stack.


int stackSize = 100;
int[] buffer = new int [stackSize * 3];
int[] stackPointer = {-1, -1, -1};

void push(int stackNum, int value) throws Exception{
  if(stackPointer[stackNum] >= stackSize - 1){
    throws new Exception("Out of space.");
  }
  stackPointer[stackNum]++;
  buffer[stackNum * stackSize + stackPointer[stackNum]] = value;
}

int pop(int stackNum) throws Exception{
  if(stackPointer[stackNum] == -1){
    throws new Exception("pop value from an empty stack.");
  }
  int value = buffer[stackNum * stackSize + stackPointer[stackNum]];
  buffer[stackNum * stackSize + stackPointer[stackNum]] = 0;
  stackPointer[stackNum]--;
  return value;
}

int peak(int stackNum){
  return   buffer[stackNum * stackSize + stackPointer[stackNum]];
}

boolean isEmpty(int stackNum){
  return stackPointer[stackNum]==-1;
}

//improvement: write a function to get the index of stack's top element
int topIndex(int stackNum){
  return stackNum * stackSize + stackPointer[stackNum];
}

/*solution2 is allow the stack to be flexible in size. When one stack exceeds its initial capacity, we grow the allowable capacity and shift elements as necessary. We will also design our array to be circular, such that the final stack may start at the end of the array and wrap around to the beginning.
*/