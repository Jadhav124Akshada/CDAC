import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public class encryDecry {

    public static void main(String[] args) {
        Path input = Path.of("D:\\java\\day10\\myfile.txt");
        Path encrypted = Path.of("encrypted.txt");
        Path decrypted = Path.of("decrypted.txt");

        try {
            // 1. Encrypt and write
            Files.writeString(encrypted, shiftText(Files.readString(input), 4));

            // 2. Decrypt and write
            Files.writeString(decrypted, shiftText(Files.readString(encrypted), -4));

            // 3. Read and print directly
            System.out.println(Files.readString(decrypted));

        } catch (IOException e) {
            System.out.println("Error processing files: " + e.getMessage());
        }
    }

    private static String shiftText(String text, int shift) {
        char[] chars = text.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            // Shifts everything, including spaces and newlines perfectly
            chars[i] = (char) (chars[i] + shift); 
        }
        return new String(chars);
    }
}
