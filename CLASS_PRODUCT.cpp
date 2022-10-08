#include<iostream>
#include<string>
using namespace std;
/*class shop
{
	
};*/
class product    //:public shop
{
	private:
	  string product_name;
	  int product_id,product_price;
	  int ch,b,p,nb,c1;
    public:
	  void total_product()
	  {
        cout<<"\t\t\t\t\t!.....PRODUCTS.....!"<<endl;
        cout<<"----------------------------------------------------------------------------------------------"<<endl;
		cout<<"\t\t*TYPE*\t\t\t*Brands available*\t\t*Quantity*\t\t"<<endl;
		cout<<"----------------------------------------------------------------------------------------------"<<endl;
		cout<<"\t\tBOOK\t\t\t4+\t\t\t\t100+\t\t"<<endl;
		cout<<"\t\tPEN\t\t\t4+\t\t\t\t100+\t\t"<<endl;
	    cout<<"\t\tNOTEBOOK\t\t4+\t\t\t\t100+\t\t"<<endl;
	    //cout<<"|\t\t \t\t\t4+\t\t\t\t100+\t\t|";
		cout<<"----------------------------------------------------------------------------------------------"<<endl;                                                                                 
      }
      void get_detail()
      {
      	cout<<"\t\t\t\t\t!....Product Details....!"<<endl;
      	do
      	{
      	cout<<"Enter Your Choice Dear Customer:\nFor Books-Press 1\nFor Pen-Press 2\nFor Notebook-Press 3\n";
      	cin>>ch;
      	switch(ch)
      	{
		  case 1:
		  	cout<<"Select your Book:\n1)Let us See\n2)OOP with C++ by E Balguruswami\n3)Design Pattern\n";
		  	cin>>b;
		    switch(b)
		   {
		    	case 1:
		  	    	cout<<"\n'Let us see...!' \nPRICE : Rs.265 \n\nEditions Available :\nAll Editions are upto 17th...!\n"; 
		  	    	break;
		  	   	case 2:
		  	    	cout<<"\n'OOP with C++ by E Balguruswami...!' \nPRICE : Rs.400 \n\nEditions Available :\nAll Editions are upto 8th...!\n"; 
		  	    	break;
				case 3:
		  	    	cout<<"\n'Design Pattern...!(GOF:Erich Gamma , Richard Helm , Ralph Johnson , John Vlissides)' \nPRICE : Rs.600 \n\nEditions Available :\nAll Editions are upto 2th...!\n";   
					break; 
	       }
	       break;
	      case 2:
		    cout<<"Select Your PEN :\n1)Ballpens\n2)Gelpens\n3)Fountain Pens\n4)Marker Pens\n";
			cin>>p;
			switch(p)
			{
				case 1:
					cout<<"Ballpens : \n Brands and Prices::: \nReynold : Rs.5 \n Rorito : Rs.5 \n Cello : Rs.5\n";
					break;
				case 2:
					cout<<"Gelpens : \n Brands and Prices::: \nRacer Gel by Reynold : Rs.5 \n Fibre Point by Rorito : Rs.5 \n Nataraj Gelix: Rs.5\n";
					break;
				case 3:
					cout<<"Fountain pens : \n Brands and Prices::: \nParkar : Rs.259 \n Cello Fountain : Rs.59 \n PIERRE cardin : Rs.313\n";
					break;
				case 4:	
				    cout<<"Marker pens : \n Brands and Prices::: \nCopic : Rs.(100-5000) \n Staedtler : Rs.(10-100) \n Uni-poska : Rs.(100-2000)\n";
				    break;
			}	
			break;
		  case 3:
		  	cout<<"Select Your NOTEBOOK :\n1)Classmate\n2)Regal\n3)Golden Touch\n4)Youva\n";
		  	cin>>nb;
		  	switch(nb)
		  	{
		  		case 1:
		  			cout<<"CLASSMATE : \n Notebook: Rs.(35-100)\n Drawing Notebook: Rs.65\n";
		  			break;
		  		case 2:
		  			cout<<"Regal : \n Notebook: Rs.(35-100)\n";
		  			break;
		  		case 3:
		  			cout<<"Golden Touch : \n Notebook: Rs.(35-100)\n";
		  			break;
		  		case 4:
		  			cout<<"Youva : \n Notebook: Rs.(35-100)\n";
		  			break;
			}
			break;
	    }
	    cout<<"\nWant to Know more about products : press 1 ---";
        cin>>c1;    
	    }while(c1==1);
	  }
};
int main()
{
	int pr,c2;
	product p;
	do
	{
	cout<<"Products In our Stationary ::\n1)Products\n2)Get Detail about all the Products-\n";
	cin>>pr;
	switch(pr)
	 { 
		case 1:
			p.total_product();
			break;
		case 2:
			p.get_detail();
			break;
	 }
	   cout<<"\nIf u have got,Which products are there in our Stationary the get detail about that....!";
        cin>>c2;    
    }while(c2==1);
//	p.total_product();
//	p.get_detail();
	return 0;
}
