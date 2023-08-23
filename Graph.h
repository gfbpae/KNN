#ifndef GRAPH_H
#define GRAPH_H
#include<graphics.h>
#include<iostream>
#include <string>
#include "PointGenerator.h"
#include "KNN.h"
#include <sstream>

using namespace std;
/** Graph Class => Used for visualization*/
class Graph
{
	public:
		/** Empty Constructor */
		Graph();
		/** Destructor */
		~Graph();
		/** Calculates the location of the x value of the incoming point in the coordinate system and returns it. Takes input(double) as x value*/
		double 	getXCor		(double)const;
		/** Calculates the location of the y value of the incoming point in the coordinate system and returns it. Takes input(double) as y value*/
		double 	getYCor		(double)const;
		/** With this function, a graphic template is created. The printing operations of the points on the graph are also done in this function.
		It takes first input as sample points data 
		It takes second input as knn points data 
		It takes third input as knn distances data 
		*/
		void 	CreateGraph	(PointGenerator& ,PointGenerator&,KNN&);
		/** Function in which the sample points are suppressed on the graph.
		It takes first input as x value
		It takes second input as y value
		It takes third input as Category ID value
		*/
		void 	PrintPoint	(int,int,int);
		/** Function in which the knn points are suppressed on the graph.
		It takes first input as x value
		It takes second input as y value
		It takes third input as circle radius value
		It takes fourth input as Category Id value
		*/
		void 	printKNN	(int,int,double,int);
	protected:
};

#endif
