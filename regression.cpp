#include "regression.hpp"

int Regression::size() const {return points_.size();}
void Regression::add(double x, double y)
{
points_.push_back({x,y});
    }

result Regression::fit() const
 {
    int N_{};
    double sum_x_{};
    double sum_y_{};
    double sum_xy_{};
    double sum_x2_{};
    for (auto const& p : points_){
      sum_x_ +=p.x;
      sum_y_ +=p.y;
      sum_xy_ +=p.x*p.y;
      sum_x2_ += p.x*p.x;
    }
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
