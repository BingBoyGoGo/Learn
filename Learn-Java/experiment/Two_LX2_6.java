public class Two_LX2_6 {
	public static void main(String args[]) {
		int i = 3;
		int k, j = 4;
		k = i + j;
		System.out.println("在复合块外的输出	k=" + k);
		{
			float f;
			f = j + 4.5F;
			i++;
			System.out.println("在复合块内的输出	f=" + f);
			System.out.println("在复合块内的输出	k=" + k);
		}
		System.out.println("在复合块外的输出	i=" + i);
	}
}
