### Longest_Progression

我们可以先提前计算出所有的countLeft[i]，表示以i为首项往左数，最长的等差数列的长度。注意除了countLeft[0]=1，其余的countLeft[i]最小是2. 同理可以计算出所有的countRight.

我们假设如果可以修改A[i]，那么最多可以产生多长的等差数列。其实有五种情况讨论：
1. 最理想的情况是，通过修改A[i]，能够组成```countLeft[i-1]+1+countRight[i+1]```这么长的数列。这需要的条件是:```A[i+1]-A[i-1] == 2*(A[i-1]-A[i-2]) == 2*(A[i+2]-A[i-1])```.
2. 通过修改A[i]，可以无条件和countLeft[i-1]组成等差数列，即```countLeft[i-1]+1```
3. 通过修改A[i]，可以无条件和countRight[i+1]组成等差数列，即```countLeft[i+1]+1```
4. 某些情况下，A[i]和A[i+1]可以和countLeft[i-1]组成等差数列，即countLeft[i-1]+2。这需要的条件是：```A[i+1]-A[i-1] == 2*(A[i-1]-A[i-2])```.
5. 某些情况下，A[i]和A[i+1]可以和countRight[i+1]组成等差数列，即countRight[i+1]+2。这需要的条件是：```A[i+1]-A[i-1] == 2*(A[i+2]-A[i+1])```.

扫一遍A[i]，即可得到全局的最大值。

