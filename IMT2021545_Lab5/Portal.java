import java.util.ArrayList;
import java.util.*;
public class Portal{
    ArrayList<Product> tv=new ArrayList<>();
    ArrayList<Product> mattress=new ArrayList<>();
    public void takeInput(){

        //to start to take input from the user
        
        Scanner sc=new Scanner(System.in);
        while(true){
            String object;
            object=sc.next();
            //checking the product name and adding to the respective arraylist
            if(object.equals("TV")==true){
                String brand,type;
                int size,price,rating;
                brand=sc.next();
                type=sc.next();
                size=sc.nextInt();
                price=sc.nextInt();
                rating=sc.nextInt();
                TV t=new TV();
                t.setVals(brand,type,size,price,rating);
                tv.add(t);
            }
            else if(object.equals("Mattress")==true){
                String type;
                int width,length,p,deltime;
                type=sc.next();
                width=sc.nextInt();
                length=sc.nextInt();
                deltime=sc.nextInt();
                p=sc.nextInt();
                Mattress m=new Mattress();
                m.setVals(type, width, length, deltime, p);
                mattress.add(m);
            }
            else{
                break;
            }
        }
        while(true){
            String objectstr,attr;
            objectstr=sc.next();
            if(objectstr.equals("TV")==true){
                attr=sc.next();
                Listing ls=new Listing();
                ls.sortList(tv,attr,"TV");
            }
            else if(objectstr.equals("Mattress")==true){
                attr=sc.next();
                Listing ls=new Listing();
                ls.sortList(mattress,attr,objectstr);
            }
            else{
                break;
            }
        }
    }
}
