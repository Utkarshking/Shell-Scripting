#include<bits/stdc++.h>
#include<stdlib.h>
#include<time.h>
#include <dirent.h>
// used for rmdir
//#include<ftw.h>
using namespace std;
//change the directory
void changedir(){
	char s[100];
	// printing current working directory
	//	printf("%s\n", getcwd(s, 100));
	// using the command
	chdir("..");
	// printing current working directory
	//	printf("%s\n", getcwd(s, 100));
	// after chdir is executed
	chdir("..");
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
// removes a empty directory
//void removedir(char* dirname){
//
//}

int main(){
string cmd;
string name;
int size=name.size();
// last char taken for '\0'
char array[size+1];
    int num=9;
    int ch;
    cout<<" WELCOME TO THE LINUX SHELL" <<endl;
    cout<<" 1: for making directory" <<endl;
    cout<<" 2: for displaying the present work directory" <<endl;
    cout<<" 3: list all the files in that directory" <<endl;
    cout<<" 4: change the working directory" <<endl;
    cout<<" 5: deletes a file in a directory" <<endl;
    cout<<" 6. makes a file in a directory"<<endl;
//    cout<<" 7. deletes a directory" <<endl;
    while(num){
    cout<<"enter the choice"<<endl;
    cin>>ch;
    switch(ch){
    case 1:     cout<<"enter the command"<<endl;
                cin>>cmd>>name;
                if(cmd=="mkdir"){
                strcpy(array,name.c_str());
                makedir(array);
				}
				else{
				cout<<cmd<<" :Command Not found"<<endl;	
				}
                break;
    case 2:     cout<<"enter the command :-"<<endl;
                cin>>cmd;
                if(cmd=="pwd"){
                 pwd();	
				}
				else{
				cout<<cmd<<" :Command Not found"<<endl;		
				}
                break;
    case 3:     cout<<"enter the command :-"<<endl;
                cin>>cmd;
                if(cmd=="ls"){
                ls();
				}
				else{
				cout<<cmd<<" :Command Not found"<<endl;		
				}
                break;
	case 4:     cout<<"enter the command :-"<<endl;
				cin>>cmd>>name;
				changedir();
				break;	
	case 5:     cout<<"enter the command :-"<<endl;
				cin>>cmd>>name;
				strcpy(array,name.c_str());
				delfile(array);
				break;
	case 6:		cout<<"enter the command :-"<<endl;
                cin>>cmd>>name;
                strcpy(array,name.c_str());
                makefile(array);
                break;
	default:    cout<<"You entered a wrong choice"<<endl;
				break;			
    }
    num--;
}

}
