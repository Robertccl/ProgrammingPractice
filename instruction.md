#涉及简单重要知识说明
1. Linux提供两种信号量：
（1） 内核信号量，由内核控制路径使用
（2） 用户态进程使用的信号量，这种信号量又分为POSIX信号量和SYSTEM V信号量。
  POSIX信号量又分为有名信号量和无名信号量。
  有名信号量，其值保存在文件中, 所以它可以用于线程也可以用于进程间的同步。
  无名信号量，其值保存在内存中。
  参考网址：http://blog.csdn.net/qinxiongxu/article/details/7830537   http://www.ibm.com/developerworks/cn/linux/l-ipc/
