#pragma once
#include "CustomerCodesRepository.h"
#include "Notifications.h"
#include "NotificationsRepository.h"
#include "TransactionsRepository.h"
#include "User.h"
#include "UserRepository.h"
#include "GlobalData.h"

#ifndef USERSERVICE_H
#define USERSERVICE_H
using namespace System;
using namespace System::IO;
using namespace System::Text::RegularExpressions;

public
ref class UserService {
  public:
    static array<User ^> ^ GetAllUsers() {
        try {
            array<User ^> ^ users = UserRepository::GetUsers();
            if (users == nullptr || users->Length == 0) {
                return nullptr;
            }
            return users;

        } catch (Exception ^ ex) {
            throw gcnew Exception("GetAllUsers error !!!", ex);
        }
    }

        static array<User ^> ^
        GetCompanyByServiceId(String ^ serviceId) {
            try {
                array<User ^> ^ users = UserRepository::GetUsers();
                if (users == nullptr || users->Length == 0) {
                    return nullptr;
                }
                List<User ^> ^ companies = gcnew List<User ^>();
                for (int i = 0; i < users->Length; i++) {
                    if (users[i]->getRole() == "company" &&
                        users[i]->getServiceId() == serviceId) {
                        companies->Add(users[i]);
                    }
                }
                if (companies->Count == 0) {
                    return nullptr;
                }
                return companies->ToArray();

            } catch (Exception ^ ex) {
                throw gcnew Exception("GetCompanyByServiceId error !!!", ex);
            }
        }

        static array<String ^> ^
        GetHistoryReceivers(String ^ fromUserId) {
            try {
                array<Transaction ^> ^ transactions = TransactionsRepository::GetAll();
                if (transactions == nullptr || transactions->Length == 0) {
                    return nullptr;
                }
                List<String ^> ^ receiverString = gcnew List<String ^>();
                int count = 0;

                for (int i = transactions->Length - 1; i > 0; i--) {
                    if (count == 5) {
                        break;
                    }
                    if (transactions[i]->FromUserId == fromUserId &&
                        transactions[i]->ToUserId != "") {
                        User ^ user = UserRepository::FindById(transactions[i]->FromUserId);
                        if (user->getRole() != "user") {
                            continue;
                        }
                        String ^ toAcc =
                            user->getBankName() + " - " +
                            user->getFullName() + " - " +
                            transactions[i]->FromUserId+
                            " - " +
                            transactions[i]->Amount;

                        receiverString->Add(toAcc);
                        count++;
                    }
                }
                if (receiverString->Count == 0) {
                    return nullptr;
                }
                return receiverString->ToArray();
            } catch (Exception ^ ex) {
                throw gcnew Exception("GetHistoryReceivers error !!!", ex);
            }
        }

        static User
        ^ GetCompanyByCustomerCodeId(String ^ customerCodeId) {
              try {
                  if (customerCodeId == "") {
                      throw gcnew Exception(L"Không có thông tin mã khách hàng");
                  }
                  array<User ^> ^ users = UserRepository::GetUsers();
                  if (users == nullptr || users->Length == 0) {
                      return nullptr;
                  }
                  CustomerCodes ^ customerCode = CustomerCodesRepository::FindCustomerCodeById(customerCodeId);
                  if (customerCode == nullptr) {
                      throw gcnew Exception(L"Không tìm thấy thông tin mã khách hàng");
                  }
                  User ^ company = UserRepository::FindById(customerCode->CompanyId);
                  if (company == nullptr) {
                      throw gcnew Exception(L"Không tìm thấy thông tin công ty");
                  }
                  return company;
              } catch (Exception ^ ex) {
                  throw gcnew Exception("GetCompanyByServiceId error !!!", ex);
              }
          }
        
        
        static void UpdateUserById(String ^ userId, User ^ user) {
            try {
            UserRepository::UpdateById(userId, user);
            } catch (Exception ^ ex) {
                throw gcnew Exception("UpdateUserByAccNumber error !!!", ex);
            }
        }

    static void TransferMoney(String ^ fromAcc, String ^ toAcc,
                              double amount, int pin, String ^ message) {
        try {
            if (pin == 0) {
                throw gcnew Exception(L"Bạn chưa đặt mã pin, hãy đặt mã pin rồi quay lại !");
            } else if (fromAcc == "" || toAcc == "") {
                throw gcnew Exception(L"Thiếu thông tin người gửi, hoặc nhận");
            } else if (fromAcc == toAcc) {
                throw gcnew Exception(L"Chuyển khoản thất bại");
            } else if (amount <= 0) {
                throw gcnew Exception(L"Số tiền chuyển khoản không hợp lệ");
            }

            // kiểm tra xem tài khoản có tồn tại không
            User ^ sender = UserService::FindUserByAccNumber(fromAcc);
            if (sender == nullptr) {
                throw gcnew Exception(L"Tài khoản người gửi không tồn tại !");
            } else if (sender->getBalance() < amount) {
                throw gcnew Exception(L"Số dư không đủ để thực hiện giao dịch !");
            } else if (sender->getPin() == 0) {
                throw gcnew Exception(L"Khách hàng chưa đạt mã pin");
                
            } else if (sender->getPin() != pin) {
                throw gcnew Exception(L"Mã pin không chính xác");
            } 

            User ^ receiver = UserService::FindUserByAccNumber(toAcc);
            if (receiver == nullptr) {
                throw gcnew Exception(L"Tài khoản người nhận không tồn tại !");
            } else if (receiver->Status == 0) {
                throw gcnew Exception(L"Tài khoản người nhận đã bị khóa !");
            }

            // chỉnh sửa thông tin và lưu
            sender->setBalance(sender->getBalance() - amount);
            UserRepository::UpdateById(sender->Id, sender);

            receiver->setBalance(receiver->getBalance() + amount);
            UserRepository::UpdateById(receiver->Id, receiver);

            // update phiên đăng nhập hiện tại
            GlobalData::SetCurrentUser(sender);

            // lưu lịch sử giao dịch
            if (message == "") {
                message = sender->FullName + L" chuyển tiền";
            }
            Transaction ^ transaction =
                gcnew Transaction(sender->Id, receiver->Id, amount, message, "transfer");
            TransactionsRepository::InsertOne(transaction);

            // thêm thông báo cho người nhận
            String ^ notificationMessage = L"Nhận " + amount + L" từ tài khoản " + fromAcc;
            Notifications ^ notification =
                gcnew Notifications(receiver->Id, notificationMessage);
            NotificationsRepository::InsertOne(notification);

        } catch (Exception ^ ex) {
            throw ex;
        }
    }

    static User ^ FindUserByAccNumber(String ^ AccNum) {
        try {
            if (AccNum == "") {
                throw gcnew Exception(L"Không có thông tin tài khoản");
            }
            array<User ^> ^ users = UserRepository::GetUsers();

            for (int i = 0; i < users->Length; i++) {
                if (users[i]->AccountNumber == AccNum) {
                    return users[i];
                }
            }
            
            return nullptr;
        } catch (Exception ^ ex) {
            throw ex;
        }
    }

        static String
        ^ SetAvatar() {
              try {
                  OpenFileDialog ^ openFileDialog = gcnew OpenFileDialog();
                  "Hình ảnh (*.jpg;*.jpeg;*.png)|*.jpg;*.jpeg;*.png";

                  if (openFileDialog->ShowDialog() ==
                      System::Windows::Forms::DialogResult::OK) {

                      String ^ projectPath =
                          System::IO::Directory::GetParent(Application::StartupPath)->Parent->FullName;
                      String ^ avatarFolder = System::IO::Path::Combine(
                          projectPath, "BankingApp_winform\\images\\avatars\\");
                      // Lấy đường dẫn ảnh gốc
                      String ^ originalPath = openFileDialog->FileName;

                      String ^ extension = Path::GetExtension(originalPath);
                      String ^ newFileName =
                          "avatar_" + GlobalData::GetCurrentUser()->AccountNumber + extension;

                      String ^ destinationPath = Path::Combine(avatarFolder, newFileName);

                      // Tạo thư mục Images nếu chưa có
                      if (!Directory::Exists(avatarFolder)) {
                          Directory::CreateDirectory(avatarFolder);
                      }

                      File::Copy(originalPath, destinationPath);

                      // Lưu đường dẫn ảnh vào file users.dat
                      GlobalData::GetCurrentUser()->UrlAvatar =
                          "BankingApp_winform\\images\\avatars\\" + newFileName;

                      UserRepository::UpdateById(GlobalData::GetCurrentUser()->Id, GlobalData::GetCurrentUser());

                      return destinationPath;
                  }
              } catch (Exception ^ ex) {
                  throw ex;
              }
          }

        static void UpdatePin(String ^ pin, String ^ password) {
        try {
            if (pin == "" || password == "") {
                throw gcnew Exception(L"Vui lòng nhập đầy đủ thông tin");
            } else if (pin->Length != 6) {
                throw gcnew Exception(L"Mã pin phải có 6 kí tự");
            }

            String ^ currUserId = GlobalData::GetCurrentUser()->Id;
            User ^ user = UserRepository::FindById(currUserId);
            if (user == nullptr) {
                throw gcnew Exception(L"Tài khoản không tồn tại");
            } else if (user->getPassword() != password) {
                throw gcnew Exception(L"Mật khẩu không chính xác");
            } else if (user->getPin() == Convert::ToInt32(pin)) {
                return;
            }

            user->setPin(Convert::ToInt32(pin));
            GlobalData::SetCurrentUser(user);

            UserRepository::UpdateById(user->Id, user);

        } catch (Exception ^ ex) {
            throw ex;
        }
    }

    static void UpdateStatus(String ^ userId, int status) {
        try {
            if (userId == "") {
                throw gcnew Exception(L"Không có thông tin tài khoản");
            }
            User ^ user = UserRepository::FindById(userId);
            if (user == nullptr) {
                throw gcnew Exception(L"Tài khoản không tồn tại");
            }
            user->Status = status;
            UserRepository::UpdateById(user->Id, user);
        } catch (Exception ^ ex) {
            throw ex;
        }
    }

    static array<User ^> ^ FilterUserMatchName(String ^ name) {
        try {
            array<User ^> ^ users = UserRepository::GetUsers();
            if (users == nullptr || users->Length == 0) {
                throw;
            }
            List<User ^> ^ matchedUsers = gcnew List<User ^>();
            for (int i = 0; i < users->Length; i++) {
                if (users[i]->getRole() != "admin") {
                    String ^ pattern = ".*" + Regex::Escape(name) + ".*";
                    // Kiểm tra tên có chứa input không (không phân biệt hoa thường)
                    bool isMatch = Regex::IsMatch(users[i]->getFullName(), pattern,
                                                  RegexOptions::IgnoreCase);
                    if (isMatch) {
                        matchedUsers->Add(users[i]);
                    }
                }
            }
            if (matchedUsers->Count == 0) {
                throw;
            }
            return matchedUsers->ToArray();
        } catch (Exception ^ ex) {
            return gcnew array<User ^>(0);
        }
    }

    static void ChangePassword(String ^ oldPw, String^ newPw, String^ newPwComfirm) {
        try {
            if (oldPw == "" || newPw == "" || newPwComfirm == "") {
                throw gcnew Exception(L"Vui lòng nhập đầy đủ thông tin");
            } else if (oldPw == newPw) {
                throw gcnew Exception(L"Mật khẩu mới không được giống mật khẩu cũ");
            } else if (newPw != newPwComfirm) {
                throw gcnew Exception(L"Mật khẩu xác nhận không đúng");
            } else if (!Validate::isValidPassword(newPwComfirm)) {
                throw gcnew Exception(L"Mật khẩu phải từ 6-9 kí tự, có ít nhất 1 chữ cái và 1 số, không chứ dấu cách");
            }
            String ^ currUserId = GlobalData::GetCurrentUser()->Id;
            User ^ user = UserRepository::FindById(currUserId);
            if (user == nullptr) {
                throw gcnew Exception(L"Tài khoản không tồn tại");
            }
            user->setPassword(newPwComfirm);
            UserRepository::UpdateById(user->Id, user);
        } catch (Exception ^ ex) {
            throw ex;
        }
    }
};

#endif // !USERSERVICE_H
