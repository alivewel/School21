#include <gtest/gtest.h>

#include "../s21_SmartCalc_v2/controller/controller.h"
#include "../s21_SmartCalc_v2/model/model.h"

class CalcTest : public ::testing::Test {
 protected:
  void SetUp() override {}
  s21::Controller controller_;
};

TEST_F(CalcTest, test_calculator1) {
  EXPECT_DOUBLE_EQ(controller_.Calculator("(5+5)*(-2)").first, -20);
}

TEST_F(CalcTest, test_calculator2) {
  EXPECT_DOUBLE_EQ(controller_.Calculator("(10+10*2)/(-3)").first, -10);
}

TEST_F(CalcTest, test_calculator3) {
  EXPECT_DOUBLE_EQ(controller_.Calculator("2.0/(3.0+2.0)*5.0").first, 2);
}

TEST_F(CalcTest, test_calculator4) {
  EXPECT_DOUBLE_EQ(controller_.Calculator("10.0+10.0*10.0").first, 110);
}

TEST_F(CalcTest, test_calculator5) {
  EXPECT_DOUBLE_EQ(controller_.Calculator("-5+(-4)*(-2)").first, 3);
}

TEST_F(CalcTest, test_calculator6) {
  EXPECT_DOUBLE_EQ(controller_.Calculator("-5.0mod(-3.0)").first, -2);
}

TEST_F(CalcTest, test_calculator7) {
  EXPECT_DOUBLE_EQ(controller_.Calculator("1.0/2.0*(2.0-1.0)").first, 0.5);
}

TEST_F(CalcTest, test_calculator9) {
  EXPECT_DOUBLE_EQ(
      controller_.Calculator("1.10+2.0+(3.0-5.5)*(1.5 - 6.5)").first, 15.6);
}

TEST_F(CalcTest, test_calculator10) {
  EXPECT_DOUBLE_EQ(controller_.Calculator("6.6-1.1-2.2-3.3-4.4-5.5").first,
                   -9.9);
}

TEST_F(CalcTest, test_calculator11) {
  EXPECT_DOUBLE_EQ(controller_.Calculator("1.1-2.2-3.3-4.4-5.5+6.6").first,
                   -7.70);
}

TEST_F(CalcTest, test_calculator12) {
  EXPECT_DOUBLE_EQ(controller_.Calculator("-1.1*5").first, -5.5);
}

TEST_F(CalcTest, test_calculator13) {
  EXPECT_DOUBLE_EQ(controller_.Calculator("2^2").first, 4);
}

TEST_F(CalcTest, test_calculator14) {
  EXPECT_DOUBLE_EQ(controller_.Calculator("5^3").first, 125);
}

TEST_F(CalcTest, test_calculator16) {
  EXPECT_DOUBLE_EQ(controller_.Calculator("2^2^3").first, 256);
}

TEST_F(CalcTest, test_calculator17) {
  EXPECT_DOUBLE_EQ(controller_.Calculator("-5+3*2^2").first, 7);
}

TEST_F(CalcTest, test_calculator19) {
  EXPECT_DOUBLE_EQ(controller_.Calculator("5mod(-1.5)").first, 0.5);
}

TEST_F(CalcTest, test_calculator20) {
  EXPECT_DOUBLE_EQ(controller_.Calculator("(5mod(-1.5)*4)^2").first, 4);
}

TEST_F(CalcTest, test_calculator21) {
  EXPECT_NEAR(controller_.Calculator("sin(30)").first, -0.988032, 1e-6);
}

TEST_F(CalcTest, test_calculator22) {
  EXPECT_NEAR(controller_.Calculator("sin(45)").first, 0.850904, 1e-6);
}

TEST_F(CalcTest, test_calculator23) {
  EXPECT_NEAR(controller_.Calculator("sin(60)").first, -0.304811, 1e-6);
}

TEST_F(CalcTest, test_calculator24) {
  EXPECT_NEAR(controller_.Calculator("sin(90)").first, 0.893997, 1e-6);
}

TEST_F(CalcTest, test_calculator25) {
  EXPECT_NEAR(controller_.Calculator("sin(120)").first, 0.580611, 1e-6);
}

TEST_F(CalcTest, test_calculator26) {
  EXPECT_NEAR(controller_.Calculator("sin(180)").first, -0.801153, 1e-6);
}

TEST_F(CalcTest, test_calculator27) {
  EXPECT_NEAR(controller_.Calculator("sin(270)").first, -0.176046, 1e-6);
}

TEST_F(CalcTest, test_calculator28) {
  EXPECT_NEAR(controller_.Calculator("sin(360)").first, 0.958916, 1e-6);
}

TEST_F(CalcTest, test_calculator29) {
  EXPECT_NEAR(controller_.Calculator("sin(0)").first, 0, 1e-6);
}

TEST_F(CalcTest, test_calculator30) {
  EXPECT_NEAR(controller_.Calculator("cos(30)").first, 0.154251, 1e-6);
}

TEST_F(CalcTest, test_calculator31) {
  EXPECT_NEAR(controller_.Calculator("cos(45)").first, 0.525322, 1e-6);
}

