#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
using namespace std;
class dnode
{
public:
	int data;
	dnode* next;
	dnode* prev;
	string name;
	string gender;
	string nation;
	double salary;
	string qualification;
	dnode(dnode* p, int val, string nam, string gen,string qualif,double sal,string nat, dnode* n)
	{
		next = n;
		data = val;
		prev = p;
		name = nam;
		gender = gen;
		nation = nat;
		qualification=qualif;
		salary=sal;
	}
};
class dlinklist
{
public:
	dnode* head;
	dnode* tail;
	int count;
	dlinklist()
	{
		head = NULL;
		tail = NULL;
		count = 0;
	}
	int is_empty()
	{
		if (head == NULL)
			return 1;
		else
			return 0;
	}
	void addhead(int no, string ism, string jins,string taleem,double tnkhwa,string shankhat)
	{
		if (is_empty())
		{
			head = new dnode(NULL, no, ism, jins,taleem,tnkhwa,shankhat, NULL);
			tail = head;
		}
		else
		{
			dnode* p;
			p = new dnode(NULL, no, ism, jins,taleem,tnkhwa,shankhat, head);
			head->prev = p;
			head = p;
		}
		count++;
	}
	void addtail(int no, string ism, string jins,string taleem,double tnkhwa, string shankhat)
	{
		if (is_empty())
		{
			head = new dnode(NULL, no, ism, jins,taleem,tnkhwa,shankhat, NULL);
			tail = head;
		}
		else
		{
			dnode* p;
			p = new dnode(tail, no, ism, jins,taleem,tnkhwa, shankhat, NULL);
			tail->next = p;
			tail = p;
		}
		count++;
	}
	void insert(int no, string ism, string jins,string taleem,double tnkhwa,string shankhat, int pos)
	{
		if (pos<0 || pos>count + 1)
			cout << "INVALID POSITION" << endl;
		else if (pos == 1)
			addhead(no, ism, jins, shankhat,tnkhwa,taleem);
		else if (pos == count + 1)
			addtail(no, ism, jins, shankhat,tnkhwa,taleem);
		else
		{
//			dnode* q;
//			dnode* p;
//			dnode* s;
//			s = new dnode(NULL, no, ism, jins, shankhat, NULL);
//			p = head;
//			for (int i = 1; i <= pos - 1; i++)
//			{
//				q = p;
//				p = p->next;
//			}
//			s->next = p->prev;
//			p->prev = s;
//			q->next = s;
dnode *p=head;
for(int i=1;i<=pos-2;i++)
{
	p=p->next;
}
dnode *r=new dnode(p,no,ism,jins,taleem,tnkhwa,shankhat,p->next);
p->next->prev=r;
p->next=r;
		}
		count++;
	}
	void dtraverse()
	{
		if (is_empty())
		{
			cout << "EMPTY LINKLIST" << endl;
		}
		else
		{
			dnode* p = head;
			do {
				cout << p->data <<"\t";
				cout << p->name <<"\t";
				cout << p->gender <<"\t";
				cout<<p->qualification<<"\t";
				cout<<p->salary<<"\t";
				cout << p->nation <<"\t";
				cout << endl;
				p = p->next;

			} while (p != NULL);
		}
	}
	void deletehead()
	{
		if (is_empty())
		{
			cout << "LINKLIST IS EMPTY" << endl;
			//return 0;
		}
		else if (head == tail)
		{
			//	int temp=head->data;
			delete head;
			head = tail = NULL;
			count--;
			//	return temp;
		}
		else
		{
			dnode* p;
			p = head;
			head = head->next;
			head->prev = NULL;
			int temp = p->data;
			delete p;
			count--;
			//return temp;
		}
	}
	void deletetail()
	{
		if (is_empty())
		{
			cout << "LINK LIST IS EMPTY";
			//	return 0;
		}
		else if (head == tail)
		{
			//	int temp=head->data;
			delete head;
			head = tail = NULL;
			count--;
			//	return temp;
		}
		else
		{
			//	int temp=tail->data;
			dnode* p = tail;
			tail = tail->prev;
			delete p;
			tail->next = NULL;

			count--;
			//	return temp;
		}

	}
	int deletekey(/*int key*/string nam)
	{//	dnode *p;
		//dnode *q;
		if (is_empty())
		{
			cout << "LINKLIST IS EMPTY" << endl;
			//return 0;
		}
		if (head->name == nam)
		{
			/*	return*/ deletehead();
		}
		else if (tail->name == nam)
		{
			/*return*/ deletetail();
		}
		else
		{

			dnode* p;
			dnode* q;
			p = head;
			while (p->name != nam && p != NULL)
			{
				q = p;
				p = p->next;
			}
			if (p == NULL)
			{
				cout << "DATA NOT FOUND........" << endl;
			}
			else
				q->next = p->next;
			dnode* s = p;
			p = p->next;
			p->prev = q;
			delete s;
		}
	//	if(is_empty())
	//	{
	//		cout<<"LINKLIST IS EMPTY"<<eendl;
	//	}
	}
	void searchkey(string nam)
	{
		try
		{
			if (is_empty())
		{
			cout << "LINKLIST IS EMPTY" << endl;
			//return 0;
			throw 99;
		}
		if (head->name == nam)
		{

			cout << head->data << "\t";
			cout << head->name << "\t";
			cout << head->gender << "\t";
			cout<<head->qualification<<"\t";
			cout<<head->salary<<"\t";
			cout << head->nation << "\t";
			cout << endl;
			throw 99;
		}
		else if (tail->name == nam)
		{
			cout << tail->data<<"\t";
			cout << tail->name<<"\t";
			cout << tail->gender<<"\t";
			cout<<tail->qualification<<"\t";
			cout<<tail->salary<<"\t";
			cout << tail->nation<<"\t";
				cout << endl;
				throw 99;
		}
		else
		{

			dnode* p;
			dnode* q;
			p = head;
			while (p->name != nam && p != NULL)
			{
				q = p;
				p = p->next;
			}
			if (p == NULL)
			{
				cout << "DATA NOT FOUND........" << endl;
				throw 99;
			}
			else
				cout << p->name << "\t";
				cout << p->gender << "\t";
				cout<<p->qualification<<"\t";
				cout<<p->salary<<"\t";
				cout << p->nation << "\t";
                  	cout << endl;
                  	throw 99;
		}
	}
	catch(int x)
	{
		cout<<endl;
	}
	}
	void searchkeyedit(string nam)
	{   try
	{
		string tbdelnam;
		string tbdelgender;
		string tbdelnation;
		string tbdeltaleem;
		double tbdeltnkhwa;
		//int priop;
		if (is_empty())
		{
			cout << "LINKLIST IS EMPTY" << endl;
				throw 99;
			//return 0;
		}
		if (head->name == nam)
		{
			cout << "ENTER YOUR CORRECT NAME" << endl;
		cin>>tbdelnam;
			cout << "ENTER YOUR CORRECT GENDER" << endl;
				cin>>tbdelgender;
			cout << "ENTER YOUR CORRECT QUALIFICATION" << endl;
				cin>>tbdeltaleem;
			cout << "ENTER YOUR CORRECT SALARY" << endl;
				cin>>tbdeltnkhwa;
			cout << "ENTER YOUR CORRECT NATION" << endl;
				cin>>tbdelnation;
			head->name = tbdelnam;
			head->gender = tbdelgender;
			head->qualification=tbdeltaleem;
			head->nation = tbdelnation;
			head->salary=tbdeltnkhwa;
				throw 99;
		}
		else if (tail->name == nam)
		{
		cout << "ENTER YOUR CORRECT NAME" << endl;
			cin>>tbdelnam;
			cout << "ENTER YOUR CORRECT GENDER" << endl;
			cin>>tbdelgender;
			cout << "ENTER YOUR CORRECT QUALIFICATION" << endl;
			cin>>tbdeltaleem;
			cout << "ENTER YOUR CORRECT SALARY" << endl;
			cin >> tbdeltnkhwa;
			cout << "ENTER YOUR CORRECT NATION" << endl;
			cin>>tbdelnation;
			tail->name = tbdelnam;
			tail->gender = tbdelgender;
			tail->qualification=tbdeltaleem;
			tail->nation = tbdelnation;
			tail->salary=tbdeltnkhwa;
				throw 99;
		}
		else
		{
             
			dnode* p;
			dnode* q;
			p = head;
		//	try
          //   {
			while (p->name != nam && p != NULL)
			{
				q = p;
				p = p->next;
					throw 99;
			}
			//throw 99;
		//}
		//catch(int x)
		//{
		//	cout<<"excepional occur";
		//}
			if (p == NULL)
			{
				cout << "data not found........" << endl;
					throw 99;
			}
			else
			{
				cout << "ENTER YOUR CORRECT NAME" << endl;
			cin>>tbdelnam;
			cout << "ENTER YOUR CORRECT GENDER" << endl;
			cin>>tbdelgender;
			cout << "ENTER YOUR CORRECT QUALIFICATION" << endl;
			cin>>tbdeltaleem;
			cout << "ENTER YOUR CORRECT SALARY" << endl;
			cin >> tbdeltnkhwa;
			cout << "ENTER YOUR CORRECT NATION" << endl;
			cin>>tbdelnation;
				p->name = tbdelnam;
				p->gender = tbdelgender;
				p->qualification=tbdeltaleem;
				p->nation = tbdelnation;
				p->salary=tbdeltnkhwa;
				throw 99;
			}
		}
	}
	catch (int x)
	{
		cout<<endl;
	}
}
		void delall()
	{
		dnode*p=head;
		while(!is_empty())
		{
			deletehead();
			
//			if(p==NULL)
//			{
//				break;
//			}
		}
	}
	~dlinklist()
	{
		delall();
	}
};
int main()
{  
	//system("Color F3");
//	system("Color 1A");
	//system("Color 3B");
	system("Color 4c");



 fstream pke_tajore;
	pke_tajore.open("pkedsapro.txt",ios::app);
	fstream tajore;
	tajore.open("dsapro.txt",ios::out);
	if(tajore.is_open())
	if(pke_tajore.is_open())
	{

	cout<<"***************************************************************************************************************************************"<<
	"****************************************************************************************************************************************************"
	<<"**************************************************************************************************************************************************"<<
	"**************************************************************************************************************************************************"<<
	"***************************************************************************************************************************************************"<<
	"**************************************************************************************************************************"<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\tWELCOME IN C++ PROJECT"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t----------------------"<<endl;
   	int count=0,a=3;
    start:
    cout<<"\t\t\t\t\t\t\t\t\t\t\tADMIN LOGIN"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t-----------"<<endl;
    cout<<"\t\t\t\t\t\t\tENTER YOUR USER USERNAME"<<endl;
    cout<<"\t\t\t\t\t\t\t--------------------"<<endl;
    string user_name,password;
    cin>>user_name;
    tajore<<user_name<<endl;
    pke_tajore<<user_name<<endl;
     cout<<"\t\t\t\t\t\t\tENTER YOUR USER PASSWORD"<<endl;
    cout<<"\t\t\t\t\t\t\t-------------------------"<<endl;
    cin>>password;
    tajore<<password<<endl;
    pke_tajore<<password<<endl;
    if(user_name=="MENAL"||user_name=="menal")
    {
    	if(password=="943591")
    	{
    		cout<<"\t\t\t\t\t\t\tLOGIN SUCCESSFULL"<<endl;
    		cout<<"\t\t\t\t\t\t\t-----------------"<<endl;
    		tajore<<"\t\t\t\t\t\t\tLOGIN SUCCESSFULL"<<endl;
    		tajore<<"\t\t\t\t\t\t\t-----------------"<<endl;
    		pke_tajore<<"\t\t\t\t\t\t\tLOGIN SUCCESSFULL"<<endl;
    		pke_tajore<<"\t\t\t\t\t\t\t-----------------"<<endl;
		}
		else
		{
			cout<<"\t\t\t\t\t\t\tLOGIN UNSUCCESSFULL"<<endl;
    		cout<<"\t\t\t\t\t\t\t-------------------"<<endl;
    			cout<<"\t\t\t\t\t\t\tYOUR PASSWORD IS INCORRECT"<<endl;
    		cout<<"\t\t\t\t\t\t\t------------------------------"<<endl;
    			tajore<<"\t\t\t\t\t\t\tLOGIN UNSUCCESSFULL"<<endl;
    		tajore<<"\t\t\t\t\t\t\t-------------------"<<endl;
    			tajore<<"\t\t\t\t\t\t\tYOUR PASSWORD IS INCORRECT"<<endl;
    		tajore<<"\t\t\t\t\t\t\t------------------------------"<<endl;
    	   pke_tajore<<"\t\t\t\t\t\t\tLOGIN UNSUCCESSFULL"<<endl;
    		pke_tajore<<"\t\t\t\t\t\t\t-------------------"<<endl;
    			pke_tajore<<"\t\t\t\t\t\t\tYOUR PASSWORD IS INCORRECT"<<endl;
    		pke_tajore<<"\t\t\t\t\t\t\t------------------------------"<<endl;
    		count++;
    		if(count<3)
	{     a=a-1;
		cout<<"your\t"<<a<<"\tattempts left"<<endl;
		cout<<"if you use your attempts and still fail then our system not work"<<endl;
		cout<<"our system thought you are unknown person who tries to get unauthorised access"<<endl;
		goto start;
	}
		}
	}
	else
	{
			cout<<"\t\t\t\t\t\t\tLOGIN UNSUCCESSFULL"<<endl;
    		cout<<"\t\t\t\t\t\t\t-------------------"<<endl;
    		cout<<"\t\t\t\t\t\t\tYOUR USERNAME IS INCORRECT"<<endl;
    		cout<<"\t\t\t\t\t\t\t-------------------"<<endl;
    		tajore<<"\t\t\t\t\t\t\tLOGIN UNSUCCESSFULL"<<endl;
    		tajore<<"\t\t\t\t\t\t\t-------------------"<<endl;
    		tajore<<"\t\t\t\t\t\t\tYOUR USERNAME IS INCORRECT"<<endl;
    		tajore<<"\t\t\t\t\t\t\t-------------------"<<endl;
    		count++;
	
	if(count<3)
	{     a=a-1;
	//	cout<<"your\t"<<a<<"\tattempts left"<<endl;
	//	cout<<"if you use your attempts and still fail then our system not work"<<endl;
	//	cout<<"our system thought you are unknown person who tries to get unauthorised access"<<endl;
		count=count-1;
		if(a==0)
		{
		return 0;
	}
		cout<<"your\t"<<a<<"\tattempts left"<<endl;
		cout<<"if you use your attempts and still fail then our system not work"<<endl;
		cout<<"our system thought you are unknown person who tries to get unauthorised access"<<endl;
		count=count-1;
		goto start;
	}
}
//tajore.close();
getch();
system("cls");
system("Color 1A");
cout<<"^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^"
<<"^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^"
<<"^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^"
<<"^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^"
<<"^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^"
<<"^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-^^-^-";
//	 cout<<"\n\n\n";
//	 cout<<"\t\t\t\t\t\t FUNCTIONALITIES OF PROGRAM"<<endl<<endl<<endl;
//	 cout<<"\t\t\t1:_______ ADD DATA"<<"\t\t\t\t PRESS 1 FOR THIS FUNCTION"<<endl;
//	 cout<<"\t\t\t2:________VIEW DATA"<<"\t\t\t\t PRESS 2 FOR THIS FUNCTION"<<endl;
//	 cout<<"\t\t\t3:________DELETE PARTICULAR DATA"<<"\t\t PRESS 3 FOR THIS FUNCTION"<<endl;
//     cout<<"\t\t\t4_________DELETE ALL DATA"<<"\t\t\t PRESS 4 FOR THIS FUNCTION"<<endl;
//	 cout<<"\t\t\t5:________EDIT PARTICULAR DATA"<<"\t\t\t PRESS 5 FOR THIS FUNCTION"<<endl;
//	 cout<<"\t\t\t6:________SEARCH DATA AND VIEW THEIR DATA"<<"\t PRESS 6 FOR THIS FUNCTION"<<endl;
//cout<<endl<<endl<<endl<<"\t\t\t\t\t\t\tpress E for exit"<<endl;
	 char b;
	 int i=1;
	 dlinklist obj;
	 string profname;
	 string profgender;
	 string profqualification;
 double profsalary;
	 string profnationality;
//	 cout<<"\t\tenter your choice"<<endl;
	 //cin>>b;
	while(1) //while(b!='e'||b!='E')
	 {
	 	 cout<<"\n\n\n";
	 cout<<"\t\t\t\t\t\t FUNCTIONALITIES OF PROGRAM"<<endl<<endl<<endl;
	 cout<<"\t\t\t1:_______ ADD DATA"<<"\t\t\t\t\t PRESS 1 FOR THIS FUNCTION"<<endl;
	 cout<<"\t\t\t2:________VIEW DATA"<<"\t\t\t\t\t PRESS 2 FOR THIS FUNCTION"<<endl;
	 cout<<"\t\t\t3:________DELETE PARTICULAR DATA"<<"\t\t\t PRESS 3 FOR THIS FUNCTION"<<endl;
     cout<<"\t\t\t4_________DELETE ALL DATA"<<"\t\t\t\t PRESS 4 FOR THIS FUNCTION"<<endl;
	 cout<<"\t\t\t5:________EDIT PARTICULAR DATA"<<"\t\t\t\t PRESS 5 FOR THIS FUNCTION"<<endl;
	 cout<<"\t\t\t6:________SEARCH DATA AND VIEW THEIR DATA"<<"\t\t PRESS 6 FOR THIS FUNCTION"<<endl;
	 cout<<"\t\t\t7:________VIEW THE FILE ON WHICH YOU ARE WORKING"<<"\t PRESS 7 FOR THIS FUNCTION"<<endl;
	 cout<<"\t\t\t8:________VIEW WHOLE DATABASE"<<"\t\t\t\t PRESS 8 FOR THIS FUNCTION"<<endl;
cout<<endl<<endl<<endl<<"\t\t\t\t\t\t\tpress E for exit"<<endl;
cout<<"\t\tenter your choice"<<endl;
tajore<<"\t\tenter your choice"<<endl;
pke_tajore<<"\t\tenter your choice"<<endl;
	 cin>>b;
	 tajore<<b;
	 pke_tajore<<b;
	 	if(b=='1')
	 	{
	 			cout<<"ENTER THE PROFESSOR NAME"<<endl;
	 		cin>>profname;
	 		cout<<"ENTER THE PROFESSOR GENDER"<<endl;
	 	    cin>>profgender;
	 	    cout<<"ENTER THE PROFESSOR QUALIFICATION"<<endl;
	 	    cin>>profqualification;
	 	    cout<<"ENTER PROFESSOR SALARY"<<endl;
	 	    cin>>profsalary;
	 	    cout<<"ENTER THE PROFESSOR NATIONALITY"<<endl;
	 	    cin>>profnationality;
	 	    
	 	    tajore<<"ENTER THE PROFESSOR NAME"<<endl;
	 		tajore<<profname;
	 		tajore<<"ENTER THE PROFESSOR GENDER"<<endl;
	 	    tajore<<profgender;
	 	    tajore<<"ENTER THE PROFESSOR QUALIFICATION"<<endl;
	 	    tajore<<profqualification;
	 	    tajore<<"ENTER PROFESSOR SALARY"<<endl;
	 	    tajore<<profsalary;
	 	    tajore<<"ENTER THE PROFESSOR NATIONALITY"<<endl;
	 	    tajore<<profnationality;
	 	    
	 	    pke_tajore<<"ENTER THE PROFESSOR NAME"<<endl;
	 		pke_tajore<<profname;
	 		pke_tajore<<"ENTER THE PROFESSOR GENDER"<<endl;
	 	    pke_tajore<<profgender;
	 	    pke_tajore<<"ENTER THE PROFESSOR QUALIFICATION"<<endl;
	 	    pke_tajore<<profqualification;
	 	    pke_tajore<<"ENTER PROFESSOR SALARY"<<endl;
	 	    pke_tajore<<profsalary;
	 	    pke_tajore<<"ENTER THE PROFESSOR NATIONALITY"<<endl;
	 	    pke_tajore<<profnationality;
obj.addtail(i,profname,profgender,profqualification,profsalary,profnationality);
++i;		
		 }
		 else if(b=='2')
		 {  cout<<"\t-------YOUR LIST----------"<<endl;
		 	cout<<"\t__________________________"<<endl;
		 	obj.dtraverse();
		 }
		 else if(b=='3')
		 {
		 	char d;
		 	cout<<"\t ENTER THE NAME WHOM YOU WANT TO DELETE THE DATA"<<endl;
		 	cin>>profname;
		 		tajore<<"\t ENTER THE NAME WHOM YOU WANT TO DELETE THE DATA"<<endl;
		 	tajore<<profname;
		 	
		 		pke_tajore<<"\t ENTER THE NAME WHOM YOU WANT TO DELETE THE DATA"<<endl;
		 	pke_tajore<<profname;
		 	
		 	
		 		cout<<"\tARE YOU SURE YOU WANT TO DELETE THE"<<profname<<"DATA"<<endl;
		 	cout<<"\tIF YES THEN ENTER Y OR y IF YOU NOT WANT ENTER N OR n"<<endl;
		 	cin>>d;
		 	tajore<<"\tARE YOU SURE YOU WANT TO DELETE THE"<<profname<<"DATA"<<endl;
		 	tajore<<"\tIF YES THEN ENTER Y OR y IF YOU NOT WANT ENTER N OR n"<<endl;
		 	
		 	pke_tajore<<"\tARE YOU SURE YOU WANT TO DELETE THE"<<profname<<"DATA"<<endl;
		 	pke_tajore<<"\tIF YES THEN ENTER Y OR y IF YOU NOT WANT ENTER N OR n"<<endl;
		 	tajore<<d;
		 	pke_tajore<<d;
		 	
		 	
		 		if(d=='y'||d=='Y')
		 	{
		 	obj.deletekey(profname);
		 }
		 else if(d=='n'||d=='N')
		 {
		 		cout<<"YOUR DATA IS SECURE"<<endl;
		 		tajore<<"YOUR DATA IS SECURE"<<endl;
		 				pke_tajore<<"YOUR DATA IS SECURE"<<endl;
		 }
		 else
		 {
		 	cout<<"INVALID INPUT"<<endl;
		 		tajore<<"INVALID INPUT"<<endl;
		 			pke_tajore<<"INVALID INPUT"<<endl;
		 }
		 }
		 else if(b=='4')
		 {
		 	cout<<"\tARE YOU SURE YOU WANT TO DELETE THE ALL DATA"<<endl;
		 	cout<<"\tIF YES THEN ENTER Y OR y IF YOU NOT WANT ENTER N OR n"<<endl;
		 		tajore<<"\tARE YOU SURE YOU WANT TO DELETE THE ALL DATA"<<endl;
		 	tajore<<"\tIF YES THEN ENTER Y OR y IF YOU NOT WANT ENTER N OR n"<<endl;
		 		pke_tajore<<"\tARE YOU SURE YOU WANT TO DELETE THE ALL DATA"<<endl;
		 	pke_tajore<<"\tIF YES THEN ENTER Y OR y IF YOU NOT WANT ENTER N OR n"<<endl;
		 	char c;
		 	cin>>c;
		 	if(c=='y'||c=='Y')
		 	{
		 		obj.delall();
			}
			else if(c=='n'||c=='N')
			{
				cout<<"YOUR DATA IS SECURE"<<endl;
				tajore<<"YOUR DATA IS SECURE"<<endl;
				pke_tajore<<"YOUR DATA IS SECURE"<<endl;
			}
			else
			{
				cout<<"INVALID INPUT"<<endl;
				tajore<<"INVALID INPUT"<<endl;
					pke_tajore<<"INVALID INPUT"<<endl;
			}
		 	
		 }
		 else if(b=='5')
		 {
		 	cout<<"ENTER THE NAME WHOM DATA YOU WANT TO EDIT"<<endl;
		 	cin>>profname;
		 	
		 	tajore<<"ENTER THE NAME WHOM DATA YOU WANT TO EDIT"<<endl;
		 	tajore<<profname;
		 	
		 	
		 		pke_tajore<<"ENTER THE NAME WHOM DATA YOU WANT TO EDIT"<<endl;
		 	pke_tajore<<profname;
		 	
		 		char e;
		 		cout<<"\tARE YOU SURE YOU WANT TO EDIT THIS  DATA"<<endl;
		 	cout<<"\tIF YES THEN ENTER Y OR y IF YOU NOT WANT ENTER N OR n"<<endl;
		 	
		 	tajore<<"\tARE YOU SURE YOU WANT TO EDIT THIS  DATA"<<endl;
		 	tajore<<"\tIF YES THEN ENTER Y OR y IF YOU NOT WANT ENTER N OR n"<<endl;
		 	
		 	pke_tajore<<"\tARE YOU SURE YOU WANT TO EDIT THIS  DATA"<<endl;
		 	pke_tajore<<"\tIF YES THEN ENTER Y OR y IF YOU NOT WANT ENTER N OR n"<<endl;
		 	cin>>e;
		 	tajore<<e;
		 	pke_tajore<<e;
		 	if(e=='y'||e=='Y')
		 	{
		 		obj.searchkeyedit(profname);
			}
			else if(e=='n'||e=='N')
			{
				cout<<"YOUR PREVIOUS DATA IS SECURE"<<endl;
				tajore<<"YOUR PREVIOUS DATA IS SECURE"<<endl;
				pke_tajore<<"YOUR PREVIOUS DATA IS SECURE"<<endl;
			}
			else
			{
				cout<<"INVALID INPUT"<<endl;
					tajore<<"INVALID INPUT"<<endl;
					pke_tajore<<"INVALID INPUT"<<endl;
			}
		 	
		 }
		 else if(b=='6')
		 {
		 	cout<<"\t enter the name whom record you want to see"<<endl;
		 	cin>>profname;
		 		tajore<<"\t enter the name whom record you want to see"<<endl;
		 	tajore<<profname;
		 		pke_tajore<<"\t enter the name whom record you want to see"<<endl;
		 	pke_tajore<<profname;
		 	obj.searchkey(profname);
		 }
		 else if(b=='e'||b=='E')
		 {
		 	cout<<"GOOD BYE MR.............."<<endl;
		 	tajore<<"GOOD BYE MR.............."<<endl;
		 	pke_tajore<<"GOOD BYE MR.............."<<endl;
		 	break;
		 }
		 else if(b=='7')
		 {
		 	cout<<"all data on file"<<endl;
		 	string line;
		 	ifstream obj("pkedsapro.txt");
		 	if(obj.is_open())
		 	{
		 		while(!obj.eof())
		 		{
		 			obj>>line;
		 			cout<<line<<endl;
				 }
				 obj.close();
			 }
		 	
		 }
		 	 else if(b=='8')
		 {
		 	cout<<"all data on file"<<endl;
		 	string lin;
		 	ifstream ob("dsapro.txt");
		 	if(ob.is_open())
		 	{
		 		while(!ob.eof())
		 		{
		 			ob>>lin;
		 			cout<<lin<<endl;
				 }
				 ob.close();
			 }
		 	
		 }
//		 else if(b=='9')
//		 {
//		 	cout<<"enter the key whom you want to delete data"<<endl;
//		 	int dog,b;
//			 cin>>dog;
//			 ifstream file("dsapro.txt")
//			 while(file>>b)
//			 if(b!=dog)
//			 {
//			 	
//			 }
//		 }
		 else
		 {
		 	cout<<"INVALID INPUT"<<endl;
		 	tajore<<"INVALID INPUT"<<endl;
		 	pke_tajore<<"INVALID INPUT"<<endl;
		 	
		 }
		 
	 }//while(b!='e'||b!='E');
}
tajore.close();
}
//	 while(b!='e'||b!='E')
//	 {
//	 
//      		cout<<"ENTER THE PROFESSOR NAME"<<endl;
//	 		cin>>profname;
//	 		cout<<"ENTER THE PROFESSOR GENDER"<<endl;
//	 	    cin>>profgender;
//	 	    cout<<"ENTER THE PROFESSOR QUALIFICATION"<<endl;
//	 	    cin>>profqualification;
//	 	    cout<<"ENTER PROFESSOR SALARY"<<endl;
//	 	    cin>>profsalary;
//	 	    cout<<"ENTER THE PROFESSOR NATIONALITY"<<endl;
//	 	    cin>>profnationality;
//obj.addtail(1,profname,profgender,profqualification,profsalary,profnationality);				
//}
//obj.dtraverse();
//}
//}






































