**Java学习笔记**

基于菜鸟教程。

# 基本语法

## 注意事项

- **大小写敏感**：Java 是大小写敏感的，这就意味着标识符 Hello 与 hello 是不同的。
- **类名**：对于所有的类来说，类名的首字母应该大写。如果类名由若干单词组成，那么每个单词的首字母应该大写，例如 **MyFirstJavaClass** 。
- **方法名**：所有的方法名都应该以小写字母开头。如果方法名含有若干单词，则后面的每个单词首字母大写。
- **源文件名**：源文件名必须和类名相同。当保存文件的时候，你应该使用类名作为文件名保存（切记 Java 是大小写敏感的），文件名的后缀为 **.java**。（如果文件名和类名不相同则会导致编译错误）。
- **主方法入口**：所有的 Java 程序由 **public static void main(String[] args)** 方法开始执行。

## 标识符

类名、变量名以及方法名都被称为标识符。所有的标识符都应该以字母（A-Z 或者 a-z）,美元符（$）、或者下划线（_）开始。

## Java注释

支持单行注释和多行注释。

```java
public class HelloWorld {
   /* 这是第一个Java程序
    * 它将输出 Hello World
    * 这是一个多行注释的示例
    */
    public static void main(String[] args){
       // 这是单行注释的示例
       /* 这个也是单行注释的示例 */
       System.out.println("Hello World"); 
    }
}
```

# Java对象和类

## 类

类可以看成是创建 Java 对象的模板。

一个类可以包含以下类型变量：

- **局部变量**：在方法、构造方法或者语句块中定义的变量被称为局部变量。变量声明和初始化都是在方法中，方法结束后，变量就会自动销毁。
- **成员变量**：成员变量是定义在类中，方法体之外的变量。这种变量在创建对象的时候实例化。成员变量可以被类中方法、构造方法和特定类的语句块访问。
- **类变量**：类变量也声明在类中，方法体之外，但必须声明为 static 类型。

## 构造方法

每个类都有构造方法。如果没有显式地为类定义构造方法，Java 编译器将会为该类提供一个默认构造方法。

在创建一个对象的时候，至少要调用一个构造方法。构造方法的名称必须与类同名，**一个类可以有多个构造方法，从而使用不同的参数来初始化对象**。

```java
public class Puppy{
    public Puppy(){
    }
 
    public Puppy(String name){
        // 这个构造器仅有一个参数：name
    }
}
```

## 创建对象（实例化）

对象是根据类创建的。在Java中，使用关键字 new 来创建一个新的对象。创建对象需要以下三步：

- **声明**：声明一个对象，包括对象名称和对象类型。
- **实例化**：使用关键字 new 来创建一个对象。
- **初始化**：使用 new 创建对象时，会调用构造方法初始化对象。

```java
public class Puppy{
   public Puppy(String name){
      //这个构造器仅有一个参数：name
      System.out.println("小狗的名字是 : " + name ); 
   }
    
   public static void main(String[] args){
      // 下面的语句将创建一个Puppy对象
      Puppy myPuppy = new Puppy( "tommy" );
   }
}
```

## 访问实例变量和方法

通过已创建的对象来访问成员变量和成员方法，称为调用。

```java
/* 实例化对象 */
Object referenceVariable = new Constructor();
/* 访问类中的变量 */
referenceVariable.variableName;
/* 访问类中的方法 */
referenceVariable.methodName();
```

## 源文件声明规则

当在一个源文件中定义多个类，并且还有import语句和package语句时，要特别注意这些规则。

- 一个源文件中只能有一个 public 类
- 一个源文件可以有多个非 public 类
- 源文件的名称应该和 public 类的类名保持一致。例如：源文件中 public 类的类名是 Employee，那么源文件应该命名为Employee.java。
- 如果一个类定义在某个包中，那么 package 语句应该在源文件的首行。
- 如果源文件包含 import 语句，那么应该放在 package 语句和类定义之间。如果没有 package 语句，那么 import 语句应该在源文件中最前面。
- import 语句和 package 语句对源文件中定义的所有类都有效。在同一源文件中，不能给不同的类不同的包声明。

## Java 包

包主要用来对类和接口进行分类。当开发 Java 程序时，可能编写成百上千的类，因此很有必要对类和接口进行分类。

### import 语句

在 Java 中，如果给出一个完整的限定名，包括包名、类名，那么 Java 编译器就可以很容易地定位到源代码或者类。import 语句就是用来提供一个合理的路径，使得编译器可以找到某个类。

# Java 基本数据类型

变量就是申请内存来存储值。通过定义不同类型的变量，可以在内存中储存整数、小数或者字符。

