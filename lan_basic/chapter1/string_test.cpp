//
// Created by chanchan on 18-9-23.
//

#include<iostream>
#include<string>

using namespace std;

int main()
{
    //Initial
    string s;
    string s1("ssss");
    string s2(s1);
    string s3=s2;
    string s4(10,'c');
    cout<<s4<<endl;
    string s5="chanchan";
    string s6=string(10,'c');

    //cp sub
    char* cs="12345";
    string s7(cs,3);
    cout<<s7<<endl;

    string s8="12345";
    string s9(s8,3);
    cout<<s9<<endl;

    string s10="1234567890";
    string s11(s10,3,4);
    cout<<s11<<endl;

    //substr
    string s12="1234567890";
    string s13=s12.substr(1,5);
    cout<<s13<<endl;
    string s14=s12.substr(5);
    cout<<s14<<endl;

    //insert
    string str="To be question";
    string str2="the ";
    string str3="or not to be";
    string::iterator it;

    str.insert(6,str2);
    str.insert(6,str3,3,4);
    str.insert(10,"that is cool",8);
    str.insert(10,"to be ");
    str.insert(15,1,':');

    it=str.insert(str.begin()+5,',');
    str.insert(str.end(),3,'.');

    //erase
    string str4("This is an example sentence.");
    cout<<str4<<endl;
    str4.erase(10,8);
    cout<<str4<<endl;
    str4.erase(str4.begin()+9);
    cout<<str4<<endl;
    str4.erase(str4.begin()+5,str4.end()-9);

    //append and replace
    string str5;
    string str6="Writing";
    string str7="print 10 and the 5 mroe";

    str5.append(str6);
    str5.append(str7,6,3);
    str5.append("dots are coll",5);
    str5.append("here:");
    str5.append(10,'.');
    str5.append(str7.begin()+8,str7.end());
//    str5.append<int>(5,65);
    str5+="lalalala";
    str5.clear();
    cout<<str5<<endl;


}


