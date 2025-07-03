## 介绍

我认为这个代码能用来测试 CPU 单核性能，亦或者用来证明 CPU 型号对 OI 的影响大不大。

事情的起因是我写了这么一道题：[GCD Extreme (hard)](https://www.luogu.com.cn/problem/SP19985)，看到 20s 的时限想着自己造一组数据看看，然后造了一组 $T = 10000$ 的数据看到跑到猴年马月跑不完，于是又造了一组 $T = 10$，这下总归是能在 25s 内跑完了。

## 用法

以下命令均要在终端执行，无论 Windows 还是 Linux。

用版本大于等于 4 的 g++ 编译：

- 对于 Windows

```
g++ Main.cpp -o Main.exe -std=c++14
```

- 对于 Linux

```
g++ Main.cpp -o Main -std=c++14
```

得到可执行文件 `Main`。

执行它：

- 对于 Windows:

```
Main.exe
```

- 对于 Linux:

```
./Main
```

等待。。。然后你就能在终端看见一个大约 $20$ 的三位小数，这就是执行时间。

## 排行榜

1. Intel i5-12400F : 10.226
1. Intel i3-6100 : 24.040

你可以通过发送 issue 的方式给出你的 CPU 型号和执行时间。建议多执行几次取最小值。