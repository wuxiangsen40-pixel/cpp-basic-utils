#include <gtest/gtest.h>
#include "bmi.hpp" // 引入你的核心业务模块

// 1. 测试正常输入 (期望结果和实际计算结果的误差在 0.01 以内)
TEST(BMICalculatorTest, NormalValues) {
    EXPECT_NEAR(calculateBMI(75.0, 1.80), 23.148, 0.01);
    EXPECT_NEAR(calculateBMI(67.0, 1.76), 21.63, 0.01); // 你的完美身材数据！
}

// 2. 测试边界情况：非法输入是否能成功触发系统的自我保护 (抛出异常)
TEST(BMICalculatorTest, InvalidValuesThrowException) {
    // 预期：如果输入负体重，程序必须抛出 invalid_argument 异常
    EXPECT_THROW(calculateBMI(-10.0, 1.80), std::invalid_argument);
    // 预期：如果身高是 0（分母为0），程序必须抛出异常阻止崩溃
    EXPECT_THROW(calculateBMI(75.0, 0.0), std::invalid_argument); 
}
