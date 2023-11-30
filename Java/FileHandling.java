import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
// import java.io.FileNotFoundException;
import java.util.Scanner;

public class FileHandling {
    
    public static void main(String[] args) {
        
        try {

            // creating a new file
            System.out.println("Creating a File if not Exists!");
            File myObj = new File("index.txt");
            if (myObj.createNewFile()) {
                System.out.println("File created: " + myObj.getName());
            } else {
                System.out.println("File already exists!");
            };

            // writing in a file
            System.out.println();
            FileWriter myObj2 = new FileWriter("index.txt");

            myObj2.write("he he he!");

            myObj2.close();

            // reading a file
            System.out.println("Reading File...");
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                String data = myReader.nextLine();
                System.out.println(data);
            }

            myReader.close();

            // deleting a file
            System.out.println("Deleting a File!");
            if (myObj.delete()) {
                System.out.println("Deleted the File: " + myObj.getName());
            } else {
                System.out.println("Failed to delete!");
            }

        } catch (IOException e){
            System.out.println("An error occurred!");
            e.printStackTrace();
        // } catch (FileNotFoundException e) {
        //     System.out.println("File is not found error!");
            
        } finally {
        }
        System.out.println("helloworld!");
    }
}
