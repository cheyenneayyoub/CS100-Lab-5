#ifndef _CONTAINTEST_HPP
#define _CONTAINTEST_HPP

#include "gtest/gtest.h"
#include "spreadsheet.hpp"
#include "select.hpp"

TEST(Contains, OneLine){
	Spreadsheet sh;
	sh.set_column_names({"First","Last","Age","Major"});
	sh.add_row({"George","Genius","9","astrophysics"});
	std::stringstream s;
	sh.set_selection(new Select_Contains(&sh,"First","George"));
	sh.print_selection(s);
	EXPECT_EQ(s.str(), "George Genius 9 astrophysics \n");
}

TEST(Contains, ContainNot){
	Spreadsheet sh;
	sh.set_column_names({"Name", "Age"});
	sh.add_row({"George Genius", "9"});
	sh.add_row({"Diane Dole", "20"});
	sh.add_row({"David Dole", "22"});
	std::stringstream s;
	sh.set_selection(
		new Select_Not(
			new Select_Contains(&sh, "Name", "ol")));
	sh.print_selection(s);
	EXPECT_EQ(s.str(), "George Genius 9 \n");
}

#endif
