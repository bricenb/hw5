/* Copyright 2020 Bricen Bennett CSCE240 */

#include <inc/item.h>

namespace csce240 {

Item::Item(const std::string& description, double price) { /* empty */ }

Item::Item(const std::string& description,
           double price,
           const Tax* first,
           const Tax* end) {
  descrip_ = description;
  price_ = price;
  for (size_t i = 0; i < 2; ++i, ++first) {
  percentage_ += first->percent();
  }
}

double Item::price() const {
  double decimal = 0.0;
  double tax_add = 0.0;
  decimal = percentage_ / 100;
  tax_add = price_ * decimal;
  return tax_add + price_;
}

bool Item::operator==(const Item& rhs) const {
  return true;
}

bool Item::operator!=(const Item& rhs) const {
  return true;
}

double Item::operator+(const Item& rhs) const {
return 0.0;
}

}  // namespace csce240
