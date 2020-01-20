#ifndef VERIFIER_H
#define VERIFIER_H
using namespace std;
//*****************************************************************
// FILE:      Verifier.h
// AUTHOR:    Patrick Schlapp
// LOGON ID:  z1806407
// DUE DATE:  
//
// PURPOSE:   Verifier header file
//*****************************************************************

class Verifier{
	private:
		int grid[9][9]={{0}};
		
	public:
		Verifier();
		void readGrid(const char*);
		void printGrid();
		bool verifySolution();
};
#endif
