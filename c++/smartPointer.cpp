#include <iostream>

/* ctci_5thEd_13.8
Write a smart pointer class. A smart pointer is a datatype, usually implemented
with templates, that simulates a pointer while also providing automatic garbage 
collection. It automatically counts the number of references to a SmartPointer<T*>
object and frees the object of type T when the reference count hits zero.
*/

template <class T> 
class SmartPointer
{
public:
  SmartPointer(T *ptr);
  SmartPointer(SmartPointer<T> &sref);
  ~SmartPointer() { Remove(); }

  SmartPointer<T>& operator=(SmartPointer<T>& from);
  T GetValue();

protected:
  T* ref;
  unsigned int *refCount;
  void Remove();
};

template <class T>
SmartPointer<T>::SmartPointer(T *ptr) 
{ 
  ref       = ptr;
  refCount  = new unsigned int;
  *refCount = 1;
  std::cout << __func__ << " refCount = " << *refCount << std::endl;
}

template <class T>
SmartPointer<T>::SmartPointer(SmartPointer<T> &sref)
{
  ref      = sref.ref;
  refCount = sref.refCount;
  ++(*refCount);
  std::cout << __func__ << " refCount = " << *refCount << std::endl;
}

template <class T>
SmartPointer<T>& SmartPointer<T>::operator=(SmartPointer<T>& from)
{
  if (this == &from) {
    return *this;
  }

  if (*refCount > 0) {
    Remove();
  }

  ref      = from.ref;
  refCount = from.refCount;
  ++(*refCount);
  std::cout << __func__ << " refCount = " << *refCount << std::endl;
  return *this;
}

template <class T>
T SmartPointer<T>::GetValue()
{
  return *ref;
}

template <class T>
void SmartPointer<T>::Remove()
{
  --(*refCount);
  std::cout << __func__ << " refCount = " << *refCount << std::endl;

  if (*refCount == 0) {
    delete ref;
    delete refCount;
    ref      = nullptr;
    refCount = nullptr;
    std::cout << __func__ << " destroying SmartPointer" << std::endl;
  }
}

int main()
{
  int* iptr = new int;
  *iptr = 13;

  SmartPointer<int> smart1(iptr);
  SmartPointer<int> smart2(smart1);

  return 0;
}