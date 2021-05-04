#ifndef __TESTAND__
#define __TESTAND__

#include "spreadsheet.hpp"
#include "select.hpp"
#include "gtest/gtest.h"

#include <string>
#include <sstream>

using namespace std;

TEST(RowPrint, RowTest) {
Spreadsheet sh;
sh.set_column_names({"First", "Last", "Age", "Major"});
sh.add_row({"Shwena", "Kak", "95", "Awesomeness"});

stringstream out;

sh.print_selection(out);
EXPECT_EQ(out.str(), "Shwena Kak 95 Awesomeness \n");
}

TEST(Spreadsheet, blank) {
	Spreadsheet sh;
	stringstream strstream;
	sh.print_selection(strstream);
	string test = strstream.str();
	EXPECT_EQ(test, "");
}

TEST(SelectAdd, AddContains) {

Spreadsheet sh;
sh.set_column_names({"Name", "Age"});
sh.add_row({"Amanda Andrews", "22"});
sh.add_row({"Diane Dole", "20"});
sh.add_row({"George Genius", "9"});
sh.add_row({"David Dole", "22"});

sh.set_selection(
	new Select_And(
		new Select_Contains(&sh, "Age", "22"),
		new Select_Contains(&sh, "Name", "e")));

	stringstream strstream;
	sh.print_selection(strstream);
	string test = strstream.str();
	EXPECT_EQ(test, "Amanda Andrews 22 \nDavid Dole 22 \n");
}


#endif
