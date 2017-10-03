import java.util.Scanner;
public class Two_fifteen{
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		double x1,x2,y1,y2;
		System.out.println("x1,y1: ");
		x1 = input.nextDouble();
		y1 = input.nextDouble();
		System.out.println("x2,y2: ");
		x2 = input.nextDouble();
		y2 = input.nextDouble();
		
		System.out.println("distance is " + Math.pow(((x2-x1)*(x2-x1) + (y2- y1)*(y2 - y1)), 0.5));
	}
};