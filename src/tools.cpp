#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
  VectorXd rmse(4);
  rmse.fill(0.0);
  
  if ((estimations.size() != ground_truth.size()) ||
       (estimations.size() == 0)) {
    return rmse;       
  }
  
  for (int i = 0; i < estimations.size(); i++) {
    VectorXd r = estimations[i] - ground_truth[i];

    r = r.array() * r.array();

    rmse = rmse + r;  
  }
  
  rmse = rmse / estimations.size();
  
  rmse = rmse.array().sqrt();
  
  return rmse;
}
