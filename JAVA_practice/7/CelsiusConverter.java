import java.util.Scanner;


public class CelsiusConverter{
    public double getFahrenhait(double celsius){
        double fahrenhait = 1.8 * celsius + 32;
        return fahrenhait;
    }
    
    public static void main(String[] args){
        System.out.print("\nPlease input celsuis : ");
        Scanner input = new Scanner(System.in);
        double celsius = input.nextDouble();                          // input.nextDouble!!!!!
        
        CelsiusConverter converter = new CelsiusConverter();
        double fahrenhait = converter.getFahrenhait(celsius);
        System.out.println("\nOutput fahrenhait is :" + fahrenhait);
    }
}

