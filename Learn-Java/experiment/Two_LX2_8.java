public class Two_LX2_8 {
	public static void main(String args[]) {
		int c = 38;

		switch (c < 10 ? 1 : c < 25 ? 2 : c < 35 ? 3 : 4) {
		case 1:
			System.out.println(" " + c + "�� �е��䡣Ҫ�ഩ�·���");
			break;
		case 2:
			System.out.println(" " + c + "�� �����ʡ���ȥ��ɡ�");
			break;
		case 3:
			System.out.println(" " + c + "�� �е��ȡ�");
			break;
		default:
			System.out.println(" " + c + "�� ̫����!���յ���");
		}
	}
}
