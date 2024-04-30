#include <iostream> 
#include <fstream> 
#include <string> 
#include <vector>

using namespace std;
int frequency_Substr(string s, string ss)
{
     int n = 0, p = 0;
    while ((p = s.find(ss, p)) != s.npos) {
        ++n;
        ++p;
    }
    return n;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    string text;
    ifstream programm("code.txt");
    int n1 = 0, n2 = 0;

    int number_of_operators[23] = { 0 };
    for (int i = 0; i < 23; i++)
        n1++;

    string operators[23] = {
     "+=",
     "()",
     "<<",
     "cin",
     ">>",
     " == ",
     "*",
     "-",
     " = ",
     "cout",
     " < ",
     "++",
     "+",
     "abs",
     "[]",
     " / ",
     "return",
     "!=",
     "&&",
     "sqrt",
     "for",
     "if",
     "else"
    };

    int number_of_operands[18] = { 0 };
    for (int i = 0; i < 18; i++)
        n2++;

    string operands[18] = 
    {
     " a ", " b ", " temp1 ", " temp2 ", " temp3 ", " x1 ", " x2 ", " x3 ", " 1.0 ", " 3 ", " 2 ", " 6 ", " 5 ", " -1 ",
     " 0 ", " count_t ", " count_d ", " temp "
    };
    std::vector<int> vec ;
    std::vector<int> gec ;



    string strh ;
    string str ;    // весь код в одной строке

    while ( !programm.eof() ) 
    {
        getline( programm, strh ) ;
        str += strh;
        if ( !programm.eof() ) 
        {
            str += '\n';
        }
    }

    for ( int i = 0; i < 18; ++ i )
    {
        vec.push_back(frequency_Substr( str, operands[i] )) ;
    }
    for ( int i = 0; i < 23; ++i ) 
    {
        gec.push_back(frequency_Substr( str, operators[i])) ;
    }
    programm.close();
   

    cout << "Количество уникальных операторов - " << n1 << endl;
    cout << "Общая сумма операторов - ";
    int N1 = 0;
    for (int i = 0; i < 23; i++)
        N1 += gec[i];
    cout << N1 << endl;
    for (int i = 0; i < 23; i++)
        cout << operators[i] << " - " << gec[i] << endl;;

    cout << endl << "Количество уникальных операндов - " << n2 << endl;
    int N2 = 0;
    for (int i = 0; i < 18; i++)
        N2 += vec[i];
    cout << "Общая сумма операндов - " << N2 << endl;
    for (int i = 0; i < 18; i++)
        cout << operands[i] << " - " << vec[i] << endl;

    cout << endl << "Объем алгоритма - " << (N1 + N2) * log2(n1 + n2);

}
