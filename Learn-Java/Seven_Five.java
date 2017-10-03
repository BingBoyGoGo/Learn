import java.util.Scanner;
public class Seven_Five{
	public static void main(String [] args) {
		judge();
	}
	
	public static void judge() {
		Scanner sc = new Scanner(System.in);
		
		int [] a1 = new int[10];
		int [] a2 = new int[10];
		int index = 0;
		
		while(index < 10) {
			a1[index++] = sc.nextInt();
			//int a = sc.nextInt();
			//a1[index++] = a;
		}
		index = 0;
		
		a2[0] = a1[0];
		
		int i = 0;
		int j = 1;
		while(index++ < 9) {
			while(a2[i] != a1[index]) {
				i++;
				if(i >= j) {
					a2[j] = a1[index];
					j++;
					i = 0;
					break;
				}
			}
			i = 0;
		}
		
		for(int e = 0; e < j; e++){
			System.out.print(a2[e] + " ");
		}
	}
};