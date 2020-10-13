#include<iostream>
#include<fstream>
#include <bits/stdc++.h>
#include<stdio.h>
#include<string>

using namespace std;

int *piTable(string pattern){
	
		int a= 6;
		char arr[6];
		strcpy(arr,pattern.c_str());
	static	int table[6];
		table[0]=0;
		int count=0,turn=0;  
		for(int i=1;i<a;i++) {
			    	for(int j=0;j<i;j++) {
			    		int x=j;
			    		while(turn<=j ) {
			    			if(arr[turn]==arr[i-x]) {
			    				if(turn==j) {
			    					turn=0;
			    					count=j+1;
			    					break;
			    				}
			    				turn++;
			    				x--;
			    			}
			    			else {
			    				turn=0;
			    				break;
			    			}
			    		}
			    	}
			    		
			    	
			    table[i]=count;
			    count=0;
			
		}
	cout<<endl;
		return table;
		

}

void KMP_search(ifstream& myfile,string birthday){
	//**opening result file**
	ofstream result;
	result.open("result.txt",ios_base::app);
	result<<"KMP String Matching Algorithm\n \n";
	result<<"indexes of birthday:970702\n \n";
	//*************************
	

	int table[6];
	int *ptr;
	ptr=piTable(birthday);
	for(int i=0;i<6;i++){
		table[i]=*(ptr+i);
	}
		char c;
		string line;
		char pat[6];
		strcpy(pat,birthday.c_str());
		int i=0,count=0,total=0;
		while(getline(myfile,line)){
			if(line.find("Pi = 3.")==line.npos){
				continue ;
			}
		while(myfile.good()){
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
						
					char arr2[6];
					strcpy(arr2,birthday.c_str());
					for(int j=0;j<6;j++) {
				
					if(c==arr2[j]) {
					
					
						if(j==5) {
							total++;
							result<<count-6<<"\n";
							cout<<endl;
							break;
						}
						myfile.get(c);
						while(c==' '|| c==':'){
							if(c==':'){
								while(c!='\n' ){
									myfile.get(c);
									if(myfile.peek()==EOF){
										break;
									}
								}
								myfile.get(c);
							}
							else {
								myfile.get(c);
							}
						}
						if(c<48 || c>57){
							myfile.get(c);
						}
						if(c>=48 && c<=57){
							count++;
						}
					
					}
					else {
					
						if(j==0) {
							break;
						}
						while(j>0) {
							
							j=table[j-1];
							if(c==arr2[j]) {
								j--;
								break;
							}
						}
						if(j==0 && c!=arr2[j]) {
							break;
						}
						
							
						
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
		
		KMP_search(myfile,birthday);
	
		
	}
	
	else{
		cout<<"file is not open\n";
	}
}
