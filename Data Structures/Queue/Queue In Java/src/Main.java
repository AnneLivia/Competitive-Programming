
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Queue q = new Queue(10);
		DynamicQueue dq = new DynamicQueue();
		
		if(q.isEmpty())
			System.out.println("It's empty");
		if(q.isFull())
			System.out.println("It's full");
		
		for(int i = 0; i < 10; i++) {
			q.push(i+1);
		}
		
		if(q.isEmpty())
			System.out.println("It's empty");
		if(q.isFull())
			System.out.println("It's full");
		
		while(!q.isEmpty()) {
			System.out.println("Front: " + q.first() + " size: " + q.size());
			q.pop();
		}
		
		if(q.isEmpty())
			System.out.println("It's empty");
		if(q.isFull())
			System.out.println("It's full");
		System.out.println("Size: " + q.size());
		
		q.push(10);
		if(q.isEmpty())
			System.out.println("It's empty");
		if(q.isFull())
			System.out.println("It's full");
		System.out.println("Front: " + q.first());
		System.out.println("Size: " + q.size());
		
		// Dynamic Queue 
		System.out.println("\n\nDYNAMIC QUEUE\n\n");
		if(dq.isEmpty()) {
			System.out.println("It's empty");
		}
		
		System.out.println("Size: " + dq.size());
		
		dq.push("A", 10);
		dq.push("B", 12);
		dq.push("C", 13);
		dq.push("D", 11);
		
		if(dq.isEmpty()) {
			System.out.println("It's empty");
		}
		
		System.out.println("Size: " + dq.size());
		
		dq.push("E", 12);
		dq.push("F", 13);
		dq.push("G", 14);
		dq.push("H", 15);
		dq.push("I", 16);
		dq.push("J", 17);
		
		while(!dq.isEmpty()) {
			System.out.println("Front: " + dq.getFront().getName() + ", " + dq.getFront().getAge() + ", size: " + dq.size());
			dq.pop();
		}
		
		if(dq.isEmpty()) {
			System.out.println("It's empty");
		}
		
		System.out.println("Size: " + dq.size());
		
		
	}

}
