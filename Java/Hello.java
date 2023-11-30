import java.io.FileInputStream;
import java.io.IOException;

public class Hello {
    public static void main(String[] args) {
        try {
            FileInputStream inputStream = new FileInputStream("./137-87475.jpg");
            int data;

            while ((data = inputStream.read()) != -1) {
                System.out.println((char) data);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
