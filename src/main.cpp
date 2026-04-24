#include <iostream>
#include <iomanip>
#include <string>

// argc: 参数的数量 (Argument Count)
// argv: 参数的数组 (Argument Vector)
int main(int argc, char* argv[]) {
    std::cout << "======================================\n";
    std::cout << "    Xiangsen's Modern C++ Utility     \n";
    std::cout << "        BMI Calculator Module         \n";
    std::cout << "======================================\n\n";

    // 1. 健壮性检查：确保用户输入了两个参数
    if (argc != 3) {
        std::cerr << "[Error]: Invalid number of arguments.\n";
        std::cerr << "Usage: " << argv[0] << " <weight_kg> <height_m>\n";
        std::cerr << "Example: " << argv[0] << " 75.0 1.80\n";
        return 1; // 抛出异常状态码 1，流水线如果遇到 1 就会亮红灯报警
    }

    try {
        // 2. 将控制台输入的字符串转换为浮点数
        double weight_kg = std::stod(argv[1]);
        double height_m = std::stod(argv[2]);

        // 3. 边界值防御
        if (height_m <= 0 || weight_kg <= 0) {
            std::cerr << "[Error]: Weight and height must be strictly positive.\n";
            return 1;
        }

        // 4. 核心计算
        double bmi = weight_kg / (height_m * height_m);

        std::cout << "Weight Input: " << weight_kg << " kg\n";
        std::cout << "Height Input: " << height_m << " m\n";
        std::cout << "Calculated BMI: " << std::fixed << std::setprecision(2) << bmi << "\n\n";

        std::cout << "[System Analysis Result]:\n";
        if (bmi < 18.5) {
            std::cout << "=> Status: Underweight. Eat more Brezeln!\n";
        } else if (bmi >= 18.5 && bmi < 24.9) {
            std::cout << "=> Status: Normal. Perfect geometry!\n";
        } else {
            std::cout << "=> Status: Overweight. Time for the gym!\n";
        }

    } catch (const std::exception& e) {
        // 捕获用户输入乱码（比如输入了字母）导致的崩溃
        std::cerr << "[Error]: Invalid input type. Please enter numeric values.\n";
        return 1;
    }

    return 0; // 状态码 0 代表完美运行
}