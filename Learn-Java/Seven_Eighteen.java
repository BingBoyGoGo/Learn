import java.util.Scanner;
public class Seven_Eighteen{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("input counts: ");
		int count = sc.nextInt();
		int[] arr = new int[count];
		
		System.out.println("Input your list: ");
		for(int i = 0; i < count; i++) {
			arr[i] = sc.nextInt();
		}
		
		// sort
		arr = bubblesort(arr, count);
	
		for(int i : arr) {
			System.out.print(i + " ");
		}
	}
	
	// bubblesort
	public static int [] bubblesort(int [] arr, int len) {
		System.out.println("After BubbleSort...");
		for(int i = len - 1; i > 0; i--) {
			for(int j = i - 1; j >= 0; j--) {
				if(arr[i] > arr[j]) {
					arr[i] ^= arr[j];
					arr[j] ^= arr[i];
					arr[i] ^= arr[j];
				}
			}
		}
		
		return arr;
	}
};