#介绍
学习了数据结构课程中的一些简单的数据结构之后，用C语言和数据结构中的一些知识实现一个简易的学校的导航系统。
> 基本上的功能如下：

![图片介绍](https://upload-images.jianshu.io/upload_images/2560151-a6128c9fb49273aa.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


1. 数据结构采用图来存储信息，根据百度地图抽象出图的结构使用的是邻接矩阵，利用节点图，直接生成邻接矩阵的图数据结构。
![学校平面图](https://upload-images.jianshu.io/upload_images/2560151-5bb0f175a67a2057.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
![学校结点图](https://upload-images.jianshu.io/upload_images/2560151-83041d3b6d9f0d91.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

2. 校园的地点信息采用文件存储的方式，随时读取。
3. 两点之间的最短路径，采用迪杰斯特拉算法找到最短的路径。
4. 所有路径，采用深度优先的想法，进行递归的遍历寻找两个节点之间的所有通路。
5. 最佳布网方案，采用Prim算法产生最小生成树。
###运行界面如下：
![](https://upload-images.jianshu.io/upload_images/2560151-819a76552cc701b7.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
###文件结构
使用code::blocks编写
|_main.c  main函数的文件
|_fun.c    所有函数的实现
|_fun.h  数据结构的定义以及函数的声明
|_*.txt   地点信息文件

具体算法设计参考我的简书和CSDN博客
> https://www.jianshu.com/p/71353cce90a4
> 