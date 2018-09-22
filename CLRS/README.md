# 一些bugs

## kmp,不同数值类型的比较

在kmp.cpp中的循环，循环判断下标（int类型）与std::string::size_type类型比较发生了循环只执行一部分的问题。

```c++
int i = j = 0
while (i < s.size() && j < p.size())
{
// some codes may make j -1;
}
```

在这段代码当中，出现了j < p.size()但是却不运行循环的情况。原因是当j为-1的时候，```j > p.size()```, 因为```unsigned/signed```类型。

```C++
string s = "ababababababababababababababababababcaHello world!";
int i = -1;
cout << "i < s.size():" << (i < s.size()) << endl;
size_t ui = i;
cout << "ui:" << ui << endl;
cout << "ui == i:" << (ui == i) << endl;
/* ouputs:
i < s.size():0
ui:18446744073709551615
ui == i:1
*/
```

```string::size()```类型是无符号类型。所以使用关系运算符会出现问题。但是继续观察剩下部分demo，发现```ui==i```为```true```，而且```ui```的字节随着32/64位机器改变，底层的比较依旧为```true```，这是一个feature。应该设计机组的底层实现的知识。负数的二进制表达。

查看《计算机组成与设计：硬件/软件接口（亚洲版）》2.4 signed and unsigned numbers部分知识得到：
Negating this number by inverting the bits and adding one.

所以-1对于```int32```为：00000...001 -> 111...1110, + 1, 11111...111，32个1。对于size_t ui = 18446744073709551615 为2 ^ 64 - 1， 也就是111111...1111， 64个1，所以他们X相等。

```C++
unsigned long ul = 0xFFFFFFFFFFFFFFFF; // 16个F， 16^16-1
int si = -1;
cout << ul << endl;
cout << "si==ul:" << (ul == si) << endl;
/*
18446744073709551615
si==ul:1
*/
```
可以看出，应该是从右边开始进行逻辑与比较，大小为小的一方。