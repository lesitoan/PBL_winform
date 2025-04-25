#include "Utils.h"

String ^ Utils::createUniqueID(String ^ subID) {
    DateTime now = DateTime::Now;
    String ^ uniqueID = now.ToString("MdHHmmssff");
    if (subID != "") {
        String ^ id = Guid::NewGuid().ToString();
        uniqueID = subID + "_" + uniqueID + id;
    }
    
    return uniqueID;
}