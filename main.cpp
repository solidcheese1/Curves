#include "task1.h"

int main()
{

    Circles s(4);
    Ellipse e(3, 6);
    Helixes h(5, 1);
    Container con;
    con.add(s);
    con.add(e);
    con.add(h);

    Circles s2(6);
    con.add(s2);
    Circles s3(5);
    con.add(s3);
    Ellipse e2(3, 6);
    con.add(e2);
    Circles s4(0.5);
    con.add(s4);
    con.sortCircles();
    std::cout << con.sumCircles();
    Curves* fig = con.get(0);
    Point p = fig->point(M_PI / 2);
    p.Print();
}