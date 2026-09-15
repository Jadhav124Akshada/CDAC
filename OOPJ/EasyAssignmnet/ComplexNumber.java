
public class ComplexNumber {
	     
	private int real;
	private int img;
	
	ComplexNumber(int r, int i){
		real=r;
		img=i;
	}
	
	public void display() {
		System.out.println(real+" + "+img+"i");
	}
	
	public void complexAdd(ComplexNumber obj){
		real=this.real+obj.real;
		img=this.img+obj.img;
	}
	
	public void complexSub(ComplexNumber obj){
		real=this.real-obj.real;
		img=this.img-obj.img;
	}
	
	public void complexMul(ComplexNumber obj){
		real=this.real*obj.real;
		img=this.img*obj.img;
	}

	public static void main(String[] args) {
		int a=0;
		int b=0;
		System.out.println("Enter 1st Real and Img Number");
		a=ConsoleInput.getInt();
		b=ConsoleInput.getInt();
		ComplexNumber Complex1=new ComplexNumber(a, b);
		Complex1.display();
		System.out.println("Enter 2nd Real and Img Number");
		a=ConsoleInput.getInt();
		b=ConsoleInput.getInt();
		ComplexNumber Complex2=new ComplexNumber(a, b);
		Complex2.display();
		Complex1.complexAdd(Complex2);
		System.out.println("The Addition is ");
		Complex1.display();
		Complex1.complexSub(Complex2);
		System.out.println("The Subtraction is ");
		Complex1.display();
		Complex1.complexMul(Complex2);
		System.out.println("The Multiplication is ");
		Complex1.display();
		
		
		
		

	}

}
