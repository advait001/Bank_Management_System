#include "Tax_Invoice.h"
#include<iostream>

using namespace std;

void Tax_Invoice::Tax_Invoice_Slab()
{
	AnnualIncome = Income * 12;
	unsigned short num = 0;
	for (int i = 0; i < 1; i++) {
		if (AnnualIncome < 250000) {
			cout << "Tax To Pay = Null" << endl;
			TaxAmountPerMonth = 0;
			TaxSlab[i];
		}
		else if (AnnualIncome == 250000 || AnnualIncome <= 500000) {
			TaxAmountPerMonth = 5 * (AnnualIncome / 100);
			num = 1;
			cout << TaxSlab[i + 1];
		}
		else if (AnnualIncome == 500000 || AnnualIncome == 750000) {
			TaxAmountPerMonth = 10 * (AnnualIncome / 100);
			num = 2;
			TaxSlab[i + 2];
		}
		else if (AnnualIncome == 750000 || AnnualIncome <= 1000000) {
			TaxAmountPerMonth = 15 * (AnnualIncome / 100);
			num = 3;
			TaxSlab[i + 3];
		}
		else if (AnnualIncome == 1000000 || AnnualIncome <= 1200000) {
			TaxAmountPerMonth = 20 * (AnnualIncome / 100);
			num = 4;
			TaxSlab[i + 4];
		}
		else if (AnnualIncome == 1200000 || AnnualIncome <= 1500000) {
			TaxAmountPerMonth = 25 * (AnnualIncome / 100);
			num = 5;
			TaxSlab[i + 5];
		}
		else if (AnnualIncome >= 1500000) {
			TaxAmountPerMonth = 30 * (AnnualIncome / 100);
			num = 6;
			TaxSlab[i + 6];
		}
		cout << "\t|---------------Tax Invoice Report----------------" << endl;
		cout << "\t|Name : " << Name1 << "                   " << endl;
		cout << "\t|Phone Number : " << PhnNo << "            " << endl;
		cout << "\t|Income : " << Income << "               " << endl;
		cout << "\t|Age : " << Age << "                     " << endl;
		cout << "\t|AaDhar No : " << PanCardNO << "         " << endl;
		cout << "\t|Gender : " << Gender << "               " << endl;
		cout << "\t|Annual Income : " << AnnualIncome << "  " << endl;
		cout << "\t|Tax Amount Per Year : " << TaxAmountPerMonth << "" << endl;
		cout << "\t|Tax Slab : " << TaxSlab[i + num] << "            " << endl;
	}
}