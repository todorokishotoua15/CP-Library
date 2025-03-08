public class Mattress extends Product {
    
    private int length;
    private int width;
    private int deltime;
    //setter method
    void setVals(String type,int w,int l,int d,int p)
    {
        length=l;
        width=w;
        deltime=d;
        super.setVals(type,p);
    }
    //getter methods
    int getLength(){
        return length;
    }

    int getWidth(){
        return width;
    }
    
    int getDeltime(){
        return deltime;
    }
}