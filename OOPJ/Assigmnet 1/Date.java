
public class Date {
	
	int day;
	int month;
	int year;
	int noOfDays[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
	
	public void setDate(int dd, int mm, int yy) {
		if(yy<1900||yy>3000)
			year=2025;
		else 
			year=yy;
		
		if(mm<1||mm>12)
			month=1;
		else 
			month=mm;	
		
		    isLeapYear();
		    if(dd<1||dd>noOfDays[month])	
			    day=1;
		    else
			    day=dd;
		
	}
		
		public boolean isLeapYear(){
			if((year%4==0 && year%100!=0)|| year%400==0) {
				noOfDays[2]=29;
			    return true;
			   }
			else {
				noOfDays[2]=28;
				 return false;
			}
		}
		
		public boolean isLeapYear(int yyy){      //2024+
			if((yyy%4==0 && yyy%100!=0)|| yyy%400==0) {
				noOfDays[2]=29;
			    return true;
			   }
			else {
				noOfDays[2]=28;
				 return false;
			}
		}

		 public int getDay() {
			 return day;
		 }

		 public int getMonth() {
			 return month;
		 }

		 public int getYear() {
			 return year;
		 }
		 
		 
		 public void addDay(int addDay) { 
			 day+=addDay;
		     isLeapYear();
//		     System.out.println(addDay);
			 while(day>noOfDays[month]) {
				 day-=noOfDays[month];
				 month++;
			     isLeapYear();
				 if(month>12) {
				    month=1;
				    year++;
			   }
			 }
			 
		 }
		 
		 public void addMonth(int addMonth) { //3
			 int daysinMonth=0;
			 int tempYear=year; //365
			 for(int tmp=0; tmp<addMonth; tmp++){
				  isLeapYear(tempYear);				 
				  daysinMonth=daysinMonth+noOfDays[month];
//				  System.out.println("Month "+noOfDays[month]);
				  month++;
				  if(month>12) {
					  month=1;
					  tempYear++;
				  }
				  
			 }
			 
			 addDay(daysinMonth);
		 }
		 
		 public void addYear(int addYear) {
			 addMonth(addYear*12);
		 }
		 
		 
		
	}


