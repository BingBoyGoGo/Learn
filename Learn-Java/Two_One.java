import java.util.Scanner;
public class Two_One{
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		double C = input.nextDouble();
		double Fahrenheit = (9.0/5) * C + 32;
		System.out.println(C + "Celsius is " + ((9.0/5) * C + 32) + "Fahrenheit"); // �������ʽ����������
		System.out.println("���϶�" + C + "��C��" + Fahrenheit +  "���϶�");
	}
};