#include "Validate.h"

bool Validate::isPin(String ^ str) {
	return Regex::IsMatch(str, "^[0-9]{6}$");
}

bool Validate::isAccountNumber(String ^ str) {
	return Regex::IsMatch(str, "^[0-9]{9}$");
}
bool Validate::isNumber(String ^ input) {
    String ^ pattern = "^[+-]?\\d*\\.?\\d+$";
    return Regex::IsMatch(input, pattern);
}
