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

TEST(Contains, Empty){
	Spreadsheet sh;
	sh.set_column_names({"Name", "Age"});
        sh.add_row({"George Genius", "9"});
        sh.add_row({"Diane Dole", "20"});
        sh.add_row({"David Dole", "22"});
        std::stringstream s;
        sh.set_selection(
		new Select_Contains(&sh, "Age", "14"));
	sh.print_selection(s);
	EXPECT_EQ(s.str(), "");

}

TEST(Contains, ContainAnd){
Spreadsheet sh;
sh.set_column_names({"First", "Last", "Age"});
sh.add_row({"Diane Dole", "20"});
sh.add_row({"Dominick Dole", "22"});
sh.add_row({"David Dole", "22"});
//sh.add_row({"Amanda Andrews", "22"});
//sh.add_row({"Brian Becker", "21"});
sh.set_selection(
	//new Select_Or(
	       // new Select_Contains(&sh, "First", "Amanda"),
	        	new Select_And(
	        		new Select_Contains(&sh, "First", "Dole"),
				new Select_Not(
	        	        	new Select_Contains(&sh, "First", "v"))));
stringstream strstream;
sh.print_selection(strstream);
//string test = strstream.str();
EXPECT_EQ(strstream.str(), "Diane Dole 20 \nDominick Dole 22 \n");
}

#endif
