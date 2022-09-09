// Solve an equation of the form x*x = a.
#include <iostream>
#include <functional>
#include <Eigen/Dense>

constexpr float learn_rate = 1e-3;
constexpr float tol = 1e-6;

Eigen::Vector2d solve(const std::function<Eigen::Vector2d(const Eigen::Vector2d&)> &fun,
                      const std::function<Eigen::Matrix2d(const Eigen::Vector2d&)> &grad,
                      const Eigen::Vector2d &x0,
                      const Eigen::Vector2d &a) {
  Eigen::Vector2d x_soln = x0;
  auto diff = fun(x_soln) - a;
  while (diff.norm() > tol) {
    diff = learn_rate * 2 * grad(x_soln) * (fun(x_soln) - a);
    x_soln -= diff;
  }
  return x_soln;
}

int main() {

  const Eigen::Vector2d a{2, 1};
  const std::function<Eigen::Vector2d(const Eigen::Vector2d&)> fun = [](const Eigen::Vector2d &x) {Eigen::Vector2d out; out << x.dot(x), x[0] + x[1]; return out;};
  const std::function<Eigen::Matrix2d(const Eigen::Vector2d&)> grad = [](const Eigen::Vector2d &x) {Eigen::Matrix2d out; out << 2*x[0], 1, 2*x[1], 1; return out;};
  const auto x_soln = solve(fun, grad, Eigen::Vector2d{1, 1}, a);
  std::cout << "Soln: x = " << x_soln;
  std::cout << "\n a = " << a;
  std::cout << "\n f(x) = " << fun(x_soln);
  return 0;
}
