import java.util.Scanner;
public class Two_Six{
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		short num;
		
		do{System.out.print("Enter a number between 0 and 1000:" );
			num = input.nextShort();
		}while(num >= 1000 && num <= 0);
		
		
		System.out.println("The sum of digits is " + (num/100 + num % 100 / 10 + num % 10));
	}
};