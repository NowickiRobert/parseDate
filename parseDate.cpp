// parseDate.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<string>


using namespace std;

enum Months {
	STYCZEN =1,
	LUTY,
	MARZEC,
	KWIECIEN,
	MAJ,
	CZERWIEC,
	LIPIEC,
	SIERPIEN,
	WRZESIEN,
	PAZDZIERNIK,
	LISTOPAD,
	GRUDZIEN
};

string parseMonth(int value) {
	switch (value) {
	case STYCZEN:		return "stycznia";
	case LUTY:			return "lutego";
	case MARZEC:		return "marca";
	case KWIECIEN:		return "kwietnia";
	case MAJ:			return "maja";
	case CZERWIEC:		return "czerwca";
	case LIPIEC:		return "lipca";
	case SIERPIEN:		return "sierpnia";
	case WRZESIEN:		return "wrzesnia";
	case PAZDZIERNIK:	return "pazdziernika";
	case LISTOPAD:		return "listopada";
	case GRUDZIEN:		return "grudnia";
	default: return "";
	}
	
}

string parseYear(int value) {
	if (value <= 20) {
		switch (value) {
			case 0: return "";
			case 1: return "pierwszego";
			case 2: return "drugiego";
			case 3: return "trzeciego";
			case 4: return "czwartego";
			case 5: return "piatego";
			case 6: return "szostego";
			case 7: return "siodmego";
			case 8: return "osmego";
			case 9: return "dziewiatego";
			case 10: return "dziesiatego";
			case 11: return "jedenastego";
			case 12: return "dwunastego";
			case 13: return "trzynastego";
			case 14: return "czternastego";
			case 15: return "pietnastego";
			case 16: return "szesnastego";
			case 17: return "siedemnastego";
			case 18: return "osiemnastego";
			case 19: return "dziewietnastego";
			case 20: return "dwudziestego";
		}		
	}
	else if (value < 100) {
		int d = value / 10;
		switch (d) {
		case 2: return "dwudziestego " + parseYear(value % 10);
		case 3: return "trzydziestego " + parseYear(value % 10);
		case 4: return "czterdziestego " + parseYear(value % 10);
		case 5: return "piecdziesiatego " + parseYear(value % 10);
		case 6: return "szescdziesiatego " + parseYear(value % 10);
		case 7: return "siedemdziesiatego " + parseYear(value % 10);
		case 8: return "osiemdziesiatego " + parseYear(value % 10);
		case 9: return "dziewiecdziesiatego " + parseYear(value % 10);
		}
	}
	else if(value < 1000){
		int d = value / 100;
		if (value % 100 != 0) {
			switch (d) {
				case 1: return "sto " + parseYear(value % 100);			
				case 2: return "dwiescie " + parseYear(value % 100);				
				case 3: return "trzysta " + parseYear(value % 100);				
				case 4: return "czterysta " + parseYear(value % 100);				
				case 5: return "piecset " + parseYear(value % 100);				
				case 6: return "szescset " + parseYear(value % 100);				
				case 7: return "siedemset " + parseYear(value % 100);				
				case 8: return "osiemdset " + parseYear(value % 100);				
				case 9: return "dziewiecset " + parseYear(value % 100);				
			}
		}
		else
		{
			switch (d) {
			case 1: return "setnego";			
			case 2: return "dwusetnego";
			case 3: return "trzysetnego";
			case 4:	return "czterysetnego";
			case 5: return "piecsetnego";
			case 6: return "szescsetnego";
			case 7: return "siedemsetnego";
			case 8: return "osiemsetnego";
			case 9: return "dziewiecsetnego";
			}
		}
	}
	else {
		int d = value / 1000;
		if(value%1000 != 0)
			switch (d) {
			case 1: return "tysiac " + parseYear(value % 1000);
			case 2: return "dwa tysiace " + parseYear(value % 1000);
			}
		else
		{
			switch (d) {
			case 1: return "tysiecznego ";
			case 2: return "dwutysiecznego ";
			}
		}
	}
	return "";
}

string parseDay(int value) {
	if (value <= 20) {
		switch (value) {
		case 0: return "";
		case 1: return "pierwszy";
		case 2: return "drugi";
		case 3: return "trzeci";
		case 4: return "czwarty";
		case 5: return "piaty";
		case 6: return "szosty";
		case 7: return "siodmy";
		case 8: return "osmy";
		case 9: return "dziewiaty";
		case 10: return "dziesiaty";
		case 11: return "jedenasty";
		case 12: return "dwunasty";
		case 13: return "trzynasty";
		case 14: return "czternasty";
		case 15: return "pietnasty";
		case 16: return "szesnasty";
		case 17: return "siedemnasty";
		case 18: return "osiemnasty";
		case 19: return "dziewietnasty";
		case 20: return "dwudziesty";
		}
	}
	else if (value < 100) {
		int d = value / 10;
		switch (d) {
		case 2: return "dwudziesty " + parseDay(value % 10);
		case 3: return "trzydziesty " + parseDay(value % 10);
		case 4: return "czterdziesty " + parseDay(value % 10);
		case 5: return "piecdziesiaty " + parseDay(value % 10);
		case 6: return "szescdziesiaty " + parseDay(value % 10);
		case 7: return "siedemdziesiaty " + parseDay(value % 10);
		case 8: return "osiemdziesiaty " + parseDay(value % 10);
		case 9: return "dziewiecdziesiaty " + parseDay(value % 10);
		}
	}
	return "";
}

bool isCorrectDate(unsigned int year, unsigned int month, unsigned int day)
{
	bool correctDay = false, correctMonth = false, correctYear = false, leap_year = false;
	//walidacja roku
	if (year > 2018) return false;
	correctYear = true;
	//czy przestepny
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) leap_year = true;
	//walidacja miesiaca (w odpowiednim zakresie 1-12)
	if (month > GRUDZIEN || month <= 0) return false;
	correctMonth = true;
	//walidacja dnia
	if (month == LUTY && (!leap_year && day > 28 || leap_year&&day>29)) return false;
	if (day < 1 || day>31) return false;
	if ((month == KWIECIEN || month == CZERWIEC || month == WRZESIEN || month == LISTOPAD) && day > 30) return false;
	correctDay = true;
	return correctYear && correctMonth&&correctDay;
	
}
void validateDate(unsigned int year, unsigned int month, unsigned int day)
{
	if (isCorrectDate(year, month, day))
		cout << parseDay(day) << " " << parseMonth(month) << " " << parseYear(year) << " roku" << endl;
	else cout << "Podano bledna date. Sprobuj jeszcze raz." << endl;
}

void printMenu()
{
	cout << "Wybierz q aby wyjsc z programu lub dowolony inny klawisz aby kontynuowac" << endl;
}

int main()
{

	int day, month, year;
	char menu;
	
	do
	{
		cout << "Prosze podac date w formacie RRRR MM DD" << endl;
		cin >> year >> month >> day;
		validateDate(year, month, day);
		printMenu();
		cin >> menu;
	} while (menu != 'q');
		
	
    return 0;
}

