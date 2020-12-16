#include <stdio.h>
#include <stdlib.h>

// Mokesciu konstantos
const float GPM = 0.15;
const float PSD = 0.06;
const float SODRA = 0.03;

// Strukturos modelis
struct Darbuotojas
{
    char vardas[50];
    char pavarde[50];
    float atlyginimas;
    float gpm;
    float psd;
    float sodra;
};

// Naujo darbuotojo ivedimas i sistema
struct Darbuotojas ivestiDarbuotoja(int darbuotojoKodas)
{
    char vardas[50];
    char pavarde[50];
    float atlyginimas;

    printf("###\n## %d DARBUOTOJAS \n##\n", darbuotojoKodas);
    printf("Iveskite darbuotojo varda: ");
    scanf("%s", vardas);
    printf("Iveskite darbuotojo pavarde: ");
    scanf("%s", pavarde);
    printf("\nIveskite darbuotojo atlyginima: ");
    scanf("%f", &atlyginimas);

    struct Darbuotojas naujasDarbuotojas;
    strcpy(naujasDarbuotojas.vardas, vardas);
    strcpy(naujasDarbuotojas.pavarde, pavarde);
    naujasDarbuotojas.atlyginimas = atlyginimas;

    return naujasDarbuotojas;
};

// Mokesciu apskaiciavimas visiems darbuotojams
void apskaiciuotiMokescius(struct Darbuotojas *darbuotojai, int kiekis)
{
    for (int i = 0; i < kiekis; i++)
    {
        darbuotojai[i].gpm = darbuotojai[i].atlyginimas * GPM;
        darbuotojai[i].psd = darbuotojai[i].atlyginimas * PSD;
        darbuotojai[i].sodra = darbuotojai[i].atlyginimas * SODRA;
    }
};

// Darbuotojo paieska tarp ivestu darbuotoju
void darbuotojoPaieska(struct Darbuotojas *darbuotojai, char *pavarde, int kiekis)
{
    for (int i = 0; i < kiekis; i++)
    {
        if (strcmp(darbuotojai[i].pavarde, pavarde) == 0)
        {
            darbuotojoInformacija(darbuotojai[i]);
            return;
        }

    }
    printf("Duomenu pagal jusu pateikta pavarde nera...");


};

// Pateikiama darbuotojo informacija i ekrana
void darbuotojoInformacija(struct Darbuotojas darbuotojas)
{
    printf("#########################\n");
    printf("## %s %s \n", darbuotojas.vardas, darbuotojas.pavarde);
    printf("#########################\n");
    printf("Atlyginimas: %0.2f EUR\n", darbuotojas.atlyginimas);
    printf("Mokesciai:\n");
    printf("-- GPM: %0.2f EUR\n", darbuotojas.gpm);
    printf("-- PSD: %0.2f EUR\n", darbuotojas.psd);
    printf("-- SODRA: %0.2f EUR\n", darbuotojas.sodra);

};

int main()
{
    struct Darbuotojas darbuotojuSarasas[5];

    for (int i = 0; i < 5; i++)
    {
        darbuotojuSarasas[i] = ivestiDarbuotoja(i + 1);
    }

    // Apskaiciuojam visu mokescius
    apskaiciuotiMokescius(darbuotojuSarasas, 5);


    char norimoDarbuotojoPavarde[50];

    while(1)
    {
        printf("\nIveskite norizmo zmogaus pavarde: ");
        scanf("%s", norimoDarbuotojoPavarde);
        darbuotojoPaieska(darbuotojuSarasas, norimoDarbuotojoPavarde, 5);
    }

    return 0;
}
