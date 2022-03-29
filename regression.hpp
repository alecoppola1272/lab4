#ifndef REGRESSION_HPP
#define REGRESSION_HPP
#include <stdexcept>
#include <vector>

struct result
{
    double A{};
    double B{};
};

class Regression {
struct Point{
    double x;
    double y;
};
std::vector<Point> points_{};

public:
    int size ()const;
    void add (double x, double y);
    result fit() const;
    auto fit(Regression const &reg);
};
#endif