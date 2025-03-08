import java.util.*;

public class Tv {

    // data
    private String brand, display;
    private Integer size, price, rating;

    // constructor to set data
    public Tv(String brnd, String dis, int sz, int prc, int rt) {
        brand = brnd;
        display = dis;
        size = sz;
        price = prc;
        rating  = rt;
    }

    // All the info of the tv
    public String info() {
        String inf = "TV " + brand + " " + display + " " + String.valueOf(size) + " " + String.valueOf(price) + " " + String.valueOf(rating);
        return inf;
    }

    // get methods
    public String get_brand(){
        return brand;
    }

    public String get_display(){
        return display;
    }

    public Integer get_size() {
        return size;
    }

    public Integer get_price() {
        return price;
    }

    public Integer get_rating() {
        return rating;
    }

}
