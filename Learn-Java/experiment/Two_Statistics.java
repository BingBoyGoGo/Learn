import java.util.Scanner;
public class Two_Statistics{
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("input a string for analysis: ");
		
		int a,e,i,o,u;
		a = e = i = o = u = 0;
		
		String str = sc.nextLine();
		str = str.toUpperCase();
		for(int index = 0; index < str.length(); index++) {
			switch(str.charAt(index)) {
			case 'A':
				a++;
				break;
			case 'E':
				e++;
				break;
			case 'I':
				i++;
				break;
			case 'O':
				o++;
				break;
			case 'U':
				u++;
				break;
			default:
				break;
			}
		}
		System.out.println("Letter      count");
		System.out.println(" A(a)         " + a);
		System.out.println(" E(e)         " + e);
		System.out.println(" I(i)         " + i);
		System.out.println(" O(o)         " + o);
		System.out.println(" U(u)         " + u);
	}
};