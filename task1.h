#pragma once

#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>

struct Point {
    double x;
    double y;
    double z;
    Point(double X, double Y, double Z);
    void Print();
};

class Curves {
public:
    virtual Point point(double param) = 0;
    virtual Point Derivative(double param) = 0;

};

class Circles : public Curves {
private:
    double r;

public:
    Circles(double R);
    Point point(double param);
    Point Derivative(double param);
    double getR();
};

class Ellipse : public Curves {
private:
    double a;
    double b;
public:
    Ellipse(double A, double B);
    Point point(double param);
    Point Derivative(double param);

};

class Helixes :public Curves {
private:
    double r;
    double step;
public:
    Helixes(double R, double Step);
    Point point(double param);
    Point Derivative(double param);

};

class Circles_from_container {
private:
    std::vector<Circles*> c;
    Circles_from_container() {};
    void add(Circles& s);
    Circles* get(size_t position);   

    friend class Container;
};

class Container {
private:
    std::vector<Curves*> figures;
    Circles_from_container x;
public:
    Container() {};
    void add(Circles& s);
    void add(Ellipse& s);
    void add(Helixes& s);
    Curves* get(int position);
    void sortCircles();
    double sumCircles();
};