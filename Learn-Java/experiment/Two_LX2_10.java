import java.io.*;

public class Two_LX2_10 {
	public static void main(String args[]) throws IOException {
		char ch;
		System.out.println("按 1/2/3 数字键可得大奖!");
		System.out.println("按空格键后回车可退出循环操作.");
		while ((ch = (char) System.in.read()) != ' ') {
			System.in.skip(2); // 跳过回车键(skip方法跳过和丢弃输入流中数据的 n 个字节)
			switch (ch) {
			case '1':
				System.out.println("恭喜你得大奖，一辆汽车!");
				break;
			case '2':
				System.out.println("不错呀，你得到一台笔记本电脑!");
				break;
			case '3':
				System.out.println("没有白来，你得到一台冰箱!");
				break;
			default:
				System.out.println("真不幸，你没有奖品!下次再来吧。");
			}
		}
	}
}
