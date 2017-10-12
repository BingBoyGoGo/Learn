import java.util.*;

public class Two_LeepYear {
	public static void test(int year) {
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
			System.out.println("是闰年！");
		else
			System.out.println("不是闰年！");

	}

	public static void main(String[] args) {
		int year;
		Scanner input = new Scanner(System.in);
		for (int i = 0; i < 4; i++) {
			year = input.nextInt();
			test(year);
		}
	}
}
