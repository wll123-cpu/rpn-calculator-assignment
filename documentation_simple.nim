import nimib

nbInit
nb.darkMode

nbText: "# RPN 计算器使用说明书"

nbText: """
## 安装和编译指南
编译命令：
"""
nbCode:
  discard "g++ -std=c++11 rpn_calc.cpp -o rpn_calc -lm"

nbText: "## 基本使用示例"
nbCode:
  echo "5 5 +    # 结果: 10"
  echo "10 2 *   # 结果: 20"

nbText: "## 支持的操作"
nbCode:
  echo "+ - * /  # 基本运算"
  echo "sqrt ^   # 高级运算"

nbText: "## 错误处理"
nbCode:
  echo "5 0 /    # Error: Division by zero"

nbSave
