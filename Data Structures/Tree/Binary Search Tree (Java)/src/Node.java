
public class Node {
	int key;
	String name;
	// Left and right child of the binary tree
	Node leftChild; 
	Node rightChild;
	
	Node(int key, String name) {
		this.key = key;
		this.name = name;
	}
	
	public String toString() {
		return name + " has a key " + key;
	}
}
