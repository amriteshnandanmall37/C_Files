//Accept string ending with 101
#include<iostream>
int main()
{
    int state; char c;char flag=0;
    while(true)
    {
        state=0; //Initial State
    std::cout<<"Input the binary characters one by one and for ending enter any other character:\n";
    std::string st="";
    while(true)
    {
        std::cin>>c;
        if(c=='0'||c=='1')
        {
            st=st+c;
            switch(state)
            {
                case 0:  //input character
                if(c=='0')
                state=0;
                else
                state=1;
                break;;
                case 1:
                if(c=='0')
                state=2;
                else
                state=1;
                break;
                case 2:
                if(c=='0')
                state=0;
                else
                state=3;
                break;
                case 3:
                if(c=='0')
                state=2;
                else
                state=1;
            }
        }
        else
        break;

    }
    if(state==3)
    std::cout<<"The input string "<<st<<" is accepted.\n";
    else
    std::cout<<"The input string "<<st<<" is rejected\n";
    
    std::cout<<"Enter 1 if you want to test another string else enter 0: ";
    std::cin>>flag;
    if(flag!='1')
    break;


}
return 0;
}