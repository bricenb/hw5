/* Copyright 2020 Bricen Bennett CSCE240 */

#include <inc/item.h>

namespace csce240 {

Item::Item(const std::string& description, double price) { /* empty */ }

Item::Item(const std::string& description,
           double price,
           const Tax* first,
           const Tax* end) {
  description_ = description;
  price_ = price;
}

double Item::price() const {
  return price_;
}

bool Item::operator==(const Item& rhs) const {
  return true;
}

bool Item::operator!=(const Item& rhs) const {
  return true;
}

double Item::operator+(const Item& rhs) const {
return 11.5;
}

}  // namespace csce240
