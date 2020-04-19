/* Copyright Bricen Bennett 2020 CSCE240 */

#include <inc/tax.h>
namespace csce240 {

Tax::Tax(const std::string& code, double percent) {
  code_ = code;
  percent_ = percent;
  if (percent_ < 0) {
    percent_ *= -1;
  }
}

const std::string& Tax::code() const {
  return code_;
}

double Tax::percent() const {
  return percent_;
}

double Tax::operator*(double rhs) const {
  double amount;
  amount = rhs;
  double percent;
  percent = percent_ / 100;
  return amount * percent;
}

double operator*(double lhs, const Tax& rhs) {
  double percent;
  percent = rhs.percent();
  percent /= 100;
  return percent * lhs;
}

std::istream& Tax::Insert(std::istream* in) {
  *in >> code_ >> percent_;
  return *in;
}

std::ostream& Tax::Extract(std::ostream* out) const {
  std::string code;
  double percent;
  code = code_;
  percent = percent_;
  *out << code << ':' << percent;
  return *out;
}

std::istream& operator>>(std::istream& lhs, Tax& rhs) {
  return rhs.Insert(&lhs);
}

std::ostream& operator<<(std::ostream& lhs, const Tax& rhs) {
  return rhs.Extract(&lhs);
}
}  // namespace csce240

