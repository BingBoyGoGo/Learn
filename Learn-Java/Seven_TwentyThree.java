public class Seven_TwentyThree{
	final static int STUDENTCOUNT = 100;
	public static void main(String[] args) {
		boolean[] l = new boolean[STUDENTCOUNT];
		for(int i = 0; i < STUDENTCOUNT; i++) {
			l[i] = true;
		}
		
		int s = 1;
		while(s < STUDENTCOUNT) {
			for(int j = s; j < STUDENTCOUNT; j += (s+1)) {
				l[j] = !l[j];
			}
			s++;
		}
		
		for(int i = 0; i < STUDENTCOUNT; i++) {
			if(l[i]) {
				System.out.print("L" + (i+1) + " ");
			}
		}
	}
};