import nimib

nbInit

nbText: """
# RPN 计算器使用说明书

基于逆波兰表示法的命令行计算器 - C++实现

## 概述

这是一个基于逆波兰表示法（RPN）的命令行计算器，使用C++实现，支持基本的四则运算和高级数学功能。
"""

nbText: """
## 安装和编译指南

### 前提条件
- GCC 或 Clang 编译器
- 支持C++11或更高版本
- Nim 语言环境（用于生成本文档）
"""

nbCode:
  # 编译C++程序
  echo "g++ -std=c++11 rpn_calc.cpp -o rpn_calc -lm"
  
  # 运行程序
  echo "./rpn_calc"

nbText: "或者使用提供的编译脚本："

nbCode:
  echo "chmod +x build.sh"
  echo "./build.sh"

nbText: """
## 基本使用示例

### 简单四则运算
"""

nbCode:
  let example1 = "5 5 +"    # 结果: 10
  let example2 = "10 2 *"   # 结果: 20  
  let example3 = "15 3 /"   # 结果: 5

nbText: "### 复杂表达式"

nbCode:
  let complexExample = "1 2 + 3 + 7 7 * +"  # 结果: 55

nbText: "实际运行示例："

nbCode:
  # 模拟计算器输出
  echo "输入: 5 5 +"
  echo "输出: 10"
  echo "输入: 10 2 *" 
  echo "输出: 20"
  echo "输入: 1 2 + 3 + 7 7 * +"
  echo "输出: 55"

nbText: """
## 所有支持的操作说明

### 基本运算
"""

nbCode:
  let operations = [
    ("+", "加法 (a + b)"),
    ("-", "减法 (a - b)"), 
    ("*", "乘法 (a * b)"),
    ("/", "除法 (a / b)")
  ]

  for op, desc in operations:
    echo &"{op}: {desc}"

nbText: "### 高级数学运算"

nbCode:
  let advancedOps = [
    ("sqrt", "平方根 (√a)"),
    ("^", "幂运算 (a^b)"),
    ("fib", "斐波那契数列 (输入n, 输出F(n))"),
    ("pascal", "杨辉三角第n行和"),
    ("sin/cos/tan", "三角函数 (角度制)")
  ]

  for op, desc in advancedOps:
    echo &"{op}: {desc}"

nbText: "### 栈操作命令"

nbCode:
  let stackCommands = [
    ("show", "显示当前栈内容"),
    ("clear", "清空栈"),
    ("history", "显示计算历史"), 
    ("help", "显示帮助信息"),
    ("q", "退出程序")
  ]

  for cmd, desc in stackCommands:
    echo &"{cmd}: {desc}"

nbText: """
## 错误代码和异常说明

### 常见错误类型
"""

nbCode:
  let errorExamples = [
    ("+", "Error: Not enough operands for +"),
    ("5 0 /", "Error: Division by zero"),
    ("5 abc +", "Error: Invalid token 'abc'"), 
    ("-4 sqrt", "Error: Square root of negative number")
  ]

  for input, error in errorExamples:
    echo &"输入: {input}"
    echo &"错误: {error}"
    echo "---"

nbText: """
## 示例输入输出

### 基础运算示例
"""

nbCode:
  let examples = [
    ("2 3 +", 5),
    ("10 5 -", 5),
    ("3 4 *", 12),
    ("15 3 /", 5),
    ("9 sqrt", 3),
    ("2 3 ^", 8)
  ]

  echo "输入 -> 输出"
  echo "------------"
  for input, expected in examples:
    echo &"{input} -> {expected}"

nbText: "### 完整会话示例"

nbCode:
  echo "=== RPN计算器会话 ==="
  echo "输入: 5 5 +"
  echo "栈: [10]"
  echo "输入: 3 *" 
  echo "栈: [30]"
  echo "输入: show"
  echo "当前栈: [30]"
  echo "输入: clear"
  echo "栈已清空"
  echo "输入: 2 3 ^"
  echo "栈: [8]"
  echo "输入: q"
  echo "程序退出"

nbSave
