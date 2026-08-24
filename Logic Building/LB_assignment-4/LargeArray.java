import java.util.*;
public class LargeArray{
  public static void main (String[] args){
   Scanner sc = new Scanner(System.in);
   int [] num = new int[5];
   System.out.print("Enter 5 integers:");
   for(int i=0; i<5; i++){
     num [i]=sc.nextInt();
}
  Arrays.sort(num);
  System.out.println("Largest element is:"+num[num.length-1]);
}
}