TEST_F(CalcTest, test_calculator32) {
  EXPECT_NEAR(controller_.Calculator("cos(90)").first, -0.448074, 1e-6);
}

TEST_F(CalcTest, test_calculator33) {
  EXPECT_NEAR(controller_.Calculator("cos(120)").first, 0.814181, 1e-6);
}

TEST_F(CalcTest, test_calculator34) {
  EXPECT_NEAR(controller_.Calculator("cos(180)").first, -0.598460, 1e-6);
}

TEST_F(CalcTest, test_calculator35) {
  EXPECT_NEAR(controller_.Calculator("cos(270)").first, 0.984382, 1e-6);
}

TEST_F(CalcTest, test_calculator36) {
  EXPECT_NEAR(controller_.Calculator("cos(360)").first, -0.283691, 1e-6);
}

TEST_F(CalcTest, test_calculator37) {
  EXPECT_NEAR(controller_.Calculator("cos(0)").first, 1, 1e-6);
}

TEST_F(CalcTest, test_calculator38) {
  EXPECT_NEAR(controller_.Calculator("tan(90)").first, -1.995200, 1e-6);
}

TEST_F(CalcTest, test_calculator40) {
  EXPECT_NEAR(
      controller_.Calculator("(sin(45)+cos(30)+tan(45)+tan(90))*2").first,
      1.25946, 1e-6);
}

TEST_F(CalcTest, test_calculator43) {
  EXPECT_NEAR(controller_.Calculator("asin(0.5)").first, 0.523598, 1e-6);
}

TEST_F(CalcTest, test_calculator44) {
  EXPECT_NEAR(controller_.Calculator("acos(0.5)").first, 1.047198, 1e-6);
}

TEST_F(CalcTest, test_calculator45) {
  EXPECT_NEAR(controller_.Calculator("acos(1)").first, 0, 1e-6);
}

TEST_F(CalcTest, test_calculator46) {
  EXPECT_NEAR(controller_.Calculator("atan(0)").first, 0, 1e-6);
}

TEST_F(CalcTest, test_calculator47) {
  EXPECT_NEAR(controller_.Calculator("atan(1)").first, 0.785398, 1e-6);
}

TEST_F(CalcTest, test_calculator48) {
  EXPECT_NEAR(controller_.Calculator("sqrt(100)/sqrt(25)*sqrt(121)").first, 22,
              1e-6);
}

TEST_F(CalcTest, test_calculator49) {
  EXPECT_NEAR(controller_.Calculator("ln(5)").first, 1.609438, 1e-6);
}

TEST_F(CalcTest, test_calculator50) {
  EXPECT_NEAR(controller_.Calculator("-5.0mod(-3.0)").first, -2, 1e-6);
}

TEST_F(CalcTest, test_calculator52) {
  EXPECT_NEAR(controller_.Calculator("1.0/2.0*(2.0-1.0)").first, 0.5, 1e-6);
}

TEST_F(CalcTest, test_calculator53) {
  EXPECT_NEAR(controller_.Calculator("1.1+2.0+(3.0*4.0)+(5.0+6.8)").first, 26.9,
              1e-6);
}

TEST_F(CalcTest, test_calculator54) {
  EXPECT_NEAR(controller_.Calculator("10^10").first, pow(10, 10), 1e-6);
}

TEST_F(CalcTest, test_calculator55) {
  EXPECT_NEAR(controller_.Calculator("1 - 1").first, 0, 1e-6);
}

TEST_F(CalcTest, test_calculator56) {
  EXPECT_DOUBLE_EQ(
      controller_
          .Calculator("1+2+3+4+5+6+7+8+9+10+100-3-2-10-3*2+12+15+16+17+18/2")
          .first,
      203);
}

TEST_F(CalcTest, test_calculator57) {
  EXPECT_DOUBLE_EQ(controller_
                       .Calculator("1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
                                   "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
                                   "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
                                   "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
                                   "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
                                   "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
                                   "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1")
                       .first,
                   128);
}

TEST_F(CalcTest, test_calculator58) {
  EXPECT_DOUBLE_EQ(controller_
                       .Calculator("1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*"
                                   "1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*"
                                   "1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*"
                                   "1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*"
                                   "1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*"
                                   "1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*"
                                   "1*1*1*1*1*1*1*1*1*1*1*1*1")
                       .first,
                   1);
}

TEST_F(CalcTest, test_calculator60) {
  EXPECT_DOUBLE_EQ(controller_.Calculator("1+1").first, 2);
}

TEST_F(CalcTest, test_calculator61) {
  EXPECT_DOUBLE_EQ(controller_.Calculator("(1+1)").first, 2);
}

TEST_F(CalcTest, test_calculator62) {
  EXPECT_DOUBLE_EQ(controller_.Calculator("(1+1)").first, 2);
}

TEST_F(CalcTest, test_calculator63) {
  EXPECT_DOUBLE_EQ(controller_.Calculator("(1+1)").first, 2);
}

