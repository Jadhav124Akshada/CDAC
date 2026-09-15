package ass2;

public class triangle {
int side1;
int side2;
int side3;

     triangle(int side1,int side2,int side3){
	 this.side1=side1;
	 this.side2=side2;
	 this.side3=side3;}
void display() {
	System.out.println("perimeter of triangle:"+ (side1+side2+side3));
};
	public static void main (String[] args) {
        triangle triangle1 = new triangle(3,4,5);
        triangle1.display();

	}
 }

