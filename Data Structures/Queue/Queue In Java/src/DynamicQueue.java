
public class DynamicQueue {
	private Node front, back;
	
	DynamicQueue() {
		this.front = null;
		this.back = null;
	}
	
	public boolean isFull() {
		return false; // This is a  dynamic queue
	}
	
	public boolean isEmpty() {
		if(front == null)
			return true;
		return false;
	}
	
	public int size() {
		Node aux = front;
		int cont = 0;
		while(aux != null) {
			aux = aux.getNext();
			cont++;
		}
		return cont;
	}
	
	public void push(String name, int age) {
		Node no = new Node(name,age);
		if(isEmpty()) {
			front = no;
		} else {
			back.setNext(no);
		}
		
		back = no;
	}
	
	public void pop() {
		if(!isEmpty()) {
			Node no = front;
			front = front.getNext();
			if(front == null)
				back = null;
			no = null;
		}
	}
	
	public Node getFront() {
		return front;
	}
}
