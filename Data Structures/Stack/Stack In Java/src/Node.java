
public class Node {
	private int number;
	private Node next;
	
	Node(int number, Node no) {
		this.number = number;
		this.next = no;
	}
	
	public int getNumber() {
		return this.number;
	}
	
	public void setNext(Node no) {
		this.next = no;
	}
	
	public Node getNext() {
		return this.next;
	}
}
