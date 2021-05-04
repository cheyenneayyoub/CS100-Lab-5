#ifndef __TESTOR__
#define __TESTOR__

#include "spreadsheet.hpp"
#include "select.hpp"
#include "gtest/gtest.h"

#include <string>
#include <sstream>

using namespace std;

TEST(RowPrintTest, RowTest) {
Spreadsheet sh;
sh.set_column_names({"First", "Last", "Age", "Major"});
sh.add_row({"Joe", "Jackson", "21", "mathematics"});

stringstream out;

sh.print_selection(out);
EXPECT_EQ(out.str(), "Joe Jackson 21 mathematics \n");
}

TEST(SpreadsheetTest, blank) {
        Spreadsheet sh;
        stringstream strstream;
        sh.print_selection(strstream);
        string test = strstream.str();
        EXPECT_EQ(test, "");
}


TEST(SelectOr, NoMatch)
{
	Spreadsheet sh;
	sh.set_selection(
		new Select_Or(
			new Select_Contains(&sh,"major","Swag"),
			new Select_Contains(&sh,"Name","Swaggy")));

	stringstream strstream;
	sh.print_selection(strstream);
	string test = strstream.str();
	EXPECT_EQ(test, "");
}

TEST(SelectOr, OrNot){
	Spreadsheet sh;
	sh.set_column_names({"First", "Last", "Age"});
	sh.add_row({"Diane Dole", "20"});
	sh.add_row({"Dominick Dole", "22"});
	sh.add_row({"David Dole", "22"});
	sh.add_row({"Amanda Andrews", "22"});
	sh.add_row({"Brian Becker", "21"});
	sh.set_selection(
		new Select_Or(
			new Select_Not(
				new Select_Contains(&sh, "First", "Dole")),
			new Select_Contains(&sh, "First", "Becker"))); 
	stringstream s;
	sh.print_selection(s);
	EXPECT_EQ(s.str(), "Amanda Andrews 22 \nBrian Becker 21 \n");
}
#endif
