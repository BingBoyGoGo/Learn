import java.util.Scanner;
public class Two_Seven{
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Enter a number of minutes: ");
		long min = input.nextLong();
		System.out.println(min + "minutes is approximately " + min/(60*24)/365 + " year(s)" + min/(60*24)%365 + " day(s)");
	}
};