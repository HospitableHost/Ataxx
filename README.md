# Ataxx （基于α-β剪枝算法的同化棋AI）
- 同化棋.exe为可执行文件，可以在windows系统下直接运行，没有内存泄漏问题！建议可以玩一下~
- 同化棋中静态估计函数的两个参数*percent*和*k*是两个预定义的值`#define PERCENTCAN 0.5`和`#define KCAN 0.1`，修改*0.5*和*0.1*的值即可修改这两个参数
- 同化棋中α-β剪枝算法的最大深度是一个预定义`#define MaxDeep 3`,修改*3*这个值就可以改变α-β剪枝算法的最大深度
- 通用α-β剪枝算法流程如图所示：（Ziqiang Dang Designed in 2019.12）

![通用α-β剪枝算法流程图](https://github.com/HospitableHost/Ataxx/blob/main/%E9%80%9A%E7%94%A8%CE%B1-%CE%B2%E5%89%AA%E6%9E%9D%E7%AE%97%E6%B3%95%E6%B5%81%E7%A8%8B%E5%9B%BE.jpg)
