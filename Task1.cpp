#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	string number;
	string gmail;
	string name;
	Node* prev;
	Node* next;
	Node(const string& n, const string& r, const string& g) : name(n), number(r), gmail(g), next(nullptr), prev(nullptr) {}
	friend class DLinkedList;
};

class DLinkedList {
	Node* head, *temp, *ptr;
	Node* ptr1, *ptr2, *dup;

public:
	Node* prevn;

	void insert();
	void sort();
	void deletecontact(const string& n);
	void deletesamenumber();
	void deletesamename();
	void deletesamegmail();
	void searchbyname(const string& p);
	void searchbynumber(const string& no);
	void searchbygmail(const string& g);
	void accept();
	void display();
	void update(const string& ch);
	DLinkedList() : head(nullptr), temp(nullptr), ptr(nullptr), ptr1(nullptr), ptr2(nullptr), dup(nullptr), prevn(nullptr) {}
};

void DLinkedList::accept() {
	string number;
	string gmail, name;
	char ans;
	do {
		cout << "ENTER NAME:";
		cin >> name;
		cout << "ENTER NUMBER:";
		cin >> number;
		while (number.length() != 10) {
			cout << "ENTER VALID NUMBER:";
			cin >> number;
		}
		cout << "ENTER G-MAIL:";
		cin >> gmail;
		temp = new Node(name, number, gmail);
		if (head == nullptr) {
			head = temp;
		}
		else {
			ptr = head;
			while (ptr->next != nullptr) {
				ptr = ptr->next;
			}
			ptr->next = temp;
			temp->prev = ptr;
		}
		cout << "DO YOU WANT TO CONTINUE(Y/N)";
		cin >> ans;
	} while (ans == 'y');
}

void DLinkedList::display() {
	ptr = head;
	while (ptr != nullptr) {
		cout << "NAME: " << ptr->name << endl;
		cout << "NUMBER: " << ptr->number << endl;
		cout << "GMAIL: " << ptr->gmail << endl;
		ptr = ptr->next;
	}
}

void DLinkedList::insert() {
	accept();
	sort();
}

void DLinkedList::sort() {
	Node* i, *j;
	string temp;
	for (i = head; i->next != nullptr; i = i->next) {
		for (j = i->next; j != nullptr; j = j->next) {
			if (i->name > j->name) {
				temp = i->name;
				i->name = j->name;
				j->name = temp;
			}
		}
	}
}

void DLinkedList::deletecontact(const string& s) {
	int c = 0;
	ptr = head;
	while (ptr != nullptr) {
		if (s == ptr->name) {
			c = 1;
			break;
		}
		else {
			c = 2;
		}
		ptr = ptr->next;
	}
	if (c == 1 && ptr != head && ptr->next != nullptr) {
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
		delete(ptr);
		cout << "YOUR CONTACT IS SUCCESSFULLY DELETED! " << endl;
	}
	if (ptr == head) {
		head = head->next;
		head->prev = nullptr;
		delete(ptr);
		cout << "YOUR CONTACT IS SUCCESSFULLY DELETED! " << endl;
	}
	if (ptr->next == nullptr) {
		ptr->prev->next = nullptr;
		ptr->prev = nullptr;
		delete(ptr);
		cout << "YOUR CONTACT IS SUCCESSFULLY DELETED!" << endl;
	}
	if (c == 2) {
		cout << "YOUR ENTERED NAME IS NOT IN THE LIST" << endl;
	}
}

void DLinkedList::deletesamename() {
	ptr1 = head;
	while (ptr1 != nullptr && ptr1->next != nullptr) {
		ptr2 = ptr1;
		while (ptr2->next != nullptr) {
			if (ptr1->name == ptr2->next->name) {
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				delete(dup);
			}
			else {
				ptr2 = ptr2->next;
			}
		}
		ptr1 = ptr1->next;
	}
}

void DLinkedList::deletesamegmail() {
	ptr1 = head;
	while (ptr1 != nullptr && ptr1->next != nullptr) {
		ptr2 = ptr1;
		while (ptr2->next != nullptr) {
			if (ptr1->gmail == ptr2->next->gmail) {
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				delete(dup);
			}
			else {
				ptr2 = ptr2->next;
			}
		}
		ptr1 = ptr1->next;
	}
}

void DLinkedList::deletesamenumber() {
	ptr1 = head;
	while (ptr1 != nullptr && ptr1->next != nullptr) {
		ptr2 = ptr1;
		while (ptr2->next != nullptr) {
			if (ptr1->number == ptr2->next->number) {
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				delete(dup);
			}
			else {
				ptr2 = ptr2->next;
			}
		}
		ptr1 = ptr1->next;
	}
}

void DLinkedList::searchbyname(const string& na) {
	ptr = head;
	while (ptr != nullptr) {
		if (na == ptr->name) {
			cout << "NAME FOUND" << endl;
			cout << "CONTACT DETAILS ARE BELOW:  " << endl;
			cout << "NAME:   " << ptr->name << endl;
			cout << "NUMBER: " << ptr->number << endl;
			cout << "Gmail:  " << ptr->gmail << endl;
		}
		ptr = ptr->next;
	}
}

