import java.util.*;
public class age{
  static void age(int age){
   if (age <18){
   System.out.println("You are an minor");
   }else if(age >=18 && age < 65){
   System.out.println("You are an adult");
   }else{
   System.out.println("You are an sinor citizen");
   }
    }
public static void main(String[] args){
Scanner sc = new Scanner(System.in);
System.out.println("Enter Your Age:");
int ages = sc.nextInt();
age(ages);
}
}