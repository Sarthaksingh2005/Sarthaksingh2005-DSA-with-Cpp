/*Create a Base class that consists of private, protected and public data members and member functions. Try using different access modifiers for inheriting Base class to the Derived class and create a table that summarizes the above three modes (when derived in public, protected and private modes) and shows the access specifier of the members of base class in the Derived class.*/
#include<iostream>
using namespace std;

class Base
{
    private:

    int a;
    void privatefn()
    {
    cout<<"private fn  called"<<endl;
    }

    protected:

    int b;
    void protectedfn()
    {
        cout<<"protected fn called"<<endl;
    }

    public:

    int c;
    void publicfn()
    {
      cout<<"Public fn called"<<endl;
    }
    
    Base(): a(10),b(20),c(30)
    {
      cout<<"base constructor called"<<endl;
    }

    void displayPrivate()
    {
        cout<<"Private data: "<<a<<endl;
    }
};
 
class publicDerived:public Base
{
    public:
          void accessmember()
          {
            cout<<"PUBLIC DERIVED CLASS"<<endl;
            //a=100; error:not accessable
            //privatefn(); not accessable

            b=200;
            protectedfn();//protected remaind protected

            c=300;
            publicfn();//public remains public


            cout<<"protected data"<<b<<endl;
            cout<<"public data"<<c<<endl;
   }
};
class ProtectedDrived: protected Base
{
    public:

    void accessmember()
    {
        cout<<"protected derived class"<<endl;
        //private data not accessable

        b=200;
        protectedfn(); //protected remains protected

        c=300;
        publicfn(); //public becomes protected

        cout<<"protected data:"<<b<<endl;
        cout<<"public data:"<<b<<endl;

    }
    
};
class PrivatedDerived: private Base
{
  public:
         void accessmember()
         {
            cout<<"private derived class"<<endl;
            //private fn not accessed
            
            b=200;
            protectedfn();//protected becomes private

            c=300;
            publicfn();//public becomes private

            cout<<"protected data: "<<b<<endl;
            cout<<"public data:"<<c<<endl;
         }
};
int main()
{
   cout<<"inhertance access modifier demostration"<<endl;

   //public inhertance
   publicDerived p;
   p.accessmember();
   p.c=400;        //public fn accessable only
   p.publicfn();
   

   //protected inhertance
   ProtectedDrived q;
   q.accessmember();   
             //no variable accessable as public become protected

   //private inhertance
   PrivatedDerived r;
   r.accessmember();             
             //no variable accessable as public becomes private
return 0;
}