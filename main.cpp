#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<fstream>
using namespace std;
void line(char ch='-', int n=100)
{
	for(int i=0;i<n;i++)
		cout<<ch;
	cout<<"\n";
}
int n,p;
int id;
class Code_library
{       char fname[100],fpath[100],fext[100],flang[100],fkey[100];
        void write();
		void backup();
		char tname[10];
		public: 
			void main_menu();
			void input();
		    void output();
		    void search();
		    void f_name();
		    void f_path();
		    void f_Ext();
		    void f_language();
		    void f_Key();
		    void delete_code();
		    void fd_name();
		    void fd_path();
		    void fd_Ext();
		    void fd_language();
		    void fd_Key();
		    void code_output();
		    void modify_code();
		    int icount();
		    int count();
};
 
void Code_library::main_menu()
	{     n=0;
	   int p=0;
	    	int choice;
	    ifstream fin;
	    fin.open("n.txt");
	    //fin.open("Codelibrary.dat",ios::binary|ios::app);
	    {
	    	fin>>n;
		}
		ifstream z;
		z.open("p.txt");
		{
			fin>>p;
		}
		fin.close();	 
		do{
		system("cls");
		cout<<"\n\t\t\t  MAIN MENU";
		cout<<"\n\n\t\t1.	Search Menu";
		cout<<"\n\n\t\t2.	Report Menu";
		cout<<"\n\n\t\t3.	Add New Code";
		cout<<"\n\n\t\t4.	Delete  Code";
		cout<<"\n\n\t\t5.	Modify  Code";
		cout<<"\n\n\t\t6.	Exit";
		cout<<"\n\t\t\t\t Enter Your choice(1..6) :"; 
	      cin>>choice;
		switch(choice)
		{
						case 1:
					search();
					break;
			case 2:
					output();
					break;
			case 3:
					write();
					break;
			case 4:
					delete_code();
					break;
			case 5:
					modify_code();
					break;
			case 6:
					break;
			default:
					cout<<"\n\n Wrong Choice...Try again";
		};
		
	}while(choice!=6);
	return;
}
void Code_library::write()
{
	  char ch;
	  input();
	  ofstream fout("Codelibrary.dat",ios::binary|ios::app);
      fout.write((char *)this, sizeof(Code_library));
	  fout.close();
	  count();
}
int Code_library::icount()
{
   id=p;
   p++;
   ofstream fout;
   fout.open("p.txt");
	fout<<p;
	fout.close();

}
int Code_library::count()
{   
    n++;
	ofstream fout;
	fout.open("n.txt");
	fout<<n;
	fout.close();

}
void Code_library::input()
{
          	icount();
	     cout<<"\n Enter File Name :";
				fflush(stdin);
				cin.getline(fname,60);
				
	    cout<<"\n Enter File path Name :";
				fflush(stdin);
				cin.getline(fpath,100);			
	            strcat(fpath,fname);
	            
	    cout<<"\n Enter File Extension Name :";
				fflush(stdin);
				cin.getline(fext,100);			
	
	    cout<<"\n Enter File Language Name :";
				fflush(stdin);
				cin.getline(flang,100);
				
		cout<<"\n Enter File Key Name :";
				fflush(stdin);
				cin.getline(fkey,100);
    //backup();
}
void Code_library::backup()
{
	char ch;
	ifstream fin;
	ofstream fout;
	fin.open(fpath);
	fout.open(fname);
	while(!fin.eof())
	{
		fin.get(ch);
		fout<<ch;   
	}
	fin.close();
	fout.close();
	cout<<"\n Backup Complete";
		count();
	}

void Code_library::output()
   { 	
    char ch;
    system("cls");
    cout<<"\t\t\t\t\tCode Library\n";
    line();
    cout<<"Id\tName\t\tExt\tLanguage\tKeyword\t\tPath\n";
	ifstream obj;
    obj.open("Codelibrary.dat");
    obj.read((char *)this,sizeof(Code_library));
    
    	while(!obj.eof())
    	{
    	cout<<id<<"\t"<<fname<<"\t\t"<<fkey;
		cout<<"\t"<<flang<<"\t"<<fkey<<"\t\t";
		cout<<fpath<<"\n";
    	/*	obj.get(ch);
    		cout<<ch;*/
		obj.read((char *)this,sizeof(Code_library));
		}
    	
	obj.close();
	getch();
	}
           
void Code_library::f_name()
	{
		int found=0;
	system("cls");
	fflush(stdin);
	char tname[100];
	cout<<"Enter File name ";
	cin.getline(tname,100);
	ifstream obj;
    obj.open("Codelibrary.dat",ios::binary);
    obj.read((char *)this,sizeof(Code_library));
    	while(!obj.eof())
    	{
    		if(strcmp(tname,fname)==0)
    	{ found=1;
    	 cout<<"\nFile found";
    	 cout<<"\nId "<<id<<"\n"<<"name "<<fname<<"\n"<<"Key "<<fkey;
		 cout<<"\n"<<"Language "<<flang<<"\n"<<"Key "<<fkey<<"\n";
		 cout<<"Path"<<fpath<<"\n";
	    }
	    obj.read((char *)this,sizeof(Code_library));
           }
           if(found==0)
	    cout<<"File not found";
       obj.close();    
       return;
     }