Java 的两大数据类型:

- 内置数据类型
- 引用数据类型

## 内置数据类型

Java语言提供了八种基本类型。六种数字类型（四个整数型，两个浮点型），一种字符类型，还有一种布尔型。

| 数据类型 | 描述                | 大小（字节） | 默认值   | 最小值                                | 最大值                                | 示例                 |
| -------- | ------------------- | ------------ | -------- | ------------------------------------- | ------------------------------------- | -------------------- |
| byte     | 8位带符号整数       | 1            | 0        | -128                                  | 127                                   | byte b = 127;        |
| short    | 16位带符号整数      | 2            | 0        | -32,768($-2^{15}$)                    | 32,767($2^{15}-1$)                    | short s = 32000;     |
| int      | 32位带符号整数      | 4            | 0        | -2,147,483,648($-2^{31}$)             | 2,147,483,647($2^{31}-1$)             | int x = 42;          |
| long     | 64位带符号整数      | 8            | 0L       | -9,223,372,036,854,775,808($-2^{63}$) | 9,223,372,036,854,775,807($2^{63}-1$) | long l = 123456L;    |
| float    | 32位浮点数          | 4            | 0.0f     | 1.4E-45                               | 3.4028235E38                          | float f = 3.14f;     |
| double   | 64位浮点数          | 8            | 0.0(d)   | 4.9E-324                              | 1.7976931348623157E308                | double d = 2.718;    |
| char     | 单个16位Unicode字符 | 2            | '\u0000' | '\u0000'                              | '\uffff'                              | char c = 'A';        |
| boolean  | 表示true或false的值 | 1/8          | false    | N/A                                   | N/A                                   | boolean flag = true; |

## 引用类型

- 在Java中，引用类型的变量非常类似于C/C++的指针。引用类型指向一个对象，指向对象的变量是引用变量。这些变量在声明时被指定为一个特定的类型，比如 Employee、Puppy 等。变量一旦声明后，类型就不能被改变了。
- 对象、数组都是引用数据类型。
- 所有引用类型的默认值都是null。
- 一个引用变量可以用来引用任何与之兼容的类型。

## Java 常量

常量在程序运行时是不能被修改的。

在 Java 中使用 final 关键字来修饰常量，声明方式和变量类似：

```java
final double PI = 3.1415927;
```

虽然常量名也可以用小写，但为了便于识别，通常使用大写字母表示常量。

当使用字面量的时候，前缀 **0** 表示 8 进制，而前缀 **0x** 代表 16 进制, 例如：

```java
int decimal = 100;
int octal = 0144;
int hexa =  0x64;
```

Java语言支持一些特殊的转义字符序列。

| 符号   | 字符含义                 |
| :----- | :----------------------- |
| \n     | 换行 (0x0a)              |
| \r     | 回车 (0x0d)              |
| \f     | 换页符(0x0c)             |
| \b     | 退格 (0x08)              |
| \0     | 空字符 (0x0)             |
| \s     | 空格 (0x20)              |
| \t     | 制表符                   |
| \"     | 双引号                   |
| \'     | 单引号                   |
| \\     | 反斜杠                   |
| \ddd   | 八进制字符 (ddd)         |
| \uxxxx | 16进制Unicode字符 (xxxx) |

## 类型转换

**整型、实型（常量）、字符型数据可以混合运算。运算中，不同类型的数据先转化为同一类型，然后进行运算。**

转换从低级到高级。

```java
低  ------------------------------------>  高

byte,short,char—> int —> long—> float —> double 
```

### 自动类型转换

必须满足转换前的数据类型的位数要低于转换后的数据类型，例如: short数据类型的位数为16位，就可以自动转换位数为32的int类型，同样float数据类型的位数为32，可以自动转换为64位的double类型。

### 强制类型转换

在把容量大的类型转换为容量小的类型时必须使用强制类型转换，转换的数据类型必须是兼容的。

格式：`(type)value` type是要强制类型转换后的数据类型

+ 转换过程中可能导致溢出或损失精度，例如：

  ```java
  int i =128;   
  byte b = (byte)i;
  //因为 byte 类型是 8 位，最大值为127，所以当 int 强制转换为 byte 类型时，值 128 时候就会导致溢出。
  ```

+ 浮点数到整数的转换是通过舍弃小数得到，而不是四舍五入，例如：

  ```
  (int)23.7 == 23;        
  (int)-45.89f == -45
  ```

### 隐含强制类型转换

- 整数的默认类型是 int。
- 小数默认是 double 类型浮点型，在定义 float 类型时必须在数字后面跟上 F 或者 f。

# Java 变量类型

