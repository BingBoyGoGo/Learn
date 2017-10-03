public class Four_Six{
	public static void main(String [] args) {
		final double R = 40.0;
		
		// 产生随机点
		// 角度
		double a = Math.toRadians(Math.random() * 2 * Math.PI);
		System.out.println(a);
		double x = R * Math.cos(a);
		double y = R * Math.sin(a);
		
		System.out.println("x is " + x + " y is " + y);
	}
};