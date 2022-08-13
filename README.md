# AlgrithmClass
包含“并查集”，“最短路”等算法的模板类，可以应付LeetCode的板子题目，也可以作为算法学习的参考代码。

## 现包含以下内容：
- 1 UnionFind 并查集类

``` C++

UnionFind(int n) //构造函数，共有n个对象可能需要合并
Unity(int x,int y) //合并索引为x和y的对象
Count() //查看当前剩余组数
Same(int x, int y) // 查看索引为x和y的对象是否在同一组

```

- 2 BOM_UnionFind 基于std::unordered_map的并查集

``` C++
BOM_UnoinFind() //构造函数，每个严格不相等的对象被认为初始属于不同的集合
Unity(T x, T y) //合并值为x和y的对象到一个集合
Count() //查看当前的集合数
Same(T x, T y) // 查看x和y是否在同一组

```

### 持续更新中……
