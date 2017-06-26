#if false
using System;
namespace Bingogo
{
    class Point
    {
        public Point(int xx,int yy)//含参数的构造函数
        {
            x = xx;
            y = yy;
        }
        public Point(){ }//无参数的构造函数
        static Point()//静态构造函数，无访问修饰符
        {             //对类中的静态成员进行赋值操作
            z = 100;
        }
        public int x;// { get; set; }
        public int y { get; set; }
        static public int z;
        public string str;
    }

    class MainClass
    {
        static void Main()
        {
            Point p1 = new Point(1,2);
            Console.Write("{0}{1}",p1.x,' ');
            Console.WriteLine(p1.x);
            p1.str = "bingogo";
            p1.str = new string('b',9);
            Console.WriteLine(p1.str);
            Point point = new Point(2, 4);
            Point p2 = new Point() { x = 2, y = 3 };
            Console.WriteLine("{0},{1}", p2.x, p2.y);
            Console.WriteLine("{0},{1}", point.x, point.y);
            Console.WriteLine("{0}", Point.z);
            Console.ReadKey();

            //AA a = new AA();
            //a.i = 3;
            //Console.Write(a.i);
            //Console.ReadKey();
        }
    }
    public abstract class AA
    {
        public int i;
    }
}
namespace bing
{
    class MainClass
    {
        static void main()
        {
            Console.ReadKey();
        }
    }
}

#endif