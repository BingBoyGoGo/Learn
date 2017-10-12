public class Two_OP {
/**	public static void main(String[] args) {
		int a = 9;
		int b = 6;
		int c = 6;
		boolean d = a > b; 
		boolean e = a < b; 
		boolean f = b == c;
		boolean g = b != c;

		f = (b == c) || (a < b); 
		g = (b == c) && (a < b); 
		System.out.println("d=" + d);
		System.out.println("e=" + e);
		System.out.println("f=" + f);
		System.out.println("g=" + g);
	}
*/
	public static void main(String[] args) {
		int a = 9;
		int b = 6;
		int c = 6;
		boolean d, e, f = false, g = false;
		d = !(a > b); // false
		e = (a > b) && (a > c); // ture
		boolean h = b >= c; // ture
		boolean i = b <= c; // ture
		boolean j = a == b; // false
		System.out.println("d=" + d);
		System.out.println("e=" + e);
		System.out.println("f=" + f);
		System.out.println("g=" + g);
		System.out.println("h=" + h);
		System.out.println("i=" + i);
		System.out.println("j=" + j);
	}
}

