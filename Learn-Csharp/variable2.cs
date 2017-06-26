using System;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            char x = 'A';
            byte y = 222;
            string str = "hello C#!!";
            Console.WriteLine("{0}", str);
            Console.WriteLine("{1}", x,y);//花括号中的数字代表有几个参数
            Console.WriteLine("y={0}", y,x);//有一个，但能放两个

            decimal PI = 3.14m;//需要加上后缀M或m
            decimal area;
            int R = 12;
            area = PI * R;//R是浮点型时会报错
            Console.WriteLine("{0}", area);

            var ss = "bingogo";//var在赋值是才确定是什么类型
            var aa = 3;//整型
            Console.WriteLine("{0}", aa);
            Console.WriteLine("{0}", ss);

            byte i = 3;
            i += 4;
            //i = i + 4;//是非法的，无法将int隐式转化为byte;
            //i += 4;之所以合法是因为实际上发生了类型转换 i = (byte) + 4;
            //由此看出 i += j 实际上是 i = (type)(i+j);
            i = (byte)(i + 4); //这一句就是合法的
            //i = i + (byte) 4;这一句也是错的
            Console.WriteLine("{0}", i);
            Console.ReadKey();
        }
    }
}