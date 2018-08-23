
public class Node {
	private String name;
	private int age;
	private Node next;
	
	Node(String name, int age) {
		this.name = name;
		this.age = age;
		this.next = null;
	}
	
	public void setNext(Node no) {
		this.next = no;
	}
	
	public Node getNext() {
		return this.next;
	}
	
	public String getName() {
		return this.name;
	}
	
	public int getAge() {
		return this.age;
	}
	
	
}
