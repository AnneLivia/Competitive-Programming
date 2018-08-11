
public class DynamicStack {
	private Node head;
	private Node tail;
	
	private int size;
	
	DynamicStack() {
		head = null;
		tail = null;
		this.size = 0;
	}
	
	public void push(int number) {
		Node no = new Node(number,null);
		if(head == null) {
			head = no;
		} else {
			tail.setNext(no);
		}
		tail = no;
		this.size++;
	}
	
	public void pop() {
		if(this.isEmpty())
			System.out.println("Empty\n");
		else {
			if(head == tail) {
				this.head = null;
				this.tail = null;
			} else {
				Node aux = head;
				while(aux.getNext() != tail) {
					aux = aux.getNext();
				}
				
				aux.setNext(null);
				tail = aux;
			}
			this.size--;
		}
	}
	
	public boolean isEmpty() {
		return (this.size == 0);
	}
	
	public boolean isFull() {
		return false;
	}
	
	public int getSize() {
		return this.size;
	}
	
	public int getTop() {
		if(!this.isEmpty())
			return this.tail.getNumber();
		else
			return -1; // Error
	}
	
	public void popAll() {
		while(head != null) {
			Node no = head;
			head = head.getNext();
			no = null;
			this.size--;
		}
		tail = null;
	}
	
}
