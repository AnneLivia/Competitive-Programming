import java.util.Arrays;

public class StaticStack {
	private String[] stackArray;
	private int stackSize; // Size of the array
	private int topStack = -1;

	StaticStack(int size) {
		this.stackSize = size; 
		stackArray = new String[size]; // Creating array
		Arrays.fill(stackArray,"-1");
	}
	
	public void push (String input) {
		if(this.topStack + 1 < this.stackSize) {
			stackArray[++this.topStack] = input;
		} else {
			System.out.println("The stack is full\n");
		}
	}
	
	public void pop() {
		if(this.topStack != -1) {
			stackArray[this.topStack] = "-1";
			this.topStack--;
		} else {
			System.out.println("The stack is empty\n");
		}
	}
	
	public boolean isEmpty() {
		return (this.topStack == -1);
	}
	
	public boolean isFull() {
		return (this.topStack + 1 == this.stackSize);
	}
	
	public int getSize() {
		return this.topStack + 1;
	}
	
	public String getTop() {
		if(!this.isEmpty()) {
			return stackArray[this.topStack];
		}
		return "";
	}
	
	public void displayStack() {
		for(int i = 0; i < this.stackSize; i++) {
			System.out.println(stackArray[i]);
		}
	}
	
}