在Java语言中，所有的变量在使用前必须声明。声明变量的基本格式如下：

```java
type identifier [ = value][, identifier [= value] ...] ;
```

**格式说明：**

- type -- 数据类型。
- identifier -- 是变量名，可以使用逗号 **,** 隔开来声明多个同类型变量。

以下列出了一些变量的声明实例。注意有些包含了初始化过程。

```java
int a, b, c;         // 声明三个int型整数：a、 b、c
int d = 3, e = 4, f = 5; // 声明三个整数并赋予初值
byte z = 22;         // 声明并初始化 z
String s = "runoob";  // 声明并初始化字符串 s
double pi = 3.14159; // 声明了双精度浮点型变量 pi
char x = 'x';        // 声明变量 x 的值是字符 'x'。
```

Java 语言支持的变量类型有：

- **局部变量（Local Variables）：**定义在方法、构造方法或语句块中的变量，作用域只限于当前方法、构造方法或语句块中。局部变量必须在使用前声明，并且不能被访问修饰符修饰。
- **成员变量（Instance Variables）：**定义在类中、方法之外的变量，作用域为整个类，可以被类中的任何方法、构造方法和语句块访问。成员变量可以被访问修饰符修饰。
- **静态变量（Class Variables）：**定义在类中、方法之外的变量，并且使用 `static` 关键字修饰，作用域为整个类，可以被类中的任何方法、构造方法和语句块访问，静态变量的值在程序运行期间只有一个副本。静态变量可以被访问修饰符修饰。
- **参数变量（Parameters）：**方法定义时声明的变量，作为调用该方法时传递给方法的值。参数变量的作用域只限于方法内部。

## Java 参数变量

Java 中的参数变量是指在方法或构造函数中声明的变量，用于接收传递给方法或构造函数的值。参数变量与局部变量类似，但它们只在方法或构造函数被调用时存在，并且只能在方法或构造函数内部使用。

Java 方法的声明语法如下：

```java
accessModifier returnType methodName(parameterType parameterName1, parameterType parameterName2, ...) {
    // 方法体
}
```

- parameterType -- 表示参数变量的类型。
- parameterName -- 表示参数变量的名称。

在调用方法时，我们必须为参数变量传递值，这些值可以是常量、变量或表达式。

方法参数变量的值传递方式有两种：**值传递**和**引用传递**。

- **值传递：**在方法调用时，传递的是实际参数的值的副本。当参数变量被赋予新的值时，只会修改副本的值，不会影响原始值。Java 中的基本数据类型都采用值传递方式传递参数变量的值。
- **引用传递：**在方法调用时，传递的是实际参数的引用（即内存地址）。当参数变量被赋予新的值时，会修改原始值的内容。Java 中的对象类型采用引用传递方式传递参数变量的值。

## Java 局部变量

- 局部变量声明在方法、构造方法或者语句块中。
- 局部变量在方法、构造方法、或者语句块被执行的时候创建，当它们执行完成后，变量将会被销毁。
- 局部变量必须在使用前声明，并且**不能被访问修饰符修饰**，因为它们的作用域已经被限制在了声明它们的方法、代码块或构造函数中。
- 局部变量只在声明它的方法、构造方法或者语句块中可见，不能被其他方法或代码块访问。
- 局部变量是在栈上分配的。
- 局部变量没有默认值，所以局部变量被声明后，必须经过初始化，才可以使用。

局部变量的声明语法为：

```java
type variableName;
```

- type -- 表示变量的类型。
- variableName -- 表示变量的名称。

局部变量必须在使用之前进行初始化，否则编译器会报错。初始化可以在声明时或后面的代码中进行。如果在声明时未初始化，变量将被赋予默认值。局部变量只在声明它的方法、构造方法或语句块内可见，其他方法、构造方法或语句块不能访问该局部变量。当方法、构造方法或语句块执行完毕后，局部变量将被销毁，其占用的内存也会被释放。

## 成员变量（实例变量）

- 成员变量声明在一个类中，但在方法、构造方法和语句块之外。
- 当一个对象被实例化之后，每个成员变量的值就跟着确定。
- 成员变量在对象创建的时候创建，在对象被销毁的时候销毁。
- 成员变量的值应该至少被一个方法、构造方法或者语句块引用，使得外部能够通过这些方式获取实例变量信息。
- 成员变量可以声明在使用前或者使用后。
- 访问修饰符可以修饰成员变量。
- 成员变量对于类中的方法、构造方法或者语句块是可见的。一般情况下应该把成员变量设为私有。通过使用访问修饰符可以使成员变量对子类可见。
- 成员变量具有默认值。数值型变量的默认值是0，布尔型变量的默认值是 false，引用类型变量的默认值是 null。变量的值可以在声明时指定，也可以在构造方法中指定；
- 成员变量可以直接通过变量名访问。但在静态方法以及其他类中，就应该使用完全限定名：**ObjectReference.VariableName**。

