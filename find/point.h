#include <array>
#include <cmath>
#include <vector>

struct Point {
public:
  Point() = default;
  Point(double x, double y, double z) : x_(x), y_(y), z_(z) {}
  static double distance(const Point &p1, const Point &p2) {
    return std::sqrt((p1.x_ - p2.x_) * (p1.x_ - p2.x_) +
                     (p1.y_ - p2.y_) * (p1.y_ - p2.y_) +
                     (p1.z_ - p2.z_) * (p1.z_ - p2.z_));
  }

  bool operator==(const Point &p1) {
    return ((this->x_ == p1.x_) && (this->y_ == p1.y_) && (this->z_ == p1.z_));
  }

private:
  double x_;
  double y_;
  double z_;
};
