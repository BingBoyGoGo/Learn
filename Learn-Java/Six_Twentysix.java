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
			
			// �жϻ�����
			while(sz_num.charAt(index) == sz_num.charAt(len-1-index)) {
				index++;
				if(index > len-1-index) {
					huiwen = true;
					break;
				}
			}
			
			// �жϻ������Ƿ�Ϊ����
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
			
			// ���ǻ�������
			if(huiwen & sushu) {
				count++;
				if(0 == count % 10) {
					System.out.printf("%6d\n", num);
				}
				else{
					System.out.printf("%6d ", num);
				}
			}
			
			// �㹻100��������
			if(count >= 100) {
				break;
			}
			
			// ��ʼ��
			sushu = true;
			huiwen = false;
			index = 0;
		}
	}
};