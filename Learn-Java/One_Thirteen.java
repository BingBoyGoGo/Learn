import java.util.Scanner;
public class One_Thirteen{
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		double x = (44.5 * 0.55 - 50.2 * 5.9) / (3.4 * 0.55 - 50.2 * 2.1);
		double y = (3.4 * 5.9 - 44.5 * 2.1) / (3.4 * 5.9 - 50.2 * 2.1);
		 
		System.out.println("x is: " + x);
		System.out.println("y is: " + y);
	}
};