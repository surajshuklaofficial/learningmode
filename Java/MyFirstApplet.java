import java.awt.Graphics;
import javafx.application.Application;

public class MyFirstApplet implements Application {
    public void paint(Graphics g) {
        g.drawString("Hello, this is my applet!", 20, 20);
    }
}
