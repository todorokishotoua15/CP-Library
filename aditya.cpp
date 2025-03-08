#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<bits/stdc++.h>

using namespace std;



class Bakery {
	int id;  //this class contains the attributes such as ID-number and an arraylist of orders
    vector<string> rb;//to store the ordered item information, its name
    public:
        Bakery(int n,vector<string> arrs){
            id=n;
            rb=arrs;
        }
        int getId()//returns the id of the order
        {
            return id;
        }
        void takeAway(string s,int i,int k)
        {
     
            rb.push_back("Order "+to_string(i)+" "+s+" "+to_string(k));
        }
        vector<string> getItems()//to return the items ordered from bakery
        {
            return rb;
        }
};

class Dairy {
    int id;  //class Dairy has attributes idnumber and an arraylist of orders. 
    vector<string> rd;
    public:
        Dairy(int n,vector<string> arrs){
            id=n;
            rd=arrs;
        }
        int getId()//to obtain the id of the order from the dairy
        {
            return id;
        }
        void takeAway(string s,int i,int k)//to store the declaration or the message of the specific dairy
        {
            
            rd.push_back("Order "+to_string(i)+" "+s+" "+to_string(k));
        }
        vector<string> items()//to return the items ordered from Dairy
        {
            return rd;
        }
};

class Store 
{
    int bakno; //The Store class contains attributes number of bakeries and,
    int darno; //number of diaries.
    int b=0;
    int d=0;
    vector<Bakery> bak;
    vector<Dairy> dar;
    
    public:
    Store(int bno,int dno)
	{       
        bakno=bno;
        darno=dno;
        for(int i=0;i<bakno;i++) //to create objects of class Bakery
        {        
            vector<string> n;
            bak.push_back(Bakery(i+1,n));
        }
        for(int i=0;i<darno;i++) //to create objects of class Dairy
        {
            vector<string> n;
            dar.push_back(Dairy(i+1,n));
        }
        
    }

    vector<vector <string> > bakrec;  //to store the orders received from Bakery
    vector<vector <string> > darrec;  //to store the orders received from Dairy

    void takeorders(string orderType,int quantity,int ornum){
        
    	if(orderType=="Bread" or orderType=="Cake" or orderType=="Muffin")
    	{
           
            if(b==bakno)
            {
               b=0;
            }
             bak[b].takeAway(orderType,ornum,quantity);   //to request the order to a specific bakery
             b++;
        }
        else if(orderType=="Milk" or orderType=="Butter")
        {

            if(d==darno)
            {
                d=0;
            }
            dar[d].takeAway(orderType,ornum,quantity);   //to request the order to a specific dairy 
            d++;
        }
    }
    void over() {  //to get the items from the suppliers
        
        for(int i=0;i<bakno;i++)
        {   
            bakrec.push_back(bak[i].getItems());   
        }
        for(int i=0;i<darno;i++)//to add the store the info of orders in darrec
        {
            darrec.push_back(dar[i].items());   
        }
        for(int i=0;i<bakrec.size();i++)//to print the stored information in bakrec
        {
            cout<<"Bakery "<<bak[i].getId() << endl;
            for(int j=0;j<bakrec[i].size();j++)
            {
                cout<<bakrec[i][j]<<"\n";
            }
            cout<<'\n';
        }
        for(int i=0;i<darrec.size();i++)//to print the stored information in darrec
        {
            cout<<"Dairy "<<dar[i].getId() << endl;
            for(int j=0;j<darrec[i].size();j++)
            {
                cout<<darrec[i][j]<<"\n";
            }
            cout<<'\n';
        }
    }

};

class Orders {
    private:
	string itemtype; //the class Orders has attributes itemType, and 
	int quantity; //quantity

    public:
    int getQuantity(){return quantity;}
    string getItemType(){return itemtype;}
	void setVals(string s,int k)//method to set the values of itemType and quantity attributes   
	{

		itemtype=s;     
		quantity=k;
        
	}

};

class Inputs{
    vector<Orders> objl;
    public:
	Store takeOrders()
	{
		int bakno;
		int darno;
		cin>>bakno;
		cin>>darno;
        Store st=Store(bakno,darno);
		//Scanner scan1=new Scanner(System.in);
		
		while(true)
		{
			string s1;
			cin>>s1;       //taking the orders from user.
            
			if(s1!="End")
            {
               // String[] sa=s1.split(" ");
			   int ite;
			   cin>>ite;
                Orders num;        //creating an object of class Orders.
                
             
                num.setVals(s1,ite); //setting its values . 
                objl.push_back(num); 
            }
			else
            {
                break;
            }	
		}	
		return st;
	}
	public :vector<Orders> getOrders(){
		return objl;
	}
    friend class Orders;
};

int main()
{
    int i;
    vector<Orders> objord;
    Inputs inp;//declaring a object in the Inputs class
    Store str=inp.takeOrders(); 
    objord=inp.getOrders();  
     
    for(i=0;i<objord.size();i++)
    {
    	str.takeorders(objord[i].getItemType(),objord[i].getQuantity(),i+1); //to call the function takeorders in Store class
    } //the arguments used in this function are itemType,quantity and order number
    if(i==objord.size())
    {
    	str.over();  //to indicate and inform that the orders are complete
    } 
	return 0;
}