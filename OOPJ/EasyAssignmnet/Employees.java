package ass2;

public class Employees {
int hoursPerday;
double salary;
  public void getInfo(int hoursPerday,double salary){
	  this.hoursPerday=hoursPerday;
	  this.salary =salary;
  }
  
  public void addSal() {
	  if(salary<500)
	  salary+=10;
  }
  public void addWork() {
	  if(hoursPerday>6)
	  salary+=5;
  }
  public static void main(String[] args) {
      Employees emp = new Employees();
      emp.getInfo(8,450);
      emp.addSal();
      emp.addWork();
      System.out.println("Final Salary:"+emp.salary);
  }

}
