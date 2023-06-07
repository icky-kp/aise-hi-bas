#include <iostream>

class Employee {
private:
    int emp_ID;
    std::string name;
    std::string designation;

public:
    static double salary_After_INC;

    Employee() {
        emp_ID = 0;
        name = "";
        designation = "";
        std::cout << "Employee ID: " << emp_ID << std::endl;
        std::cout << "Employee Name: " << name << std::endl;
        std::cout << "Employee Designation: " << designation << std::endl;
    }

    Employee(int emp_ID, std::string name, std::string designation)
        : emp_ID(emp_ID), name(name), designation(designation) {
        std::cout << "Employee ID: " << emp_ID << std::endl;
        std::cout << "Employee Name: " << name << std::endl;
        std::cout << "Employee Designation: " << designation << std::endl;
    }

    void calculateSalary(double basicPay, double DA, double HRA) {
        double salary_before_INC = basicPay + DA + HRA;
        std::cout << "Basic pay of Employee: " << basicPay << std::endl;
        std::cout << "DA of Employee: " << DA << std::endl;
        std::cout << "HRA of Employee: " << HRA << std::endl;
        std::cout << "Salary_Before_INC: " << salary_before_INC << std::endl;
    }

    static void calculateIncrement(double& DA) {
        DA += (DA * 0.06);  // Increment DA by 6%
    }

    static void displaySalary_After_INC() {
        std::cout << "Salary_After_INC: " << salary_After_INC << std::endl;
    }
};

double Employee::salary_After_INC = 0.0;

int main() {
    Employee AP;
    std::cout << std::endl;

    Employee ASP(1234, "John Doe", "Associate Professor");
    ASP.calculateSalary(95800, 0.25 * 95800, 0.08 * 95800);
    std::cout << std::endl;

    Employee PROF(5678, "Jane Smith", "Professor");
    PROF.calculateSalary(105000, 0.25 * 105000, 0.08 * 105000);
    std::cout << std::endl;

    // Increment DA for all employees
    double DA = 0.25 * 77500;  // DA for Assistant Professor
    Employee::calculateIncrement(DA);
    Employee::salary_After_INC = DA + 77500;  // Set salary_After_INC for Assistant Professor
    Employee::displaySalary_After_INC();

    DA = 0.25 * 95800;  // DA for Associate Professor
    Employee::calculateIncrement(DA);
    Employee::salary_After_INC = DA + 95800;  // Set salary_After_INC for Associate Professor
    Employee::displaySalary_After_INC();

    DA = 0.25 * 105000;  // DA for Professor
    Employee::calculateIncrement(DA);
    Employee::salary_After_INC = DA + 105000;  // Set salary_After_INC for Professor
    Employee::displaySalary_After_INC();

    return 0;
}
