# Test Data

我们用3*4 的map为例

**程序首先输出：**

![image-20220329181131235](C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20220329181131235.png)

```
Make sure that the total number of rooms is more than 3 (x * y >= 3),
Please enter the length and width of the map:
```

**输入**

```
3 4
```

**输出初始地图：**

<img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20220329181222716.png" alt="image-20220329181222716" style="zoom:67%;" />

**程序提示：**

```
Welcome to the lobby.
There are 3 exits: west, east and north.Enter your command: 
```

**假设我们输入**`go north`,

**输出：**

<img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20220329181305941.png" alt="image-20220329181305941" style="zoom:67%;" />

**假设我们输入`go west`**

**输出：**

<img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20220329181414518.png" alt="image-20220329181414518" style="zoom:67%;" />

**假设我们此时输入`go nores`(这是一种错误输入)**

**输出：**

<img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20220329181457875.png" alt="image-20220329181457875" style="zoom:67%;" />

（程序提示你重新输入）

**那我们输入`go north`**

**输出：**

<img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20220329181532808.png" alt="image-20220329181532808" style="zoom:67%;" />

……（n次输入）

**此时我们找到了公主：**

<img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20220329181637410.png" alt="image-20220329181637410" style="zoom:67%;" />

两次输入`go south`之后，回到lobby，游戏成功：

<img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20220329181746353.png" alt="image-20220329181746353" style="zoom:67%;" />