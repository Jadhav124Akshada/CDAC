import java.util.*;
public class StringPalindrome{
   public static void main (String[] args){
   Scanner sc = new Scanner(System.in);
   System.out.print("Enter a String: ");
   String original = sc.next();
   char[] character =original.toCharArray();
   String reversed="";
   for (int i = character.length - 1; i >= 0; i--) {
        reversed += character[i];
}
  if (original.equals(reversed)){
    System.out.println("the string " + original+" is palindrome");
   }else{
     System.out.println("the string " + original+" is not palindrome");

} 
}
}