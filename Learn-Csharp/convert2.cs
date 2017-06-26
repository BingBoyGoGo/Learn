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


namespace ConsoleApp1
{
    class Program
    {
        static int Main(string[] args)
        {
            Console.WriteLine("Hello World!");

            string MyString = "falsE";
            bool MyBool = Convert.ToBoolean(MyString);//Convert类的ToBoolean方法
            String Str = "233343";
            int i = Convert.ToInt32(Str);//Convert类的ToInt32方法

            Console.WriteLine("{0}", MyString);
            Console.WriteLine("{0}", i);
            Console.WriteLine("{0}", Str);
            Console.WriteLine("{0}", MyBool);
            Console.ReadKey();
            return 0;
        }
    }
}