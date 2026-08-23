import java.util.*;
public class PositiveArray{
  public static void main(String[] args){
    Scanner sc= new Scanner(System.in);
    int [] num = new int[6];
    System.out.print("Enter 6 integers:");
    int positiveCount =0;
    int negativeCount = 0;
    for(int i=0; i<num.length; i++){
      num[i] = sc.nextInt();
      if(num[i]>=0) {
        positiveCount++;
     }else if(num[i]<0) {
        negativeCount++;
}
}
      System.out.println("Positive numbers:"+positiveCount);
      System.out.println("Negative numbers:"+negativeCount);

}

}    