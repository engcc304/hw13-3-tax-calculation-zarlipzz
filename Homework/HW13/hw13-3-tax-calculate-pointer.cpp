/*
    HR ของบริษัทเน็ตเวิร์คทำการกรอกข้อมูลพนักงานลงไปในระบบคำนวณฐานภาษีเพื่อเตรียมส่งยอดภาษีสู่ฝ่ายบัญชี โดยจะหักภาษี ณ ที่จ่าย 7% ของเงินเดือนที่ได้ ให้คุณคำนวณภาษีพนักงานทั้งหมดที่บริษัทของคุณต้องชำระภายในปีนี้ (กรอกเลข -1 ถือเป็นการสิ้นสุดการกรอก และทำการสรุปผลภาษีที่ต้องชำระภายในปีนี้) และสร้างฟังก์ชันที่ระบุคนที่ต้องชำระภาษีเยอะที่สุดในบริษัทมาแสดงในผลสรุปยอดของบริษัทด้วย
    (กำหนดให้ฟังก์ชันที่สร้างขึ้น ห้ามมีการใช้คำสั่ง return แต่สามารถส่งผ่านค่าแบบ pass by reference ได้เท่านั้น)

    Test case:
        Employee 1's Name : 
            Omar
        Sarary (Bath/Month) : 
            12750
        Employee 2's Name : 
            Alice
        Sarary (Bath/Month) : 
            15900
        Employee 3's Name : 
            Max
        Sarary (Bath/Month) : 
            19860
        Employee 4's Name : 
            -1
    Output:
        All salary per month: 48,510.00 Bath
        All salary per year: 582,120.00 Bath
        Tax (7% per year) : 40,748.40 Bath
        Most tax in company : Max (16,682.40 Bath per year)

    Test case:
        Employee 1's Name : 
            John
        Sarary (Bath/Month) : 
            15780
        Employee 2's Name : 
            Oven
        Sarary (Bath/Month) : 
            16890
        Employee 3's Name : 
            May
        Sarary (Bath/Month) : 
            17870
        Employee 4's Name : 
            Bill
        Sarary (Bath/Month) : 
            22100
        Employee 5's Name : 
            -1
    Output:
        All salary per month: 72,640.00 Bath
        All salary per year: 871,680.00 Bath
        Tax (7% per year) : 61,017.60 Bath
        Most tax in company : Bill (18,564.00 Bath per year)
*/
#include <stdio.h>

typedef struct {
    char name[50];
    float salary;
} Employee;

void calculateTax(Employee employees[]) {
    float totalSalaryPerMonth = 0;
    float totalSalaryPerYear = 0;
    Employee maxTaxEmployee;
    float maxTax = 0;

    for (int i = 0; i < 100; i++) {
        if (employees[i].name[0] == '-' && employees[i].name[1] == '1') {
            break;
        }

        totalSalaryPerMonth += employees[i].salary;
        totalSalaryPerYear += employees[i].salary * 12;

        float tax = employees[i].salary * 12 * 0.07;

        if (tax > maxTax) {
            maxTax = tax;
            maxTaxEmployee = employees[i];
        }
    }

    printf("All salary per month: %.2f Bath\n", totalSalaryPerMonth);
    printf("All salary per year: %.2f Bath\n", totalSalaryPerYear);
    printf("Tax (7%% per year): %.2f Bath\n", totalSalaryPerYear * 0.07);
    printf("Most tax in company: %s (%.2f Bath per year)\n", maxTaxEmployee.name, maxTax);
}

int main() {
    Employee employees[100];

    for (int i = 0; i < 100; i++) {
        printf("Employee's Name: ");
        scanf("%s", employees[i].name);

        if (employees[i].name[0] == '-' && employees[i].name[1] == '1') {
            break;
        }

        printf("Salary (Bath/Month): ");
        scanf("%f", &employees[i].salary);
    }

    calculateTax(employees);

    return 0;
}
