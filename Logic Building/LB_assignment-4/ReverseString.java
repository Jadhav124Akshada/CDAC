import java.util.*;
public class ReverseString{
   public static void main (String[] args){
   Scanner sc = new Scanner(System.in);
   System.out.print("Enter a String: ");
   String original = sc.next();
   char[] character =original.toCharArray();
   String reversed="";
   for (int i = character.length - 1; i >= 0; i--) {
        reversed += character[i];
} 
        System.out.println("Reversed string: " + reversed);
}
}