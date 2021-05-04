#include "spreadsheet.cpp"
#include "select.hpp"
#include "gtest/gtest.h"
#include "testand.cpp"
#include "testor.cpp"

using namespace std;

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
};

