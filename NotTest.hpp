#ifndef _NOTTEST_HPP_
#define _NOTTEST_HPP_

#include "gtest/gtest.h"
#include "spreadsheet.hpp"
#include "select.hpp"

TEST(Not_Test, NotContains){
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

TEST(Not_Test, Empty){
        Spreadsheet sh;
        sh.set_column_names({"Name", "Age"});
        //sh.add_row({"George Genius", "9"});
        sh.add_row({"Diane Dole", "20"});
        sh.add_row({"David Dole", "22"});
        std::stringstream s;
        sh.set_selection(
                new Select_Not(
                        new Select_Contains(&sh, "Name", "ol")));
        sh.print_selection(s);
        EXPECT_EQ(s.str(), "");
}

#endif
