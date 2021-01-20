#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::cin;
using std::vector;
typedef long double ULong;
class factorial
{
    vector<ULong>factVec;
    int num;
    public:
        factorial(int num)
        {
            this->num=num;
            factVec.reserve(num);
            factVec={0};
        }
        ULong operator !()
        {
            cout<<"printing to see if all elements are 0"<<endl;
            for(std::vector<ULong>::iterator it = factVec.begin(); it != factVec.end(); ++it) 
            {
                cout<<*it<<" ";
            }
            factVec[0]=1;
            for(int itr=1;itr<=num;++itr)
            {
                factVec[itr]=itr*factVec[itr-1];
            }
            return factVec[num];
        }
};

int main()
{
    auto num = 29;
    if(num > 0)
    {
       ULong res= !factorial(num);
       cout<<"The factorial value is "<<res<<endl;
    }
    else
    {
        cout<<"Lodu Kya enter kar raha hai BC"<<endl;
    }
    return 1;
}