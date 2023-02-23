受到NOJ T033的启发，题目如下。



## 1 取模、取余

num%2——取出二进制的最后一位

num/2——右移去掉二进制的最后一位

## 2 移位求与

```c++
function valueAtBit2(num, bit) {
    return (num >> (bit -1)) & 1;
}
```

## 3 按位求与

比如说16位二进制数A：1000 1000 1000 1000，我想获得A的第三位，就把B的第三位数字设置为1，则B为0000 0000 0000 0100，之后A、B求与，结果若为0，说明A的第三位为0，结果为1，说明A的第三位为1。

```cpp
function valueAtBit3(num,bit){
    return num & (1<<(bit-1));
}
```

