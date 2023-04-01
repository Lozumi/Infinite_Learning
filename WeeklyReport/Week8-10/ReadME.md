# 三、CSS基础

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


# 四、JavaScript基础

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

+ ## 重新定义变量

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

  

