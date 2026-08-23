import java.util.*;
public class IndexArray{
  public static void main (String[] args){
   Scanner sc=new Scanner(System.in);
   Integer []num=new Integer[5];
   System.out.print("Enter 5 integers:");
   
   for(int i=0; i<num.length; i++){
   num[i] = sc.nextInt();
}
   System.out.print("Enter number to search:");
   int search =sc.nextInt();
   
   List <Integer> list=Arrays.asList(num);
   if (list.contains(search)){
    int index = list.indexOf(search);
    System.out.print("Number " +search+ " is found at index " +index);
}else{
     System.out.print("Not Found");

}
}
}