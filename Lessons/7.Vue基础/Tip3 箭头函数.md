## 引入

在表单输入绑定一章中，手动连接值绑定和更改事件监听器采用如下代码：

> <input
>   :value="text"
>   @input="event => text = event.target.value">

其中的`event => text = event.target.value`是一个箭头函数。

## 概念

箭头函数是 ECMAScript 2015（ES6）引入的一种新的函数定义方式，它更为简洁，并且具有一些特殊的行为。以下是箭头函数的基本定义和语法：

### 基本语法：

```javascript
// 无参数的箭头函数
const func1 = () => {
  // 函数体
};

// 单参数的箭头函数
const func2 = (param) => {
  // 函数体
};

// 多参数的箭头函数
const func3 = (param1, param2) => {
  // 函数体
};

// 简化的单参数箭头函数，可以省略括号
const func4 = param => {
  // 函数体
};

// 简化的箭头函数，无参数时也可以省略括号
const func5 = () => {
  // 函数体
};
```

### 特点：

1. **没有自己的 `this` 绑定：** 箭头函数没有自己的 `this` 绑定，而是继承自外部作用域。这意味着箭头函数中的 `this` 指向的是外部函数的 `this`。

2. **更简洁的语法：** 箭头函数的语法更为紧凑，特别适合用于短小的函数定义或作为回调函数。

3. **无法作为构造函数：** 箭头函数不能被用作构造函数，因此不能通过 `new` 关键字来实例化对象。

### 示例：

```javascript
// 传统函数定义
function add(a, b) {
  return a + b;
}

// 箭头函数定义
const addArrow = (a, b) => a + b;

// 使用箭头函数作为回调函数
const numbers = [1, 2, 3];
const squared = numbers.map(num => num * num);

// 使用箭头函数处理异步代码
const fetchData = async () => {
  const response = await fetch('https://api.example.com/data');
  const data = await response.json();
  return data;
};
```

总体而言，箭头函数提供了一种更为简洁和方便的函数定义方式，特别适用于处理短小的函数或在回调函数中使用。

## 解释

在上文例子中，箭头函数是一个匿名函数，用于处理 `input` 事件。具体来说，这个箭头函数的形式是：

```javascript
event => text = event.target.value
```

这里有两个主要部分：

1. `event =>`：箭头函数的声明部分，表示一个接受参数 `event` 的函数。作为单参数箭头函数，省略了参数的括号。

2. `text = event.target.value`：箭头函数的函数体，这是对输入框的 `input` 事件的处理逻辑。它将输入框的当前值（`event.target.value`）赋给 Vue 实例中的 `text` 数据属性。

若使用传统的函数定义方式，上述箭头函数的等效写法可能是：

```javascript
function(event) {
  text = event.target.value;
}
```

箭头函数有一些特殊的行为，其中一个是它没有自己的 `this` 绑定，而是继承自外部作用域。在这个例子中，箭头函数中的 `this` 指向的是外部作用域的 `this`，通常是 Vue 实例。这种特性使得箭头函数在处理 Vue 组件中的事件处理时非常方便。