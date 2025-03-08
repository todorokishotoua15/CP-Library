import java.util.*;


// Brand Comparator
class brand_comp implements Comparator<Tv> {

    @Override
    public int compare(Tv o1, Tv o2) {
        
        return o1.get_brand().compareTo(o2.get_brand());

    }

}

// Display Type comparator
class display_comp implements Comparator<Tv> {
    @Override
    public int compare(Tv o1, Tv o2) {
        
        return o1.get_display().compareTo(o2.get_display());

    }
}

// Price Comparator
class price_comp  implements Comparator<Tv> {
    
    @Override
    public int compare(Tv o1, Tv o2) {
        return o1.get_price().compareTo(o2.get_price());
    }

}

// Size Comparator
class size_comp implements Comparator<Tv> {

    @Override
    public int compare(Tv o1, Tv o2) {
        
        return o1.get_size().compareTo(o2.get_size());

    }

}

// Rating Comparator
class rating_comp implements Comparator<Tv> {

    @Override
    public int compare(Tv o1, Tv o2) {
        
        int a1 =  o1.get_rating().compareTo(o2.get_rating());
        a1 = -1*a1;
        return (a1 == 0 ? o1.get_price().compareTo(o2.get_price()) : a1);

    }

}
