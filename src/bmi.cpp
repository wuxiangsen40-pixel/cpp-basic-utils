#include "bmi.hpp"
#include <stdexcept>

double calculateBMI(double weight_kg, double height_m) {
    // 核心业务防御：任何不合法的物理数据直接抛出异常
    if (weight_kg <= 0 || height_m <= 0) {
        throw std::invalid_argument("Weight and height must be strictly positive.");
    }
    return weight_kg / (height_m * height_m);
}
