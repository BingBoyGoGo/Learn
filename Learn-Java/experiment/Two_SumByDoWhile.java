public class Two_SumByDoWhile{
	public static void main(String[] args) {
		int sum = 0;
		int i = 1;
		do {
			sum += i;
		}while(i++ < 100);
		System.out.println(sum);
	}
};