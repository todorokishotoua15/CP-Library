import java.util.Comparator;
public class sortMattress implements Comparator<Product>{
    
    private String attr;
    
    sortMattress(String str)
    {
        attr=str;
    }
    
    //sorting according to the delivery_time or time attribute
    public int compare(Product pfirst,Product psecond)
    {
        if(attr.equals("DeliveryTime")==true)
        {
            int del=pfirst.getDeltime()-psecond.getDeltime();
            if(del==0)
            {
                return pfirst.getPrice()-psecond.getPrice();
            }
            return pfirst.getDeltime()-psecond.getDeltime();
        }
        if(attr.equals("Type")==true){
            return pfirst.getType().compareTo(psecond.getType());
        }
        return pfirst.getPrice()-psecond.getPrice();
    }
}
