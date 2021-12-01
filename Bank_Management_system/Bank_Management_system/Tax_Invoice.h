#pragma once
class Tax_Invoice
{
public:
	unsigned int Income;
	char Name1[30];
	char PhnNo[15];
	unsigned short Age;
	char aadharNumber;
	char PanCardNO[20];
	char Gender[1];
	char AccountNumber;
	unsigned long AnnualIncome;
	unsigned int TaxAmountPerMonth;
	const char* TaxSlab[7] = { "Slab 1","Slab 2","Slab 3","Slab 4","Slab 5","Slab 6","Slab 7" };
public:
	void Tax_Invoice_Slab();
};

