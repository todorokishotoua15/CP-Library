struct Point {
    int x,y;
    Point(int a, int b) : x(a), y(b) {}
    Point() {}
    
    friend istream &operator >> (istream &in, Point &p) {
        int x,y;
        in >> p.x >> p.y;
        return in;
    }

    bool operator==(Point &other) {
        return (x == other.x && y == other.y);
    }

};

// Finding area of polygon - Shoelace formula https://en.wikipedia.org/wiki/Shoelace_formula

int dot_product (Point p1, Point p2, Point p3, Point p4) {
    int i1 = p2.x-p1.x;
    int i2 = p2.y-p1.y;
    int i3 = p4.x-p3.x;
    int i4 = p4.y-p3.y;

    return (i1*i3 + i2*i4);
}

int cross_product (Point p1, Point p2, Point p3, Point p4) {
    int i1 = p2.x-p1.x;
    int i2 = p2.y-p1.y;
    int i3 = p4.x-p3.x;
    int i4 = p4.y-p3.y;

    return (i1*i4 - i2*i3);
}

int sign(int x) {
    if (x == 0) return 0;
    if (x < 0) return -1;
    return 1;
}