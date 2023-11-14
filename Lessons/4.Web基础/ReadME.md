

## 一、网页三件套

+ **HTML** 定义了网页的内容
+ **CSS** 描述了网页的布局
+ **JavaScript** 控制了网页的行为

## 二、HTML5基础

- pre标签
  - 该标签可定义预格式化的文本，被包围在 pre 元素中的文本通常会保留空格和换行符，并且文本会呈现为等宽字体。该标签的一个常见应用就是用来表示计算机的源代码。
  - 该元素中允许的文本可以包括物理样式和基于内容的样式变化，还有链接、图像和水平分隔线。当把其他标签（比如 <a> 标签）放到 <pre> 块中时，就像放在 HTML/XHTML 文档的其他部分中一样即可。
  - 标签中的特殊符号被转换为符号实体，比如 "&lt;" 代表 "<"，"&gt;" 代表 ">"。
  - 可以导致段落断开的标签（比如<h1>、<p> 和 <address> 标签）尽量不要包含在 <pre> 所定义的块里
  - 如果使用 <pre> 标签来定义计算机源代码，请使用符号实体来表示特殊字符，比如 "&lt;" 代表 "<"，"&gt;" 代表 ">"，"&amp;" 代表 "&"。

- 删除字效果和插入字效果：<del>和<ins>

## 三、CSS基础

+ CSS即**C**ascading **S**tyle **S**heets，层叠样式表。

+ id和class选择器：如果你要在HTML元素中设置CSS样式，你需要在元素中设置"id" 和 "class"选择器。

  + id选择器：id 选择器可以为标有特定 id 的 HTML 元素指定特定的样式。HTML元素以id属性来设置id选择器,CSS 中 id 选择器以 "#" 来定义。

    ```css
    #para1
    {
        text-align:center;
        color:red;
    }
    ```

  + class选择器：class 选择器用于描述一组元素的样式，class 选择器有别于id选择器，class可以在多个元素中使用。class 选择器在 HTML 中以 class 属性表示, 在 CSS 中，类选择器以一个点 **.** 号显示。

    ```css
    .center {text-align:center;}
    ```


## 四、JavaScript基础

+ **应用注释符号验证浏览器是否支持 JavaScript 脚本功能**

  如果用户不能确定浏览器是否支持JavaScript脚本，那么可以应用HTML提供的注释符号进行验证。HTML注释符号是以 **<--** 开始以 **-->** 结束的。如果在此注释符号内编写 JavaScrip t脚本，对于不支持 JavaScript 的浏览器，将会把编写的 JavaScript 脚本作为注释处理。

  使用 JavaScript 脚本在页面中输出一个字符串，将 JavaScript 脚本编写在 HTML 注释中，如果浏览器支持 JavaScript 将输出此字符串，如果不支持将不输出此字符串，代码如下:

  ```html
  <script>
  <!--
  document.write("您的浏览器支持JavaScript脚本!");
  //-->
  </script>
  ```

  **注意：**注释行结尾处的两条斜杠 **//** 是 JavaScript 注释符号。这可以避免 JavaScript 执行 **-->** 标签。

+ **重新定义变量**

  使用 var 关键字重新声明变量可能会带来问题。在块中重新声明变量也会重新声明块外的变量：

  ```js
  var x = 10;
  // 这里输出 x 为 10
  { 
      var x = 2;
      // 这里输出 x 为 2
  }
  // 这里输出 x 为 2
  ```

  let 关键字就可以解决这个问题，因为它只在 let 命令所在的代码块 **{}** 内有效。

  ```JS
  var x = 10;
  // 这里输出 x 为 10
  { 
      let x = 2;
      // 这里输出 x 为 2
  }
  // 这里输出 x 为 10
  ```

+ **JavaScript 数组**

  分步创建：

  ```js
  var cars=new Array();
  cars[0]="Saab";
  cars[1]="Volvo";
  cars[2]="BMW";
  ```

  扼要创建（condensed array）：

  ```js
  var cars=new Array("Saab","Volvo","BMW");
  ```

  文本创建（literal array）：

  ```js
  var cars=["Saab","Volvo","BMW"];
  ```

+ JavaScript 对象

  声明：

  ```js
  var person={firstname:"John", lastname:"Doe", id:5566};
  ```

  寻址方式有二：

  ```js
  name=person.lastname;
  name=person["lastname"];
  ```

+ 声明变量类型

  声明变量时，可以使用关键词 "new" 来声明其类型：

  ```js
  var carname=new String;
  var x=      new Number;
  var y=      new Boolean;
  var cars=   new Array;
  var person= new Object;
  ```

  实际上，JavaScript的所有变量都是对象。具体的数据类型是对象的具体实现。