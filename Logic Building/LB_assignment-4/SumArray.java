import java.util.*;
public class SumArray{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter 5 integers:");
    int [] num=new int[5];
    int sum=0;
    for (int i=0; i<5; i++){
    num[i]=sc.nextInt();
    sum = sum +  num[i];
}
   for(int add :num){}
   System.out.print("sum of all number is: "+sum);
}
}
