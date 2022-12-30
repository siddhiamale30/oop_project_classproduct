#include<iostream>
#include<iomanip>
#include<conio.h>
#include<cstring>
#include<stdlib.h>
#include<fstream>


using namespace std;
fstream file,file1;
class shop_owner
{
protected:
	  string owner_name;
	  long owner_contact,wor_con;
	  string shop_name;
	  
	  int num,num1;
	public:
	  shop_owner()
	  {
		shop_name="STATIONARY HOUSE";
		owner_name="Kanchan Patil";
		owner_contact=1234567890;
	  }
	  
	  void disdata()
	  {
	  	cout<<"SHOP\n"<<shop_name<<"\nOwner name::"<<owner_name<<"\nOwner contact:"<<owner_contact;
	  }
};
 
 
class product:public shop_owner
{
	protected:
	int product_number;
	string p_name;
	float price,qty,tax,dis;
public:
		void create();
		void show();
		void write();
		void display();
		void shop();
		void search(int n);
		void modify(int n);
		void del(int n);
		void menu();
	
 } ;
 
 
 class customer:public product
 {
 	public:
 		void order();
 };
 void product::create()
 {
 	cout<<"\n\n Please Enter the product number:";
 	cin>>product_number;
 	cout<<"\n\n Please Enter the name of the product:";
 	cin>>p_name;
 	cout<<"\n\n Please Enter the price of product:";
 	cin>>price;
 	cout<<"\n\n Please Enter the Discount(%):";
 	cin>>dis;
 }
 
 
 void product::show()
 {
 	cout<<"\n The product no.of the product:"<<product_number;
 	cout<<"\n The name of the product:"<<p_name;
 	cout<<"\n The price of the product:"<<price;
 	cout<<"\n Discount:"<<dis<<"%";	
 }
 
 void product::write()
 {
 	char ch;
 	do
	 {
	file.open("shop.txt",ios::out|ios::app);
 	create();
 	file<<" "<<product_number<<" "<<p_name<<" "<<price<<" "<<dis;
 	file.close();
 	cout<<"\n\n The product has been created";
 	getch();
 	cout<<"\n\nDo you Want to Add more product(Y/N):";
 	cin>>ch;
	 }while(ch=='y'||ch=='Y');
 
 }
 void product::display()
 {
 	system("cls");
 	cout<<"\n\n\n\t\t DISPLAY ALL RECORD!!!\n\n";
 	file.open("shop.txt",ios::in);
 	if(!file)
 	shop();
 	file>>product_number>>p_name>>price>>dis;
 	while(!file.eof())
 	{
 		show();
 		cout<<"\n\n==================================\n\n";
 		file>>product_number>>p_name>>price>>dis;
	 }
	 file.close();
	 getch();
}


