public class StringLiteral{
   public static void main(String[] args){
     String str1 = "hello";
     String str2 = new String("hello");
     Boolean isSameObject =(str1==str2);
     System.out.println("Both variables point to the same object: " + isSameObject);
}
}

