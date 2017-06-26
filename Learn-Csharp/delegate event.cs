#if true

/**
 * 委托delegate，相当于C++的指针函数(*p)()，需定义对象才能使用 
 * 事件event
 **/

using System;

namespace Bing
{
    class Bin
    {
        public bool AA(int i)
        {
            Console.Write(i);
            return true;
        }
    }

    class Bing
    {
        //定义委托
        public delegate bool Delg(int i);

        public static bool AA(int i)
        {   //静态方法
            Console.WriteLine(i);
            return true;
        }
        static void Main()
        {
            //delegate变量声明
            Delg dele;
            //实例化delegate
            Bin bin = new Bin();
            dele = new Delg(bin.AA);
            //使用delegate
            dele(8);            
            Console.ReadKey();
            Delg delg = new Delg(Bing.AA);
            delg(5);
            Console.ReadKey();
        }
    }
}


#endif