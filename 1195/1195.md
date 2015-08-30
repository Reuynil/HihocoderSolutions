hihocoder提供的伪代码是有问题的。例如如下数据：

```
2 2
0 0 0
0 0 1
```

应该是无解，但按照伪代码提供的算法，是有无穷多个解。1195.cpp.bak的代码解决了这个问题。

```
// 处理出上三角矩阵
For i = 1..N
    Flag ← False
    For j = i..M                // 从第i行开始，找到第i列不等于0的行j
        If a[j][i] != 0 Then
            Swap(j, i)          // 交换第i行和第j行
            Flag ← True
            Break
        End If
    End For
    // 若无法找到，则存在多个解，这一步有问题。
    If (not Flag) Then
        return "Many solutions"
    End If
    // 消除第i+1行到第M行的第i列
    For j = i+1 .. M
        a[j][] ← a[j][] - a[i][] * (a[j][i] / a[i][i])
        b[j] ← b[j] - b[i] * (a[j][i] / a[i][i])
    End For
End For 

// 检查是否无解，即存在 0 = x 的情况
For i = 1..M
    If (第i行系数均为0 and (b[i] != 0)) Then
        return "No solutions"
    End If
End For
```