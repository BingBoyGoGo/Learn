import java.io.*;

public class Two_LX2_10 {
	public static void main(String args[]) throws IOException {
		char ch;
		System.out.println("�� 1/2/3 ���ּ��ɵô�!");
		System.out.println("���ո����س����˳�ѭ������.");
		while ((ch = (char) System.in.read()) != ' ') {
			System.in.skip(2); // �����س���(skip���������Ͷ��������������ݵ� n ���ֽ�)
			switch (ch) {
			case '1':
				System.out.println("��ϲ��ô󽱣�һ������!");
				break;
			case '2':
				System.out.println("����ѽ����õ�һ̨�ʼǱ�����!");
				break;
			case '3':
				System.out.println("û�а�������õ�һ̨����!");
				break;
			default:
				System.out.println("�治�ң���û�н�Ʒ!�´������ɡ�");
			}
		}
	}
}
