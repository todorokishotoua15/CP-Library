#include <bits/stdc++.h>
#include "Product.h"
#include "Compare.h"

template<typename T>
int Compare<T>::compare(T* o1, T* o2, string obj, string typ) {
	if (obj == "TV") {
		if (typ == "Brand" || typ == "Type") {
			return o1->get_brand->compare(o2->get_brand);
		}
		if (typ == "Price") {
			return o1->get_price - o2->get_price;
		}
		if (typ == "Rating") {
			int a1 = o1->get_rating() - o2->get_rating();
			a1 *= -1;
			return (a1 == 0  ? o1->get_price()-o2->get_price() : a1);
		}
	}
	else if (obj == "Mattress") {
		if (typ == "Brand" || typ == "Type") {
			return o1->get_brand->compare(o2->get_brand);
		}
		if (typ == "Price") {
			return o1->get_price - o2->get_price;
		}
		if (typ == "Delivery time") {
			int a = o1->get_delivery() - o2->get_delivery();
			return (a == 0 ? o1->get_price() - o2->get_price() : a);
		}
	}

	return 0;
}