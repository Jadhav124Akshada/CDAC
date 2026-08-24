import java.util.*;
public class AvgArray{
  public static void main(String[] args){ 
    Scanner sc = new Scanner(System.in);
    int [] num =new int [5];
    System.out.print("Enter 5 integer:");
    int sum=0;
    for (int i=0; i<5; i++){
      num[i] = sc.nextInt();
      sum += num[i];
}
   float avg = sum/5;
   System.out.print("Average of numbers is:"+avg);
}
}
    