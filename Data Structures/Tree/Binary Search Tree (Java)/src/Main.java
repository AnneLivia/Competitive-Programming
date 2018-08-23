
import java.util.Scanner;

public class Main {
	
	
	
	public static void main(String args[]) {
		BinarySTree bt = new BinarySTree();
		Scanner ip = new Scanner(System.in);
		
		bt.addNode(1, "A");
		bt.addNode(2, "B");
		bt.addNode(3, "C");
		bt.addNode(88, "Z");
		bt.addNode(102, "D");
		bt.addNode(15, "X");
		
		System.out.println("Pre order: \n");
		bt.pre_order(bt.root);
		System.out.println("\nIn order: \n");
		bt.in_order(bt.root);
		System.out.println("\nPost order: \n");
		bt.post_order(bt.root);
		
		System.out.print("Type an number to search: ");
		int n = ip.nextInt();
		Node no = bt.findNode(n);
		if(no == null) {
			System.out.println("Number " + n + " was not found");
		} else {
			System.out.println("Number " + no.key + " was found");
		}
		
		System.out.print("Remove a node: ");
		n = ip.nextInt();
		if(bt.removeNode(n)) {
			System.out.println("The " + n + " was removed");
		} else {
			System.out.println("The " + n + " doesn't exist in the tree");
		}
	}
}
