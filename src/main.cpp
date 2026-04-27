#include <iostream>
#include <iomanip>
#include <string>
#include "bmi.hpp" // 引入我们刚才写的模块

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "[Error]: Invalid number of arguments.\n";
        std::cerr << "Usage: " << argv[0] << " <weight_kg> <height_m>\n";
        return 1; 
    }

    try {
        double weight_kg = std::stod(argv[1]);
        double height_m = std::stod(argv[2]);

        // 调用解耦后的外部函数
        double bmi = calculateBMI(weight_kg, height_m);

        std::cout << "Weight Input: " << weight_kg << " kg\n";
        std::cout << "Height Input: " << height_m << " m\n";
        std::cout << "Calculated BMI: " << std::fixed << std::setprecision(2) << bmi << "\n\n";

        if (bmi < 18.5) {
            std::cout << "=> Status: Underweight. Eat more Brezeln!\n";
        } else if (bmi >= 18.5 && bmi < 24.9) {
            std::cout << "=> Status: Normal. Perfect geometry!\n";
        } else {
            std::cout << "=> Status: Overweight. Time for the gym!\n";
        }

    } catch (const std::invalid_argument& e) {
        std::cerr << "[Error]: " << e.what() << "\n";
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "[Error]: Invalid input type. Please enter numeric values.\n";
        return 1;
    }

    return 0;
}
