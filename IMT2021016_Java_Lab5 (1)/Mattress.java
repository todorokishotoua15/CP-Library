
import java.util.*;
public class Mattress {
    // Data
    private String type;
    private Integer width, length,price, delivery;

    // Constructor
    public Mattress(String typ, int wid, int len, int deliver, int pric) {
        type = typ;
        width = wid;
        length = len;
        price = pric;
        delivery = deliver;
    }

    // Info of the mattress
    public String info() {
        String inf = "Mattress " + type + " " + String.valueOf(width) + " " + String.valueOf(length) + " " + String.valueOf(delivery) + " " + String.valueOf(price);
        return inf;
    }

    // Method to get data
    public String get_type() {
        return type;
    }

    public Integer get_width() {
        return width;
    }

    public Integer get_length() {
        return length;
    }

    public Integer get_price() {
        return price;
    }
    public Integer get_delivery() {
        return delivery;
    }


}
