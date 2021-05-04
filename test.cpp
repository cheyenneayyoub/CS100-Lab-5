#include "spreadsheet.hpp"
#include "select.hpp"
#include "spreadsheet.cpp"
#include "gtest/gtest.h"
#include "PrintTest.hpp"
#include "ContainTest.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
