#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

#include "sha256.h"

class Block
{
private:
    long long index;  // Block index in blockchain
    short time[6];      // Time when the block was created
    /*
    0 element - minutes;
    1 element - hours;
    2 element - seconds;
    3 element - day;
    4 element - month;
    5 element - year;
    */
    string data;      // Data in the block
    string _hash;     // Block`s hash
    string prev_hash; // Previous block`s hash

    /*
        Hash calculation function
    */
    string calcHash (long long index, string data, string prev_hash)
    {
        long long sum = index; // Variable with sum of all elements need for hash calculation
        for (int i = 0; i < data.length(); i++)             //
            sum += (int)data[i];                           //
        for (int i = 0; i < prev_hash.length(); i++)      //    Calculating
            sum += (int)prev_hash[i];                    //
        for (int i = 0; i < 6; i++)                     //
            sum += time[i];                            //

        return sha256(toString(sum));
    }

    /*
        Function which made string out of number
    */
    string toString(long long num)
    {
        char buffer[64];
        itoa (num, buffer, 10);
        return buffer;
    }

    /*
        Function which return time      Default date: 12:12:12 20.4.20!8
    */
    void getTime()
    {
        time[0] = 12;
        time[1] = 12;
        time[2] = 12;
        time[3] = 20;
        time[4] = 4;
        time[5] = 2018;
    }

    /*
        Saving Block to memory
    */
    void save_Block()
    {
        ofstream fout;
        fout.open("blockchain.txt", fstream::app);
        fout << index << " " << time[0] << " " << time[1] << " " << time[2] << " " << time[3] << " "
        << time[4] << " " <<  time[5] << " " << data << " " << _hash << " " << prev_hash << endl;
        fout.close();
    }

public:
    /*
        Constructor
    */
    Block(long long index, string data, string prev_hash)
    {
        this->index = index;
        this->getTime();
        this->data = data;
        this->_hash = calcHash(index, data, prev_hash);
        this->prev_hash = prev_hash;
    }

    ~Block()
    {
        save_Block();
    }
};

#endif // BLOCK_H_INCLUDED
