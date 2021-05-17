#include <iostream>

template <typename T>
class Vector
{
private:
  T *vectorPtr;

public:
  T xCoord;
  T yCoord;
  T zCoord;
  Vector(){
    xCoord = 0;
    yCoord = 0;
    zCoord = 0;
  }
  
  Vector(T x, T y, T z){
    xCoord = x;
    yCoord = y;
    zCoord = z;
  }
};

template <typename T>
Vector<T>& operator + (Vector<T> v1, Vector<T> v2)
{
  v1.xCoord += v2.xCoord;
  v1.yCoord += v2.yCoord; 
  v1.zCoord += v2.zCoord; 

  return(v1);
}

template <typename T>
Vector<T>& operator - (Vector<T> v1, Vector<T> v2)
{
  v1.xCoord -= v2.xCoord;
  v1.yCoord -= v2.yCoord; 
  v1.zCoord -= v2.zCoord; 
  
  return(v1);
}

template <typename T>
T operator * (Vector<T> v1, Vector<T> v2)
{
  return(v1.xCoord*v2.xCoord + v1.yCoord*v2.yCoord + v1.zCoord*v2.zCoord);
}

template <typename T>
void output(Vector<T> v){
    std::cout << "{" << v.xCoord << ", " << v.yCoord << ", " << v.zCoord << "}" << std::endl;
  }

int main(){

  Vector <int> v1(1, 2, 3);
  Vector <int> v2(2, 3, 4);

  Vector <int> vSum = v1+v2;
  Vector <int> vDiff = v1-v2;
  int vMult = v1*v2;

  output(vSum);
  output(vDiff);
  std::cout << vMult << std::endl;
}