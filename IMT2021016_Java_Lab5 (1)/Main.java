import java.util.*;

public class Main {

    public static void main(String[] args) {

        // List of all TVs and Mattresses
        ArrayList<Tv> tvs = new ArrayList<Tv>();
        ArrayList<Mattress> mat = new ArrayList<Mattress>();
        
        Scanner inp = new Scanner(System.in);

        // inputs
        while (true) {
            String name = inp.next();

            if (name.equals("End") ) {
                break;
            }

            String brand_or_typ = inp.next();
            
            if (name.equals("TV")) {
                String type = inp.next();
                int size = inp.nextInt();
                int price = inp.nextInt();
                int rating = inp.nextInt();

                Tv tv1 = new Tv(brand_or_typ,type,size,price,rating); // add the tv
                tvs.add(tv1);
            }

            else {
                int wid = inp.nextInt();
                int len = inp.nextInt();
                int deliver = inp.nextInt();
                int price = inp.nextInt();

                Mattress mat1 = new Mattress(brand_or_typ, wid, len, deliver, price); // add the mattress
                mat.add(mat1);
            }

        }

        // Sorting
        while (true) {
            String name = inp.next();

            if (name.equals("End")) break;

            if (name.equals("TV")) {
                Sort<Tv> sort1 = new Sort<Tv>();
                String t1 = inp.next();
                ArrayList<Tv> arr = new ArrayList<Tv>();

                if (t1.equals("Brand")) {
                    arr = sort1.srt(tvs, new brand_comp());
                } 

                if (t1.equals("Type")) {
                    arr = sort1.srt(tvs, new display_comp());
                }

                else if (t1.equals("Price")) {
                    arr = sort1.srt(tvs, new price_comp());
                }

                else if (t1.equals("Size")) {
                    arr = sort1.srt(tvs, new size_comp());
                }

                else if (t1.equals("Rating") ) {
                    arr = sort1.srt(tvs, new rating_comp());
                }

                for (Tv tv : arr) {
                    System.out.println(tv.info());
                }
            }

            else {
                Sort<Mattress> sort1 = new Sort<Mattress>();
                String t1 = inp.next();
                ArrayList<Mattress> arr = new ArrayList<Mattress>();

                if (t1.equals("Type")) {
                    arr = sort1.srt(mat, new typ_comp());
                } 

                else if (t1.equals("Price")) {
                    arr = sort1.srt(mat, new price_comp_mat());
                }

                else if (t1.equals("DeliveryTime") ) {
                    arr = sort1.srt(mat, new delivery_comp());
                }

                else if (t1.equals("Width")) {
                    arr = sort1.srt(mat, new wid_comp());
                }

                else if (t1.equals("Length")) {
                    arr = sort1.srt(mat, new len_comp());
                }

                for (Mattress mats : arr) {
                    System.out.println(mats.info());
                }
            }
        }
    }
}
