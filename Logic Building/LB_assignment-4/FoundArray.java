import java.util.*;
public class FoundArray{
  public static void main(String[] args){
   Scanner sc =new Scanner(System.in);
   Integer [] num =new Integer[5];
   System.out.print("Enter 5 integers:");

   for (int i=0; i<num.length; i++){
   num[i] =sc.nextInt();
}
   System.out.print("Enter number to search:");
   int search= sc.nextInt();
   List <Integer>  list = Arrays.asList(num);
   if(list.contains(search)) {
     System.out.print("Found");
   }else{
     System.out.print("Not Found");
}
}
}