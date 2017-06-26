#if false
using System;
namespace CLASS
{
    class Bingogo
    {
        //可以定义在Main()后面
        //数据成员：包括常量，事件，字段（在类中定义的变量，用来存储描述类的特征的值，如颜色）
        public int i;
        public string str;

        /**属性成员：是字段的一种扩展，是一个与类或对象相关联的命名。
          * 与字段不同的是，属性不表示存储位置属性拥有访问器，访问器定义了读取或写入属性值时必须执行的代码
          * 通过属性的get{}和set{}访问器来实现对类中私有字段的读/写操作。
          * 为了类的封装性，一般把描述类的特征字段定义为private，把属性设为public来操作私有字段。
          * 定义：[访问修饰符] 数据类型 属性名
          * {
          *     get{}
          *     set{}
          * }
         **/
        private string name;
        public string Name
        {
            get { return name + " hahaha"; }//可以写表达式,也可以单纯的返回name
            set { name = value; }//可以不写表达式
        }

        //方法成员：[访问控制符] 返回值类型 方法名(参数列表){}
        public void Print()
        {
            Console.WriteLine("function");
        }

        //静态成员：静态成员是和类相关联的，不依赖于特定的对象，通过 类名.静态成员 来访问
        //区分C++中是用 类名::静态成员 来进行访问
        //类中常量（如const）隐式是静态
        static int aa;
        static void Aaa()
        {
            Console.WriteLine(Bingogo.aa);
        }

        static void Main()
        {
            Bingogo bingogo;
            bingogo = new Bingogo();//需要用new来申请内存
            bingogo.i = 1;
            bingogo.str = "bingogo";
            bingogo.Name = "BINGOGO";//通过set{}访问器为私有字段name赋值
            Bingogo.aa = 1;//对Bingogo类的静态数据成员赋值
            Bingogo.Aaa();

            bingogo.Print();//方法成员
            Console.WriteLine(bingogo.Name);//通过get{}访问器获取私有字段name
            Console.WriteLine(bingogo.i);
            Console.WriteLine(bingogo.str);
            Console.ReadKey();

        }
    }
    /**还有匿名类型和对象初始化器
      * 对象初始化器可以对对象进行初始化操作
      * Bingogo bing = new Bingogo(){name = "bing"};//对name进行了初始化
      * 匿名类型可以定义内嵌的类型，不需要显示的定义一个类型
      * var bing = new {x = 0,y = 1};//假设没有定义一个Point类却要使用Point类对象（即类是匿名的），可以使用对象初始化器
      * 构造函数也能做初始化工作，对象初始化器也可以做部分或者全部的工作
      * 匿名类型则在内嵌一个对象时比较方便
    **/

    /**
      *C#类不支持类的多继承，多继承实现靠接口
      *密封类：sealed 不能当成基类，不能派生类
      *抽象类：abstract 不能定义对象
    **/
}


#endif