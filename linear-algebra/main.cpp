#include <armadillo>
#include <iostream>
#include <fmt/core.h>

#include <Eigen/Dense>

int
main()
{
  Eigen::MatrixXd eigen_matrix(2, 2);

  eigen_matrix(0, 0) = 3;
  eigen_matrix(1, 0) = 2.5;
  eigen_matrix(0, 1) = -1;
  eigen_matrix(1, 1) = eigen_matrix(1, 0) + eigen_matrix(0, 1);

  const arma::mat A(4, 5, arma::fill::randu);
  const arma::mat B(4, 5, arma::fill::randu);
  const auto result = A*(B.t());

  std::cout << "Eigen3:\n" << eigen_matrix << std::endl;
  // fmt::print("Eigen3 matrix {}", eigen_matrix);

  std::cout << "Armadillo\n" << "A:\n" << A << "\nB:\n" << B << "A* B.t():\n"<< result << std::endl;
  // fmt::print("Armadillo matrix {}", result);

  return 0;
}
