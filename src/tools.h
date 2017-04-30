#ifndef TOOLS_H_
#define TOOLS_H_
#include <vector>
#include "Eigen/Dense"

class Tools {
public:
  static constexpr double EPSILON = 0.01; ///* minimum value of px, py to avoid divide by zero

  Tools();
  virtual ~Tools();

  /**
  * A helper method to calculate RMSE.
  */
  static Eigen::VectorXd CalculateRMSE(const std::vector<Eigen::VectorXd> &estimations, const std::vector<Eigen::VectorXd> &ground_truth);
  static void NormalizeAngle(double& a) { while (a > M_PI) a -= 2.*M_PI; while (a <-M_PI) a += 2.*M_PI; }
  static Eigen::VectorXd CalculateStdDev(const std::vector<Eigen::VectorXd> &process_state);
  static void EnsureNonZero(double& v) { if (v == 0.0) v = EPSILON; }
};

#endif /* TOOLS_H_ */
