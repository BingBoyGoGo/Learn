import java.util.Scanner;
public class Four_Twenty{
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		
		String str = sc.nextLine();
		
		System.out.println("Length: " + str.length() + "\nFirst character: " + str.charAt(0));
	}
};