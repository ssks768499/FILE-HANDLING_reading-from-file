#include <iostream>  
#include <fstream>
#include <cstring>
using namespace std;
string input_data_with_spaces() 
{
    string input;
    getline(cin,input);
	return input;
}
int main()
{
	cout<<"----------Reading data from file----------";
	string name,reg,mark,remark,display;
	int count= 0,n,i;
	cout<<"\n\nEnter number of students details you want know: ";
	cin>>n;
	ifstream file;	
	cin.ignore();
	for(i=0;i<n;i++)
	{
		file.open("Students_list.csv");
		cout<<"\n\nEnter the students registration number whose details wants to see: ";
		display=input_data_with_spaces();	
		while (file.good())
		{
			getline (file,reg,',');
			getline (file,name,',');
			getline (file,mark,',');
			getline (file,remark,'\n');
			if(reg == display)
			{
				cout<<"\n\nStudents detail mentioned registration number :";
				cout<<"\nRegistraion Number"<<'\t'<<":"<<'\t'<<reg;
				cout<<"\nName of the student"<<'\t'<<":"<<'\t'<<name;
				cout<<"\nTotal marks obtained"<<'\t'<<":"<<'\t'<<mark;
				cout<<"\nRemarks provided"<<'\t'<<":"<<'\t'<<remark;
				count+=1;
			}	
		}
		if(count == 0)
		{
			cout<<"\n\nStudents detail not available for mentioned registration number!!!!";
		}
		file.close();
		count=0;
	}
	cout<<"\n\n\n\n\n";
	return 0;
}
