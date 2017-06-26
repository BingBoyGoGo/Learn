#if false
using System;

namespace Program
{
    class Program
    {
        static void Main(string []args)
        {
            /***try-catch-finally语句
                *try{可能出现异常的代码}
                *catch(异常类型 异常对象){对可能出现的异常进行处理}   
                *finally{最后要执行的代码，进行必要的清理操作，以释放资源}
            ***/
            try
            {
                int x = int.Parse(Console.ReadLine());
                int y = 10;
                int z = y / x;
            }
            catch(Exception e)                  //捕获异常
            {
                Console.WriteLine(e.Message);   //输出被捕获的异常对象e的Message属性值
            }
            finally
            {
                Console.ReadKey();              //关闭文件
            }

            //throw语句：throw 异常对象

        }
    }
}
#endif