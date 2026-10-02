#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
using namespace std;

void clearscreen(){
    system("cls");
}

void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.ignore(1000, '\n');
    cin.get();
    system("cls");
}

bool login() {
    string password;

    cout << "\n=====================================\n";
    cout << "     HOSPITAL MANAGEMENT SYSTEM\n";
    cout << "=====================================\n";
    cout << "\nPlease login to continue\n\n";

    cout << "Enter Password: ";
    cin >> password;

    if (password == "1234") {
        cout << "\nLogin successful!\n";
        cout << "\n=====================================";
        Sleep(1000);
        clearscreen();
        return true;
    }
    else {
        cout << "\nIncorrect password!\n";
        return false;
    }
}

string getPaymentStatus();

//doctor record
struct Doctor {
    string id;
    string name;
    string gender;
    string specialization;
    string phone;
};

Doctor doctor[100];
int total = 0;

void addDoctor() {
    cout << "\n============ Add Doctor =============\n";

    cout << left;

    cout << setw(17) << "\nDoctor ID" << ": ";
    cin >> doctor[total].id;
    cin.ignore();

    cout << setw(16) << "Name" << ": Dr.";
    getline(cin, doctor[total].name);

    cout << setw(16) << "Gender" << ": ";
    getline(cin, doctor[total].gender);

    cout << setw(16) << "Specialization" << ": ";
    getline(cin, doctor[total].specialization);

    cout << setw(16) << "Phone" << ": ";
    getline(cin, doctor[total].phone);

    total++;

    cout << "\nDoctor added successfully!\n";
    cout << "=====================================";
    pauseScreen();
}

void viewDoctors() {
    cout << "\n=========== Doctor List =============\n";

    if (total == 0) {
        cout << "No doctor records found.\n";
        return;
    }

    for (int i = 0; i < total; i++) {
        cout << "\nDoctor " << i + 1 << endl;
        cout << left << setw(16) << "Doctor ID" << ": " << doctor[i].id << endl;
        cout << setw(16) << "Name" << ": Dr. " << doctor[i].name << endl;
        cout << setw(16) << "Gender" << ": " << doctor[i].gender << endl;
        cout << setw(16) << "Specialization" << ": " << doctor[i].specialization << endl;
        cout << setw(16) << "Phone" << ": " << doctor[i].phone << endl;
        cout << "\n=====================================" << endl;
        pauseScreen();
    }
}

void updateDoctor() {
    string id;
    cout << "\nEnter Doctor ID to update: ";
    cin >> id;
    cin.ignore();
    clearscreen();

    for (int i = 0; i < total; i++) {
        if (doctor[i].id == id) {
            cout << "\n=========== Update Doctor ===========\n";

            cout << left << setw(19) << "\nNew Name" << ": Dr. ";
            getline(cin, doctor[i].name);

            cout << setw(18) << "New Gender" << ": ";
            getline(cin, doctor[i].gender);

            cout << setw(18) << "New Specialization" << ": ";
            getline(cin, doctor[i].specialization);

            cout << setw(18) << "New Phone" << ": ";
            getline(cin, doctor[i].phone);

            cout << "\nDoctor updated successfully!";
            cout << "\n=====================================";
            pauseScreen();
            return;
        }
    }
    cout << "\nDoctor not found.\n";
    pauseScreen();
}

void deleteDoctor() {
    string id;
    cout << "\n=========== Delete Doctor ===========\n";
    cout << "\nPlease Enter Doctor ID to delete: ";
    cin >> id;

    for (int i = 0; i < total; i++) {
        if (doctor[i].id == id) {

            for (int j = i; j < total - 1; j++) {
                doctor[j] = doctor[j + 1];
            }

            total--;
            cout << "\nDoctor deleted successfully!";
            cout << "\n=====================================";
            pauseScreen();
            return;
        }
    }

    cout << "\nDoctor not found.\n";
    cout << "=====================================";
    pauseScreen();
}

