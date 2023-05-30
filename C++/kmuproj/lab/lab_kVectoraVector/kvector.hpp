#ifndef KVECTOR_H
#define KVECTOR_H

class Kvector{
public:
    Kvector() = default;
    Kvector(int const size, int const value=0);
    virtual ~Kvector() = default;

public:
    void clear();
    void print() const;
    int size() const;
public:
    int *m{};
    int len{};

};

#endif