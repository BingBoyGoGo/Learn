#if false

using System;

namespace Bing
{
    interface inter1
    {   //借口的定义和类类似
        int aa
        {   //定义一个属性
            get;
            set;
        }
    }

    interface inter2
    {
        string str
        {
            get;
            set;
        }
    }

    class bing : inter1, inter2
    {
        public int i;
        public string s;

        //接口属性实现，此时加上修饰符
        public int aa
        {
            get { return i; }
            set { i = 10; }
        }

        public string str
        {
            get { return this.s; }
            set { s = value; }//this.s = "bing"; }
        }

    }

    class Bing
    {
        static void Main()
        {
            bing bingogo = new bing();
            bingogo.str = "bingogo";
            bingogo.aa = 11;

            Console.WriteLine(bingogo.i);
            Console.WriteLine(bingogo.s);
            Console.ReadKey();
        }
    }
}


#endif 