void product::search(int n)
{
	int found=0;
	file.open("shop.txt",ios::in);
	if(!file)
	shop();
	file>>product_number>>p_name>>price>>dis;
	while(!file.eof())
	{
		if(product_number==n)
		{
			system("cls");
			show();
			found=1;
			
		}
		file>>product_number>>p_name>>price>>dis;
	}
	file.close();
	if(found==0)
	cout<<"\n\n RECORD NOT EXIST";
	getch();
}
 
 
 void product::modify(int n)
 {
 	int found=0;
 	system("cls");
 	cout<<"\n\n\t To Modify";
 	file.open("shop.txt",ios::in);
 	if(!file)
 	shop();
 	file1.open("shop.txt",ios::out|ios::app);
 	file>>product_number>>p_name>>price>>dis;
 	while(!file.eof())
{
	if(product_number==n)
	{
		show();
		cout<<"\n\n Please Enter New Detail";
		create();
		file1<<" "<<product_number<<" "<<p_name<<" "<<price<<" "<<dis<<endl;
		cout<<"\n\n\t Record Updated";
		found=1;	
	}
	else
	file1<<" "<<product_number<<" "<<p_name<<" "<<price<<" "<<dis<<endl;
	file>>product_number>>p_name>>price>>dis;
	 } 	
	 file.close();
	 file1.close();
	 remove("shop.txt");
	 rename("shop1.txt","shop.txt");
	 if(found==0)
	 cout<<"\n\n Record Not Found";
	 getch(); 
 }
 
 void product::del(int n)
 {
 	int found=0;
 	file.open("shop.txt",ios::in);
 	if(!file)
 	shop();
 	file1.open("shop1.txt",ios::out);
 		file>>product_number>>p_name>>price>>dis;
 		while(!file.eof())
 		{
 			if(product_number==n)
 			{
 				cout<<"\n\n\t Record Deleted";
 				found=1;	
			 }
			 else
			    file1<<" "<<product_number<<" "<<p_name<<" "<<price<<" "<<dis<<endl;
			 	file>>product_number>>p_name>>price>>dis;
		 }
		 file.close();
		 file1.close();
		 remove("shop.txt");
		 rename("shop1.txt","shop.txt");
		 if(found==0)
		 cout<<"\n\n Record Not Found";
		 getch();
 }
 void product::menu()
 {
 	system("cls");
 	file.open("shop.txt",ios::in);
 	cout<<"\n\n\t\t\t\t Product Menu\n\n";
 	cout<<"===================================================================================";
 	cout<<"\nPRODUCT_NUMBER\t\tNAME\t\t\tPRICE\t\t\tDISCOUNT\n";
 	cout<<"===================================================================================\n";
 	file>>product_number>>p_name>>price>>dis;
 	while(!file.eof())
 	{
 		cout<<product_number<<"\t\t\t"<<p_name<<"\t\t\t"<<price<<"\t\t\t"<<dis<<"\n";
 		file>>product_number>>p_name>>price>>dis;
	 }
	 file.close();
 }
 
 void customer::order()
 {
 	int order_arr[50],quan[50],c=0;
 	float amount=0,dis_amount=0,total=0;
 	char ch;
 	file.open("shop.txt",ios::in);
 	if(file)
 	{
 	file.close();
	 menu();
	 cout<<"\n\t\t\t\t===========================";
	 cout<<"\n\t\t\t\t    PLACE YOUR ORDER";
	 cout<<"\n\t\t\t\t===========================\n";
	 do
	 {
	 	cout<<"\n\n Enter the product number:";
	 	cin>>order_arr[c];
	 	cout<<"\n Quantity in number:";
	 	cin>>quan[c];
	 	c++;
	 	cout<<"Do You Want to another Product(Y/N)";
	 	cin>>ch;
		 }while(ch=='y'||ch=='Y');
		 cout<<"\n\n Thank You For Placing Order";
		 getch();
		 system("cls");
		 cout<<"\n\n****************************************INVOICE*****************************************************************\n";
		 cout<<"\nProduct Number\tProduct Name\tQuantity\tAmount\tAmount After Discount\n";
		 for(int x=0;x<=c;x++)
		 {
		 	file.open("shop.txt",ios::in);
		 	file>>product_number>>p_name>>price>>dis;;
		 	while(!file.eof())
		 	{
		 		if(product_number==order_arr[x])
		 		{
		 			amount=price*quan[x];
		 			dis_amount=amount-(amount/100*dis);
		 			cout<<"\n"<<order_arr[x]<<"\t\t"<<p_name<<"\t\t"<<quan[x]<<"\t\t"<<price<<"\t\t"<<amount;
		 			total+=dis_amount;
				 }
				 file>>product_number>>p_name>>price>>dis;
			 }
			 file.close();
		 }
		 cout<<"\n\n\t\t\t\t\t\t\t TOTAL="<<total;
		 getch();
    } 
 }
  
 void product::shop()
 {
 system("cls");
 int choice;
 cout<<"\n\n\n\t SHOP OWNER MENU";
 cout<<"\n\n\t1.Shop Details";
  cout<<"\n\n\t2.ADD PRODUCT";
   cout<<"\n\n\t3.DISPLAY ALL PRODUCTS";
    cout<<"\n\n\t4.SEARCH PRODUCT";
     cout<<"\n\n\t5.MODIFY PRODUCT";
      cout<<"\n\n\t6.DELETE PRODUCT";
       cout<<"\n\n\t7.VIEW PRODUCT MENU";
        cout<<"\n\n\t8.BACK TO MAIN MENU";
        cout<<"\n\n\tPlease Enter Choice(1-7):";
        cin>>choice;
        switch(choice)
        {
        	case 1:
        		system("cls");
        		shop_owner();
        		disdata();
	            break;
	            case 2:
	            	write();
	            	break;
	            		case 3:
	            			display();
	            			break;
	            			case 4:
	            				int num;
	            				system("cls");
	            				cout<<"\n\n\t Please Enter the Product Number:";
	            				cin>>num;
	            				search(num);
	            				break;
	            				case 5:
	            			    system("cls");
	            				cout<<"\n\n\t Please Enter the Product Number:";
	            				cin>>num;
	            				modify(num);
	            				break;
	            				case 6:
	            					system("cls");
	            					cout<<"\n\n\t\t\t\t Delete Record";
	            					cout<<"\n\n Please Enter The Product Number:";
	            					cin>>num;
	            					del(num);
	            					break;
	            					case 7:
	            						menu();
	            						getch();
	            						break;
	            						case 8:
	            							default:
	            								cout<<"\a";
	            								shop();					
		} 
  } 
  int main()
  {
  	cout << endl
		 << endl
		 << "You'r in the Stationary Management System ......... Prepared by Achievers" << endl
		 << endl;
  
  			for(int i=1 ; i<=3 ; i++)
	{
	string user,pass;
	int ch;
	cout<<"USERNAME : : ";
	cin>>user;
	cout<<"PASSWORD  :: ";
	ch=getch();
	
	while(ch!=13 )
    {
        pass.push_back(ch);
        cout<<'*';
        ch=getch();
    }
	cout<<endl;
	try {
		if((user=="stationary"|| user=="STATIONARY" )&& pass=="2003")
		{
				int choice,ch3;
  	customer c;
  	a:
			do{
					system("cls");
  	cout<<"\n\n\n\t\t\t\t\tMAIN MENU";
  	cout<<"\n\n\n\t1.SHOP OWNER";
  	cout<<"\n\n\n\t2.CUSTOMER";
  	cout<<"\n\n\n\t3.EXIT";
  	cout<<"\n\n\t Please Select Your Option(1-3):";
  	cin>>choice;
  	switch(choice)
  	{
  		case 1:
  			system("cls");
  			c.shop();
  			getch();
  			break;
  	    case 2:
  	    	c.order();
  	    	break;
  	    	case 3:
  	    		exit(0);
  	    		default :
  	    			cout<<"\a";
	  }
	  goto a;
}while(ch!=4);
				
			}
				else
	{
		throw pass;
	}
	}
	catch(...)
	{
		cout<<"Username or Password is Incorrect "<<endl<<endl;
		cout<<3-i<<" : Chance Left " <<endl<<endl;
		if(3-i==0)
		cout<<"Sorry... \n We Can't allow You ";
	}
	}
  	
  
	  return 0;
  }