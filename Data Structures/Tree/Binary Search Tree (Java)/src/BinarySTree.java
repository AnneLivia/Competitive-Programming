

public class BinarySTree {
	Node root;
	
	public void addNode(int key, String name) {
		Node no = new Node(key,name);
		
		if(root == null) { // if the tree is empty
			root = no;
		} else {
			// if it's not empty
			Node aux = root;
			Node prev = null;
			
			while(true) {
				prev = aux; // Prev is aux
				/*
				 * Another approach to the problem:
				 * if (key < aux.key) {
				 * 		aux = aux.leftChild;
				 * 		if(aux == null) {
				 * 			prev.leftChild = no;
				 * 			return;
				 * 		}
				 * } else {
				 * 		aux = aux.rightChild;
				 * 		if(aux == null) {
				 * 			prev.rightChild = aux;
				 * 			return;
				 *		}
				 * }
				 * */
				if(key < aux.key) { // If the key is lesser than the key in the node, then the node must be inserted at the left side
					if(aux.leftChild == null) {  // if leftchild is null, then the space is free to insert a value there
						aux.leftChild = no; // inserting
						break; // break loop
					} else { // otherwise
						aux = aux.leftChild; // aux will be updated
					}
				} else { // Same as above but now with the right side of the tree is case the key is greater
					if(aux.rightChild == null) {
						aux.rightChild = no;
						break;
					} else {
						aux = aux.rightChild;
					}
				}
			}
		}
	}
	
	// Traversals 
	// In order = left, root and right
	public void in_order(Node no) {
		if(no != null) {
			in_order(no.leftChild);
			System.out.println(no);
			in_order(no.rightChild);
		}
	}
	
	// Pre order = root, left and right
	
	public void pre_order(Node no) {
		if(no != null) {
			System.out.println(no);
			pre_order(no.leftChild);
			pre_order(no.rightChild);
		}
	}
	
	// post order = left, right and then root.
	public void post_order(Node no) {
		if(no != null) {
			post_order(no.leftChild);
			post_order(no.rightChild);
			System.out.println(no);
		}
	}
	
	// Find a specific node
	public Node findNode(int key) {
		Node node = root;
		
		while(node.key != key) { // as long as the node key is not equal to the key the loop will search 
			if(key < node.key) {
				node = node.leftChild;
			} else {
				node = node.rightChild;
			}
			
			if(node == null) // key was not found
				return null;
		}
		return node; // return node if it was found
	}
	
	public Node getPlaceNode(Node no) {
		
		Node auxPrevious = no;
		Node replace = no;
		
		Node current = no.rightChild;
		
		while(current != null) {
			
			auxPrevious = replace;
			
			replace = current;
			
			current = current.leftChild;
		}
		
		if(replace != no.rightChild) {
			
			auxPrevious.leftChild = replace.rightChild;
			replace.rightChild = no.rightChild;
			
		}
		
		return replace;
	}
	
	public boolean removeNode(int key) {
		
		if(root == null)
			return false; // Tree is empty
		
		Node previous = root;
		Node current = root;
		boolean isLeft = false;
		// Search for the key:
		while(current.key != key) {
			previous = current; // Previous is current
			if(key < current.key) { // If the value is at the right
				isLeft = true; // Is left child
				current = current.leftChild;
			} else {
				isLeft = false; // Is right child
				current = current.rightChild;
			}
			
			if(current == null) // if current is equal to null, the key was not found
				return false;
		}
		
		// If the node does not have children 
		if(current.leftChild == null && current.rightChild == null) {
			// and the node is equal to the root
			if(current == root) {
				
				this.root = null;
				
			}  else if (isLeft) { // If the value is a left child and it does not have child
				
				previous.leftChild = null; // just set it to null
				
			} else { // It's a right child
				
				previous.rightChild = null; // Just set it to null
			}
			
			
		} else if (current.rightChild == null){ // When the node does not have a right child
			
			if(current == root) { // if it is the root
				root = current.leftChild; // The root now is going to be the left child
			} else if (isLeft) { // If is a left child
				previous.leftChild = current.leftChild; // Instead of point to the current, now, this is going to point to the left child current is pointing to
			} else {
				previous.rightChild = current.leftChild; // Same as above
			}
		} else if (current.leftChild == null) { // When there's no left child
			if(current == root) {
				root = current.rightChild;
			} else if (isLeft) {
				previous.leftChild = current.rightChild;
			} else {
				previous.rightChild = current.leftChild;
			}
		} else { // There's two children
			Node aux = getPlaceNode(current);
			
			if(current == root) {
				root = aux;
			} else if (isLeft) {
				previous.leftChild = aux;
			} else {
				previous.rightChild = aux;
			}
			
			aux.leftChild = current.leftChild;
		}
		
		return true;
	}
}
