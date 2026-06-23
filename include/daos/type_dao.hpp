#ifndef TYPE_DAO_HPP
#define TYPE_DAO_HPP

#pragma GCC diagnostic ignored "-Wdeprecated-declarations" 

#include <sqlite_orm/sqlite_orm.h>
#include "../models/type.hpp"
#include "../db/database_conection_manager.hpp"
#include "../exceptions/id_not_found_exception.hpp"
#include "dao_interface.hpp"

using TypeStorage = decltype(
    sqlite_orm::make_storage("",
                  sqlite_orm::make_table("types",
                     sqlite_orm::make_column("id_type", 
                        &Type::id_type, 
            sqlite_orm::primary_key().autoincrement()),
                     sqlite_orm::make_column("description",
                            &Type::description))));

class TypeDao : public DaoInterface<Type> {
    TypeStorage storage;

public:
    TypeDao();

    std::vector<Type> findAll() override;
    std::optional<Type> getByID(int id_type) override;
    int save(Type type) override;
    void deleteById(int id_type) override;
    void update(int id_type, Type type) override;
    bool exists(int id_type) override;
};

#endif