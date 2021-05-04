#include "spreadsheet.hpp"
#include "select.hpp"
#include "spreadsheet.cpp"
#include "gtest/gtest.h"

TEST(Print, OneLine){
Spreadsheet sheet;
sheet.set_column_names({"First","Last","Age","Major"});
sheet.add_row({"George","Genius","9","astrophysics"});
std::stringstream out;
sheet.print_selection(out);
EXPECT_EQ(out.str, "George Genius 9 astrophysics");
}

/*
TEST(ContTest, ByItself){
	new Select_Containts(&sheet, "Last", "Dole");
	EXPECT_EQ(	
}
*/
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
