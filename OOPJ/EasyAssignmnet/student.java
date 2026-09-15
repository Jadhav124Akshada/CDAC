package ass2;

public class student {
 String name;
 int roll_no;
 String phone_no;
 String address;
 public static void main (String[] args) {
	 student student1= new student();
	 student1.name="john";
	 student1.roll_no=2;
	 System.out.println(student1.name);
	 System.out.println(student1.roll_no);
	 
	 student student2=new student();
	 student2.name="sam";
	 student2.roll_no=1;
	 student2.phone_no="9988776655";
	 student2.address="XZY";
	 System.out.println(student2.name);
	 System.out.println(student2.roll_no);
	 System.out.println(student2.phone_no);
	 System.out.println(student2.address);


 }
}
