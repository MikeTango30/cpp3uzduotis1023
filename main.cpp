#include <iostream>
#include <string>
#include <fstream>

using namespace std;

ifstream in("duomenys4.txt");
ofstream out("Rezultatai.txt");

string nuskaitytiEilute();
void transfomuotiIMasyva(string duomenys, int masyvas[], int &masyvoDydis);
int rastiDidziausia(int duomenys[], int kiek);
int rastiMaziausia(int duomenys[], int kiek);
void isvestiRezultata(int rezultatas[]);

int const C_MASYVO_DYDIS = 4;

int main()
{
    int C[C_MASYVO_DYDIS],
        cIndeksas = 0;

    while (!in.eof()){
        string duomenuEilute = nuskaitytiEilute();
        int kiek = duomenuEilute.size();
        int masyvas[kiek];
        transfomuotiIMasyva(duomenuEilute, masyvas, kiek); //grazins skaitmenu masyvo "kiek"
        int maziausias = rastiMaziausia(masyvas, kiek);
        C[cIndeksas] = maziausias;
        cIndeksas += 2;
        int didziausias = rastiDidziausia(masyvas, kiek);
        C[cIndeksas] = didziausias;
        cIndeksas -= 1;
    }

    isvestiRezultata(C);

    in.close();
    out.close();

    return 0;
}

string nuskaitytiEilute()
{
    string eilute;
    getline(in, eilute);

    return eilute;
}

void transfomuotiIMasyva(string duomenys, int masyvas[], int &masyvoDydis)
{
    int skaitmenuMasyvoIndeksas = 0,
        kiek = duomenys.size();
    string laikinaEilute;

    for (int i = 0; i < kiek; i++) {
        //ziurim keliazenklis skaitmuo ir ji priskiriam laikinai eilutei
        int j = 1;
        if (duomenys[i] == '{' || duomenys[i] == ' '){
            laikinaEilute = "";
            while (duomenys[i + j] != ' ' && duomenys[i + j] != '}'){
                laikinaEilute.push_back(duomenys[i + j]);
                j++;
            }
            //priskiriam skaitmenu masyvui
            masyvas[skaitmenuMasyvoIndeksas] = stoi(laikinaEilute);
            skaitmenuMasyvoIndeksas++;
        }
    }
    masyvoDydis = skaitmenuMasyvoIndeksas;
}

int rastiDidziausia(int duomenys[], int kiek)
{
    int didziausias = duomenys[0];
    for (int i = 1; i < kiek; i++) {
        if (didziausias < duomenys[i]) {
            didziausias = duomenys[i];
        }
    }

    return didziausias;
}

int rastiMaziausia(int duomenys[], int kiek)
{
    int maziausias = duomenys[0];
    for (int i = 1; i < kiek; i++) {
        if (maziausias > duomenys[i]) {
            maziausias = duomenys[i];
        }
    }

    return maziausias;
}

void isvestiRezultata(int rezultatas[])
{
    out << "C{";
    for (int i = 0; i < C_MASYVO_DYDIS - 1; i++) {
        out << rezultatas[i] << " ";
    }
    out << rezultatas[C_MASYVO_DYDIS - 1] << "}" << endl;
}