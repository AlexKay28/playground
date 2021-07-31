#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
int main()
{
    string s="i,love,my,country,very,much";   //declare a string
    string answer[6];  // string array to store the result
    stringstream string_stream(s);  // creating string stream object

    int i=0;            // declaring i and assign  to 0

    while(string_stream.good())   // loop will continue if string stream is error free
    {
      string a;
      getline( string_stream, a, ',' );   //calling getline fuction
      answer[i]=a;
      i++;
    }

    for(i=0;i<6;i++){
     cout<<answer[i]<<endl;   // printing a result
    }
    return 0;
}
