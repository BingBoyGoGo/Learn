import java.util.Scanner;
public class Seven_Nineteen{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("input ten nums to judge if the list is sorted:");
		
		int [] list = new int[10];
		for(int i = 0; i < 10; i++) {
			list[i] = sc.nextInt();
		}
		
		boolean b = isSorted(list);
		if(b) {
			System.out.println("The list you input is sorted");
		}
		else {
			System.out.println("The list you input is not sorted yet");
		}
	}
	
	public static boolean isSorted(int[] list) {
		int i = 0;
		int len = list.length;
		while(list[i] < list[i + 1] && i++ < len - 2) {
		}
		
		if(i == len-1) {
			return true;
		}
		else {
			return false;
		}
	}
};