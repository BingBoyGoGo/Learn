public class Six_Twentysix{
	public static void main(String[] args) {
		judge();
	}
	
	public static void judge(){
		boolean huiwen = false;
		boolean sushu = true;
		int index = 0;
		int count = 0;
		int len = 0;
		
		for(int num = 2; ; num++){
			String sz_num = Integer.toString(num);
			len = sz_num.length();
			
			// 判断回文数
			while(sz_num.charAt(index) == sz_num.charAt(len-1-index)) {
				index++;
				if(index > len-1-index) {
					huiwen = true;
					break;
				}
			}
			
			// 判断回文数是否为素数
			if(huiwen) {
				int sq = (int)Math.sqrt(num);
				int i = 2;
				while(i <= sq) {
					if(0 == num % i++) {
						sushu = false;
						//b = false;
					}
				}
			}
			
			// 若是回文素数
			if(huiwen & sushu) {
				count++;
				if(0 == count % 10) {
					System.out.printf("%6d\n", num);
				}
				else{
					System.out.printf("%6d ", num);
				}
			}
			
			// 足够100个数结束
			if(count >= 100) {
				break;
			}
			
			// 初始化
			sushu = true;
			huiwen = false;
			index = 0;
		}
	}
};