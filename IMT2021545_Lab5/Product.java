public class Product {

    protected String type;
    protected int price;
    //setter method
    void setVals(String t,int p){
        type=t;
        price=p;
    }

    //getter methods
    String getType(){
        return type;
    }

    int getPrice(){
        return price;
    }

    String getBrand(){
        return "";
    }

    int getSize(){
        return 0;
    }

    int getRating(){
        return 0;
    }
    
    int getLength(){
        return 0;
    }

    int getWidth(){
        return 0;
    }
    
    int getDeltime(){
        return 0;
    }
}
