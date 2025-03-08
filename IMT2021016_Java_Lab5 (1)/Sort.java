
import java.util.*;

// Sort a general class
public class Sort<T> {
    public ArrayList<T> srt(ArrayList<T> arr, Comparator<T> c) {
        ArrayList<T> arr1 = new ArrayList<T>();
        for (T t : arr) arr1.add(t);
        Collections.sort(arr1, c);

        return arr1;
    }
}
