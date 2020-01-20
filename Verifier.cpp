#include <iostream>
#include <cstring>
#include <fstream>
#include "Verifier.h"
using namespace std;

//*****************************************************************
// FILE:      Verifier.cpp
// AUTHOR:    Patrick Schlapp
// LOGON ID:  z1806407
// DUE DATE:  
//
// PURPOSE:   Verifies Sudoku solution files
//*****************************************************************

//*********************************
//INPUT: none
//RETURN: none
//PURPOSE: Default constructor for the Verifier class
//*********************************
Verifier::Verifier(){
	for(int r=0;r<9;r++){
		for(int c=0;c<9;c++){
			grid[r][c]=0;
		}
	}
}
//*********************************
//INPUT: const char*
//RETURN: none
//PURPOSE: reads the sudoku solution from the text file
//*********************************
void Verifier::readGrid(const char* file){
	ifstream input;
	input.open(file);
	for(int r=0;r<9;r++){
		for(int c=0;c<9;c++){
			input>>grid[r][c];
		}
	}
	input.close();
}
//*********************************
//INPUT: none
//RETURN: none
//PURPOSE: Prints the parent sudoku solution
//*********************************
void Verifier::printGrid(){
	for(int r=0;r<9;r++){
		if(r%3==0)
			cout << " -------------------------" <<endl;
		for(int c=0;c<9;c++){
			if(c%3==0)
				cout << " |";
			cout<<" "<<grid[r][c];
		}
		cout <<" |"<<endl;
	}
	cout << " -------------------------" <<endl;
}
//*********************************
//INPUT: none
//RETURN: boolean
//PURPOSE: Checks if parent solution is valid per the rules of sudoku
//*********************************
bool Verifier::verifySolution(){
	//check for no repeats in the row
	for(int r=0;r<9;r++){
		bool found[9] = {false};
		for(int c=0;c<9;c++){
			int sub = grid[r][c]-1;
			if(found[sub]){ //checks to make sure that the element is a valid value in sudoku
				return false;
			}
			else
				found[sub]=true;
		}
	}
	//check for no repeats in column
	for(int c=0;c<9;c++){
		bool found[9] = {false};
		for(int r=0;r<9;r++){
			int sub = grid[r][c]-1;
			if(found[sub]){
				return false;
			}		
			else
				found[sub]=true;
		}
	}
	//check for no repeats in box
	for(int a=0;a<7;a+=3){
		for(int b=0;b<7;b+=3){
			bool found[9]={false};
			for(int r=0+a;r<3+a;r++){
				for(int c=0+b;c<3+b;c++){
					int sub = grid[r][c]-1;
					if (found[sub]){
						return false;
					}
					else
						found[sub]=true;
				}
			}
		}
	}
	return true;
}
