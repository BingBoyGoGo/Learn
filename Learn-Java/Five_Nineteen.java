public class Five_Nineteen{
	public static void main(String[] args) {
		for(int i = 1; i <= 8; i++) {
			for(int j = 8; j > i ; j--) {
				System.out.print("    ");
			}
			
			int num = 1;
			while (num < i) {
				System.out.printf("%4d", num);
			}
		}
	}
};