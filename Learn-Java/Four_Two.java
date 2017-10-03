import java.util.Scanner;
public class Four_Two{
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		System.out.println("Enter point 1 (latitude and longitude) in degrees: ");
		double la1 = Math.toRadians(input.nextDouble());
		double lo1 = Math.toRadians(input.nextDouble());
		
		System.out.println("Enter point 2 (latitude and longitude) in degrees: ");
		double la2 = Math.toRadians(input.nextDouble());
		double lo2 = Math.toRadians(input.nextDouble());
		
		System.out.println("The distance between the two points is "  
					+ (6371.01 * Math.acos(Math.sin(la1) * Math.sin(la2) + Math.cos(la1)* Math.cos(la2) * Math.cos(lo1 - lo2)))
					+ " km");
	}
};