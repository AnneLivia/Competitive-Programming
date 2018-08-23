
public class Node {
	String name;
	Node next;
	
	Node(String name) {
		this.name = name;
	}
	
	public void setNext(Node no) {
		this.next = no;
	}
	
	public void showName() {
		System.out.println(this.name);
	}
	
	public String toString() {
		return "Name: " + this.name;
	}
}
