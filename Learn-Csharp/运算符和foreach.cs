#if false
using System;

namespace ConsoleAPP3
{
    class Program
    {
        static void Main()
        {
            /*new运算符：用于创建一个新的类型实例。
              *对象创建表达式：class N{};N n = new N;
              *数组创建表达式：string [] M = new string[5];
              *委托（代表）创建表达式：delegate double(int p); L f=new L(2);
            */

            //typeof运算符:用于获取系统原型对象的类型即type类型，type类包含关于值类型和引用类型的信息
            Type T = typeof(int);
            Console.WriteLine("类型：{0}", T);
            Console.ReadKey();

            //checked和unchecked运算符：用于允许或禁止对指定的运算进行检测，并指出相应的错误提示信息
            byte s = 255;
            unchecked //换成checked则会中断
            {
                s += 2;//溢出了
            }
            Console.WriteLine(s.ToString());
            Console.ReadLine();

            //&运算符实现状态控制,这种方式的权限有查看、新增、修改、删除、保存权限并给予拥护查看、修改、保存的权限
            int None = 0;   //00000000
            int Scan = 1;   //00000001
            int New = 2;    //00000010
            int Modify = 4; //00000100
            int Delete = 8; //00001000
            int Save = 16;  //00010000
            //最好只有一位是1
            int userRight = None;//默认无权限
            userRight = Scan | Modify | Save | Delete;   //00010101
            Console.WriteLine("{0}", userRight);
            Console.ReadKey();
            if((userRight&Scan) == Scan)    //00000001 == 00000001
            {
                Console.WriteLine("用户有查看权限。");
            }
            if((userRight&New) == New)      //00000000 != 00000010
            {
                Console.WriteLine("用户有新建权限。");
            }
            else
            {
                Console.WriteLine("用户无新建权限。");
            }
            Console.ReadKey();

            /**
                *foreach：获取集合中的所有对象，不需要给出循环变量和循环条件，
                 也不需要给循环变量赋初值和修改循环变量的值
                *foreach语句中，需要根据集合或者数组的元素类型，
                 定义一个相同类型的局部变量，执行循环体，然后判断集合中是否存在元素
                 若存在则将集合中的第一个元素赋给局部变量，执行循环体
                 然后判断是否还有剩余元素。若存在则将下一个元素赋给局部变量，再次执行循环体
            **/
            Console.WriteLine("foreach");
            string[] week = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };//定义数组并赋初值
            foreach (string str in week)//遍历数组元素，局部变量str的类型与数组元素类型相同
            {
                Console.WriteLine(str);
            }
            //和for语句的区别在于foreach每次的参数值都可以有很大的变化，也可以比上一次的值小
            //而for语句只能加或减，只是数值朝一个方向变化了而已
            Console.ReadKey();
        }
    }
}

#endif