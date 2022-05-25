# echo_server
第一个手写的http服务器-socket编程与网络通信

echo_server.c文件是模拟服务器
echo_client.c文件是模拟客户端
两个文件下载至linux服务器上，分别编译一下即可运行成功.

操作步骤：
1. gcc echo_server.c -o echo_server  # 编译服务器文件;
2. gcc echo_client.c -o echo_client  # 编译客户端文件;
3. ./echo.server  # 启动服务器进程，等待客户端的连接;
4. ./echo.client  # 启动客户端进行开始连接客户端进行交互.
