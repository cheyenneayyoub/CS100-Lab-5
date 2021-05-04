#include "spreadsheet.hpp"
#include "select.hpp"
#include "spreadsheet.cpp"
#include "gtest/gtest.h"
#include "PrintTest.hpp"
#include "ContainTest.hpp"
#include "NotTest.hpp"
#include "testand.cpp"
#include "testor.cpp"
using namespace std;


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
};

