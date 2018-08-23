
public class LinkedList {
	Node head;
	
	LinkedList() {
		
		head = null;
		
	}
	
	public boolean isEmpty() {
		if(head == null)
			return true;
		return false;
	}
	
	public void insertBack(String name) {
		Node no = new Node(name);
		no.setNext(null);
		if(head == null) {
			head = no;
		} else {
			Node aux = head;
			while(aux.next != null) {
				aux = aux.next;
			}
			aux.next = no;
		}
	}
	
	public void insertFront(String name) {
		Node no = new Node(name);
		
		if(head == null) {
			head = no;
			no.setNext(null);
		} else {
			no.setNext(head);
			head = no;
		}
	}
	
	public void showAllNodes() {
		Node aux = head;
		
		while(aux != null) {
			System.out.println(aux.name);
			aux = aux.next;
		}
	}
	
	public void deleteFront() {
		if (head != null)
			head = head.next;
	}
	
	public void deleteBack() {
		Node aux = head;
		Node previous = head;
		if(head != null) {
			while(aux.next != null) {
				previous = aux;
				aux = aux.next;
			}
			
			if(aux == head) {
				head = head.next;
			} else {
				previous.next = aux.next;
				aux = null;
			}
		}
	}
	
	public void deleteNode(String name) {
		Node aux = head;
		Node previous = head;
		while(!aux.name.equals(name) && aux != null) {
			previous = aux;
			aux = aux.next;
		}
		
		if(aux != null) { // has found the element
			if(aux == head) {
				head = head.next;
			} else {
				previous.setNext(aux.next);
				aux = null; // Just set it too null
			}
		}
	}
	
	public boolean findNode(String name) {
		Node aux = head;
		if(isEmpty())
			return false;
		while(!aux.name.equals(name) && aux.next != null) {
			aux = aux.next;
		}
		
		if(!aux.name.equals(name)) {
			return false; // Hasn't found
		} 
	
		return true;
	}
}
