import java.util.*;
public class positive{
static void positiveNum(){
Scanner sc = new Scanner(System.in);
int number;
do{
System.out.println("enter a positive number:");
number = sc.nextInt();
}
while(number <=0);
System.out.println("You enter a positive number:"+number);
}
public static void main (String[]args){
positiveNum();
}
}
