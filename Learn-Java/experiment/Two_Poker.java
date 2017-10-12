public class Two_Poker{
	enum Face{
		Diamods, Clubs, Hearts, Spades;
	
		public static Face get(int i) {
			for(Face e : Face.values()) {
				if(e.ordinal() == i) {
					return e;
				}
			}
			// 此处必须要有返回值
			return Face.Spades;
		}
	};
	
	enum Points{
		_2,_3,_4,_5,_6,_7,_8,_9,_10,Jack,Queen,King,Ace;
		
		public static Points get(int i) {
			for(Points e : Points.values()) {
				if(e.ordinal() == i) {
					return e;
				}
			}
			return Points.Ace;
		}
	};
		
	public static void main(String[] args) {
		// int num = (int) ((Math.random() * 2 + Math.random() * 3) * 52 / 5);
		// Face face = Face.get(num % 4);
		// Points points = Points.get(num % 13);
		
		// 感觉概率比较相近
		Face face = Face.get((int)(Math.random() * 4));
		Points points = Points.get((int)((Math.random() + Math.random()) * 13 / 2));
		System.out.print("The Card you picked is ");
		if(points.ordinal() < 9) {
			System.out.println((points.ordinal() + 2) + " of " + face);
		}
		else
			System.out.println(points + " of " + face);	
	}
	
	public static void print(Face face, Points points) {
		System.out.println("The Card you picked is " + points + " of " + face);
	}
};

