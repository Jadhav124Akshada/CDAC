public class StringIntern{
   public static void main(String[] args){
     String str1 = "hello";
     String str2 = str1.intern();
     String str3 = "hello";
     boolean isSameContent = str2.equals(str3);
     System.out.println("Is str2 and str3 pointing to the same object ?" + isSameContent);
}
}

