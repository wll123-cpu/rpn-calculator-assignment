#!/bin/bash

echo "=== RPN计算器编译脚本 ==="
echo "编译C++程序..."

# 编译C++程序
g++ -std=c++11 rpn_calc.cpp -o rpn_calc -lm

if [ $? -eq 0 ]; then
    echo "✓ 编译成功！"
    echo "可执行文件: ./rpn_calc"
    echo ""
    echo "运行计算器..."
    echo "==============================="
    ./rpn_calc
else
    echo "✗ 编译失败！"
    echo "请检查代码错误"
    exit 1
fi