void Code_library::f_path()
{
		int found=0;
	system("cls");
	fflush(stdin);
	char tname[100];
	cout<<"Enter path name";
	cin.getline(tname,100);
	ifstream obj;
    obj.open("Codelibrary.dat");
    obj.read((char *)this,sizeof(Code_library));
    	while(!obj.eof())
    	{
    		if(strcmp(tname,fname)==0)
    		{ found=1;
    	 cout<<"\nFile found";
    	 cout<<"\nId"<<id<<"\n"<<"name"<<fname<<"\n"<<"Key"<<fkey;
		 cout<<"\n"<<"Language"<<flang<<"\n"<<"Key"<<fkey<<"\n";
		 cout<<"Path"<<fpath<<"\n";
		 }
			 obj.read((char *)this,sizeof(Code_library));
	
      }
      if(found==0)
	    cout<<"File not found";
       obj.close();
}

void Code_library::f_Ext()
{
	{
			int found=0;
	system("cls");
	fflush(stdin);
	char tname[100];
	cout<<"Enter Ext name";
	cin.getline(tname,100);
	ifstream obj;
    obj.open("Codelibrary.dat");
    obj.read((char *)this,sizeof(Code_library));
    	while(!obj.eof())
    	{
    		if(strcmp(tname,fname)==0)
    		{ found=1;
    	 cout<<"\nFile found";
    	 cout<<"\nId"<<id<<"\n"<<"name"<<fname<<"\n"<<"Key"<<fkey;
		 cout<<"\n"<<"Language"<<flang<<"\n"<<"Key"<<fkey<<"\n";
		 cout<<"Path"<<fpath<<"\n";
	}
		obj.read((char *)this,sizeof(Code_library));
      }
      if(found==0)
	    cout<<"File not found";
       obj.close();
	}
}
void Code_library::f_language()
{
		int found=0;
	system("cls");
	fflush(stdin);
	char tname[100];
	cout<<"Enter File Language name";
	cin.getline(tname,100);
	ifstream obj;
    obj.open("Codelibrary.dat");
    obj.read((char *)this,sizeof(Code_library));
    	while(!obj.eof())
    	{
    		if(strcmp(tname,fname)==0)
    		{ found=1;
    	 cout<<"\nFile found";
    	 cout<<"\nId"<<id<<"\n"<<"name"<<fname<<"\n"<<"Key"<<fkey;
		 cout<<"\n"<<"Language"<<flang<<"\n"<<"Key"<<fkey<<"\n";
		 cout<<"Path"<<fpath<<"\n";
	       }
	       	obj.read((char *)this,sizeof(Code_library));
      }
      if(found==0)
	    cout<<"File not found";
       obj.close();
	}
void Code_library:: f_Key()
{
	{
	int found=0;
	system("cls");
	fflush(stdin);
	char tname[100];
	cout<<"Enter Key name";
	cin.getline(tname,100);
	ifstream obj;
    obj.open("Codelibrary.dat");
    obj.read((char *)this,sizeof(Code_library));
    	while(!obj.eof())
    	{
    		if(strcmp(tname,fname)==0)
    		{ found=1;
    	 cout<<"\nFile found";
    	 cout<<"\nId"<<id<<"\n"<<"name"<<fname<<"\n"<<"Key"<<fkey;
		 cout<<"\n"<<"Language"<<flang<<"\n"<<"Key"<<fkey<<"\n";
		 cout<<"Path"<<fpath<<"\n";
           }
           	obj.read((char *)this,sizeof(Code_library));
      }
      if(found==0)
	    cout<<"File not found";
       obj.close();
	}
		   }		   
void Code_library::search()
{
    int choice;
	do{
		system("cls");
		cout<<"\n\t\t\t  SEARCHN MENU";
		cout<<"\n\n\t\t1.	Name";
		cout<<"\n\n\t\t2.	File path";
		cout<<"\n\n\t\t3.	File Ext";
		cout<<"\n\n\t\t4.	File language";
		cout<<"\n\n\t\t5.	File Key";
		cout<<"\n\n\t\t6.	Exit";
		cout<<"\n\t\t\t\t Enter Your choice(1..6) :"; cin>>choice;
		switch(choice)
		{
			case 1:
					f_name();
					getch();
					break;
			case 2:
					f_path();
					break;
			case 3:
				    f_Ext();
					break;
			case 4:
				    f_language();
					break;
			case 5:
					f_Key();
					break;
			case 6:
					break;
			default:
					cout<<"\n\n Wrong Choice...Try again";
		}
		
	}while(choice!=6);
	return;
}
	
