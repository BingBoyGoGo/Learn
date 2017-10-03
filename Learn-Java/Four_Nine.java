import java.util.Scanner;
public class Four_Nine{
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		// ASCII to Int
		System.out.println("Enter a character: ");
		String str = sc.next();
		char ch = str.charAt(0);
		System.out.println("The character for ASCII code " + ch + " is " + (int)ch);
	
		// Int to ASCII
		System.out.println("Enter a ASCII code: ");
		int i = sc.nextInt();
		System.out.println("The character for ASCII code " + i + " is " + (char)i);
	}
};