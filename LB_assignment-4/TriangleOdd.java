public class TriangleOdd{ 
  public static void main (String[] args){
  int n = 5;
  for(int i=1; i<=n ;i++){
    for(int j=1; j<=i; j++){
     int num = (2*j-1);
     System.out.print(num);
     if(j<i){ 
       System.out.print("*");

    }
    }
   System.out.println();
}
}
}