void Code_library::delete_code()
{
	int choice;
	do{
		system("cls");
		cout<<"\n\t\t\t  Delete MENU";
		cout<<"\n\n\t\t1.	Name";
		cout<<"\n\n\t\t2.	File path";
		cout<<"\n\n\t\t3.	File Ext";
		cout<<"\n\n\t\t4.	File language";
		cout<<"\n\n\t\t5.	File Key";
		cout<<"\n\n\t\t6.	Exit";
		cout<<"\n\t\t\t\t Enter Your choice(1..6) :"; cin>>choice;
		switch(choice)
		{
			case 1:
					fd_name();
					getch();
					break;
			case 2:
					fd_path();
					break;
			case 3:
				    fd_Ext();
					break;
			case 4:
				    fd_language();
					break;
			case 5:
					fd_Key();
					break;
			case 6:
					break;
			default:
					cout<<"\n\n Wrong Choice...Try again";
		}
	
	   }while(choice!=6);
    }
void Code_library::fd_name()
{
	{
	int found=0;
	system("cls");
	fflush(stdin);
	char tname[100];
	ifstream obj;
	ofstream fout("temp.dat",ios::binary|ios::app);
    obj.open("Codelibrary.dat");
    obj.read((char *)this,sizeof(Code_library));
    	cout<<"Enter File name ";
	cin.getline(tname,100);
    	while(!obj.eof())
    	{
    		if(strcmp(tname,fname)!=0)
    		{ found=1;
    		fout.write((char *)this, sizeof(Code_library));
             }
        obj.read((char *)this,sizeof(Code_library));
      }
      
      remove("Codelibrary.dat");
      rename("Temp.dat","Codelibrary.dat");
      if(found==1)
	    cout<<"File deleted";
       obj.close();
	}
		   }	

void Code_library::fd_path()
{
	{
	int found=0;
	system("cls");
	fflush(stdin);
	char tname[100];
	cout<<"Enter path name";
	cin.getline(tname,100);
	ifstream obj;
	ofstream fout("temp.dat",ios::binary|ios::app);
    obj.open("Codelibrary.dat");
    obj.read((char *)this,sizeof(Code_library));
    	while(!obj.eof())
    	{
    		if(strcmp(tname,fname)!=0)
    		{ found=1;
    		fout.write((char *)this, sizeof(Code_library));
             }
           	obj.read((char *)this,sizeof(Code_library));
      }
      
      remove("Codelibrary.dat");
      rename("Temp.dat","Codelibrary.dat");
      remove("Temp.dat");
      if(found==1)
	    cout<<"File deleted";
	  if(found==0)
	  cout<<"File does not exists";  
	    
       obj.close();
	}
		   }	

void Code_library::fd_Ext()
{
	{
	int found=0;
	system("cls");
	fflush(stdin);
	char tname[100];
	cout<<"Enter Extension name";
	cin.getline(tname,100);
	ifstream obj;
	ofstream fout("temp.dat",ios::binary|ios::app);
    obj.open("Codelibrary.dat");
    obj.read((char *)this,sizeof(Code_library));
    	while(!obj.eof())
    	{
    		if(strcmp(tname,fname)!=0)
    		{ found=1;
    		fout.write((char *)this, sizeof(Code_library));
             }
           	obj.read((char *)this,sizeof(Code_library));
      }
      
      remove("Codelibrary.dat");
      rename("Temp.dat","Codelibrary.dat");
      remove("Temp.dat");
      if(found==1)
	    cout<<"File deleted";
	  if(found==1)
	  cout<<"File does not exists";  
	    
       obj.close();
	}
		   }	

void Code_library::fd_language()	
{
	{
	int found=0;
	system("cls");
	fflush(stdin);
	char tname[100];
	cout<<"Enter language name";
	cin.getline(tname,100);
	ifstream obj;
	ofstream fout("temp.dat",ios::binary|ios::app);
    obj.open("Codelibrary.dat");
    obj.read((char *)this,sizeof(Code_library));
    	while(!obj.eof())
    	{
    		if(strcmp(tname,fname)!=0)
    		{ found=1;
    		fout.write((char *)this, sizeof(Code_library));
             }
           	obj.read((char *)this,sizeof(Code_library));
      }
      
      remove("Codelibrary.dat");
      rename("Temp.dat","Codelibrary.dat");
      remove("Temp.dat");
      if(found==1)
	    cout<<"File deleted";
	  if(found==0)
	  cout<<"File does not exists";  
	    
       obj.close();
	}
		   }	

void Code_library:: fd_Key()
{
	{
	int found=0;
	system("cls");
	fflush(stdin);
	char tname[100];
	cout<<"Enter Key name";
	cin.getline(tname,100);
	ifstream obj;
	ofstream fout("temp.dat",ios::binary|ios::app);
    obj.open("Codelibrary.dat");
    obj.read((char *)this,sizeof(Code_library));
    	while(!obj.eof())
    	{
    		if(strcmp(tname,fname)!=0)
    		{ found=1;
    		fout.write((char *)this, sizeof(Code_library));
             }
           	obj.read((char *)this,sizeof(Code_library));
      }
      
      remove("Codelibrary.dat");
      rename("Temp.dat","Codelibrary.dat");
      remove("Temp.dat");
      if(found==1)
	    cout<<"File deleted";
	  if(found==0)
	  cout<<"File does not exists";  
	    
       obj.close();
	}
		   }	
	
void Code_library::code_output()
{
	
}
void Code_library::modify_code()
{
	
}
int main()
{
	Code_library obj;
	obj.main_menu();
}
