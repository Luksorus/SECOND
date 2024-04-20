#include <iostream>

using namespace std;

class Person {
private:
	int getSign() {
		int day, month, year; 
        sscanf(this->dateOfBirth.c_str(), "%d.%d.%d", &day, &month, &year);

		if ((month == 3 && day >= 21) || (month == 4 && day <= 20)) {
			return 1;
		} else if ((month == 4 && day >= 21) || (month == 5 && day <= 21)) {
			return 2;
		} else if ((month == 5 && day >= 22) || (month == 6 && day <= 21)) {
			return 3;
		} else if ((month == 6 && day >= 22) || (month == 7 && day <= 22)) {
			return 4;
		} else if ((month == 7 && day >= 23) || (month == 8 && day <= 21)) {
			return 5;
		} else if ((month == 8 && day >= 22) || (month == 9 && day <= 23)) {
			return 6;
		} else if ((month == 9 && day >= 24) || (month == 10 && day <= 23)) {
			return 7;
		} else if ((month == 10 && day >= 24) || (month == 11 && day <= 22)) {
			return 8;
		} else if ((month == 11 && day >= 23) || (month == 12 && day <= 22)) {
			return 9;
		} else if ((month == 12 && day >= 23) || (month == 1 && day <= 20)) {
			return 10;
		} else if ((month == 1 && day >= 21) || (month == 2 && day <= 19)) {
			return 11;
		} else if ((month == 2 && day >= 20) || (month == 3 && day <= 20)) {
			return 12;
		}
		return 0;
	}
public:
	string firstName;
	string lastName;
	string gender;
	string dateOfBirth;
	int astrologicalSign;

	Person(string _firstName, string _lastName, string _gender, string _dateOfBirth) :
		firstName(_firstName), lastName(_lastName), gender(_gender), dateOfBirth(_dateOfBirth) {
		this->astrologicalSign = getSign();
	};

	void goAway();
    virtual void find() = 0;
};

Person* peoples[10];

void Person::goAway() {
    int personIndex = 0;
    for (int i = 0; i < 10; ++i) {
        if (peoples[i] == this) {
            personIndex = i;
            break;
        }
    }

    for (int i = personIndex; i < 9; ++i) {
        peoples[i] = peoples[i + 1];
    }
    peoples[9] = nullptr;
}

class MilkHunter : public Person {
public:
    MilkHunter(string sex, string date, string name, string surname) : Person(sex, date, name, surname) {};
    void find();
};

class Skuf : public Person {
public:
    Skuf(string sex, string date, string name, string surname) : Person(sex, date, name, surname) {};
    void find();
};

class Altushka : public Person {
public:
    Altushka(string sex, string date, string name, string surname) : Person(sex, date, name, surname) {};
    void find();
};

class Extended : public Person {
public:
    Extended(string sex, string date, string name, string surname) : Person(sex, date, name, surname) {};
    void find();
};

void Skuf::find() {
    int index = -1;
    string minDate = "00.00.00";
    for (int i = 0; i < 10; ++i) {
        Altushka* altushka = dynamic_cast<Altushka*>(peoples[i]);
        if (altushka && altushka->dateOfBirth > minDate) {
            minDate = altushka->dateOfBirth;
            index = i;
        }
    }
    if (index != -1) {
        cout << peoples[index]->firstName << endl;
        cout << peoples[index]->lastName << endl;
        cout << peoples[index]->dateOfBirth << endl;
    }
    else {
        cout << "oops" << endl;
    }
}

void MilkHunter::find() {
    int index = -1;
    string maxDate = "99.99.9999";
    for (int i = 0; i < 10; ++i) {
        Extended* extended = dynamic_cast<Extended*>(peoples[i]);
        if (extended && extended->dateOfBirth < maxDate) {
            maxDate = extended->dateOfBirth;
            index = i;
        }
    }
    if (index != -1) {
        cout << peoples[index]->firstName << endl;
        cout << peoples[index]->lastName << endl;
        cout << peoples[index]->dateOfBirth << endl;
    }
    else {
        cout << "oops" << endl;
    }
}

void Altushka::find() {
    int index = -1;
    string minData = "00.00.00";
    for (int i = 0; i < 10; i++) {
        Skuf* skuf = dynamic_cast<Skuf*>(peoples[i]);
        if (skuf && this->astrologicalSign == skuf->astrologicalSign && skuf->dateOfBirth > minData) {
            minData = skuf->dateOfBirth;
            index = i;
        }
    }
    if (index != -1) {
        cout << peoples[index]->firstName << endl;
        cout << peoples[index]->lastName << endl;
        cout << peoples[index]->dateOfBirth << endl;
    }
    else {
        cout << "oops" << endl;
    }
}

void Extended::find() {
    int index = -1;
    string maxData = "99.99.9999";
    for (int i = 0; i < 10; i++) {
        MilkHunter* milkHunter = dynamic_cast<MilkHunter*>(peoples[i]);
        if (milkHunter && milkHunter->astrologicalSign == (this->astrologicalSign + 6) % 12 && milkHunter->dateOfBirth < maxData) {
            maxData = milkHunter->dateOfBirth;
            index = i;
        }
    }
    if (index != -1) {
        cout << peoples[index]->firstName << endl;
        cout << peoples[index]->lastName << endl;
        cout << peoples[index]->dateOfBirth << endl;
    }
    else {
        cout << "oops" << endl;
    }
}

Person *goIn() {
    string gender;
    string firstName;
    string lastName;
    string birthDate;
    int day, month, year;

    cin >> lastName >> firstName >> gender >> birthDate;
    sscanf(birthDate.c_str(), "%d.%d.%d", &day, &month, &year);

    int age = 2024 - year;
    if ((month > 1) || ((month == 1) && (day > 1))) {
        age--;
    }

    if (gender == "m" && age >= 25) {
        return new Skuf(firstName, lastName, gender, birthDate);
    } else if (gender == "m" && age < 25) {
        return new MilkHunter(firstName, lastName, gender, birthDate);
    } else if (gender == "f" && age >= 25) {
        return new Extended(firstName, lastName, gender, birthDate);
    } else if (gender == "f" && age < 25) {
        return new Altushka(firstName, lastName, gender, birthDate);
    }
    return nullptr;
}
#include "main3_5.cpp"
