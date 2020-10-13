#include<iostream>
#include<fstream>
#include <bits/stdc++.h>
#include<stdio.h>
#include<string>

using namespace std;



void niveString(ifstream& myfile,string birthday){
	//**opening result file**
	ofstream result;
	result.open("result.txt",ios_base::app);
	result<<"NAIVE String Matching Algorithm\n \n";
	result<<"indexes of birthday:970702\n \n";
	//*************************
		char c;
		string line;
		char pat[6];
		strcpy(pat,birthday.c_str());
		int i=0,total=0,count=0,match_no=0;
		char arr[6];
		while(getline(myfile,line)){
			if(line.find("Pi = 3.")==line.npos){
				continue ;
			}
			
			while(myfile.good()){     
				if(i<6){ 
					myfile.get(c);
					
				    if(c==' '){
						continue;
					}
					
					else if(c==':'){
					
						while(c!='\n' ){
							myfile.get(c);
							if(myfile.peek()==EOF){
								break;
							}
						}
						
					}
					else if(c>=48 && c<=57){
						count++;
						arr[i]=c;
						i++;
					}
				}
				else if(i==6){
					for(int z=0;z<6;z++){
						
							if(arr[z]!=pat[z]){
					
								arr[0]=arr[1];
								arr[1]=arr[2];
								arr[2]=arr[3];
								arr[3]=arr[4];
								arr[4]=arr[5];
								i--;
									break;
							}
							else if(z==5 && arr[z]==pat[z]){
									total++;
									match_no=count-6;
									result<<match_no<<"\n";
									cout<<endl;
									arr[0]=arr[1];
									arr[1]=arr[2];
									arr[2]=arr[3];
									arr[3]=arr[4];
									arr[4]=arr[5];
									i--;
									break;
							}
							else{
								continue;
							}

					}				
				}
							
	    	}
	    	
	    	result<<"\n total macthing indexes:"<<total<<"\n \n";
		}
		
	
	}
	



int main(){

	ifstream myfile;
	myfile.open("pi.txt");
	
	if(myfile.is_open()){
		string birthday;
		string year,month,day;
		cout<<"input your Birthday by separating spaces(EX:1997 07 02): ";
		cin>>year>>month>>day;
		
		cout<<year<<" "<<month<<" "<<day<<endl;
		char arr[4];
		strcpy(arr,year.c_str());
	    string newyr;
	    newyr += arr[2];
	    newyr += arr[3];
		birthday=newyr+month+day;
		cout<<birthday<<endl;
		
		niveString(myfile,birthday);
	
		
	}
	
	else{
		cout<<"file is not open\n";
	}
}
