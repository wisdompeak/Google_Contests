### Round_B_Energy Stones

#### 第一问
假设有一堆能量石你必须都吃掉，每个石头吃完的时间都相同（记为S），你会以什么样的顺序去吃？答案是按照decay从快到慢的速率排序。decay快的石头搁置地越久损耗越多，显然不合算，必须优先吃掉。所以我们依此顺序将所有的石头排序，接下来的任务是从里面挑选若干个去吃（言下之意，如果是挑中的石头那么它们的顺序就已经是确定的了）。

从一堆石头里挑选若干个，但时间是有限的，这就是一个背包问题。我们逐个遍历能量石i，考虑它是第几个被吃（或者不吃）以及相应的gain。如果是第k个被吃，那么你的gain就是
```
dp[k] = dp[k-1] + Energy[i] - (k*S-decay[i])
```
其中k的取值可以是0（也就是不吃），1，2，...，直至i（也就是之前的所有能量石都会吃掉）。dp[k]取它们的最大值即可。

注意，```Energy[i] - (k*S-decay[i])```小于零的话，说明吃它的时候能量已经损耗完了，这里需要取零而不是负数。