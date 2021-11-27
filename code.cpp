#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
#include <dirent.h>
// used for rmdir
//#include<ftw.h>
using namespace std;
//change the directory
void changedir(){
	char s[100];
	chdir("..");
	// printing current working directory
	printf("%s\n", getcwd(s, 100));
}
void dir(char* folder){
	char s[100];
	chdir(folder);
	// printing current working directory
	printf("%s\n", getcwd(s, 100));
}
//deletes a file 
void delfile(char* file){
	if (remove(file) == 0)
	cout<<"Deleted successfully"<<endl;
	else
	cout<<"Unable to delete the file"<<endl;
}
// makes a directory
void makedir(char* dirname){
	bool check;
	check=mkdir(dirname);
	if(!check){
		cout<<"directory created"<<endl;
	}
	else {
		cout<<"directory already exists named :"<<dirname<<endl;
	}
}
// displays the present work directory
void pwd(){
char buffer[FILENAME_MAX];
_getcwd(buffer,FILENAME_MAX);
cout<<"current work directory is\n"<<buffer;
cout<<endl;
}
// lists all the files in the directory
int ls()
{   
struct dirent *de;
DIR *dr = opendir(".");
if (dr == NULL)
{
printf("Could not open current directory");
return 0;
}
while ((de = readdir(dr)) != NULL)
printf("%s\n", de->d_name);
closedir(dr);
return 0;
}
// makes a file in the directory
// not for every file 
void makefile(char* filename){
    FILE *fp = fopen(filename, "w");
}
// opens notepad using command line
void notepad(string s){
	string str="notepad \""+s+"\"";
	system(str.c_str());
}

int main(){
	// starting the time measuring the program execution time 
	 time_t start,end;
	 // starting the time 
	 time(&start);
	// taking the input from the dataset
	#ifndef ONLINE_JUDGE
    freopen("dataset.txt", "r", stdin);
	#endif
	// taken for the string and name 
string cmd;
string name;
int size=name.size();
// last char taken for '\0'
char array[size+1];
    int num;
    cin>>num;
    int ch;
    cout<<"    WELCOME TO THE LINUX SHELL" <<endl;
    cout<<" 1: for making directory" <<endl;
    cout<<" 2: for displaying the present work directory" <<endl;
    cout<<" 3: list all the files in that directory" <<endl;
    cout<<" 4: back to previous directory" <<endl;
    cout<<" 5: deletes a file in a directory" <<endl;
    cout<<" 6. makes a file in a directory"<<endl;
    cout<<" 7. moves to another directory"<<endl;
	cout<<"	8: To open a file in notepad or a third party Editor"<<endl;
    while(num){
    cout<<"enter the choice"<<endl;
    cin>>ch;
    cout<<ch<<"\n";
    switch(ch){
    case 1:     cout<<"enter the command"<<endl;
    			cout<<"anonymous_user@windows: ~$";
                cin>>cmd>>name;
                cout<<cmd<<" "<<name<<endl;
                if(cmd=="mkdir"){
                strcpy(array,name.c_str());
                makedir(array);
				}
				else{
				cout<<cmd<<" :Command Not found"<<endl;	
				}
                break;
    case 2:     cout<<"enter the command :-"<<endl;
    			cout<<"anonymous_user@windows: ~$";
                cin>>cmd;
                if(cmd=="pwd"){
                cout<<cmd<<endl;
                 pwd();	
				}
				else{
				cout<<cmd<<" :Command Not found"<<endl;		
				}
                break;
    case 3:     cout<<"enter the command :-"<<endl;
    			cout<<"anonymous_user@windows: ~$";
                cin>>cmd;
                cout<<cmd<<endl;
                if(cmd=="ls"){
                ls();
				}
				else{
				cout<<cmd<<" :Command Not found"<<endl;		
				}
                break;
	case 4:     cout<<"enter the command :-"<<endl;
				cout<<"anonymous_user@windows: ~$";
				cin>>cmd>>name;
				if(cmd=="cd"){
					changedir();
				}
				else{
				cout<<cmd<<" :Command Not found"<<endl;	
				}
				break;	
	case 5:     cout<<"enter the command :-"<<endl;
				cout<<"anonymous_user@windows: ~$";
				cin>>cmd>>name;
				if(cmd=="rm"){
				strcpy(array,name.c_str());
				delfile(array);	
				}
				else{
				cout<<cmd<<" :Command Not found"<<endl;	
				}
				break;
	case 6:		cout<<"enter the command :-"<<endl;
				cout<<"anonymous_user@windows: ~$";
                cin>>cmd>>name;
                if(cmd=="touch"){
                	strcpy(array,name.c_str());
                	makefile(array);
				}
				else{
					cout<<cmd<<" :Command Not found"<<endl;	
				}
				break;
	case 7:		cout<<"enter the command"<<endl;
				cout<<"anonymous_user@windows: ~$";
				cin>>cmd>>name;
				if(cmd=="cd"){
					strcpy(array,name.c_str());
					dir(array);
				}
				else{
				cout<<cmd<<" :Command Not found"<<endl;	
				}
	case 8:	 	cout<<"enter the command"<<endl;	
				cout<<"anonymous_user@windows: ~$";
				cin>>cmd>>name;
				if(cmd=="notepad" or cmd=="Notepad"){
					notepad(name);
				}
				break;	
	default:    cout<<"You entered a wrong choice"<<endl;
				break;			
    }
    num--;
}
	time(&end);
	double time_taken=double(end-start);
	cout<<"time taken for the program: "<<fixed<<time_taken<<setprecision(5)<<endl;
}
