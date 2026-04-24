#include <iostream>
#include <iomanip>

int main() {
    std::cout << "======================================\n";
    std::cout << "    Xiangsen's Modern C++ Utility     \n";
    std::cout << "        BMI Calculator Module         \n";
    std::cout << "======================================\n\n";

    double weight_kg = 75.0; 
    double height_m = 1.80;  

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

    return 0;
}