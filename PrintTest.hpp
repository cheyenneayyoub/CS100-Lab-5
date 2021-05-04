#ifndef _PRINTTEST_HPP
#define _PRINTTEST_HPP

#include "gtest/gtest.h"
//#include "spreadsheet.cpp"
#include "spreadsheet.hpp"
#include "select.hpp"

TEST(Print, OneLine){
	Spreadsheet sh;
	sh.set_column_names({"First","Last","Age","Major"});
	sh.add_row({"George","Genius","9","astrophysics"});
	std::stringstream s;
	sh.print_selection(s);
	EXPECT_EQ(s.str(), "George Genius 9 astrophysics \n");
}

#endif
