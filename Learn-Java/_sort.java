public class _sort{
	public static void main(String[] args) {
		int [] list = {1,2,3,4,6,4,3,4,5};
		list = selectionsort(list,list.length);
		for(int e : list) {
			System.out.print(e + " ");
		}
		
		System.out.println();
		list = bubblesort(list,list.length);
		for(int e : list) {
			System.out.print(e + " ");
		}
	}
	
	// bubblesort
	public static int[] bubblesort(int[] list, int count) {
		System.out.println("After bubblesort...");
		for(int i = count - 1; i > 0; i--) {
			for(int j = i - 1; j >= 0; j--) {
				if(list[i] > list[j]) {
					list[i] ^= list[j];
					list[j] ^= list[i];
					list[i] ^= list[j];
				}
			}
		}
		
		return list;
	}
	
	// selectionsort
	public static int[] selectionsort(int[] list, int count) {
		System.out.println("After selectionsort...");
		int index;
		for(int i = 0; i < count - 1; i++) {
			index = i;
			for(int j = i + 1; j < count; j++) {
				if(list[j] < list[index]) {
					index = j;
				}
			}
			if(index != i) {
				list[index] ^= list[i];
				list[i] ^= list[index];
				list[index] ^= list[i];
			}
		}
		
		return list;
	}
};