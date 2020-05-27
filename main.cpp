#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

class kolejka
{
ifstream plik1;
ofstream plik2;

std::queue <int> que;

public:
    kolejka();
    ~kolejka();

void wczytaj();
void zapisz();

};

kolejka::kolejka()
{
	plik1.open("plik1.txt");
	plik2.open("plik2.json");
}

void kolejka::wczytaj()
{
int x;

while(!plik1.eof())
    {
		plik1>>x;
		que.push(x);
	}
}

void kolejka::zapisz()
{
bool y = true;

plik2<<"["<<endl;

	while(!que.empty())
{
    if(y)
    {
        plik2<<"{\"liczba\":"<<que.front()<<"}",
        que.pop();
			y = false;

}
else
{
    plik2<<","<<endl;

    plik2<<"{\"liczba\":"<<que.front()<<"}",

    que.pop();
}
}

	plik2<<endl<<"]";
}

kolejka::~kolejka()
{
	plik1.close();
	plik2.close();
}

int main(int argc, char** argv)
{
	kolejka t1;
	t1.wczytaj();
	t1.zapisz();
	return 0;
}