成员变量的声明语法为：

```java
accessModifier type variableName;
```

- accessModifier --表示访问修饰符，可以是 public、protected、private 或默认访问级别（即没有显式指定访问修饰符）。
- type -- 表示变量的类型。
- variableName -- 表示变量的名称。

与局部变量不同，成员变量的值在创建对象时被分配，即使未对其初始化，它们也会被赋予默认值，例如 int 类型的变量默认值为 0，boolean 类型的变量默认值为 false。

成员变量可以通过对象访问，也可以通过类名访问（如果它们是静态成员变量）。如果没有显式初始化成员变量，则它们将被赋予默认值。可以在构造函数或其他方法中初始化成员变量，或者通过对象或类名访问它们并设置它们的值。

## 类变量（静态变量）

Java 中的静态变量是指在类中定义的一个变量，它与类相关而不是与实例相关，即无论创建多少个类实例，静态变量在内存中只有一份拷贝，被所有实例共享。

静态变量在类加载时被创建，在整个程序运行期间都存在。

### 定义方式

静态变量的定义方式是在类中使用 **static** 关键字修饰变量，通常也称为类变量。

以下实例中我们定义一个静态变量 **count** ，其初始值为 0：

## 实例

**public** **class** MyClass {
  **public** **static** **int** count = 0;
  *// 其他成员变量和方法*
}

### 访问方式

由于静态变量是与类相关的，因此可以通过类名来访问静态变量，也可以通过实例名来访问静态变量。

## 实例

MyClass.count = 10; *// 通过类名访问*
MyClass obj = **new** MyClass();
obj.count = 20; *// 通过实例名访问*

### 生命周期

静态变量的生命周期与程序的生命周期一样长，即它们在类加载时被创建，在整个程序运行期间都存在，直到程序结束才会被销毁。因此，静态变量可以用来存储整个程序都需要使用的数据，如配置信息、全局变量等。

### 初始化时机

静态变量在类加载时被初始化，其初始化顺序与定义顺序有关。

如果一个静态变量依赖于另一个静态变量，那么它必须在后面定义。

## 实例

**public** **class** MyClass {
  **public** **static** **int** count1 = 0;
  **public** **static** **int** count2 = count1 + 1;
  *// 其他成员变量和方法*
}

上面的例子中，count1 要先于 count2 初始化，否则编译时会报错。

### 常量和静态变量的区别

常量也是与类相关的，但它是用 final 关键字修饰的变量，一旦被赋值就不能再修改。与静态变量不同的是，常量在编译时就已经确定了它的值，而静态变量的值可以在运行时改变。另外，常量通常用于存储一些固定的值，如数学常数、配置信息等，而静态变量通常用于存储可变的数据，如计数器、全局状态等。

总之，静态变量是与类相关的变量，具有唯一性和共享性，可以用于存储整个程序都需要使用的数据，但需要注意初始化时机和与常量的区别。

### 静态变量的访问修饰符

静态变量的访问修饰符可以是 public、protected、private 或者默认的访问修饰符（即不写访问修饰符）。

需要注意的是，静态变量的访问权限与实例变量不同，因为静态变量是与类相关的，不依赖于任何实例。

### 静态变量的线程安全性

Java 中的静态变量是属于类的，而不是对象的实例。因此，当多个线程同时访问一个包含静态变量的类时，需要考虑其线程安全性。

静态变量在内存中只有一份拷贝，被所有实例共享。因此，如果一个线程修改了静态变量的值，那么其他线程在访问该静态变量时也会看到修改后的值。这可能会导致并发访问的问题，因为多个线程可能同时修改静态变量，导致不确定的结果或数据一致性问题。

为了确保静态变量的线程安全性，需要采取适当的同步措施，如同步机制、原子类或 volatile 关键字，以便在多线程环境中正确地读取和修改静态变量的值。

### 静态变量的命名规范

静态变量的命名规范与实例变量相同，一般采用驼峰命名法，并且要用 static 关键字明确标识。例如：

## 实例

**public** **class** MyClass {
  **public** **static** **int** MAX_COUNT = 100;
  *// 其他成员变量和方法*
}

### 静态变量的使用场景

静态变量通常用于以下场景：

- 存储全局状态或配置信息
- 计数器或统计信息
- 缓存数据或共享资源
- 工具类的常量或方法
- 单例模式中的实例变量
