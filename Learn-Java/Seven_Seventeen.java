import java.util.Scanner;
public class Seven_Seventeen{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Please input Student num: ");
		int num = sc.nextInt();
		
		int[] mark = new int[num];
		String[] name = new String[num];
		int index = 0;
		
		System.out.println("Please input Student name & marks (bingogo 100)");
		while(index < num) {
			name[index] = sc.next();
			mark[index] = sc.nextInt();
			index++;
		}
		
		// sort
		for(int i = 0; i < num; i++) {
			for(int j = i + 1; j < num; j++) {
				if(mark[i] < mark[j]) {
					mark[i] ^= mark[j];
					mark[j] ^= mark[i];
					mark[i] ^= mark[j];
					
					String s = name[j];
					name[j] = name[i];
					name[i] = s;
				}
			}
		}
		
		// output Student name
		for(String e: name) {
			System.out.print(e + " ");
		}
	}
};