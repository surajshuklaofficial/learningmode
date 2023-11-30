import java.io.File;
import java.io.IOException;
public class ExceptionHandling {
    public static void main(String[] args) {
        File x = new File("index.txt");

        if (x.createNewFile()) {
            System.out.println("File created: " + x.getName());
        } else {
            System.out.println("File already exists!");
        };
    }
 }