void DLinkedList::searchbynumber(const string& num) {
	ptr = head;
	while (ptr != nullptr) {
		if (num == ptr->number) {
			cout << "NUMBER FOUND" << endl;
			cout << "CONTACT DETAILS ARE BELOW:" << endl;
			cout << "NAME  ::\t" << ptr->name << endl;
			cout << "NUMBER::\t+91-" << ptr->number << endl;
			cout << "G-MAIL::\t" << ptr->gmail << endl;
		}
		ptr = ptr->next;
	}
}

void DLinkedList::searchbygmail(const string& gm) {
	ptr = head;
	while (ptr != nullptr) {
		if (gm == ptr->gmail) {
			cout << "G-MAIL FOUND" << endl;
			cout << "CONTACT DETAILS ARE BELOW:" << endl;
			cout << "NAME  ::\t" << ptr->name << endl;
			cout << "NUMBER::\t+91-" << ptr->number << endl;
			cout << "G-MAIL::\t" << ptr->gmail << endl;
		}
		ptr = ptr->next;
	}
}

void DLinkedList::update(const string& n) {
	char ans;
	int c;
	ptr = head;
	while (ptr != nullptr) {
		if (n == ptr->name) {
			do {
				cout << endl;
				cout << "WHAT DO YOU WANT TO UPDATE? " << endl;
				cout << "1).NAME: " << endl;
				cout << "2).PHONE NUMBER: " << endl;
				cout << "3).GMAIL: " << endl;
				cin >> c;

				if (c == 1) {
					cout << "ENTER NEW-NAME=";
					cin >> ptr->name;
				}
				else if (c == 2) {
					cout << "ENTER NEW PHONE-NUMBER?";
					cin >> ptr->number;
					while (ptr->number.length() != 10) {
						cout << "ENTER VALID NUMBER  :";
						cin >> ptr->number;
					}
				}
				else if (c == 3) {
					cout << "ENTER NEW G-MAIL";
					cin >> ptr->gmail;
				}

				cout << "DO YOU WANT TO CONTINUE UPDATING?";
				cin >> ans;
			} while (ans == 'y');
		}
		ptr = ptr->next;
	}
}

int main() {
	string n, nam, name, number, gmail;
	DLinkedList d1;
	char ans;
	int ch, a;
	cout << "**************       PTCL PHONE BOOK DIRECTORY       ********************" << endl;
	cout << "WHAT IS YOUR NAME? " << endl;
	cin >> name;
	cout << "WELCOME Mr./Mrs." << name << "!" << endl;
	cout << "LET'S CREATE OUR PHONEBOOK " << name << endl;
	d1.accept();
	d1.sort();
	do {
		cout << "1). DISPLAY YOUR PHONE BOOK " << endl;
		cout << "2). INSERT NEW CONTACT " << endl;
		cout << "3). UPDATE DETAILS ON EXISTING CONTACT " << endl;
		cout << "4). DELETE CONTACT " << endl;
		cout << "5) DELETE SAME NAME IN PHONEBOOK " << endl;
		cout << "6) DELETE SAME NUMBERS IN PHONEBOOK " << endl;
		cout << "7) SEARCH " << endl;
		cout << "8) DELETE SAME GMAIL IN PHONEBOOK " << endl;
		cin >> ch;

		if (ch == 2) {
			d1.insert();
		}
		else if (ch == 1) {
			d1.display();
		}
		else if (ch == 3) {
			cout << "ENTER THE NAME OF PERSON YOU WANT TO UPDATE: " << endl;
			cin >> n;
			d1.update(n);
			d1.sort();
		}
		else if (ch == 4) {
			cout << "ENTER THE NAME YOU WANT TO DELETE: " << endl;
			cin >> name;
			d1.deletecontact(name);
		}
		else if (ch == 5) {
			d1.deletesamename();
			d1.display();
		}
		else if (ch == 6) {
			d1.deletesamenumber();
			d1.display();
		}
		else if (ch == 7) {
			do {
				cout << "1).SEARCH BY NAME " << endl;
				cout << "2).SEARCH BY NUMBER " << endl;
				cout << "3).SEARCH BY GMAIL " << endl;
				cin >> a;
				if (a == 1) {
					cout << "ENTER THE NAME TO BE SEARCHED" << endl;
					cin >> name;
					d1.searchbyname(name);
				}
				else if (a == 2) {
					cout << "ENTER THE NUMBER TO BE SEARCHED" << endl;
					cin >> number;
					d1.searchbynumber(number);
				}
				else if (a == 3) {
					cout << "ENTER THE GMAIL TO BE SEARCHED" << endl;
					cin >> gmail;
					d1.searchbygmail(gmail);
				}
				else {
					cout << "NO PROPER INPUT GIVEN....." << endl;
				}
				cout << "DO YOU WANT TO CONTINUE SEARCHING?";
				cin >> ans;
			} while (ans == 'y');
		}
		else if (ch == 8) {
			d1.deletesamegmail();
			d1.display();
		}
		else {
			cout << "NO PROPER INPUT GIVEN.." << endl;
		}

		cout << "DO YOU WANT TO CONTINUE OPERATIONS?";
		cin >> ans;
	} while (ans == 'y');

	return 0;
}
