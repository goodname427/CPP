#include <iostream>
using namespace std;

typedef struct Student
{
   int no;
   string name;
} Student;

class StudentCollection
{
private:
   Student *students;
   int capacity;

public:
   int size;

   StudentCollection(int capacity) : capacity(capacity), size(0)
   {
      students = new Student[capacity];
   }

   ~StudentCollection()
   {
      delete[] students;
   }

   Student &operator[](string name)
   {
      for (int i = 0; i < size; i++)
         if (students[i].name == name)
            return students[i];
      throw exception();
   }

   Student &operator[](int index)
   {
      if (index < 0 || index >= size)
         throw exception();
      return students[index];
   }

   bool Add(Student std)
   {
      if (size == capacity)
         return false;
      students[size++] = std;
   }

   void Remove(int index)
   {
      if (index < 0 || index >= size)
         return;
      for (int i = index + 1; i < size; i++)
      {
         students[i - 1] = students[i];
      }
      size--;
   }
};

int main()
{
   StudentCollection sc(10);
   sc.Add({1, "Jim"});
   sc.Add({2, "Jeffry"});
   sc.Add({3, "Herry"});
   sc.Add({4, "Tom"});
   try
   {

      cout << sc["Tom"].no << endl;
      cout << sc[3].name << endl;
      cout << sc[2].name << endl;
      sc.Remove(2);
      cout << sc[2].name << endl;
      cout << sc["Tina"].no << endl;
   }
   catch(exception)
   {
      cout << "出错啦！" << endl;
   }
}