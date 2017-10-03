public class Four_TwentyFive{
	public static void main(String[] args) {
		char ch1 = (char)(Math.random() * 10 + 65);
		char ch2 = (char)(Math.random() * 10 + 65);
		char ch3 = (char)(Math.random() * 10 + 65);
		
		// java 不能对String直接用下标索引
		// 用 char[]代替
		char []s = new char[7];
		s[0] = ch1;
		s[1] = ch2;
		s[2] = ch3;
		s[3] = (char)(Math.random() * 10 + 48);
		s[4] = (char)(Math.random() * 10 + 48);
		s[5] = (char)(Math.random() * 10 + 48);
		s[6] = (char)(Math.random() * 10 + 48);
		System.out.println(s);
		
		// char[] 也不能强制转换成String
		String str = new String(s);
		System.out.println(str);
	}
};