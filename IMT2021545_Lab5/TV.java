public class TV extends Product {

    private String brand;
    private int size;
    private int rating;

    //setter method
    void setVals(String b,String t,int s,int p,int r)
    {
        brand=b;
        rating=r;
        size=s;
        super.setVals(t,p);
    }

    //getter methods
    String getBrand(){
        return brand;
    }

    int getSize(){
        return size;
    }
    
    int getRating(){
        return rating;
    }
}
