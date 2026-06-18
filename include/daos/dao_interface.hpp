#ifndef DAO_INTERFACE_HPP
#define DAO_INTERFACE_HPP

#include<vector>
#include <optional>

template<typename T>
class DaoInterface{

    public:

    virtual std::vector<T> findAll() = 0;
    virtual std::optional<T> getByID(int) = 0;
    virtual int save(T) = 0;
    virtual void deleteById(int) = 0;
    virtual void update(int, T);

};

#endif