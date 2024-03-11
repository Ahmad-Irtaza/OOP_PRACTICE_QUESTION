#include <iostream>
#include <string>
using namespace std;

class personType
{
    string firstName;
    string lastName;
public:
    void print() const;
    void setName(string first, string last);
    string getFirstName() const;
    string getLastName() const;
    personType(string first = "", string last = "");


};

class doctorType : public personType
{
    string specialty;
public:
    doctorType(string first = "", string last = "", string specialty = "");
    void setSpecialty(string specialty);
    string getSpecialty() const;


};

class dateType
{
    int dMonth;
    int dDay;
    int dYear;
public:
    void setDate(int month, int day, int year);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void printDate() const;
    dateType(int month = 1, int day = 1, int year = 1900);

};

class billType
{
    int patientID;
    double pharmacyCharges;
    double doctorFee;
    double roomCharges;
public:
    billType(int patientID = 0, double pharmacyCharges = 0.0, double doctorFee = 0.0, double roomCharges = 0.0);
    void setPatientID(int ID);
    void setPharmacyCharges(double charges);
    void setDoctorFee(double fee);
    void setRoomCharges(double charges);
    int getPatientID() const;
    double getPharmacyCharges() const;
    double getDoctorFee() const;
    double getRoomCharges() const;


};

class patientType : public personType
{
    int patientID;
    int age;
    dateType dob;
    doctorType attendingPhysician;
    dateType admitDate;
    dateType dischargeDate;
public:
    patientType(string first = "", string last = "", int ID = 0, int age = 0, dateType dob = dateType(), doctorType attendingPhysician = doctorType(), dateType admitDate = dateType(), dateType dischargeDate = dateType());
    void setPatientID(int ID);
    void setAge(int age);
    void setDOB(int month, int day, int year);
    void setAttendingPhysician(doctorType physician);
    void setAdmitDate(int month, int day, int year);
    void setDischargeDate(int month, int day, int year);
    int getPatientID() const;
    int getAge() const;
    dateType getDOB() const;
    doctorType getAttendingPhysician() const;
    dateType getAdmitDate() const;
    dateType getDischargeDate() const;


};


// Implementation of member functions

void personType::print() const
{
    cout << firstName << " " << lastName;
}

void personType::setName(string first, string last)
{
    firstName = first;
    lastName = last;
}

string personType::getFirstName() const
{
    return firstName;
}

string personType::getLastName() const
{
    return lastName;
}

personType::personType(string first, string last)
{
    firstName = first;
    lastName = last;
}

doctorType::doctorType(string first, string last, string specialty)
    : personType(first, last)
{
    this->specialty = specialty;
}

void doctorType::setSpecialty(string specialty)
{
    this->specialty = specialty;
}

string doctorType::getSpecialty() const
{
    return specialty;
}

void dateType::setDate(int month, int day, int year)
{
    dMonth = month;
    dDay = day;
    dYear = year;
}

int dateType::getDay() const
{
    return dDay;
}

int dateType::getMonth() const
{
    return dMonth;
}

int dateType::getYear() const
{
    return dYear;
}

void dateType::printDate() const
{
    cout << dMonth << "-" << dDay << "-" << dYear;
}

dateType::dateType(int month, int day, int year)
{
    dMonth = month;
    dDay = day;
    dYear = year;
}

billType::billType(int patientID, double pharmacyCharges, double doctorFee, double roomCharges)
{
    this->patientID = patientID;
    this->pharmacyCharges = pharmacyCharges;
    this->doctorFee = doctorFee;
    this->roomCharges = roomCharges;
}

void billType::setPatientID(int ID)
{
    patientID = ID;
}

void billType::setPharmacyCharges(double charges)
{
    pharmacyCharges = charges;
}

void billType::setDoctorFee(double fee)
{
    doctorFee = fee;
}

void billType::setRoomCharges(double charges)
{
    roomCharges = charges;
}

int billType::getPatientID() const
{
    return patientID;
}

double billType::getPharmacyCharges() const
{
    return pharmacyCharges;
}

double billType::getDoctorFee() const
{
    return doctorFee;
}

double billType::getRoomCharges() const
{
    return roomCharges;
}

patientType::patientType(string first, string last, int ID, int age, dateType dob, doctorType attendingPhysician, dateType admitDate, dateType dischargeDate)
    : personType(first, last)
{
    patientID = ID;
    this->age = age;
    this->dob = dob;
    this->attendingPhysician = attendingPhysician;
    this->admitDate = admitDate;
    this->dischargeDate = dischargeDate;
}

void patientType::setPatientID(int ID)
{
    patientID = ID;
}

void patientType::setAge(int age)
{
    this->age = age;
}

void patientType::setDOB(int month, int day, int year)
{
    dob.setDate(month, day, year);
}

void patientType::setAttendingPhysician(doctorType physician)
{
    attendingPhysician = physician;
}

void patientType::setAdmitDate(int month, int day, int year)
{
    admitDate.setDate(month, day, year);
}

void patientType::setDischargeDate(int month, int day, int year)
{
    dischargeDate.setDate(month, day, year);
}

int patientType::getPatientID() const
{
    return patientID;
}

int patientType::getAge() const
{
    return age;
}

dateType patientType::getDOB() const
{
    return dob;
}

doctorType patientType::getAttendingPhysician() const
{
    return attendingPhysician;
}

dateType patientType::getAdmitDate() const
{
    return admitDate;
}

dateType patientType::getDischargeDate() const
{
    return dischargeDate;
}

int main()
{
   
    doctorType doctor("Ali", "Irtaza", "Cardiology");
    personType person("an", "BUtt");
    dateType dob(1990, 5, 10);
    dateType admitDate(2023, 5, 25);
    dateType dischargeDate(2023, 6, 2);
    patientType patient("aaa", "bb", 12345, 35, dob, doctor, admitDate, dischargeDate);
    billType bill(12345, 150.0, 200.0, 500.0);

    cout << "Patient Information:" << endl;
    cout << "Name: ";
    person.print();
    cout << endl;
    cout << "Patient ID: " << patient.getPatientID() << endl;
    cout << "Age: " << patient.getAge() << endl;
    cout << "Date of Birth: ";
    patient.getDOB().printDate();
    cout << endl;
    cout << "Attending Physician: " << patient.getAttendingPhysician().getFirstName() << " " << patient.getAttendingPhysician().getLastName() << endl;
    cout << "Admit Date: ";
    patient.getAdmitDate().printDate();
    cout << endl;
    cout << "Discharge Date: ";
    patient.getDischargeDate().printDate();
    cout << endl;

    cout << endl;

    cout << "Billing Information:" << endl;
    cout << "Patient ID: " << bill.getPatientID() << endl;
    cout << "Pharmacy Charges: " << bill.getPharmacyCharges() << endl;
    cout << "Doctor's Fee: " << bill.getDoctorFee() << endl;
    cout << "Room Charges: " << bill.getRoomCharges() << endl;

    return 0;
}

//        .............code Ends...............