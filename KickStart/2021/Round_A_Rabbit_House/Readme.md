### Rabbit_House

本题的思路类似于```LeetCode 135. Candy```，做two pass的贪心。

第一遍pass，我们让每个格子做调整，使得其相比于它的左边和上边，“不会矮太多”。具体的说，我们先按照顺序逐行逐列处理。假设某个格子的高度是A，它的左边格子的高度是B，上边格子的高度是C。如果A比max(B,C)还高，那么我们就不需要调整A，因为A并不比左边/上边的矮。如果A比max(B,C)要小，那我们将A调整至max(B,C)-1. 这样做之后，A可能会比一个邻居高，比一个邻居矮，但相较于更高的邻居而言差距只有1，也就是“不会矮太多”。

第二遍pass，我们逆序逐行逐列处理。假设某个格子的高度是A，它的右边格子的高度是B，下边格子的高度是C。如果A比max(B,C)还高，那么我们就不需要调整A，因为A并不比左边/上边的矮。如果A比max(B,C)要小，那我们将A调整至max(B,C)-1. 这样做之后，A可能会比一个邻居高，比一个邻居矮，但相较于更高的邻居而言差距只有1，也就是“不会矮太多”。

这两边处理后，任何一个格子都不会比起邻居“矮”多余一个单位。那就符合了题意。