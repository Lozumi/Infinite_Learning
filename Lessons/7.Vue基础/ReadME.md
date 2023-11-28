Vue学习笔记

# 一、创建应用

## 应用实例

每个 Vue 应用都是通过 [`createApp`](https://cn.vuejs.org/api/application.html#createapp) 函数创建一个新的 **应用实例**：

```js
import { createApp } from 'vue'

const app = createApp({
  /* 根组件选项 */
})
```

## 根组件

我们传入 `createApp` 的对象实际上是一个组件，每个应用都需要一个“根组件”，其他组件将作为其子组件。

如果你使用的是单文件组件，我们可以直接从另一个文件中导入根组件。

```js
import { createApp } from 'vue'
// 从一个单文件组件中导入根组件
import App from './App.vue'

const app = createApp(App)
```

## 挂载应用

应用实例必须在调用了 `.mount()` 方法后才会渲染出来。该方法接收一个“容器”参数，可以是一个实际的 DOM 元素或是一个 CSS 选择器字符串：

```html
<div id="app"></div>
```

```js
app.mount('#app')
```

应用根组件的内容将会被渲染在容器元素里面。容器元素自己将**不会**被视为应用的一部分。

`.mount()` 方法应该始终在整个应用配置和资源注册完成后被调用。同时请注意，不同于其他资源注册方法，它的返回值是**根组件实例**而非应用实例。

## 应用配置

应用实例会暴露一个 `.config` 对象允许我们配置一些应用级的选项，例如定义一个应用级的错误处理器，用来捕获所有子组件上的错误：

```js
app.config.errorHandler = (err) => {
  /* 处理错误 */
}
```

应用实例还提供了一些方法来注册应用范围内可用的资源，例如注册一个组件：

```js
app.component('TodoDeleteButton', TodoDeleteButton)
```

# 二、模板语法

Vue 使用一种基于 HTML 的模板语法，使我们能够声明式地将其组件实例的数据绑定到呈现的 DOM 上。所有的 Vue 模板都是语法层面合法的 HTML，可以被符合规范的浏览器和 HTML 解析器解析。

在底层机制中，Vue 会将模板编译成高度优化的 JavaScript 代码。结合响应式系统，当应用状态变更时，Vue 能够智能地推导出需要重新渲染的组件的最少数量，并应用最少的 DOM 操作。

## 文本插值

最基本的数据绑定形式是文本插值，它使用的是“Mustache”语法 (即双大括号)：

```vue
<span>Message: {{ msg }}</span>
```

双大括号标签会被替换为相应组件实例中 `msg` 属性的值。同时每次 `msg` 属性更改时它也会同步更新。

## 原始 HTML

双大括号会将数据解释为纯文本，而不是 HTML。若想插入 HTML，你需要使用 [`v-html` 指令](https://cn.vuejs.org/api/built-in-directives.html#v-html)：

```vue
<p>Using text interpolation: {{ rawHtml }}</p>
<p>Using v-html directive: <span v-html="rawHtml"></span></p>
```

Using text interpolation: <span style="color: red">This should be red.</span>

Using v-html directive: This should be red.

这里我们遇到了一个新的概念。这里看到的 `v-html` attribute 被称为一个**指令**。指令由 `v-` 作为前缀，表明它们是一些由 Vue 提供的特殊 attribute，你可能已经猜到了，它们将为渲染的 DOM 应用特殊的响应式行为。这里我们做的事情简单来说就是：在当前组件实例上，将此元素的 innerHTML 与 `rawHtml` 属性保持同步。`span` 的内容将会被替换为 `rawHtml` 属性的值，插值为纯 HTML——数据绑定将会被忽略。

## Attribute 绑定

双大括号不能在 HTML attributes 中使用。想要响应式地绑定一个 attribute，应该使用 [`v-bind` 指令](https://cn.vuejs.org/api/built-in-directives.html#v-bind)：

```vue
<div v-bind:id="dynamicId"></div>
```

`v-bind` 指令指示 Vue 将元素的 `id` attribute 与组件的 `dynamicId` 属性保持一致。如果绑定的值是 `null` 或者 `undefined`，那么该 attribute 将会从渲染的元素上移除。

因为 `v-bind` 非常常用，我们提供了特定的简写语法：

```vue
<div :id="dynamicId"></div>
```

### 动态绑定多个值

如果你有像这样的一个包含多个 attribute 的 JavaScript 对象：

```js
const objectOfAttrs = {
  id: 'container',
  class: 'wrapper'
}
```

通过不带参数的 `v-bind`，你可以将它们绑定到单个元素上：

```vue
<div v-bind="objectOfAttrs"></div>
```

## 使用 JavaScript 表达式

在 Vue 模板内，JavaScript 表达式可以被使用在如下场景上：

- 在文本插值中 (双大括号)
- 在任何 Vue 指令 (以 `v-` 开头的特殊 attribute) attribute 的值中

每个绑定仅支持**单一表达式**，也就是一段能够被求值的 JavaScript 代码。一个简单的判断方法是是否可以合法地写在 `return` 后面。

### 调用函数

可以在绑定的表达式中使用一个组件暴露的方法：

```vue
<time :title="toTitleDate(date)" :datetime="date">
  {{ formatDate(date) }}
</time>
```

## 指令 Directives

指令是带有 `v-` 前缀的特殊 attribute。Vue 提供了许多[内置指令](https://cn.vuejs.org/api/built-in-directives.html)，包括上面我们所介绍的 `v-bind` 和 `v-html`。

指令 attribute 的期望值为一个 JavaScript 表达式 (除了少数几个例外，即之后要讨论到的 `v-for`、`v-on` 和 `v-slot`)。一个指令的任务是在其表达式的值变化时响应式地更新 DOM。以 [`v-if`](https://cn.vuejs.org/api/built-in-directives.html#v-if) 为例：

```vue
<p v-if="seen">Now you see me</p>
```

### 参数 Arguments

某些指令会需要一个“参数”，在指令名后通过一个冒号隔开做标识。

```vue
//用 v-bind 指令来响应式地更新一个 HTML attribute
<a v-bind:href="url"> ... </a>

<!-- 简写 -->
<a :href="url"> ... </a>

//监听 DOM 事件
<a v-on:click="doSomething"> ... </a>

<!-- 简写 -->
<a @click="doSomething"> ... </a>
```

### 动态参数

同样在指令参数上也可以使用一个 JavaScript 表达式，需要包含在一对方括号内：

```vue
<a v-bind:[attributeName]="url"> ... </a>

<!-- 简写 -->
<a :[attributeName]="url"> ... </a>
```

相似地，你还可以将一个函数绑定到动态的事件名称上。

动态参数中表达式的值应当是一个**字符串**，或者是 `null`。特殊值 `null` 意为显式移除该绑定。其他非字符串的值会触发警告。

#### 动态参数语法的限制

动态参数表达式因为某些字符的缘故有一些语法限制，比如空格和引号，在 HTML attribute 名称中都是不合法的。例如下面的示例：

```vue
<!-- 这会触发一个编译器警告 -->
<a :['foo' + bar]="value"> ... </a>
```

如果你需要传入一个复杂的动态参数，我们推荐使用[计算属性](https://cn.vuejs.org/guide/essentials/computed.html)替换复杂的表达式，也是 Vue 最基础的概念之一，我们很快就会讲到。

当使用 DOM 内嵌模板 (直接写在 HTML 文件里的模板) 时，我们需要避免在名称中使用大写字母，因为浏览器会强制将其转换为小写：

```vue
<a :[someAttr]="value"> ... </a>
```

上面的例子将会在 DOM 内嵌模板中被转换为 `:[someattr]`。如果你的组件拥有 “someAttr” 属性而非 “someattr”，这段代码将不会工作。单文件组件内的模板**不**受此限制。

最后是完整语法结构。

![vue1](./vue1.png)

# 三、响应式基础

## 声明响应式状态

### `ref()`

在组合式 API 中，推荐使用 [`ref()`](https://cn.vuejs.org/api/reactivity-core.html#ref) 函数来声明响应式状态：

```js
import { ref } from 'vue'

const count = ref(0)
```

`ref()` 接收参数，并将其包裹在一个带有 `.value` 属性的 ref 对象中返回：

```js
const count = ref(0)

console.log(count) // { value: 0 }
console.log(count.value) // 0

count.value++
console.log(count.value) // 1
```

> 参考：[为 refs 标注类型](https://cn.vuejs.org/guide/typescript/composition-api.html#typing-ref) 

要在组件模板中访问 ref，请从组件的 `setup()` 函数中声明并返回它们：

```js
import { ref } from 'vue'

export default {
  // `setup` 是一个特殊的钩子，专门用于组合式 API。
  setup() {
    const count = ref(0)

    // 将 ref 暴露给模板
    return {
      count
    }
  }
}
```

```vue
<div>{{ count }}</div>
```

注意，在模板中使用 ref 时，我们**不**需要附加 `.value`。为了方便起见，当在模板中使用时，ref 会自动解包 (有一些[注意事项](https://cn.vuejs.org/guide/essentials/reactivity-fundamentals.html#caveat-when-unwrapping-in-templates))。

你也可以直接在事件监听器中改变一个 ref：

```vue
<button @click="count++">
  {{ count }}
</button>
```

### `<script setup>`

在 `setup()` 函数中手动暴露大量的状态和方法非常繁琐。幸运的是，我们可以通过使用[单文件组件 (SFC)](https://cn.vuejs.org/guide/scaling-up/sfc.html) 来避免这种情况。我们可以使用 `<script setup>` 来大幅度地简化代码：

```vue
<script setup>
import { ref } from 'vue'

const count = ref(0)

function increment() {
  count.value++
}
</script>

<template>
  <button @click="increment">
    {{ count }}
  </button>
</template>
```

`<script setup>`中的顶层的导入、声明的变量和函数可在同一组件的模板中直接使用。你可以理解为模板是在同一作用域内声明的一个 JavaScript 函数——它自然可以访问与它一起声明的所有内容。

### 深层响应性

Ref 可以持有任何类型的值，包括深层嵌套的对象、数组或者 JavaScript 内置的数据结构，比如 `Map`。

Ref 会使它的值具有深层响应性。这意味着即使改变嵌套对象或数组时，变化也会被检测到：

```js
import { ref } from 'vue'

const obj = ref({
  nested: { count: 0 },
  arr: ['foo', 'bar']
})

function mutateDeeply() {
  // 以下都会按照期望工作
  obj.value.nested.count++
  obj.value.arr.push('baz')
}
```

非原始值将通过 [`reactive()`](https://cn.vuejs.org/guide/essentials/reactivity-fundamentals.html#reactive) 转换为响应式代理，该函数将在后面讨论。

也可以通过 [shallow ref](https://cn.vuejs.org/api/reactivity-advanced.html#shallowref) 来放弃深层响应性。对于浅层 ref，只有 `.value` 的访问会被追踪。浅层 ref 可以用于避免对大型数据的响应性开销来优化性能、或者有外部库管理其内部状态的情况。

### DOM 更新时机

当你修改了响应式状态时，DOM 会被自动更新。但是需要注意的是，DOM 更新不是同步的。Vue 会在“next tick”更新周期中缓冲所有状态的修改，以确保不管你进行了多少次状态修改，每个组件都只会被更新一次。

要等待 DOM 更新完成后再执行额外的代码，可以使用 [nextTick()](https://cn.vuejs.org/api/general.html#nexttick) 全局 API：

```js
import { nextTick } from 'vue'

async function increment() {
  count.value++
  await nextTick()
  // 现在 DOM 已经更新了
}
```

## `reactive()`

还有另一种声明响应式状态的方式，即使用 `reactive()` API。与将内部值包装在特殊对象中的 ref 不同，`reactive()` 将使对象本身具有响应性：

```js
import { reactive } from 'vue'

const state = reactive({ count: 0 })
```

> 参考：[为 `reactive()` 标注类型](https://cn.vuejs.org/guide/typescript/composition-api.html#typing-reactive) 

在模板中使用：

```vue
<button @click="state.count++">
  {{ state.count }}
</button>
```

响应式对象是 [JavaScript 代理](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Proxy)，其行为就和普通对象一样。不同的是，Vue 能够拦截对响应式对象所有属性的访问和修改，以便进行依赖追踪和触发更新。

`reactive()` 将深层地转换对象：当访问嵌套对象时，它们也会被 `reactive()` 包装。当 ref 的值是一个对象时，`ref()` 也会在内部调用它。与浅层 ref 类似，这里也有一个 [`shallowReactive()`](https://cn.vuejs.org/api/reactivity-advanced.html#shallowreactive) API 可以选择退出深层响应性。

### `reactive()` 的局限性

`reactive()` API 有一些局限性：

1. **有限的值类型**：它只能用于对象类型 (对象、数组和如 `Map`、`Set` 这样的[集合类型](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects#keyed_collections))。它不能持有如 `string`、`number` 或 `boolean` 这样的[原始类型](https://developer.mozilla.org/en-US/docs/Glossary/Primitive)。

2. **不能替换整个对象**：由于 Vue 的响应式跟踪是通过属性访问实现的，因此我们必须始终保持对响应式对象的相同引用。这意味着我们不能轻易地“替换”响应式对象，因为这样的话与第一个引用的响应性连接将丢失：

   js

   ```
   let state = reactive({ count: 0 })
   
   // 上面的 ({ count: 0 }) 引用将不再被追踪
   // (响应性连接已丢失！)
   state = reactive({ count: 1 })
   ```

3. **对解构操作不友好**：当我们将响应式对象的原始类型属性解构为本地变量时，或者将该属性传递给函数时，我们将丢失响应性连接：

   js

   ```
   const state = reactive({ count: 0 })
   
   // 当解构时，count 已经与 state.count 断开连接
   let { count } = state
   // 不会影响原始的 state
   count++
   
   // 该函数接收到的是一个普通的数字
   // 并且无法追踪 state.count 的变化
   // 我们必须传入整个对象以保持响应性
   callSomeFunction(state.count)
   ```

由于这些限制，我们建议使用 `ref()` 作为声明响应式状态的主要 API。