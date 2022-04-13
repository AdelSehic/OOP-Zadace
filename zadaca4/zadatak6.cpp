#include <iostream>
#include <list>
#include <vector>
#include <map>

struct predmet{
    std::string naziv;
    std::string odsjek;

    predmet() = default;

    predmet(std::string a, std::string b)
        : naziv{a}, odsjek{b} {};
};

std::list<predmet> pred;

struct ocjenaIzPredmeta{
    int ocjena;
    std::list<predmet>::const_iterator predmet_;

    ocjenaIzPredmeta() = default;
};

struct student{
    std::string brojIndeksa;
    std::string ime;
    std::string prezime;
    std::string grad;
    std::vector<ocjenaIzPredmeta> ocjene;

    student() = default;

    student(std::string a, std::string b, std::string c, std::string d, ocjenaIzPredmeta e){
            brojIndeksa = a;
            ime = b;
            prezime = c;
            grad = d;
            ocjene.push_back(e);
            std::cout << "Konstruisan student sa informacijama:\nBroj indeksa: " << a << "\nIme: " << b << "\nPrezime: " << c << "\nGrad: " << d << std::endl;
        };
};

ocjenaIzPredmeta unosOcjene(){
    std::string a;
    std::cout << "Unesite naziv predmeta: ";
    std::cin >> a;
    auto it = pred.begin();
    while(it -> naziv != a){
        ++it;
        if(it==pred.end()) throw std::string{"Odabrani predmet ne postoji"};
    }
    int b=0;
    while(b<5||b>10){
        std::cout << "Unesite ocjenu (5-10): ";
        std::cin >> b;
    }
    ocjenaIzPredmeta temp;
    temp.ocjena = b;
    temp.predmet_ = it;
    return temp;
}

void unos(std::map<std::string, student>& stu){
    std::string indeks, ime, prezime, grad;
    std::cout << "Unesite indeks: ";
    std::cin >> indeks;
    auto it = stu.find(indeks);
    if(it != stu.end()){
        throw std::string{"Student s tim brojem indeksa vec postoji!"};
    }
    std::cin.ignore(1000, '\n');
    std::cout << "\nIme:";
    std::getline(std::cin, ime);
    std::cout << "\nPrezime:";
    std::getline(std::cin, prezime);
    std::cout << "\nGrad:";
    std::getline(std::cin, grad);
    ocjenaIzPredmeta ocj = unosOcjene();
    student temp(indeks,ime,prezime,grad,ocj);
    stu[indeks] = temp;
}

int main()
{
    {
        predmet temp("Mat1","PMF");
        pred.push_back(temp);
        temp.naziv = "OE";
        temp.odsjek = "TK";
        pred.push_back(temp);
        temp.naziv = "OOP";
        temp.odsjek = "RI";
        pred.push_back(temp);
    }

    std::map<std::string, student> studenti;

    int izlaz = 1;
    while((izlaz == 1 || izlaz == 2) && std::cin ){
            
        std::cout << "Dobrodosli u sirotinjski stuslu, izaberite operaciju: " << std::endl;
        std::cout << "1. Unos podataka\n2. Editovanje podataka\n3. Zatvaranje programa\nOdaberite: ";
        std::cin >> izlaz;

        if(izlaz == 1)
            try{ unos(studenti); }catch(const std::string& err){std::cout << err << std::endl;}
        else if (izlaz == 2)
            std::cout << "Editovanje" << std::endl;
    }

    std::cout << "Allahimanet" << std::endl;
    return 0;
}