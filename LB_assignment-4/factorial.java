import java.util.*;
public class factorial{
  public static void main (String[] args){
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter a number:");
    int n =sc.nextInt();
    int result = 1;
    for(int i=1; i<=n; i++){
    result = i*result;
}
    System.out.print("Factorial of "+n+" is: "+result);
    
}
}