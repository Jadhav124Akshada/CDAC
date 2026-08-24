import java.util.*;
public class StringVowel{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String original = sc.nextLine();
        String lowerStr = original.toLowerCase();
        int vowelCount = 0;
        for (int i = 0; i < lowerStr.length(); i++) {
            char ch = lowerStr.charAt(i);
             if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowelCount++;}
}
        System.out.println("The number of vowels in '" + original + "' is " + vowelCount);
        
}
}
