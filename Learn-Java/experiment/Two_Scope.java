public class Two_Scope {
	public static void main(String[] args) {
		int x = 25;
		int y = 36;
		System.out.println("x=" + x);{
			System.out.println("x=" + x);
			System.out.println("y=" + y);
		}
		System.out.println("x=" + x);
		System.out.println("y=" + y);
	}
}
