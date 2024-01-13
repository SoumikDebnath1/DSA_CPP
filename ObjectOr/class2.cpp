// Object is an instance of a class
// one byte is the smallest addessable memory so an empty class will stored in a one byte space
// padding
/*if there is a int variable and a bool variable inside
a class it shows 8 bit even though  it should be 5 because while picking 4 bits cpu have to perform extra operation to get the 1 bit for bool
,to avoid that case it addjust thid secniario using padding adding 3 more bit with that one bit */
// if the data type is too big then it only  add padding to the nearest and the bigest multiple of a small data type
// when we use something only in surface lever it's called abstraction we do not khow what is in the back ground
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
private:
    string gf;

public:
    int id;
    int age;
    bool present;
    string name;
    int nos;
    int *v;

    // ctor: Default ctor: assigns garbage value
    // no khokhla student
    Student()
    {
        cout << "Student ctor called" << endl;
    }

    // paremeterized ctor
    Student(int id, int age, bool present, string name, int nos, string gf)
    {
        this->id = id;
        this->age = age;
        this->present = present;
        this->name = name;
        this->nos = nos;
        this->gf = gf;
        this->v = new int(10);
        cout << "Student paremeterized ctor called" << endl;
    }

    Student(int id, int age, bool present, string name, int nos)
    {
        this->id = id;
        this->age = age;
        this->present = present;
        this->name = name;
        this->nos = nos;
        cout << "Student paremeterized ctor w/o gf called" << endl;
    }

    // copy ctor
    Student(const Student &srcobj)
    {
        cout << "Student copy ctor called" << endl;
        this->name = srcobj.name;
        this->age = srcobj.age;
        this->gf = srcobj.gf;
        this->nos = srcobj.nos;
        this->present = srcobj.present;
        this->id = srcobj.id;
    }

    // getter / setter
    string getGfName()
    {
        return gf;
        // return this->gf;
    }

    void setGfName(string gf)
    {
        this->gf = gf;
    }

    void study()
    {
        cout << "studying" << endl;
    }
    void sleep()
    {
        cout << "sleeping" << endl;
    }
    void bunk()
    {
        cout << "bunking" << endl;
    }

    ~Student()
    {
        cout << "Student dtor called" << endl;
        delete v;
    }

private:
    void gfchatting()
    {
        cout << "Chatting" << endl;
    }

    void cheating()
    {
        cout << "Cheating" << endl;
    }
};

int main()
{
    // cout << sizeof(Student) << endl;
    // Student s1;

    // Student s2(1, 12, 1, "Chota Bheem", 1, "Chutki");
    // cout << s2.name << endl;
    // cout << s2.id << endl;

    // Student s3(2, 15, 0, "Lokesh", 5);
    // cout << s3.name << endl;

    // // alocating on heap
    // Student *s4 = new Student(3, 34, 1, "Chintu", 6);
    // cout << s4->name << endl;
    // cout << (*s4).name << endl;

    // delete s4; // no LEAK

    // s1.name = "Goli";
    // s1.age = 12;
    // s1.id = 1;
    // s1.nos = 5;
    // s1.present = 1;

    // Student s2;
    // s2.name = "Chota Bheem";
    // s2.age = 11;
    // s2.id = 2;
    // s2.nos = 1;
    // s2.present = 0;

    // copy ctor
    // Student s1(1, 12, 1, "Chota Bheem", 1, "Chutki");
    // Student s2 = s1;
    // Student s2(s1);

    // Student s2 = s1;

    // cout << s1.name << endl;
    // cout << s2.name << endl;

    Student s1(1, 12, 1, "Chota Bheem", 1);
    cout << s1.name << endl;
    cout << s1.getGfName() << endl;

    s1.setGfName("Indumati");

    cout << s1.getGfName() << endl;

    return 0;
}
