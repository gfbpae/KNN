#include "Graph.h"

Graph::Graph()
{
}

Graph::~Graph()
{
}

double Graph::getXCor(double x)const{return (((x*50)+300));}
double Graph::getYCor(double y)const{return ((-(y*50)+300));}

void Graph::CreateGraph(PointGenerator& sample,PointGenerator& knnO, KNN& knn)
{
	initwindow(600,600);
	line(0, 300, 600, 300);
    line(300, 0, 300, 600);
	outtextxy(50,300,"-5");
	outtextxy(100,300,"-4");
	outtextxy(150,300,"-3");
	outtextxy(200,300,"-2");
	outtextxy(250,300,"-1");
	outtextxy(300,300,"0");
	outtextxy(350,300,"1");
	outtextxy(400,300,"2");
	outtextxy(450,300,"3");
	outtextxy(500,300,"4");
	outtextxy(550,300,"5");
	outtextxy(300,50,"5");
	outtextxy(300,100,"4");
	outtextxy(300,150,"3");
	outtextxy(300,200,"2");
	outtextxy(300,250,"1");
	outtextxy(300,300,"0");
	outtextxy(300,350,"-1");
	outtextxy(300,400,"-2");
	outtextxy(300,450,"-3");
	outtextxy(300,500,"-4");
	outtextxy(300,550,"-5");
	
	for (int i=0; i<sample.getLastIndex(); i++)
    {
		PrintPoint(getXCor(sample.getPointX(i)),getYCor(sample.getPointY(i)),sample.getPointID(i));
	}
	for(int j=0; j<knnO.getLastIndex();j++)
	{
		printKNN(getXCor(knnO.getPointX(j)),getYCor(knnO.getPointY(j)),(knn.getDistances(j*sample.getLastIndex()+4))*50,knn.getCategory(j));	
	}
	getch();
	getch();
    closegraph();
}

void Graph::PrintPoint(int x, int y,int ID)
{
	if(ID==1)
	{
    	setcolor(CYAN);
    	circle(x,y,3);
        floodfill(x,y,CYAN);
    	outtextxy(x+5,y,"1");
   	}
	else if (ID==2)
	{
        setcolor(MAGENTA);
		circle(x,y,3);
		floodfill(x,y,MAGENTA);
        outtextxy(x+5,y,"2");
    }
    else
    {
        setcolor(LIGHTBLUE);
        circle(x,y,3);
        floodfill(x,y,LIGHTBLUE);
        outtextxy(x+5,y,"3");
    }
}
void Graph::printKNN(int x,int y,double r,int c)
{
	setcolor(WHITE);
	circle(x,y,3);
	floodfill(x,y,WHITE);
	
	if(c==1){outtextxy(x+5,y,"k->1");}
	else if (c==2){outtextxy(x+5,y,"k->2");}
    else {outtextxy(x+5,y,"k->3");}
    
	setcolor(WHITE);
	circle(x,y,r);
}
