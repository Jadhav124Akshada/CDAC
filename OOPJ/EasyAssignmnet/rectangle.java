package ass2;

public class rectangle {
	int l;
	int b;
	int area;
	rectangle(int l,int b){
		this.l=l;
		this.b=b;
	}
     public int area() {
	    return l*b ;
	    }
	 public static void main (String[] args) {
		 rectangle rect1 = new rectangle(4, 5);
		 rectangle rect2 = new rectangle(5, 8);
  System.out.println("area of rectangle 1:"+rect1.area());
  System.out.println("area of rectangle 2:"+rect2.area());

		 
	 }
 }

