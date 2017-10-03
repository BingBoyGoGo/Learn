public class Five_Ten{
	public static void main(String [] args) {
		// 5 和  6 最小公倍数是 30
		int result = 120;
		s: while (result < 1000) {
			for (int i = 0; i < 10; i++) {
				System.out.print(result + "  ");
				result += 30;
				// 满足条件跳出while
				if(result > 1000) 
					break s;
			}
			System.out.println();
		}
		
		// 下面来常规的
		System.out.println();
		System.out.println();
		int i = 1;
		for(int re = 120; re < 1000; re += 30) {
			if(i++ > 10) {
				System.out.println();
				i = 2;
			}
			System.out.print(re + "  ");
		}
		
		// 最暴力的
		System.out.println();
		System.out.println();
		int k = 1;
		for(int j = 100; j < 1000; j++) {
			if (0 == j % 5 && 0 == j % 6) {
				System.out.print(j + "  ");
				if (k++ > 9) {
					System.out.println();
					k = 1;
				}
			}
		}
	}
};