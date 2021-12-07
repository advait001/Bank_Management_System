#include "Tax_Invoice.h"
#include<iostream>

using namespace std;

void Tax_Invoice::Tax_Invoice_Slab()
{
	AnnualIncome = Income * 12;//..for calculating annual income
	unsigned short num = 0;
	for (int i = 0; i < 1; i++) {
		if (AnnualIncome < 250000) {//..If annual income is less then 2.5 lakhs you don't have to pay tax
			cout << "Tax To Pay = Null" << endl;
			TaxAmountPerMonth = 0;
			TaxSlab[i];//..slab 1
		}
		else if (AnnualIncome == 250000 || AnnualIncome <= 500000) 
		{//..if annual salary is between 2.5 lakhs and 5 lakhs the interest rate will be 5 %
			TaxAmountPerMonth = 5 * (AnnualIncome / 100);
			num = 1;
			cout << TaxSlab[i + 1];//..slab 2
		}
		else if (AnnualIncome == 500000 || AnnualIncome == 750000)
		{//..if annual salary is between 5 lakhs and 7.5 lakhs the interest rate will be 10 %
			TaxAmountPerMonth = 10 * (AnnualIncome / 100);
			num = 2;
			TaxSlab[i + 2];
		}
		else if (AnnualIncome == 750000 || AnnualIncome <= 1000000) 
		{//..if annual salary is between 7.5 lakhs and 10 lakhs the interest rate will be 15 %
			TaxAmountPerMonth = 15 * (AnnualIncome / 100);
			num = 3;
			TaxSlab[i + 3];
		}
		else if (AnnualIncome == 1000000 || AnnualIncome <= 1250000) 
		{//..if annual salary is between 10 lakhs and 12.5 lakhs the interest rate will be 20 %
			TaxAmountPerMonth = 20 * (AnnualIncome / 100);
			num = 4;
			TaxSlab[i + 4];
		}
		else if (AnnualIncome == 1250000 || AnnualIncome <= 1500000)
		{//..if annual salary is between 12.5 lakhs and 15 lakhs the interest rate will be 25 %
			TaxAmountPerMonth = 25 * (AnnualIncome / 100);
			num = 5;
			TaxSlab[i + 5];
		}
		else if (AnnualIncome >= 1500000)
		{//..if annual salary is  15 lakhs the interest rate will be 30 %
			TaxAmountPerMonth = 30 * (AnnualIncome / 100);
			num = 6;
			TaxSlab[i + 6];
		}
		//..Tax Invoice Reported Display
		cout << "\t|---------------Tax Invoice Report----------------" << endl;
		cout << "\t|Name : " << Name1 << endl;
		cout << "\t|Account Number : " << AccountNumber << endl;
		cout << "\t|Phone Number : " << PhnNo << endl;
		cout << "\t|Income : " << Income << endl;
		cout << "\t|Age : " << Age << endl;
		cout << "\t|AaDhar No : " << PanCardNO << endl;
		cout << "\t|Gender : " << Gender << endl;
		cout << "\t|Annual Income : " << AnnualIncome << endl;
		cout << "\t|Tax Amount Per Year : " << TaxAmountPerMonth << endl;
		cout << "\t|Tax Slab : " << TaxSlab[i + num] << endl;
		cout << "\t------------------------------------------------------" << endl;
	}
}