//	 cin>>b;
	 //while(b!='e'||b!='E')
	// {
	 	
	 //	if (b=='1')
	 //	{
	 	//	for(int i=1;i<=3;i++)
	 	//	{
//	 		cout<<"ENTER THE PROFESSOR NAME"<<endl;
//	 		getline(cin,profname);
//			 
//	 		cout<<"ENTER THE PROFESSOR GENDER"<<endl;
//	 	    getline(cin,profgender); 
//	 	    
//	 	    cout<<"ENTER THE PROFESSOR QUALIFICATION"<<endl;
//	 	    getline(cin,profqualification);
//			   
//	 	    cout<<"ENTER PROFESSOR SALARY"<<endl;
//	 	    cin>>profsalary;
//	 	     
//	 	    cout<<"ENTER THE PROFESSOR NATIONALITY"<<endl;
//	 	    getline(cin,profnationality);
//	 	     
//			obj.addtail(1,profname,profgender,profqualification,profsalary,profnationality);
//		//	}
//			obj.dtraverse();
//	//	}
	 //}
    
    
    
    
    
    



//}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
//	dlinklist obj;
//	obj.addtail(1,"mujtaab","male","bscs","pakistani");
//		obj.addtail(2,"mujtaba","male","bscs","pakistani");
//			obj.addtail(3,"zaheer","male","bscs","pakistani");
//				obj.addtail(4,"rohan","male","bscs","pakistani");
//					obj.addtail(5,"nawab","male","bscs","pakistani");
//					obj.dtraverse();
//					obj.insert(6,"syeda tahira","female","mba","pakistani",4);
//					cout<<"\n\n";
//		cout<<"after insert"<<endl;
//		obj.dtraverse();
//	obj.searchkeyedit("syeda tahira");
//	cout<<"after edit traversing"<<endl;
//	obj.dtraverse();
//	obj.searchkey("zaheer");
//	
	
	
	
	
	
	
	
	
	
	
	
	
//	dlinklist obj;
//	obj.addhead(1,"moon","male","pak");
//	obj.addhead(2,"tahira","female","pak");
//	obj.addhead(3,"zahira","female","pak");
//	obj.addhead(4,"ali hassan","male","pak");
//	//obj.searchkey("zahira");
//	//obj.searchkeyedit("zahira");
////	obj.dtraverse();
////	obj.delall();
////	obj.dtraverse();
//obj.insert(5,"mooooon","male","pak",3);
//obj.dtraverse();
//}
