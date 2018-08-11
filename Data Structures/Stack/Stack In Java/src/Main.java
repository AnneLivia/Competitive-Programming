

public class Main {
	
	public static void main(String[] args) {
		StaticStack s = new StaticStack(10);
		DynamicStack ds = new DynamicStack();
		
		System.out.println(" ---------- Static Stack ---------- ");
		if(s.isEmpty()) {
			System.out.println("The static stack is empty\n");
		} else {
			System.out.println("The static stack is not empty\n");
		}
		
		s.push("1");
		s.push("2");
		s.push("3");
		s.push("4");
		s.push("5");
		s.push("6");
		s.push("7");
		s.push("8");
		s.push("9");
		s.push("10");
		
		if(s.isEmpty()) {
			System.out.println("The static stack is empty\n");
		} else {
			System.out.println("The static stack is not empty\n");
		}
		
		if(s.isFull()) {
			System.out.println("The static stack is Full\n");
		} else {
			System.out.println("The static stack is not Full\n");
		}
		
		while(!s.isEmpty()) {
			System.out.println("Top: " + s.getTop() + ", Stack size: " + s.getSize());
			s.pop();
		}
		
		System.out.println(" ---------- Dynamic Stack ---------- ");
		
		if(ds.isEmpty()) {
			System.out.println("The dynamic stack is empty\n");
		} else {
			System.out.println("The dynamic stack is not empty\n");
		}
		
		ds.push(1);
		ds.push(2);
		ds.push(3);
		ds.push(4);
		ds.push(5);
		ds.push(6);
		ds.push(7);
		ds.push(8);
		ds.push(9);
		ds.push(10);
		ds.push(11);
		ds.push(12);
		ds.push(13);
		ds.push(14);
		ds.push(15);
		ds.push(16);
		
		if(ds.isEmpty()) {
			System.out.println("The dynamic stack is empty\n");
		} else {
			System.out.println("The dynamic stack is not empty\n");
		}
		
		if(s.isFull()) {
			System.out.println("The dynamic stack is Full\n");
		} else {
			System.out.println("The dynamic stack is not Full\n");
		}
		
		while(!ds.isEmpty()) {
			System.out.println("Top: " + ds.getTop() + ", dynamic Stack size: " + ds.getSize());
			ds.pop();
		}
		
		if(ds.isEmpty()) {
			System.out.println("The dynamic stack is empty\n");
		} else {
			System.out.println("The dynamic stack is not empty\n");
		}
		
		ds.push(1);
		ds.push(2);
		ds.push(3);
		ds.push(4);
		ds.push(5);
		
		System.out.println("Size: " + ds.getSize());
		
		ds.popAll();
		
		System.out.println("Size: " + ds.getSize());
	}
}
