#include <iostream>
#include <fstream>

class adress {
public:

    adress() {
        city = "unkwonw";
        street = "unkown";
        building = 0;
        apartment = 0;
    }

    void setCity(std::string city_) { city = city_; }
    void setStreet(std::string street_) { street = street_; }
    void setBuilding(int building_) { building = building_; }
    void setApartment(int apartment_) { apartment = apartment_; }

    std::string getCity() { return city; }
    std::string getStreet() { return street; }
    int getBuilding() { return building; }
    int getApartment() { return apartment; }

private:

    std::string city;
    std::string street;
    int building;
    int apartment;

};

int main()
{
    setlocale(LC_ALL, "Russian");

    std::ifstream inputFile("in.txt");
    if (!inputFile.is_open()) {
        std::cout << "File didnt opened!";
        return 0;
    }

    int arraySize = 0;
    inputFile >> arraySize;

    adress* adressArray = new adress[arraySize];

    std::string tempString = "";
    int tempInt = 0;

    for (int i = 0; i < arraySize; i++) {

        inputFile >> tempString;
        adressArray[i].setCity(tempString);
        inputFile >> tempString;
        adressArray[i].setStreet(tempString);

        inputFile >> tempInt;
        adressArray[i].setBuilding(tempInt);
        inputFile >> tempInt;
        adressArray[i].setApartment(tempInt);

    }

    inputFile.close();

    std::ofstream outputFile("out.txt");
    if (!outputFile.is_open()) {
        std::cout << "File didnt opened!";
        return 0;
    }

    outputFile << arraySize << std::endl;

    int sortArraySize = arraySize;
    while (sortArraySize--)
    {
        bool swapped = false;

        for (int i = 0; i < sortArraySize; i++)
        {
            if ((adressArray[i].getCity().compare(adressArray[i + 1].getCity()) == 0) && (adressArray[i].getStreet().compare(adressArray[i + 1].getStreet()) == 1))
            {
                std::swap(adressArray[i], adressArray[i + 1]);
                swapped = true;

            }
            if (adressArray[i].getCity().compare(adressArray[i + 1].getCity()) == 1)
            {
                std::swap(adressArray[i], adressArray[i + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }

    for (int i = 0; i < arraySize; i++) {
        outputFile << adressArray[i].getCity() << ", " << adressArray[i].getStreet() << ", " << adressArray[i].getBuilding() << ", " << adressArray[i].getApartment() << std::endl;
    }

    delete[] adressArray;
    outputFile.close();




    return 0;
}

