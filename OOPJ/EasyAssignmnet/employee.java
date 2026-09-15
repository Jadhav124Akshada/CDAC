package ass2;


public class employee {
	String name;
	int yearOFjoining;
	String address;
	
	employee(String name,int yearOFjoining,String address){
		this.name = name;
		this.yearOFjoining =yearOFjoining;
		this.address =address;
	}
	public void display() {        
		System.out.println(name + "\t\t" + yearOFjoining + "\t\t" + address);
}
	public static void main (String[] args) {
		employee employee1= new employee("Robert",1994,"64C- WallsStreat");
		employee employee2= new employee("Sam",2000,"68D- WallsStreat");
		employee employee3= new employee("John",1999,"26B- WallsStreat");

        System.out.println("Name\t\tYear of joining\t\tAddress");

        
		employee1.display();
		employee2.display();
		employee3.display();

	}

}
