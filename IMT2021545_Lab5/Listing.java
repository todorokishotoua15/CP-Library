import java.util.ArrayList;
import java.util.*;
public class Listing {
    ArrayList<Product> tvs=new ArrayList<>();
    ArrayList<Product> mattresses=new ArrayList<>();
    
    void sortList(ArrayList<Product> products,String rand,String p)
    {
        if(p.equals("Mattress")==true)
        {
           for(int i=0;i<products.size();i++)
           {
                mattresses.add(products.get(i));
           } 
           //to sort according to the specific attribute
           Collections.sort(mattresses,new sortMattress(rand));
           
           //printing the desired output
           for(int i=0;i<mattresses.size();i++)
           {
                System.out.println("Mattress"+" "+mattresses.get(i).getType()+" "+mattresses.get(i).getWidth()+" "+mattresses.get(i).getLength()+" "+mattresses.get(i).getDeltime()+" "+mattresses.get(i).getPrice());
           }
        }
        if(p.equals("TV")==true)
        {
            for(int i=0;i<products.size();i++)
            {
                tvs.add(products.get(i));
            }
            //to sort according to the specific attribute
            Collections.sort(tvs,new sortTV(rand));

            //printing the desired output
            for(int i=0;i<tvs.size();i++)
            {
                System.out.println("TV"+" "+tvs.get(i).getBrand()+" "+tvs.get(i).getType()+" "+tvs.get(i).getSize()+" "+tvs.get(i).getPrice()+" "+tvs.get(i).getRating());
            }
        }
    }
}