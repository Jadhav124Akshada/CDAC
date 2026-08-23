public class StringNew{
   public static void main(String[] args){
     String str1 = new String("hello");
     String str2 = new String("hello");
     boolean isSameObject =(str1==str2);
     boolean isSameContent = str1.equals(str2);
     System.out.println("Using == : " + isSameObject);
     System.out.println("Using .equals(): " + isSameContent);
}
}

