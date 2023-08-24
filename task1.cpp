// task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "task1.h"
Point::Point(double X, double Y, double Z) {
    x = X;
    y = Y;
    z = Z;

};
void Point::Print() {
    std::cout << " ( " << x << " , " << y << " , " << z << " )" << std::endl;
};

Circles::Circles(double R) {
    r = R;
};
Point Circles::point(double param) {
    double x = r * cos(param);
    double y = r * sin(param);
    return Point(x, y, 0);

};
Point Circles::Derivative(double param) {
    double x = -r * sin(param);
    double y = r * cos(param);
    return Point(x, y, 0);

}
double Circles::getR() {
    return r;
}

Ellipse::Ellipse(double A, double B) {
    a = A;
    b = B;
}
Point Ellipse::point(double param) {
    double x = a * cos(param);
    double y = b * sin(param);
    return Point(x, y, 0);

}
Point Ellipse::Derivative(double param) {
    double x = -a * sin(param);
    double y = b * cos(param);
    return Point(x, y, 0);
}

Helixes::Helixes(double R, double Step) {
    r = R;
    step = Step;

};
Point Helixes::point(double param) {
    int n = 0;
    double x = r * cos(param);
    double y = r * sin(param);
    // double delta_h = step / 2 * M_PI;
    double z = param * (step / (2 * M_PI));
    return Point(x, y, z);

}
Point Helixes::Derivative(double param)
{
    double x = -r * sin(param);
    double y = r * cos(param);
    double z = step / (2 * M_PI);
    return Point(x, y, z);
}

//int main()
//{
//    
//    Circles s(4);
//    Ellipse e(3, 6);
//    Helixes h(5, 1);
//    Container con;
//    con.add(s);
//    con.add(e);
//    con.add(h);
//
//    Circles s2(6);
//    con.add(s2);
//    Circles s3(5);
//    con.add(s3);
//    con.sortCircles();
//    Curves* fig = con.get(0);
//    Point p = fig->point(M_PI / 2);
//    p.Print();
//}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

void Circles_from_container::add(Circles& s)
{
    c.push_back(&s);
}

Circles* Circles_from_container::get(size_t position)
{
    return c[position];
}



void Container::add(Circles& s)
{
    figures.push_back(&s);
    x.add(s);
}

void Container::add(Ellipse& s)
{
    figures.push_back(&s);
}

void Container::add(Helixes& s)
{
    figures.push_back(&s);
}

Curves* Container::get(int position)
{
    if (position < figures.size()) {
        return figures[position];
    }
    else return nullptr;
}

void Container::sortCircles()
{
    std::sort(x.c.begin(), x.c.end(), [](Circles* circle1, Circles* circle2) {
        double r1 = circle1->getR();
        double r2 = circle2->getR();
        return r1 < r2;
        });
    //x.sortCirles();
}

double Container::sumCircles()
{
    double sum = 0;
    for (auto el : x.c) {
        sum = sum + (el->getR());


}
    return sum;
}
