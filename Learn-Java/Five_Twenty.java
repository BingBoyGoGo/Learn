public class Five_Twenty{
	public static void main(String[] args) {
		int k = 0;
		int j = 2;
		boolean b = true;
		
		for(int i = 2; i < 998; i++) {
			int sq = (int)Math.sqrt(i);
			while(j <= sq) {
				if(0 == (i % j++)){
					b = false;
					break;
				}
			}
			j = 2;
			
			if(b){
				if(k == 9) {
					System.out.printf("%4d\n",i);
					k = 0;
				}
				else {
					System.out.printf("%4d",i);
					k++;
				}
			}
			b = true;
		}
	}
};