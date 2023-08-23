#ifndef MENU_H
#define MENU_H
#include<iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include "PointGenerator.h"
#include "KNN.h"
#include "RW.h"
#include "Graph.h"
#include <stdexcept>

using namespace std;
/** Menu Class => program works here */
class Menu : public Graph
{
	public:
		/** Empty Constructor */
		Menu();
		/** Destructor */
		~Menu();
		/** Options are suppressed */
		void printMenu();
		/** Returns Sample Data (When the function is const, it gives an error. ) */
		PointGenerator& getSampleData();
		/** Returns Test Data (When the function is const, it gives an error. ) */
		PointGenerator& getTestData();
		/** It is called with the try body in the menu. Performs operations according to the selection made. throws an error on invalid selections. */
		void choose();
		
	protected:
		/** Creates sample data object from point generator class */
		PointGenerator sample_data;
		/** Creates test data object from point generator class */
		PointGenerator test_data;
		/** Creates knn object from KNN class */
		KNN knn;
		/** Creates file object from RW class */
		RW file;
		/** */
		int x;
};

#endif
