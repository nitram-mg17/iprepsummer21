//author: Martin Gonzales

/* Idea: Replace word by reading file line by line to get
 * same format as original file.
 *
 * Plan: Read the original file and create a temporary file
 * as an output file. Count the number of taboo words every
 * time it is replaced. Save the temp file as the original
 * and move file to trash if taboo > 5.
 */
 
#include <iostream> 
#include <fstream> 
using namespace std; 

int main() 
{
	//initialize variables
	int count = 0;
    string line;
    //create file descriptors
    ifstream filein("sample1.txt");  //read file
    ofstream fileout("temp.txt"); //save temp file
    
    //exit if original file does not exist
    if(!filein){
        printf("FILE DOES NOT EXIST!\n");
        return 1;
    }
 
 	//read line by line
    while(getline(filein, line)){
    	//fix 1st taboo word "bad"
    	while(line.find("bad") != string::npos){
    		line.replace(line.find("bad"), 3, "***");
    		count++;
    	}
    	//fix 2nd taboo word "worse"
    	while(line.find("worse") != string::npos){
    		line.replace(line.find("worse"), 5, "*****");
    		count++;
    	}
    	//write to temp file
    	fileout << line << endl;
    }  
    //replace temp to original file
    remove("sample1.txt");
    rename("temp.txt","sample1.txt");
    
    //check if taboo word is > 5
    //linux system call format is used to move file to trash folder
    //trash can be replaced by path of folder.
    if (count > 5) {
    	system("mv sample1.txt trash");
    	printf("%s moved to trash folder\n", "sample1.txt");
    }
    
    //output
    printf("Number of Taboo words: %d\n", count);
    
    return 0; 
} 
