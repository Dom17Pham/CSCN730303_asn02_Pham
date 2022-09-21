#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

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

	file.open(student_data_names);

	if (!file) {
		cout << "Cannot open file." << endl;
		return 1;
	}

	while (!file.eof()) {
		string input;
		getline(file, input, ',');
		student_data.put_last_name(input);

		getline(file, input);
		student_data.put_first_name(input);

		students.push_back(student_data);
	}

	file.close();

	return 1;
}