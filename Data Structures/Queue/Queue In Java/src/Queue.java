import java.util.Arrays;

public class Queue {
	private int[] number;
	private int queueSize;
	private int front, back, numberItems = 0;
	
	Queue(int size) {
		this.queueSize = size;
		number = new int[this.queueSize];
		
		Arrays.fill(number, -1);
		front = 0;
		back = 0;
	}
	
	public boolean isFull() {
		if(this.numberItems == this.queueSize)
			return true;
		else
			return false;
	}
	
	public boolean isEmpty() {
		if(this.numberItems == 0)
			return true;
		return false;
	}
	
	public void push(int number) {
		if(!isFull()) {
			this.number[this.back] = number;
			numberItems++;
			this.back = (this.back + 1) % this.queueSize;
		} else {
			System.out.println("Queue is full");
		}
	}
	
	public void pop() {
		if(!isEmpty()) {
			this.front = (this.front + 1) % this.queueSize;
			numberItems--;
		} else {
			System.out.println("Queue is empty");
		}
	}
	
	public int first() {
		return number[this.front];
	}
	
	public int size() {
		return this.numberItems;
	}
}
