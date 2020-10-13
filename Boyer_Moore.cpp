#include<iostream>
#include<fstream>
#include <bits/stdc++.h>
#include<stdio.h>
#include<string>

using namespace std;

//******************************************************

struct node{
	char num;
	int table_val;
	struct node *next;
};
node *head=NULL;
node *tail=NULL;

void add_table(char a,int b){
	
	if(head==NULL){
	
		node *temp=new node;
		temp->num=a;
		temp->table_val=b;
		temp->next=NULL;
		head =temp;
		tail=temp;
	}
	else{
		node *temp=head;
		while(temp != NULL){
			if(temp->num==a){
				temp->table_val=b;
				break;
			}
			else if(temp->num != a && temp->next==NULL){
	
				node *temp=new node;
				temp->num=a;
				temp->table_val=b;
				temp->next=NULL;
				tail->next=temp;
				tail=temp;
				break;
			}
			temp=temp->next;
		
		}
	}
	   
}

void badStringTable(string birthday){
	char arr[6];
	strcpy(arr,birthday.c_str());
	for(int i=0;i<6;i++){
		int val=6-i-1;
	
		if(val>1){
			add_table(arr[i],val);
	
		}
		else{
	
			add_table(arr[i],1);
		}
	}	
	
	
}
//******************************************************

int search(char val){
	node *temp=head;
	int flag=0;
	while(temp!=NULL){
		if(temp->num==val){
			flag=1;
			return temp->table_val;
		}
		temp=temp->next;
	}
	if(flag==0){
		return 6;
	}
}

//******************************************************
void boyer_moore(ifstream& myfile,string birthday){
	//**opening result file**
	ofstream result;
	result.open("result.txt",ios_base::app);
	result<<"BOYER-MOORE String Matching Algorithm\n \n";
	result<<"indexes of birthday:970702\n \n";
	//*************************
	
	char c;
		string line;
		char pat[6];
		strcpy(pat,birthday.c_str());
		int i=0,count=0,shift=0,total=0;
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
					for(int z=5;z>=0;z--){
						
							if(arr[z]!=pat[z]){
								shift=search(arr[z]);

								if(shift<6){
										
									for(int a=0;a<6-shift;a++){
										arr[a]=arr[shift+a];
									}

									i=6-shift;
									break;
	 							}
	 							else{
	 								i=0;
	 								break;
								 }
							}
							else if(z==0 && arr[z]==pat[z]){
								
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
		badStringTable(birthday);
		
		boyer_moore(myfile,birthday);
	
		
	}
	
	else{
		cout<<"file is not open\n";
	}
}
