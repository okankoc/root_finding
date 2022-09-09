// Solve an equation of the form x*x = a.
#include <iostream>
#include <functional>

constexpr float learn_rate = 1e-3;
constexpr float tol = 1e-6;

float solve(const std::function<float(float)> &fun, const std::function<float(float)> &grad, const float &x0, const float &a) {
  float x_soln = x0;
  float diff = 2*tol;
  while (std::abs(diff) > tol) {
    diff = learn_rate * 2 * (fun(x_soln) - a) * grad(x_soln);
    x_soln -= diff;
  }
  return x_soln;
}

int main() {

  const float a  = 7;
  const std::function<float(float)> fun = [](const float &x) {return x*x*x;};
  const std::function<float(float)> grad = [](const float &x) {return 3*x*x;};
  const float x_soln = solve(fun, grad, 3.72, a);
  std::printf("Soln: x = %f, a = %f, f(x) = %f\n", x_soln, a, fun(x_soln));
  return 0;
}
