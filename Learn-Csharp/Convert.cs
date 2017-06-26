#if false
using System;
/*常用的有一下方法*/
/*
    * ToBoolean
    * ToChar
    * ToDateTime
    * ToDecimal
    * ToDouble
    * ToInt16
    * ToInt32
    * ToString
*/
/*
 * 数值类型的Tostring()方法可以将数值型数据转换为字符串
 * 数值类型的Parse()方法可以将字符串转换为数值型
 */

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!!");

            string MyString = "false";
            bool MyBool = Convert.ToBoolean(MyString);//Convert类的ToBoolean方法
            String Str = "233343";
            int i = Convert.ToInt32(Str);//Convert类的ToInt32方法

            Console.WriteLine("{0}", MyString);
            Console.WriteLine("{0}", i);
            Console.WriteLine("{0}", Str);
            Console.WriteLine("{0}", MyBool);
            Console.ReadKey();

            //Parse()和ToString()方法
            int a = 5678;
            string aa = Convert.ToString(a);
            string bb = "1234";
            string dd = "1234.5678";
            int b = int.Parse(bb);
            double d = double.Parse(dd);
            Console.WriteLine("{0}",aa);
            Console.WriteLine("{0}",b);
            Console.WriteLine("{0}",d);
            Console.ReadLine();
            
            /*
             *装箱与拆箱：
             * 拆箱是把“引用”类型转换成“值”类型，装箱是把“值”类型转换成“引用”类型
             * 当方法参数要求使用“引用”类型而想把“值”类型的变量通过该参数传入就需要用到这个操作
             */
            int n = 4;//n是“值”类型
            object obj = n;//封箱，把任何值类型隐式转换成object类型，其中object为引用类型
            Console.WriteLine("n的初始值是{0}，装箱后的值是{1}",n,obj.ToString());
            int m = (int)obj;
            Console.WriteLine("引用类型的值是{0}，拆箱后的值是{1}", obj.ToString(), m);
            Console.ReadKey();

            /*
             * “值”类型在定义后分配内存，“引用”类型要用new显示分配内存
             * “值”类型在栈上分配，“引用”类型从堆分配
             */

            int x = 100;
            object obje = x;
            int y = (int)obje;
            Console.WriteLine("{0}\n", y);
            Console.ReadKey();

        }
    }
}
#endif