TEST_F(CalcTest, test_calculator64) {
  EXPECT_DOUBLE_EQ(controller_.Calculator("(1+1)").first, 2);
}

TEST_F(CalcTest, test_calculator65) {
  EXPECT_DOUBLE_EQ(controller_.Calculator("((((1)+(1))))").first, 2);
}

TEST_F(CalcTest, test_calculator66) {
  EXPECT_DOUBLE_EQ(controller_.Calculator("(5*9)-(2+(3-(2/1)+35))").first,
                   (5 * 9) - (2 + (3 - (2 / 1) + 35)));
}

TEST_F(CalcTest, test_calculator67) {
  double result = 0.0;
  EXPECT_DOUBLE_EQ(controller_.Calculator("(").first, result);
}

TEST_F(CalcTest, test_calculator68) {
  double result = 0.0;
  EXPECT_DOUBLE_EQ(controller_.Calculator("()").first, result);
}

TEST_F(CalcTest, test_calculator69) {
  double result = 0.0;
  EXPECT_DOUBLE_EQ(controller_.Calculator("1+)3").first, result);
}

TEST_F(CalcTest, test_calculator70) {
  double result = 1.935483;
  EXPECT_NEAR(controller_.Calculator("(18/9.3)").first, result, 1e-6);
}

TEST_F(CalcTest, test_calculator71) {
  double result = 0.0;
  EXPECT_DOUBLE_EQ(controller_.Calculator("(1/+2)").first, result);
}

TEST_F(CalcTest, test_calculator72) {
  double result = 1.2 + 5;
  EXPECT_DOUBLE_EQ(controller_.Calculator("1.2+5").first, result);
}

TEST_F(CalcTest, test_calculator73) {
  double result = 1.2 + 5 + 9 + 6;
  EXPECT_DOUBLE_EQ(controller_.Calculator("1.2+5+9+6").first, result);
}

TEST_F(CalcTest, test_calculator78) {
  double result = 0.0;
  EXPECT_DOUBLE_EQ(controller_.Calculator("1.54837495+1.345213431+(-(5)").first,
                   result);
}

TEST_F(CalcTest, test_calculator80) {
  double result = 0.0;
  EXPECT_DOUBLE_EQ(controller_.Calculator("1-1").first, result);
}

TEST_F(CalcTest, test_calculator81) {
  double result = 1 - 0;
  EXPECT_DOUBLE_EQ(controller_.Calculator("1-0").first, result);
}

TEST_F(CalcTest, test_calculator82) {
  double result = 1 - 0.1;
  EXPECT_DOUBLE_EQ(controller_.Calculator("1-0.1").first, result);
}

TEST_F(CalcTest, test_calculator83) {
  double result = 156156 * 3;
  EXPECT_DOUBLE_EQ(controller_.Calculator("156156*3").first, result);
}

TEST_F(CalcTest, test_calculator84) {
  double result = 156156 * 3 * 3 * 0.1 * 0.1;
  EXPECT_DOUBLE_EQ(controller_.Calculator("156156*3*3*0.1*0.1").first, result);
}

TEST_F(CalcTest, test_calculator85) {
  double result = 0.0;
  EXPECT_DOUBLE_EQ(controller_.Calculator("*156156*3*3*0.1*0.1").first, result);
}

TEST_F(CalcTest, test_calculator86) {
  double result = 0.0;
  EXPECT_DOUBLE_EQ(controller_.Calculator("156156*3*3*0.1*0.1*()").first,
                   result);
}

TEST_F(CalcTest, test_calculator87) {
  double result = 156 / 2;
  EXPECT_DOUBLE_EQ(controller_.Calculator("156/2").first, result);
}

TEST_F(CalcTest, test_calculator88) {
  double result = 512 / 2 / 2 / 2;
  EXPECT_DOUBLE_EQ(controller_.Calculator("512/2/2/2").first, result);
}

TEST_F(CalcTest, test_calculator89) {
  double result = 512 / 2 / 2 / 2 / 0.5;
  EXPECT_DOUBLE_EQ(controller_.Calculator("512/2/2/2/0.5").first, result);
}

TEST_F(CalcTest, test_calculator91) {
  double result = -2 + 12;
  EXPECT_DOUBLE_EQ(controller_.Calculator("-2+12").first, result);
}

TEST_F(CalcTest, test_calculator92) {
  double result = pow(-2, 2);
  EXPECT_DOUBLE_EQ(controller_.Calculator("(-2)^2").first, result);
}

TEST_F(CalcTest, test_calculator93) {
  double result = 0.4;
  EXPECT_DOUBLE_EQ(controller_.Calculator("(3.4)mod3").first, result);
}

TEST_F(CalcTest, test_calculator94) {
  double result = 2;
  EXPECT_DOUBLE_EQ(controller_.Calculator("+3-1").first, result);
}

TEST_F(CalcTest, test_calculator95) {
  double result = 1;
  EXPECT_DOUBLE_EQ(controller_.Calculator("log(10)").first, result);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  free(__cxxabiv1::__cxa_get_globals());
  return RUN_ALL_TESTS();
}