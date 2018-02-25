#ifndef STRIKE_H
#define STRIKE_H

/*Csíkozás pl: raid0ba*/

class Strike
{
public:
    Strike(int size);
    ~Strike();

    char* getDataPointer();

private:
    char * m_data; //Konstruktorba kapja a méretét
};

#endif // STRIKE_H
