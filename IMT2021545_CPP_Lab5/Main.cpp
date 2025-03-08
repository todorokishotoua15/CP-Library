#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include"Listing.h"
int main()
{

  Listing* list = new Listing();  // listing class instance

  //to take input from the user
  int c=1;
  while(c!=0)
  {
    
    string prod;
    cin>>prod;
    // creating and adding appropriate products
    if(prod=="Mattress")
    {
      string type;
      int width,length,deltime,price;
      Product *product=new Mattress();
      cin>>type>>width>>length>>deltime>>price;
      product->set_valmat(type,width,length,deltime,price);
      list->addMattress(product);
    }
    else if(prod=="TV")
    {
      string brand,type;
      int size,price,rating;
      Product *product=new TV();
      cin>>brand>>type>>size>>price>>rating;
      product->set_valtv(brand,type,size,price,rating);
      list->addTv(product);
    }
    else if(prod=="End")
    {
      c=0;
    }
  }
  c=1;
  while(c!=0)
  {
    string prod_type;
    cin>>prod_type;
    
    // taking listing input and sorting accodingly
    if(prod_type=="TV")
    {
      string attr;
      cin>>attr;

      vector<Product*> temp_tv = list->getTvlist();
      list->sorting(temp_tv,attr,prod_type);

      for (auto it : temp_tv) {
        it->getInfo();
      }
    }
    else if(prod_type=="Mattress")
    {
      string attr;
      cin>>attr;

      vector<Product*> temp_mat = list->getMatlist();

      list->sorting(temp_mat,attr,prod_type);

      for (auto it : temp_mat) {
        it->getInfo();
      }
    }
    else if(prod_type=="End")
    {
      c=0;
    }

  }
  return 0;
}
