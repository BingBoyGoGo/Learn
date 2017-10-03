import java.util.Scanner;
public class Two_One{
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		double C = input.nextDouble();
		double Fahrenheit = (9.0/5) * C + 32;
		System.out.println(C + "Celsius is " + ((9.0/5) * C + 32) + "Fahrenheit"); // 算术表达式必须阔起来
		System.out.println("摄氏度" + C + "°C是" + Fahrenheit +  "华氏度");
	}
};