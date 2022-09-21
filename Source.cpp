#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

//#define PRERELEASE

struct STUDENT_DATA {
	void put_first_name(string Iname) { first_name = Iname; }
	void put_last_name(string Iname) { last_name = Iname; }
	void put_email(string Iemail) { email = Iemail; }

	string get_first_name() { return first_name; }
	string get_last_name() { return last_name; }
	string get_email() { return email; }

private:
	string first_name;
	string last_name;
	string email;
};

int main() {

	string student_data_names = "StudentData.txt";
	string student_data_emails = "StudentData_Emails.txt";
	string read_line;

	vector <STUDENT_DATA> students;
	STUDENT_DATA student_data;

	ifstream file;

	#ifdef PRERELEASE
	cout << "Pre-release running" << endl;

	file.open(student_data_emails);

	if (!file) {
		cout << "Cannot open file." << endl;
		return 1;
	}

	while (!file.eof()) {
		string input;
		getline(file, input, ',');
		student_data.put_last_name(input);

		getline(file, input, ',');
		student_data.put_first_name(input);

		getline(file, input);
		student_data.put_email(input);

		students.push_back(student_data);
	}
	#else
	cout << "Standard running" << endl;

	file.open(student_data_names);

	while (!file.eof()) {
		string input;
		getline(file, input, ',');
		student_data.put_last_name(input);

		getline(file, input);
		student_data.put_first_name(input);

		students.push_back(student_data);
	}
	#endif

	file.close();

	#ifdef _DEBUG
	for (int c = 0; c < students.size(); c++) {
		#ifdef PRERELEASE
		cout << students[c].get_last_name() << ",";
		cout << students[c].get_first_name() << ",";
		cout << students[c].get_email() << endl;
		#else
		cout << students[c].get_last_name() << ",";
		cout << students[c].get_first_name() << endl;
		#endif
	}
	#endif

	return 1;
}