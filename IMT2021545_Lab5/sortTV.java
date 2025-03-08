import java.util.*;
public class sortTV implements Comparator<Product> {
    private String attr;
    
    sortTV(String s)
    {
        this.attr=s;
    }

    public int compare(Product pfirst,Product psecond)
    {

        //sorting according to the brand or rating or type or price attribute
        if(attr.equals("Brand")==true){
            return pfirst.getBrand().compareTo(psecond.getBrand());
        }
        if(attr.equals("Rating")==true){
            int r=psecond.getRating()-pfirst.getRating();
            if(r==0){
                return pfirst.getPrice()-psecond.getPrice();
            }
            return psecond.getRating()-pfirst.getRating();
        }
        if(attr.equals("Type")==true){
            return pfirst.getType().compareTo(psecond.getType());
        }
        if(attr.equals("Price")==true){
            return pfirst.getPrice()-psecond.getPrice();
        }
        return pfirst.getSize()-psecond.getSize();
    }
}