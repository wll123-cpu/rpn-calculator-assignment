#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <stdexcept>
#include <stack>
#include <map>
#include <functional>

class RPNCalculator {
private:
    std::vector<double> stack;
    std::vector<std::string> history;

    bool isOperator(const std::string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/" || 
               token == "sqrt" || token == "^" || token == "fib" || token == "pascal" ||
               token == "sin" || token == "cos" || token == "tan";
    }

    bool isNumber(const std::string& token) {
        std::istringstream iss(token);
        double d;
        iss >> d;
        return !iss.fail() && iss.eof();
    }

    double fibonacci(int n) {
        if (n < 0) throw std::invalid_argument("Fibonacci input must be non-negative");
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        double a = 0, b = 1;
        for (int i = 2; i <= n; i++) {
            double temp = b;
            b = a + b;
            a = temp;
        }
        return b;
    }

    double pascalTriangle(int n) {
        if (n < 0) throw std::invalid_argument("Pascal triangle row must be non-negative");
        std::vector<double> row = {1};
        for (int i = 1; i <= n; i++) {
            std::vector<double> newRow(i + 1, 1);
            for (int j = 1; j < i; j++) {
                newRow[j] = row[j - 1] + row[j];
            }
            row = newRow;
        }
        // Return the sum of the row
        double sum = 0;
        for (double num : row) {
            sum += num;
        }
        return sum;
    }

public:
    void push(double value) {
        stack.push_back(value);
    }

    double pop() {
        if (stack.empty()) {
            throw std::runtime_error("Error: Stack is empty");
        }
        double value = stack.back();
        stack.pop_back();
        return value;
    }

    void clear() {
        stack.clear();
    }

    void displayStack() {
        std::cout << "Stack: ";
        if (stack.empty()) {
            std::cout << "empty";
        } else {
            for (size_t i = 0; i < stack.size(); i++) {
                std::cout << stack[i];
                if (i < stack.size() - 1) {
                    std::cout << " ";
                }
            }
        }
        std::cout << std::endl;
    }

    void calculate(const std::string& operation) {
        if (operation == "clear") {
            clear();
            return;
        }
        if (operation == "show") {
            displayStack();
            return;
        }

        std::istringstream iss(operation);
        std::string token;
        
        while (iss >> token) {
            if (isNumber(token)) {
                push(std::stod(token));
            } else if (isOperator(token)) {
                if (token == "+") {
                    if (stack.size() < 2) throw std::runtime_error("Error: Not enough operands for +");
                    double b = pop();
                    double a = pop();
                    push(a + b);
                } else if (token == "-") {
                    if (stack.size() < 2) throw std::runtime_error("Error: Not enough operands for -");
                    double b = pop();
                    double a = pop();
                    push(a - b);
                } else if (token == "*") {
                    if (stack.size() < 2) throw std::runtime_error("Error: Not enough operands for *");
                    double b = pop();
                    double a = pop();
                    push(a * b);
                } else if (token == "/") {
                    if (stack.size() < 2) throw std::runtime_error("Error: Not enough operands for /");
                    double b = pop();
                    if (b == 0) throw std::runtime_error("Error: Division by zero");
                    double a = pop();
                    push(a / b);
                } else if (token == "sqrt") {
                    if (stack.empty()) throw std::runtime_error("Error: Not enough operands for sqrt");
                    double a = pop();
                    if (a < 0) throw std::runtime_error("Error: Square root of negative number");
                    push(std::sqrt(a));
                } else if (token == "^") {
                    if (stack.size() < 2) throw std::runtime_error("Error: Not enough operands for ^");
                    double b = pop();
                    double a = pop();
                    push(std::pow(a, b));
                } else if (token == "fib") {
                    if (stack.empty()) throw std::runtime_error("Error: Not enough operands for fib");
                    double n = pop();
                    if (n != static_cast<int>(n) || n < 0) {
                        throw std::runtime_error("Error: Fibonacci requires non-negative integer");
                    }
                    push(fibonacci(static_cast<int>(n)));
                } else if (token == "pascal") {
                    if (stack.empty()) throw std::runtime_error("Error: Not enough operands for pascal");
                    double n = pop();
                    if (n != static_cast<int>(n) || n < 0) {
                        throw std::runtime_error("Error: Pascal triangle requires non-negative integer");
                    }
                    push(pascalTriangle(static_cast<int>(n)));
                } else if (token == "sin") {
                    if (stack.empty()) throw std::runtime_error("Error: Not enough operands for sin");
                    double a = pop();
                    push(std::sin(a * M_PI / 180.0)); // 转换为弧度
                } else if (token == "cos") {
                    if (stack.empty()) throw std::runtime_error("Error: Not enough operands for cos");
                    double a = pop();
                    push(std::cos(a * M_PI / 180.0));
                } else if (token == "tan") {
                    if (stack.empty()) throw std::runtime_error("Error: Not enough operands for tan");
                    double a = pop();
                    push(std::tan(a * M_PI / 180.0));
                }
            } else {
                throw std::runtime_error("Error: Invalid token '" + token + "'");
            }
        }
        
        history.push_back(operation);
    }

    double getResult() {
        if (stack.empty()) {
            throw std::runtime_error("Error: No result available");
        }
        return stack.back();
    }

    void showHistory() {
        std::cout << "Calculation History:" << std::endl;
        if (history.empty()) {
            std::cout << "No history available" << std::endl;
        } else {
            for (size_t i = 0; i < history.size(); i++) {
                std::cout << i + 1 << ": " << history[i] << std::endl;
            }
        }
    }

    bool hasResult() {
        return !stack.empty();
    }
};

void printHelp() {
    std::cout << "=== RPN Calculator Commands ===" << std::endl;
    std::cout << "数字: 将数字压入栈 (例: 5, 3.14)" << std::endl;
    std::cout << "+ : 加法" << std::endl;
    std::cout << "- : 减法" << std::endl;
    std::cout << "* : 乘法" << std::endl;
    std::cout << "/ : 除法" << std::endl;
    std::cout << "sqrt : 平方根" << std::endl;
    std::cout << "^ : 幂运算" << std::endl;
    std::cout << "fib : 斐波那契数列 (输入n, 输出F(n))" << std::endl;
    std::cout << "pascal : 杨辉三角第n行和" << std::endl;
    std::cout << "sin/cos/tan : 三角函数 (角度制)" << std::endl;
    std::cout << "show : 显示当前栈" << std::endl;
    std::cout << "clear : 清空栈" << std::endl;
    std::cout << "history : 显示计算历史" << std::endl;
    std::cout << "help : 显示帮助" << std::endl;
    std::cout << "q : 退出程序" << std::endl;
    std::cout << "===============================" << std::endl;
}

int main() {
    RPNCalculator calc;
    std::string input;
    
    std::cout << "C++ RPN 计算器" << std::endl;
    std::cout << "输入表达式 (例: '5 5 +'), 或 'help' 查看帮助, 'q' 退出." << std::endl;
    
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);
        
        if (input == "q" || input == "quit") {
            std::cout << "再见!" << std::endl;
            break;
        } else if (input == "help") {
            printHelp();
        } else if (input == "history") {
            calc.showHistory();
        } else if (input.empty()) {
            continue;
        } else {
            try {
                calc.calculate(input);
                if (calc.hasResult()) {
                    std::cout << "结果: " << calc.getResult() << std::endl;
                }
            } catch (const std::exception& e) {
                std::cout << e.what() << std::endl;
            }
        }
    }
    
    return 0;
}
