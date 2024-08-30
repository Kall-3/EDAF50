#include <iostream>

using namespace std;

class person {
    public:
        person(const string& fname, const string& lname);
        virtual ~person() = default;
        person(const person&) = delete;
        person& operator=(const person&) = delete;

        virtual string to_string() const;
        const string& first_name() const { return fn; };
        const string& last_name() const { return ln; };
    private:
        string fn;
        string ln;
};

person::person(const string& fname, const string& lname) : fn(fname), ln(lname) {}

class student : public person {
    using person::person;
    virtual string to_string() const override;
};

class teacher : public person {
    using person::person;
    virtual string to_string() const override;
};

string person::to_string() const {
    return first_name() + " " + last_name();
}

string student::to_string() const {
    return first_name() + " " + last_name();
}

string teacher::to_string() const {
    return first_name() + " " + last_name();
}

void print(const person& p) {
    cout << p.to_string() << endl;
}

const person& make_person(const string& fname, const string& lname) {
    return person(fname, lname);
}

const student& make_student(const string& fname, const string& lname) {
    student s(fname, lname);
    return s;
}

void example1() {
    const auto& p1 = make_person("John", "Doe");
    print(p1);
}

void example2() {
    const auto& s1 = make_student("John", "Doe");
    print(s1);
}

int main (int argc, char *argv[]) {
    cout << "example2" << endl;
    example2();
    return 0;
}
