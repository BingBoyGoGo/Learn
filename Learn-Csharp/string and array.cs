#if false
using System;

namespace Application1
{
    enum Week { 星期一 = 1, 星期二 };
    class Bingogo
    {
        static void Main(string []args)
        {
            //enum
            Week week = (Week)2;
            Console.WriteLine(week);
            Console.WriteLine((Week)1);
            Console.ReadKey();

            //string：有许多方法，string类的对象也有许多方法
            string str = new string('a', 6);//str值:"aaaaaa";
            Console.WriteLine("{0}",str);
            int i = 3;
            int a = 4;
            Console.WriteLine("{0,5},{1}",i,a);//{0,5}占5个位，右对齐
            Console.ReadKey();

            //array：有许多方法
            int[] arr1 = { 4, 5 };//一维数组，不能在声明的时候指定大小
            int[] arr2;//无法指定大小
            arr2 = new int[8] {1,2,3,4,5,6,7,8};//使用new来为数组分配空间来指定大小，{}用来初始化
            int[] arr3 = new int[3]; //也可以写成一句
            int[,] arr4;//二维数组的声明
            arr4 = new int[,] { { 1 }, { 2 } };//二维数组的定义
            int[,] arr42 = new int[,] { { 1,2,3},{ 4,5,6} };//二维数组的定义
            int[][] arr5;//交错数组的声明
            arr5 = new int[2][];//需指定大小
            arr5[0] = new int[3] { 1, 2, 3 };
            arr5[1] = new int[4] { 4, 5, 6, 7 };//交错数组的初始化
            Console.ReadKey();
        }
    }
}

#endif