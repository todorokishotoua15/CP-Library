import java.util.*;


// Type comparator 
class typ_comp implements Comparator<Mattress> {

    @Override
    public int compare(Mattress o1, Mattress o2) {
        //System.out.println("hi " + o1.get_type() + " " + o2.get_type() + " " + o1.get_type().compareTo(o2.get_type()));
        return o1.get_type().compareTo(o2.get_type());
    }

}

// Price Comparator
class price_comp_mat  implements Comparator<Mattress> {

    @Override
    public int compare(Mattress o1, Mattress o2) {
        return o1.get_price().compareTo(o2.get_price());
    }

}

// Delivery Time Comparator
class delivery_comp  implements Comparator<Mattress> {

    @Override
    public int compare(Mattress o1, Mattress o2) {
        int a1 =  o1.get_delivery().compareTo(o2.get_delivery());

        return (a1 == 0 ? o1.get_price().compareTo(o2.get_price()) : a1);
    }

}

// Width Comparator
class wid_comp  implements Comparator<Mattress> {

    @Override
    public int compare(Mattress o1, Mattress o2) {
        int a1 =  o1.get_delivery().compareTo(o2.get_delivery());

        return (a1 == 0 ? o1.get_width().compareTo(o2.get_width()) : a1);
    }

}

// Length Comparator
class len_comp  implements Comparator<Mattress> {

    @Override
    public int compare(Mattress o1, Mattress o2) {
        int a1 =  o1.get_delivery().compareTo(o2.get_delivery());

        return (a1 == 0 ? o1.get_length().compareTo(o2.get_length()) : a1);
    }

}