void doctorMenu(){
    int choice;
        do {
            cout << "\n=====================================\n";
            cout << "            DOCTOR RECORDS\n";
            cout << "=====================================\n";
            cout << "1. Add Doctor\n";
            cout << "2. View Doctors\n";
            cout << "3. Update Doctor\n";
            cout << "4. Delete Doctor\n";
            cout << "5. Back to main Menu\n";
            cout << "=====================================";
            cout << "\nEnter your choice: ";
            cin >> choice;

        switch (choice) {

            case 1:
                clearscreen();
                addDoctor();
                break;
            case 2:
                clearscreen();
                viewDoctors();
                break;
            case 3:
                clearscreen();
                updateDoctor();
                break;
            case 4:
                clearscreen();
                deleteDoctor();
                break;
            case 5:
                cout << "Returning to Main Menu...\n";
                Sleep(1000);
                clearscreen();
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }while (choice != 5);

                }
//Patient Records
struct Patient {
    string id;
    string name;
    string age;
    string gender;
    string phone;
    string roomNumber;
    string diagnosis;
    string assignedDoctor;
};

Patient patient[100];
int totalPatients = 0;

void addPatient() {
    cout << "\n=========== Add Patient ============\n";
    cin.ignore();

    cout << left;
    cout << setw(21) << "\nPatient ID" << ": ";
    getline(cin, patient[totalPatients].id);

    cout << setw(20) << "Patient Name" << ": ";
    getline(cin, patient[totalPatients].name);

    cout << setw(20) << "Age" << ": ";
    getline(cin, patient[totalPatients].age);

    cout << setw(20) << "Gender" << ": ";
    getline(cin, patient[totalPatients].gender);

    cout << setw(20) << "Phone Number" << ": ";
    getline(cin, patient[totalPatients].phone);

    cout << setw(20) << "Room Number" << ": ";
    getline(cin, patient[totalPatients].roomNumber);

    cout << setw(20) << "Disease/Diagnosis" << ": ";
    getline(cin, patient[totalPatients].diagnosis);

    cout << setw(20) << "Assigned Doctor" << ": Dr.";
    getline(cin, patient[totalPatients].assignedDoctor);

    totalPatients++;

    cout << "\nPatient added successfully!";
    cout << "\n====================================";
    pauseScreen();
}

void viewPatients() {
    cout << "\n=========== Patient list ===========\n";

    if (totalPatients == 0) {
        cout << "No patient records found.\n";
        return;
    }

    for (int i = 0; i < totalPatients; i++) {
        cout << "\nPatient " << i + 1 << endl;
        cout << left << setw(20) << "Patient ID" << ": " << patient[i].id << endl;
        cout << setw(20) << "Name" << ": " << patient[i].name << endl;
        cout << setw(20) << "Age" << ": " << patient[i].age << endl;
        cout << setw(20) << "Gender" << ": " << patient[i].gender << endl;
        cout << setw(20) << "Phone Number" << ": " << patient[i].phone << endl;
        cout << setw(20) << "Room Number" << ": " << patient[i].roomNumber << endl;
        cout << setw(20) << "Disease/Diagnosis" << ": " << patient[i].diagnosis << endl;
        cout << setw(20) << "Assigned Doctor" << ": Dr." << patient[i].assignedDoctor << endl;
        cout << "";
        cout << "\n====================================";
        pauseScreen();
    }
}

void updatePatient() {
    string id;

    cout << "\nEnter Patient ID to update: ";
    cin >> id;
    cin.ignore();
    clearscreen();

    for (int i = 0; i < totalPatients; i++) {
        if (patient[i].id == id) {

            cout << "\n========== Update Patient ===========\n";

            cout << left << setw(22) << "\nNew Patient Name" << ": ";
            getline(cin, patient[i].name);

            cout << setw(21) << "New Age" << ": ";
            getline(cin, patient[i].age);

            cout << setw(21) << "New Gender" << ": ";
            getline(cin, patient[i].gender);

            cout << setw(21) << "New Phone Number" << ": ";
            getline(cin, patient[i].phone);

            cout << setw(21) << "New Room Number" << ": ";
            getline(cin, patient[i].roomNumber);

            cout << setw(21) << "New Disease/Diagnosis" << ": ";
            getline(cin, patient[i].diagnosis);

            cout << setw(21) << "New Assigned Doctor" << ": Dr. ";
            getline(cin, patient[i].assignedDoctor);

            cout << "\nPatient updated successfully!";
            cout << "\n=====================================";
            pauseScreen();
            return;
        }
    }

    cout << "\nPatient not found.\n";
    cout << "=====================================";
    pauseScreen();
}

void deletePatient() {
    string id;
    cout << "\n=========== Delete Patient ==========\n";
    cout << "\nEnter Patient ID to delete: ";
    cin >> id;

    for (int i = 0; i < totalPatients; i++) {
        if (patient[i].id == id) {

            for (int j = i; j < totalPatients - 1; j++) {
                patient[j] = patient[j + 1];
            }

            totalPatients--;

            cout << "\nPatient deleted successfully!";
            cout << "\n=====================================";
            pauseScreen();
            return;
        }
    }
    cout << "\nPatient not found.\n";
    cout << "=====================================";
    pauseScreen();
}

void patientMenu() {
    int choice;

    do {
        cout << "=====================================\n";
        cout << "            PATIENT RECORDS\n";
        cout << "=====================================\n";
        cout << "1. Add Patient\n";
        cout << "2. View Patients\n";
        cout << "3. Update Patient\n";
        cout << "4. Delete Patient\n";
        cout << "5. Back to Main Menu\n";
        cout << "=====================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                clearscreen();
                addPatient();
                break;

            case 2:
                clearscreen();
                viewPatients();
                break;

            case 3:
                clearscreen();
                updatePatient();
                break;

            case 4:
                clearscreen();
                deletePatient();
                break;

            case 5:
                cout << "Returning to Main Menu...\n";
                Sleep(1000);
                clearscreen();
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);
}

//doctor appointment
struct Appointment {
    string patientID;
    string patientName;
    string doctorName;
    string date;
    string time;
    string status;
};

Appointment appointment[100];
int totalAppointments = 0;

void addAppointment() {
    cout << "\n======= Add Doctor Appointment =======\n";

    cout << left << setw(23) << "\nPatient ID" << ": ";
    cin >> appointment[totalAppointments].patientID;
    cin.ignore();

    cout << setw(22) << "Patient Name" << ": ";
    getline(cin, appointment[totalAppointments].patientName);

    cout << setw(22) << "Doctor Name" << ": Dr.";
    getline(cin, appointment[totalAppointments].doctorName);

    cout << setw(22) << "Date" << ": ";
    getline(cin, appointment[totalAppointments].date);

    cout << setw(22) << "Time" << ": ";
    getline(cin, appointment[totalAppointments].time);

    cout << setw(22) << "Appointment Status" << ": Confirmed" << endl;
    appointment[totalAppointments].status = "Confirmed";

    totalAppointments++;
    cout << "Appointment added successfully!\n";
    cout << "\n======================================";
    pauseScreen();
}

void viewAppointments() {
    cout << "========== Appointment List =========\n";

    if (totalAppointments == 0) {
        cout << "No appointment records found.\n";
        return;
    }

    for (int i = 0; i < totalAppointments; i++) {
        cout << "\nAppointment " << i + 1 << endl;

        cout << left << setw(22) << "Patient ID" << ": " << appointment[i].patientID << endl;
        cout << setw(22) << "Patient Name" << ": " << appointment[i].patientName << endl;
        cout << setw(22) << "Doctor Name" << ": Dr. " << appointment[i].doctorName << endl;
        cout << setw(22) << "Date" << ": " << appointment[i].date << endl;
        cout << setw(22) << "Time" << ": " << appointment[i].time << endl;
        cout << setw(22) << "Appointment Status" << ": " << appointment[i].status << endl;
        cout << "\n======================================" << endl;
        pauseScreen();
    }
}

void updateAppointment() {
    string id;

    cout << "";
    cout << "\nEnter Patient ID to update appointment: ";
    cin >> id;
    cin.ignore();
    clearscreen();

    for (int i = 0; i < totalAppointments; i++) {
        if (appointment[i].patientID == id) {

            cout << "\n======== Update Appointment ========\n";

            cout << left << setw(25) << "\nNew Patient Name" << ": ";
            getline(cin, appointment[i].patientName);

            cout << setw(24) << "New Doctor Name" << ": Dr. ";
            getline(cin, appointment[i].doctorName);

            cout << setw(24) << "New Date" << ": ";
            getline(cin, appointment[i].date);

            cout << setw(24) << "New Time" << ": ";
            getline(cin, appointment[i].time);

            cout << setw(24) << "New Appointment Status" << ": Confirmed\n";
            appointment[i].status = "Confirmed";

            cout << "\nAppointment updated successfully!";
            cout << "\n=====================================";
            pauseScreen();
            return;
        }
    }

    cout << "Appointment not found.\n";
    cout << "\n===========================================";
    pauseScreen();
}

void deleteAppointment() {
    string id;

    cout << "\nEnter Patient ID to delete appointment: ";
    cin >> id;

    for (int i = 0; i < totalAppointments; i++) {
        if (appointment[i].patientID == id) {

            for (int j = i; j < totalAppointments - 1; j++) {
                appointment[j] = appointment[j + 1];
            }

            totalAppointments--;

            cout << "\nAppointment deleted successfully!";
            cout << "\n===========================================";
            pauseScreen();
            return;
        }
    }

    cout << "\nAppointment not found.\n";
    cout << "===========================================";
    pauseScreen();
}

void appointmentMenu() {
    int choice;

    do {
        cout << "\n=====================================\n";
        cout << "          APPOINTMENT RECORDS\n";
        cout << "=====================================\n";
        cout << "1. Add Appointment\n";
        cout << "2. View Appointments\n";
        cout << "3. Update Appointment\n";
        cout << "4. Delete Appointment\n";
        cout << "5. Back to Main Menu\n";
        cout << "=====================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                clearscreen();
                addAppointment();
                break;

            case 2:
                clearscreen();
                viewAppointments();
                break;

            case 3:
                clearscreen();
                updateAppointment();
                break;

            case 4:
                clearscreen();
                deleteAppointment();
                break;

            case 5:
                cout << "Returning to Main Menu...\n";
                Sleep(1000);
                clearscreen();
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);
}

//patient report
struct PatientReport {
    string patientID;
    string patientName;
    string age;
    string gender;
    string roomNumber;
    string assignedDoctor;
    string diagnosis;
    string appointmentDate;
    string status;
};

PatientReport report[100];
int totalReports = 0;

void viewPatientReport() {
    string id;
    bool patientFound = false;
    bool appointmentFound = false;
    cout << "\n======== View Patient Report ========\n";
    cout << "\nPlease Enter Patient ID: ";
    cin >> id;
    clearscreen();

    // Find patient
    for (int i = 0; i < totalPatients; i++) {

        if (patient[i].id == id) {
            patientFound = true;

            cout << "\n============= PATIENT REPORT =============\n";
            cout << left << setw(23) << "\nPatient ID" << ": " << patient[i].id << endl;
            cout << setw(22) << "Patient Name" << ": " << patient[i].name << endl;
            cout << setw(22) << "Age" << ": " << patient[i].age << endl;
            cout << setw(22) << "Gender" << ": " << patient[i].gender << endl;
            cout << setw(22) << "Room Number" << ": " << patient[i].roomNumber << endl;
            cout << setw(22) << "Assigned Doctor" << ": Dr. " << patient[i].assignedDoctor << endl;
            cout << setw(22) << "Diagnosis" << ": " << patient[i].diagnosis << endl;
            cout << "\n==========================================";

            // Find appointment
            for (int j = 0; j < totalAppointments; j++) {

            if (appointment[j].patientID == id) {

                cout << "\nAppointment Date: "
                     << appointment[j].date << endl;

                appointmentFound = true;
                break;
            }
        }

        if (!appointmentFound) {
            cout << "\nAppointment Date: No appointment found" << endl;
        }
        else {
            cout << "Status: Completed" << endl;
            cout << "\n==========================================";
            pauseScreen();
            clearscreen();
        }

            if (!patientFound) {
                cout << "Patient not found.\n";
                cout << "\n==========================================";
                pauseScreen();
            }
        }
    }
}

void reportMenu() {
    int choice;

    do {
        cout << "\n=====================================\n";
        cout << "            PATIENT REPORTS\n";
        cout << "=====================================\n";
        cout << "1. View Patient Report\n";
        cout << "2. Back to Main Menu\n";
        cout << "=====================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                clearscreen();
                viewPatientReport();
                break;

            case 2:
                cout << "Returning to Main Menu...\n";
                Sleep(1000);
                clearscreen();
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 2);
}

//billing services
struct Billing {
    string patientID;
    string patientName;
    double doctorFee;
    double treatmentCharge;
    double roomCharge;
    double medicineCharge;
    double totalAmount;
    string paymentStatus;
};

Billing billing[100];
int totalBills = 0;

void addBill() {
    cout << "\n============ Add Billing ============\n";

    cout << left << setw(29) << "\nPatient ID" << ": ";
    cin >> billing[totalBills].patientID;
    cin.ignore();

    cout << setw(28) << "Patient Name" << ": ";
    getline(cin, billing[totalBills].patientName);

    cout << setw(28) << "Doctor Fee" << ": $";
    cin >> billing[totalBills].doctorFee;

    cout << setw(28) << "Treatment Charge" << ": $";
    cin >> billing[totalBills].treatmentCharge;

    cout << setw(28) << "Room Charge" << ": $";
    cin >> billing[totalBills].roomCharge;

    cout << setw(28) << "Medicine Charge" << ": $";
    cin >> billing[totalBills].medicineCharge;

    billing[totalBills].totalAmount =
        billing[totalBills].doctorFee +
        billing[totalBills].treatmentCharge +
        billing[totalBills].roomCharge +
        billing[totalBills].medicineCharge;

        billing[totalBills].paymentStatus = getPaymentStatus();

    totalBills++;

    cout << "\nBilling added successfully!";
    cout << "\n=====================================";
    pauseScreen();
}
string getPaymentStatus() {
    string status;

    do {
        cout << "Payment Status (Paid/Unpaid): ";
        cin >> status;

        if (status == "paid" || status == "PAID" || status == "Paid") {
            return "Paid";
        }
        else if (status == "unpaid" || status == "UNPAID" || status == "Unpaid") {
            return "Unpaid";
        }
        else {
            cout << "Invalid status. Please enter Paid or Unpaid.\n";
        }

    } while (true);
}

void viewBills() {
    cout << "\n========== Billing Records ==========\n";

    if (totalBills == 0) {
        cout << "No billing records found.\n";
        return;
    }

    for (int i = 0; i < totalBills; i++) {
        cout << "\nBill " << i + 1 << endl;
        cout << left << setw(22) << "Patient ID" << ": " << billing[i].patientID << endl;
        cout << setw(22) << "Patient Name" << ": " << billing[i].patientName << endl;
        cout << setw(22) << "Doctor Fee" << ": $" << billing[i].doctorFee << endl;
        cout << setw(22) << "Treatment Charge" << ": $" << billing[i].treatmentCharge << endl;
        cout << setw(22) << "Room Charge" << ": $" << billing[i].roomCharge << endl;
        cout << setw(22) << "Medicine Charge" << ": $" << billing[i].medicineCharge << endl;
        cout << "\n-------------------------------------" << endl;
        cout << setw(22) << "Total Amount" << ": $" << billing[i].totalAmount << endl;
        cout << setw(22) << "Payment Status" << ": " << billing[i].paymentStatus << endl;
        cout << "\n=====================================" << endl;
        pauseScreen();
    }
}

void updateBill() {
    string id;

    cout << "\nEnter Patient ID to update bill: ";
    cin >> id;
    cin.ignore();
    clearscreen();

    for (int i = 0; i < totalBills; i++) {
        if (billing[i].patientID == id) {
            cout << "\n============ Update Bills ===========\n";

            cout << left << setw(29) << "\nNew Patient Name" << ": ";
            getline(cin, billing[i].patientName);

            cout << setw(28) << "New Doctor Fee" << ": $";
            cin >> billing[i].doctorFee;

            cout << setw(28) << "New Treatment Charge" << ": $";
            cin >> billing[i].treatmentCharge;

            cout << setw(28) << "New Room Charge" << ": $";
            cin >> billing[i].roomCharge;

            cout << setw(28) << "New Medicine Charge" << ": $";
            cin >> billing[i].medicineCharge;

            billing[i].totalAmount =
                billing[i].doctorFee +
                billing[i].treatmentCharge +
                billing[i].roomCharge +
                billing[i].medicineCharge;

            billing[totalBills].paymentStatus = getPaymentStatus();

            cout << "\nBilling updated successfully!";
            cout << "\n=====================================";
            pauseScreen();
            return;
        }
    }
    cout << "\nBilling record not found.\n";
    cout << "=====================================";
    pauseScreen();
}

void deleteBill() {
    string id;

    cout << "\nEnter Patient ID to delete bill: ";
    cin >> id;

    for (int i = 0; i < totalBills; i++) {
        if (billing[i].patientID == id) {

            for (int j = i; j < totalBills - 1; j++) {
                billing[j] = billing[j + 1];
            }
            totalBills--;

            cout << "\nBilling deleted successfully!";
            cout << "\n=====================================";
            pauseScreen();
            return;
        }
    }

    cout << "\nBilling record not found.";
    cout << "\n=====================================";
    pauseScreen();
}

void billingMenu() {
    int choice;

    do {
        cout << "=====================================\n";
        cout << "           BILLING SERVICES\n";
        cout << "=====================================\n";
        cout << "1. Add Bill\n";
        cout << "2. View Bills\n";
        cout << "3. Update Bill\n";
        cout << "4. Delete Bill\n";
        cout << "5. Back to Main Menu\n";
        cout << "=====================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                clearscreen();
                addBill();
                break;

            case 2:
                clearscreen();
                viewBills();
                break;

            case 3:
                clearscreen();
                updateBill();
                break;

            case 4:
                clearscreen();
                deleteBill();
                break;

            case 5:
                cout << "Returning to Main Menu...\n";
                Sleep(1000);
                clearscreen();
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);
}


int main() {

    if (!login()){
        return 0;
    }
    int choice;
    do {
        cout << "\n=====================================\n";
        cout << "     HOSPITAL MANAGEMENT SYSTEM\n";
        cout << "=====================================\n";
        cout << "1. Doctor Records\n";
        cout << "2. Patient Records\n";
        cout << "3. Doctor Appointments\n";
        cout << "4. Patient Reports\n";
        cout << "5. Billing Services\n";
        cout << "6. Exit\n";
        cout << "=====================================\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
            case 1:
                clearscreen();
                doctorMenu();
                break;

            case 2:
                clearscreen();
                patientMenu();
                break;
            case 3:
                clearscreen();
                appointmentMenu();
                break;
            case 4:
                clearscreen();
                reportMenu();
                break;
            case 5:
                clearscreen();
                billingMenu();
                break;
            case 6:
                cout << "\nThank you for using the Hospital Management System!\n";
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 6);




    return 0;
}
