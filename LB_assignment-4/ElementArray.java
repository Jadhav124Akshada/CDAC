import java.util.*;
public class ElementArray{
  public static void main(String[] args){
  Scanner sc = new Scanner(System.in);
  System.out.print("Enter 5 Integers:");
  int [] num =new int[5];
  for(int i=0; i<5; i++){
     num[i] = sc.nextInt();
  }
  for (int number : num){
    System.out.print(number+" ");
}
}
}