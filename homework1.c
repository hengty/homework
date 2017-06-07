#include<iostream>	//To use basic input and output
#include<fstream>	//For dealing with files
#include<string>
using namespace std; //So that there is no need to write "std::"

int main()
{
//////////////////////Problem 1.10.1////////////////////////////////////////////// 
	string age;
	cout<<"What is your age?\n";
	cin>>age;
	cout<<age<<"\n";
	ofstream f;	//Declare f as the name of a file to be opened for editing (ifstream for reading, fstream for both).
	f.open("output.txt");
	f << age;
	f.close();
	
	
	
	
/////////////////////Problem 1.10.2///////////////////////////////////////////////
//Part 1
	char character='c';
	char *pointer_to_a_char = &character;	//A pointer to a character
	
	int array_of_ten_int[] = {9,8,7,6,5,4,3,2,1,0};	//An array of ten integers
	
	int (*pointer_to_an_array_of_10_int)[10] = &array_of_ten_int;	//A pointer to an array of ten integers
	
	char charstr[]={'s','t','r','i','n','g'};
	char (*pointer)[sizeof(charstr)]=&charstr;	//A pointer to an array of character strings
	
	char **pointer_to_a_pointer_to_char = &pointer_to_a_char; //A pointer to a pointer of a character
	
	int const int_constant=1; //An integer constant
	
	int const *pointer_to_int_constant = &int_constant; //A pointer to an integer constant
	
	int integer=1;
	int *const constant_pointer_to_int = &integer; //A constant pointer to an integer
	
//Part 2
	int array_on_stack[]={0,1,2,3,4,5,6,7,8,9};	//An array on stack
	
	int *pointer_to_array_on_heap = new int[10]; //An array on heap
	for (int i=0; i<10; i++)
	{
		pointer_to_array_on_heap[i]=array_on_stack[i];
	}
	
	
	
	
/////////////////////Problem 1.10.3///////////////////////////////////////////////
	ifstream g("matrix_market.txt");	//Open file
	if(!g.is_open())
	{
		cout<<"Can't open file"<<endl;
		return -1;						//Terminate if can't open file
	}
	
	string percent="%";
	string data="%";
	string test="%";
	
	while(test==percent)
	{
		getline(g,data); //Skip line beginning with "%"
		test = data[0];
	}
	cout<<"Number of rows: "<<data[0]<<endl;
	cout<<"Number of columns: "<<data[2]<<endl;
	cout<<"Number of non-zero elements: "<<data[4]<<endl;
	
	return 0;
}