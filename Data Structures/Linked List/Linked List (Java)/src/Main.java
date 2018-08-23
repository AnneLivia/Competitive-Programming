import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		LinkedList list = new LinkedList();
		Scanner ip = new Scanner(System.in);
		int op;
		String name;
		
		if(list.isEmpty())
			System.out.println("List is empty");
		
		list.insertFront("A");
		list.insertFront("B");
		list.insertBack("C");
		list.insertFront("D");
		list.insertBack("X");
		
		// D B A C X
		
		list.showAllNodes();
		
		if(list.findNode("K")) {
			System.out.println("k was found");
		} else {
			System.out.println("K was not found");
		}
		
		while(!list.isEmpty()) {
			
			System.out.println("Want to delete: ");
			System.out.println("1 - Back");
			System.out.println("2 - Front ");
			System.out.println("3 - Specific Value");
			System.out.print("Type here: ");
			
			op = ip.nextInt();
			
			switch(op) {
			case 1 :
				list.deleteBack();
				break;
			case 2 :
				list.deleteFront();
				break;
			case 3 :
				System.out.println("Type a name to delete: ");
				name = ip.next();
				list.deleteNode(name);
				break;
			default:
				System.out.println("Wrong option");
			}
			list.showAllNodes();
		}
		
		if(list.isEmpty())
			System.out.println("It's empty");
	}

}
