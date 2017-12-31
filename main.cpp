#include "block.h"

long long _quantity = 0; // quantity of blocks in chain

void createBlock(string);       //Function that creates a new block in a chain
//void printBlock(long long);     //Function that shows information about some block: time, data and hash

int main()
{
    ifstream fin("info.txt");
    if (!fin.is_open())
    {
        ofstream fout("info.txt");
        fout << 0 << endl << 0;
        fout.close();
    }
    fin >> _quantity;
    fin.close();

    while(true)
    {
        cout << "\t\t CPchain \n\n" << endl;
        cout << "1.Show block" << endl;
        cout << "2.Add new block" << endl;

        long long answear;
        cin >> answear;
        if (answear == 1)   //Show block
        {
            cout << "Enter number of a block: ";
            cin >> answear;

            if (answear > _quantity-1)
                cout << "Error: No such block in chain" << endl;
            //else
                //printBlock(answear);
        } else
        if (answear == 2)   //Create new block
        {
            cout << "Enter block message: ";
            string data;
            cin >> data;
            createBlock(data);
        }
        system("cls");
    }
    return 0;
}

/*
    Function that creates a new block in a chain
*/
void createBlock(string data)
{
    ifstream fin("info.txt");
    string buffer;
    fin >> buffer;
    fin >> buffer;
    fin.close();
    Block _block(_quantity, data, buffer);
    ofstream fout("info.txt");
    fout << ++_quantity;
    fout.close();
}

/*
    Function that shows information about some block: time, data and hash
*//*
void printBlock(long long index)
{
    int info[10];
    for (int i = 0; i < index; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            fin >> info[j];
        }
    }
    cout << "Block #" << info[0] << endl
    << "Time when block was created: " << info[1] << ":" << info[2] << ":" << info[3] << " " << info[4] << "." << info[5] << "." << info[6] << endl
    << ""
}*/
