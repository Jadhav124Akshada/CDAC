
public class Program {

	public static void main(String[] args) {
		
		Date date= new Date();
		
		int choice=0;
		
		
		do{
			System.out.println("Enter the Choice");
			System.out.println("1->Set the date");
			System.out.println("2->add days");
			System.out.println("3->add months");
			System.out.println("4->add years");
			choice=ConsoleInput.getInt();
			
			switch(choice) {
			case 1: 
				   System.out.println("Enter the date want to set DDMMYY");
				    int day;
					int month;
					int year;
				    day=ConsoleInput.getInt();
				    month=ConsoleInput.getInt();
				    year=ConsoleInput.getInt();
				    date.setDate(day, month, year);
				    System.out.println("Current Date: "+date.getDay()+"/"+date.getMonth()+"/"+date.getYear());
				    break;
			case 2:
				   System.out.println("Enter days want to add");
				   int addedDay=ConsoleInput.getInt();
				   date.addDay(addedDay);
				   System.out.println("Updated Date: "+date.getDay()+"/"+date.getMonth()+"/"+date.getYear());
				   break;
			case 3:
				   System.out.println("Enter Month want to add");
				   int addedmonth=ConsoleInput.getInt();
				   date.addMonth(addedmonth);
				   System.out.println("Updated Date: "+date.getDay()+"/"+date.getMonth()+"/"+date.getYear());
				   break;
			case 4:
				   System.out.println("Enter days want to add");
				   int addedYear=ConsoleInput.getInt();
				   date.addYear(addedYear);
				   System.out.println("Updated Date: "+date.getDay()+"/"+date.getMonth()+"/"+date.getYear());
				   break;
			 default: break;	   
			}
			
			
			
		}while(true);

	}

}
