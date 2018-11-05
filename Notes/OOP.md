

### OOP
1. Start with:
- Start asking 6W's : who what when why where how. Try to understand all aspects of idea.
- Let say for restaurent oop. Start defining core objects like table, guest, server, party, order, meal, employee etc.
- Analyse relationship 
       * which objects are memeber of which obj.
       * Any object inherits from other obj.
       * relation 1-1, 1-many or many-many.
- Investigate actions
    For example a Party walks into the Restaurant, and a Guest requestsa Table from the Host. The Host looks up the Reservation and, if it exists, assigns the Party to a Table.Otherwise, the Party is added to the end of the list. When a Party leaves, the Table is freed and assigned to a new Party in the list.
 

2. Design Pattern:
- Singleton Class : The Singleton pattern ensures that a class has only one instance and ensures access to the instance through the application.
- Factory Method : The Factory Method offers an interface for creating an instance of a class, with its subclasses deciding which class to instantiate.    

```cpp
public class Shapes {
    public static Shapes createShape(ShapeType type) {
        if (type == ShapeType.Circle) {
            return new Circle();
        } else if (type == ShapeType. Square){
            return new Square();
        }
        return null;
    }
}
```

3. Static function and static member

```cpp
class Box {
   public:
      static int objectCount;
      
      // Constructor definition
      Box(double l = 2.0, double b = 2.0, double h = 2.0) {
         cout <<"Constructor called." << endl;
         length = l;
         breadth = b;
         height = h;

         // Increase every time object is created
         objectCount++;
      }
      double Volume() {
         return length * breadth * height;
      }
      static int getCount() {
         return objectCount;
      }
      
   private:
      double length;     // Length of a box
      double breadth;    // Breadth of a box
      double height;     // Height of a box
};

// Initialize static member of class Box
int Box::objectCount = 0;

int main(void) {
   // Print total number of objects before creating object.
   cout << "Inital Stage Count: " << Box::getCount() << endl;

   Box Box1(3.3, 1.2, 1.5);    // Declare box1
   Box Box2(8.5, 6.0, 2.0);    // Declare box2

   // Print total number of objects.
   cout << "Total objects: " << Box::objectCount << endl;
   
   // Print total number of objects after creating object.
   cout << "Final Stage Count: " << Box::getCount() << endl;

   return 0;
}
```
4. Abstract virtual class 

Info : https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/




References:
Cracking coding interview book
