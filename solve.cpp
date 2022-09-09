// Solve an equation of the form x*x = a.
#include <iostream>

const float learn_rate = 1e-3;
const float tol = 1e-6;

float fun(const float &x) {
  return x * x;
}

// TODO: Extend for arbitrary functions
float grad(const float &x) {
  return 2*x;
}

float optimize(const float &a) {
  float x_soln = a;
  float diff = 2*tol;
  while (std::abs(diff) > tol) {
    diff = learn_rate * grad(x_soln);
    x_soln -= diff;
  }
  return x_soln;
}

float solve(const float &a) {
  float x_soln = a;
  float diff = 2*tol;
  while (std::abs(diff) > tol) {
    diff = learn_rate * 2 * (fun(x_soln) - a) * grad(x_soln);
    x_soln -= diff;
  }
  return x_soln;
}

int main() {

  const float a  = 5;
  const float x_soln = solve(a);
  std::printf("Soln: x = %f, a = %f, f(x) = %f\n", x_soln, a, fun(x_soln));
  return 0;
}
