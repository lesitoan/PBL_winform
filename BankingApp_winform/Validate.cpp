#include "Validate.h"

bool Validate::isPin(String ^ str) {
	return Regex::IsMatch(str, "^[0-9]{6}$");
}

bool Validate::isAccountNumber(String ^ str) {
	return Regex::IsMatch(str, "^[0-9]{10}$");
}
bool Validate::isNumber(String ^ input) {
    String ^ pattern = "^[+-]?\\d*\\.?\\d+$";
    return Regex::IsMatch(input, pattern);
}

// mk chi chứa a-z, A-Z, 0-9 và ít nhất 1 chữ cái và 1 số, từ 6 đên 9 kí tự
bool Validate::isValidPassword(String ^ password) {
    String ^ pattern =
        "^(?=.*[A-Za-z])(?=.*\\d)[A-Za-z\\d~!@#$%^&*()_+={}:;,.?-]{6,9}$";
    Regex ^ regex = gcnew Regex(pattern);
    return regex->IsMatch(password);
}

// Số điện thoại Việt Nam bắt đầu bằng số 0, tiếp theo là 9 chữ số từ 2-9 hoặc 1
// số 7 hoặc 8 và 1 số từ 0-9 (không bắt đầu bằng 1) tổng cộng 10 chữ số 
bool Validate::isValidVietnamPhoneNumber(String ^ phoneNumber) {
    String ^ pattern = "^0(3[2-9]|5[2689]|7[0-9]|8[1-9]|9[0-9])\\d{7}$";
    Regex ^ regex = gcnew Regex(pattern);
    return regex->IsMatch(phoneNumber);
}

// chỉ chứa chữ in hoa, không chứa số và kí tự đặc biệt, ít nhất 2 từ
bool Validate::isValidCustomerName(String ^ name) {
    String ^ pattern = "^[A-Z]+( [A-Z]+)+$";
    Regex ^ regex = gcnew Regex(pattern);
    return regex->IsMatch(name);
}
