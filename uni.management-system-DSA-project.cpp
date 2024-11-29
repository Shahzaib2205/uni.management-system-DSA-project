# include <iostream>
using namespace std;
	class Node {
public:
	int id;
	string name;
	int semester;
	string dateOfBirth;
	string phone;
	float cgpa;
	Node* next;
	Node(int i, int sem, float gpa, string nm, string dob, string ph) {
		id = i;
		semester = sem;
		cgpa = gpa;
		name = nm;
		dateOfBirth = dob;
		phone = ph;
		next = NULL;
	}
};
	class student {
		Node* head = NULL;
	public:
		void insertAtStart(int i, int sem, float gpa, string nm, string dob, string ph) {
			Node* newStudent = new Node(i, sem, gpa, nm, dob, ph);
			newStudent->next = head;
			head = newStudent;
		}
		void insertAtEnd(int i, int sem, float gpa, string nm, string dob, string ph) {
			Node* newStudent = new Node(i, sem, gpa, nm, dob, ph);
			Node* temp = head;
			if (head == NULL)
			{
				insertAtStart(i, sem, gpa, nm, dob, ph);
			}
			else {
				while (temp != NULL) {
					temp = temp->next;
				}
				temp->next = newStudent;
			}
		}
		void insertInOrder(int i, int sem, float gpa, string nm, string dob, string ph) {
			Node* newStudent = new Node(i, sem, gpa, nm, dob, ph);
			if (head == NULL || i < head->id) {
				newStudent->next = head;
				head = newStudent;
			}
			else {
				Node* temp = head;
				while (temp->next != NULL && temp->next->id < i) {
					temp = temp->next;
				}
				newStudent->next = temp->next;
				temp->next = newStudent;
			}
		}

		void printList() {
			Node* temp = head;
			while (temp != NULL) {
				cout << "ID: " << temp->id << " | Name: " << temp->name << " | CGPA: " << temp->cgpa << endl;
				temp = temp->next;
			}
		}
		void deleteAtStart() {
			Node* temp = head;
			head = temp->next;
			delete temp;
			temp = NULL;

		}

		void deleteAtEnd() {
			if (head == nullptr) {
				cout << "List is already empty." << endl;
				return;
			}
			else if (head->next == nullptr) {
				delete head;
				head = nullptr;
				return;
			}
			else{
				Node* temp = head;
			while (temp->next->next != nullptr) {
				temp = temp->next;
			}
			delete temp->next;
			temp->next = NULL;
		}
		}
		void deleteAtPosition() {
			int pos;
			cin >> pos;
			if (pos < 1) {
				cout << "invalid position" << endl;
				return;
			}
			else if (pos == 1) {
				deleteAtStart();
				return;

			}
			else {
				Node* temp = head;
				Node* temp2 = NULL;
				for (int i = 1; i < pos - 1; i++) {
					temp = temp->next;
				}
				if (temp == NULL) {
					cout << "position not found" << endl;
					return;
				}
				else {
					temp2 = temp->next;
					temp->next = temp2->next;
					delete temp2;
					temp2 = NULL;
				}

			}

		}
		void searchById() {
			int Id;
			Node* temp = head;
			cout << "Enter the id \n";
			cin >> Id;
			if (Id < 1) {
				cout << "invalid position \n";
				return;
			}
			else {
				while (temp != NULL)
				{
					if (temp->id == Id) {
						cout << "name= " << temp->name << "	rollno.= " << temp->id << endl;
					}
					temp = temp->next;
				}

			}

		}
		void update() {
			int id;
			cout << "Enter the ID  to update the details\n" << endl;
			cin >> id;
			Node* temp = head;
			while (temp != NULL) {
				if (id == temp->id) {
					cout << "Enter the details \n";
					cout << "Enter the name::";
					cin >> temp->name;
					cout << "Enter the cgpa::";
					cin >> temp->cgpa;
					cout << "Enetr the phone number::";
					cin >> temp->phone;
					cout << "Enter the dateOfBirth::";
					cin >> temp->dateOfBirth;
					cout << "Enter the id::";
					cin >> temp->id;
					cout << "Enter the semester::";
					cin >> temp->semester;
					return;
				}

				temp = temp->next;
			}

		}

	};
	class TeacherNode {
	public:
		int id;
		string name;
		string department;
		string designation;
		string dateOfBirth;
		string phone;
		double salary;
		TeacherNode* next;

		TeacherNode(int i, string nm, string dept, string desg, string dob, string ph, double sal) {
			id = i;
			name = nm;
			department = dept;
			designation = desg;
			dateOfBirth = dob;
			phone = ph;
			salary = sal;
			next = NULL;
		}
	};
	class Teacher {
		TeacherNode* head = NULL;

	public:
		void insertAtStart(int i, string nm, string dept, string desg, string dob, string ph, double sal) {
			TeacherNode* newTeacher = new TeacherNode(i, nm, dept, desg, dob, ph, sal);
			newTeacher->next = head;
			head = newTeacher;
		}

		void insertAtEnd(int i, string nm, string dept, string desg, string dob, string ph, double sal) {
			TeacherNode* newTeacher = new TeacherNode(i, nm, dept, desg, dob, ph, sal);
			if (head == NULL) {
				insertAtStart(i, nm, dept, desg, dob, ph, sal);
			}
			else {
				TeacherNode* temp = head;
				while (temp->next != NULL) {
					temp = temp->next;
				}
				temp->next = newTeacher;
			}
		}

		void insertInOrder(int i, string nm, string dept, string desg, string dob, string ph, double sal) {
			TeacherNode* newTeacher = new TeacherNode(i, nm, dept, desg, dob, ph, sal);

			if (head == NULL || i < head->id) {
				newTeacher->next = head;
				head = newTeacher;
			}
			else {
				TeacherNode* temp = head;
				while (temp->next != NULL && temp->next->id < i) {
					temp = temp->next;
				}
				newTeacher->next = temp->next;
				temp->next = newTeacher;
			}
		}

		void printList() {
			TeacherNode* temp = head;
			while (temp != NULL) {
				cout << "ID: " << temp->id
					<< " | Name: " << temp->name
					<< " | Department: " << temp->department
					<< " | Designation: " << temp->designation
					<< " | Salary: " << temp->salary << endl;
				temp = temp->next;
			}
		}

		void deleteAtStart() {
			if (head == NULL) {
				cout << "List is already empty." << endl;
				return;
			}
			TeacherNode* temp = head;
			head = head->next;
			delete temp;
		}

		void deleteAtEnd() {
			if (head == NULL) {
				cout << "List is already empty." << endl;
				return;
			}
			if (head->next == NULL) {
				delete head;
				head = NULL;
				return;
			}
			TeacherNode* temp = head;
			while (temp->next->next != NULL) {
				temp = temp->next;
			}
			delete temp->next;
			temp->next = NULL;
		}

		void deleteAtPosition() {
			int pos;
			cout << "Enter position to delete: ";
			cin >> pos;

			if (pos < 1) {
				cout << "Invalid position." << endl;
				return;
			}
			if (pos == 1) {
				deleteAtStart();
				return;
			}
			TeacherNode* temp = head;
			for (int i = 1; i < pos - 1 && temp != NULL; i++) {
				temp = temp->next;
			}
			if (temp == NULL || temp->next == NULL) {
				cout << "Position not found." << endl;
				return;
			}
			TeacherNode* temp2 = temp->next;
			temp->next = temp2->next;
			delete temp2;
		}

		void searchById() {
			int Id;
			cout << "Enter ID to search: ";
			cin >> Id;

			TeacherNode* temp = head;
			while (temp != NULL) {
				if (temp->id == Id) {
					cout << "ID: " << temp->id
						<< " | Name: " << temp->name
						<< " | Department: " << temp->department
						<< " | Designation: " << temp->designation
						<< " | Salary: " << temp->salary << endl;
					return;
				}
				temp = temp->next;
			}
			cout << "Teacher with ID " << Id << " not found." << endl;
		}

		void update() {
			int id;
			cout << "Enter ID to update: ";
			cin >> id;

			TeacherNode* temp = head;
			while (temp != NULL) {
				if (temp->id == id) {
					cout << "Enter new details:" << endl;
					cout << "Name: ";
					cin >> temp->name;
					cout << "Department: ";
					cin >> temp->department;
					cout << "Designation: ";
					cin >> temp->designation;
					cout << "Date of Birth: ";
					cin >> temp->dateOfBirth;
					cout << "Phone: ";
					cin >> temp->phone;
					cout << "Salary: ";
					cin >> temp->salary;
					return;
				}
				temp = temp->next;
			}
			cout << "Teacher with ID " << id << " not found." << endl;
		}
	};
	int main() {
		student s1;
		Teacher t1;
		int choice;

		do {
			
			cout << "\n--- University Management System ---\n";
			cout << "1. Add Student\n";
			cout << "2. Add Teacher\n";
			cout << "3. Display All Students\n";
			cout << "4. Display All Teachers\n";
			cout << "5. Search Student by ID\n";
			cout << "6. Search Teacher by ID\n";
			cout << "7. Update Student Details\n";
			cout << "8. Update Teacher Details\n";
			cout << "9. Delete Student\n";
			cout << "10. Delete Teacher\n";
			cout << "0. Exit\n";
			cout << "Enter your choice: ";
			cin >> choice;

			switch (choice) {
			case 1: {
				int id, sem;
				float cgpa;
				string name, dob, phone;
				cout << "Enter Student ID: ";
				cin >> id;
				cout << "Enter Name: ";
				cin >> name;
				cout << "Enter Semester: ";
				cin >> sem;
				cout << "Enter CGPA: ";
				cin >> cgpa;
				cout << "Enter Date of Birth: ";
				cin >> dob;
				cout << "Enter Phone Number: ";
				cin >> phone;
				s1.insertInOrder(id, sem, cgpa, name, dob, phone);
				system("cls");
				break;
			}
			case 2: {
				int id;
				string name, department, designation, dob, phone;
				double salary;
				cout << "Enter Teacher ID: ";
				cin >> id;
				cout << "Enter Name: ";
				cin >> name;
				cout << "Enter Department: ";
				cin >> department;
				cout << "Enter Designation: ";
				cin >> designation;
				cout << "Enter Date of Birth: ";
				cin >> dob;
				cout << "Enter Phone Number: ";
				cin >> phone;
				cout << "Enter Salary: ";
				cin >> salary;
				t1.insertInOrder(id, name, department, designation, dob, phone, salary);
				break;
			}
			case 3:
				cout << "\n--- List of Students ---\n";
				system("cls");
				s1.printList();
				
				break;
			case 4:
				cout << "\n--- List of Teachers ---\n";
				t1.printList();
				break;
			case 5:
				s1.searchById();
				break;
			case 6:
				t1.searchById();
				break;
			case 7:
				s1.update();
				break;
			case 8:
				t1.update();
				break;
			case 9: {
				cout << "\n--- Delete Student ---\n";
				int subChoice;
				cout << "1. Delete First Student\n";
				cout << "2. Delete Last Student\n";
				cout << "3. Delete Student by Position\n";
				cout << "Enter your choice: ";
				cin >> subChoice;
				if (subChoice == 1) s1.deleteAtStart();
				else if (subChoice == 2) s1.deleteAtEnd();
				else if (subChoice == 3) s1.deleteAtPosition();
				else cout << "Invalid choice.\n";
				break;
			}
			case 10: {
				cout << "\n--- Delete Teacher ---\n";
				int subChoice;
				cout << "1. Delete First Teacher\n";
				cout << "2. Delete Last Teacher\n";
				cout << "3. Delete Teacher by Position\n";
				cout << "Enter your choice: ";
				cin >> subChoice;
				if (subChoice == 1) t1.deleteAtStart();
				else if (subChoice == 2) t1.deleteAtEnd();
				else if (subChoice == 3) t1.deleteAtPosition();
				else cout << "Invalid choice.\n";
				break;
			}
			case 0:
				cout << "Exiting the system. Goodbye!\n";
				break;
			default:
				cout << "Invalid choice. Please try again.\n";
			}
		} while (choice != 0);

		return 0;
	}
