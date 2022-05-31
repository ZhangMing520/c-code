#!/usr/bin/bash

# 下载 Python2.5包
wget -O Python-2.5.tgz  https://www.python.org/ftp/python/2.5/Python-2.5.tgz
# 解压
tar zxvf Python-2.5.tgz

# 必须是绝对路径
./configure --prefix=/home/zhangming/gitspace/Python-2.5/build
make
make install

# python 交互
build/bin/python