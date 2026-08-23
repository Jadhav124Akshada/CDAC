import java.util.*;
public class sum{
      public static int sum(int num1,int num2){
        return num1+num2;
        }
      public static void main(String[] args){
           Scanner sc = new Scanner (System.in);
           System.out.println("enter 1st number:");
           int num1 = sc.nextInt();
           System.out.println("enter 2nd number:");
           int num2 = sc.nextInt();
           int result =sum(num1, num2) ;
           System.out.println("sum of "+ num1 + " and " + num2 +" is:" +result);
  }
}