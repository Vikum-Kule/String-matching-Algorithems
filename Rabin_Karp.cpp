#include<iostream>
#include<fstream>
#include <bits/stdc++.h>
#include<stdio.h>
#include<string>
#include<sstream>

using namespace std; 
int flag_note=0;
int first_val=0;
int pre_sum=0;
int hash_val(char *char_arr){
	
	
   int arr[6];
   stringstream convert;
   for(int i=0;i<6;i++){
   		char a=char_arr[i];
   		arr[i]=(int)a-48;
   	
   }	int hash=0;
		int sum=0;
	if(flag_note==0){
	
		for(int i=1;i<=6;i++){
			int mul=1;
			for(int j=0;j<6-i;j++){
				mul=mul*10;
			}
			mul=mul*arr[i-1];
			sum=sum+mul;
			
			if(i==1){
				first_val=sum;
			}
		}
		pre_sum=sum;
	}
	else{
		sum=(pre_sum-first_val)*10+arr[5];
		first_val=arr[0]*10*10*10*10*10;
		pre_sum=sum;

	}
	
	hash=sum%13;
	return hash;
	
}

void RabinKarp_search(ifstream& myfile,string birthday,int pat_hash){
	//**opening result file**
	ofstream result;
	result.open("result.txt",ios_base::app);
	result<<"RABIN-KARP String Matching Algorithm\n \n";
	result<<"indexes of birthday:970702\n \n";
	//*************************


		char c;
		string line;
		char pat[6];
		char pos[9]="";
		strcpy(pat,birthday.c_str());
		int i=0,count=0,total=0;
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
					else  if(c>=48 && c<=57){
						count++;
						arr[i]=c;
						i++;
					}
				}
				else if(i==6){
					if(hash_val(arr)==pat_hash){
					 	for(int p=0;p<6;p++){
							if(pat[p]==arr[p]){
								if(p==5){
									result<<count-6<<"\n";
									total++;
									arr[0]=arr[1];
									arr[1]=arr[2];
									arr[2]=arr[3];
									arr[3]=arr[4];
									arr[4]=arr[5];
									i--;
									break;
														
								}
							}
							else{
								arr[0]=arr[1];
								arr[1]=arr[2];
								arr[2]=arr[3];
								arr[3]=arr[4];
								arr[4]=arr[5];
								i--;
									break;
								
							}
						}
					}
					else{
						
						arr[0]=arr[1];
						arr[1]=arr[2];
						arr[2]=arr[3];
						arr[3]=arr[4];
						arr[4]=arr[5];
						i--;
							
					}
					flag_note=1;
								
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
		char arr2[6];
		strcpy(arr2,birthday.c_str());
		
		int pat_hash=hash_val(arr2);
		cout<<"<<<<"<<pat_hash<<endl;
		RabinKarp_search(myfile,birthday,pat_hash);
	
		
	}
	
	else{
		cout<<"file is not open\n";
	}

}
