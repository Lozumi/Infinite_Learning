

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

### 1.概述

CSS即**C**ascading **S**tyle **S**heets，层叠样式表。

### 2.选择器字符串

在CSS（层叠样式表）中，选择器字符串是用来选择页面中要应用样式的HTML元素的字符串。选择器字符串描述了样式应该应用到哪些元素上。以下是一些常见的CSS选择器示例：

1. **元素选择器：**
   - `p`：选择所有 `<p>` 元素。
2. **类选择器：**
   - `.classname`：选择所有具有特定类名的元素，例如 `.header` 选择所有具有 `header` 类的元素。
3. **ID选择器：**
   - `#id`：选择具有特定ID的元素，例如 `#navbar` 选择ID为 `navbar` 的元素。
4. **通用选择器：**
   - `*`：选择所有元素。
5. **后代选择器：**
   - `ancestor descendant`：选择某个祖先元素内的所有后代元素，例如 `ul li` 选择所有在 `<ul>` 元素内的 `<li>` 元素。
6. **子元素选择器：**
   - `parent > child`：选择某个父元素下的直接子元素，例如 `ul > li` 选择所有直接在 `<ul>` 元素内的 `<li>` 元素。
7. **属性选择器：**
   - `[attribute=value]`：选择具有特定属性值的元素，例如 `[type="text"]` 选择所有 `type` 属性为 `text` 的元素。
8. **伪类选择器：**
   - `:hover`：选择被用户悬停的元素。
   - `:nth-child(n)`：选择父元素的第n个子元素。

这只是一小部分常见的CSS选择器。CSS选择器允许你根据各种条件选择和样式化文档中的元素。这些选择器可以单独使用，也可以组合使用以实现更复杂的选择逻辑。

+ 示例1

  ```css
  #para1
  {
      text-align:center;
      color:red;
  }
  ```

+ 示例2

  ```css
  #para1
  {
      text-align:center;
      color:red;
  }
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