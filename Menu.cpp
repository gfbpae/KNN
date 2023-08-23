#include "Menu.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}
void Menu::printMenu()
{
	cout<<"Welcome to KNN Application : "<<endl<<endl;
	while(1)
	{
		system("pause");
		system("cls");
		cout<<"ß                                            Options                                                      ß"<<endl;
		cout<<"ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß"<<endl;
		cout<<"ß 1) Creating Sample Data                                                                                 ß"<<endl;
		cout<<"ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß"<<endl;
		cout<<"ß 2) Creating Test Data                                                                                   ß"<<endl;
		cout<<"ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß"<<endl;
		cout<<"ß 3) Add new data to Sample Data                                                                          ß"<<endl;
		cout<<"ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß"<<endl;
		cout<<"ß 4) Add new data to test data                                                                            ß"<<endl;
		cout<<"ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß"<<endl;
		cout<<"ß 5) KNN                                                                                                  ß"<<endl;
		cout<<"ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß"<<endl;
		cout<<"ß 6) Write all to file                                                                                    ß"<<endl;
		cout<<"ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß"<<endl;
		cout<<"ß 7) Draw Graph and Exit                                                                                  ß"<<endl;
		cout<<"ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß"<<endl;
		
		/// To avoid invalid arguments
		try
		{
			choose();
		}
		/// Catches the error that returned if the invalid argument is entered
		catch (string xx)
		{
			cout<<x<<xx<<endl;
		}		
		if(x==7) break;
	}
}

void Menu::choose()
{
	int exc=-1;
	cin>>x;
	if(0<x<=7)
	{
		switch (x)
		{
			case 1:
				cout<<"How many test data will be generated?"<<endl;
				cin>>x;
				getSampleData().SampleGenerator(0,x,true);
				cout<<getSampleData();
				break;
			case 2:
				cout<<"How many test data will be generated?"<<endl;
				cin>>x; 
				getTestData().SampleGenerator(0,x,false);
				cout<<getTestData();
				break;
			case 3:
				cout<<"How many sample data will be added"<<endl;
				cin>>x;
				getSampleData().addSamplePoints(x,true);
				cout<<getSampleData();				
				break;
			case 4:
				cout<<"How many knn data will be added"<<endl;
				cin>>x;
				getTestData().addSamplePoints(x,false);	
				cout<<getTestData();				
				break;
			case 5:
				knn.calculateDistances(getSampleData(),getTestData());
				cout<<"KNN for (3,5 etc.) "<<endl;
				cin>>x;
				knn.DetermineCategory(getSampleData(),getTestData(),x);
				//knn.print(getSampleData(),getTestData()); /// When this line executed, graph class gives an error. So it is kept close.
				break;
			case 6:
				file.fileWriting(getSampleData());
				file.fileWriting(getTestData());
				cout<<"The write operation realized successfully.."<<endl;
				file.fileReading();
				break;
			case 7:
				CreateGraph(getSampleData(),getTestData(),knn);
				break;
		}
	}
	else throw " : not included in the options .. ";
}

PointGenerator& Menu::getSampleData(){return sample_data;}
PointGenerator& Menu::getTestData(){return test_data;}
		
