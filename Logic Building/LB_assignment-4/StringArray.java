import java.util.*;
public class StringArray{
   public static void main (String[] args){
   Scanner sc=new Scanner(System.in);
   System.out.print("Enter 4 names:");
   String [] name =new String[4];
   for(int i=0; i<name.length; i++){
   name[i]=sc.next();
 } 
   for (String names: name){
   System.out.println(names+" ");
}
}
}