#include "regression.hpp"

int Regression::size() const {return N_;}
void Regression::add(double x, double y)
{
         ++N_;
        sum_x_ += x;
        sum_y_ += y;
        sum_x2_ += (x * x);
        sum_xy_ += (x * y);
    }

result Regression::fit() const
 {
       if (N_ < 2) {
      throw std::runtime_error{"Not enough points to run a fit"};
    }
    double const d = N_ * sum_x2_ - sum_x_ * sum_x_;
    if (d == 0.) {
      throw std::runtime_error{"Trying to fit a vertical line"};
    }
    double const a = (sum_y_ * sum_x2_ - sum_x_ * sum_xy_) / d;
    double const b = (N_ * sum_xy_ - sum_x_ * sum_y_) / d;
    return {a, b};
  }

auto Regression::fit(Regression const &reg) {
  return reg.fit();
}
