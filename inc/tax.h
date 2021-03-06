/* Copyright 2020 Bricen Bennett CSCE240 */
/* This class tests your ability to manage operator overloading.
 *
 * Points:
 *  Style : 1
 *  Compilation : 1
 *   Tax::operator*, operator* : 1
 *   operator>> : 0.5
 *   operator<< : 0.5
 */

#ifndef INC_TAX_H_
#define INC_TAX_H_

#include <istream>
#include <ostream>
#include <string>

namespace csce240 {
class Tax {
 public:
  /* Default
   */
  Tax() : code_(""), percent_(0.0) { /* Intentionally Empty */ }

  /* Constructor builds a tax instance from provided string code and double
   * percentage. The percent parameter should be a percentage.
   *
   * Precondition: percent is positive
   */
  Tax(const std::string& code, double percent);

  /* Accessor returns tax instance code
   */
  const std::string& code() const;

  /* Accessor returns tax instance percentage as a percent
   */
  double percent() const;

  /* Method accepts an amount and applies the tax percent, returning the
   * product of taxation.
   *
   * Precondition: amount is positive
   */
  double operator*(double rhs) const;

  std::ostream& Extract(std::ostream* out) const;

  std::istream& Insert(std::istream* in);

 private:
    std::string code_;
    double percent_;
};

/* Operator accepts a double amount and applies the tax percent, returning the
 * product of taxation.
 *
 * Precondition: amount is positive
 */
double operator*(double lhs, const Tax& rhs);

/* Inserter removes a string and numeric from the input stream, storing in
 * this calling instance.
 *
 * Precondition: there exists a whitespace-delimited string and numeric on
 *               the stream in the form:
 *   AAA 00.0
 */
std::istream& operator>>(std::istream& lhs, Tax& rhs);

/* Extractor appends the code and tax in the form:
 *   AAA:00.0
 * to the ostream object and returns it.
 */
std::ostream& operator<<(std::ostream& lhs, const Tax& rhs);
}  // namespace csce240


#endif  // INC_TAX_H_
