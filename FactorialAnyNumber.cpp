#include<iostream>
#include<stack>
using std::cout;
using std::cin;
using std::endl;

class factOverloading
{
    int num;
    std::string product;
    public:
    factOverloading(int number)
    {
        num=number;
        product="1";
    }
    
    std::string operator!()
    {
        for(int itr=2; itr<=num; ++itr)
        {
            if(!product.empty())
            {
                int lsb=0,carryOver=0,mult=0;
                std::stack <int> st;
                int strSize=product.size();
                //cout<<"strSize "<<strSize<<endl;
                std::string dupString;
                dupString.assign(product);
                for(int indx=strSize-1; indx>=0; --indx)
                {
                    //cout<<"I am here"<<endl;
                    //cout<<"Value of Product "<<product<<endl;
                    std::string character;
                    character.append(1,dupString.at(indx));
                    //cout<<"character "<<dupString.at(indx)<<endl;
                    mult=std::stoi(character);
                    mult*=itr;
                    mult+=carryOver;
                    lsb=mult%10;
                    carryOver=(mult-lsb)/10;
                    //cout<<"lsb "<<lsb<<endl;
                    //cout<<"carryOver "<<carryOver<<endl;
                    st.push(lsb);
                }
                if(carryOver > 0)
                {
                    st.push(carryOver);
                }
                product.clear();
                while(st.size() > 0)
                {
                    int element = st.top();
                    //cout<<"Popped out element is "<<element<<endl;
                    product+=std::to_string(element);
                    st.pop();
                    //cout<<"product "<<product<<endl;
                }
            }
        }
        return product;
    }
};

int main()
{
  std::string numberVal("");
    cout<<"Enter the number for which factorial needs to be computed"<<endl;
    cin>>numberVal;
    bool isDecimal = numberVal.find(".");
    bool isNegative = numberVal.find("-");
    int number=stoi(numberVal);

    if((number>0))
    {
        std::string result = !factOverloading(number);
        cout<<"The result is "<<result<<endl;
    }
    else
    {
        cout<<"Stupid entry: Go Die"<<endl;
    }
}
