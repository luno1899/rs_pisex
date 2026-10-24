#ifndef SCHEMASYSTEM_H
#define SCHEMASYSTEM_H
#ifdef _WIN32
#pragma once
#endif

#include <cstdint>
#include <type_traits>
#include <schemasystem/schemasystem.h>

// Uses the SDK's own ISchemaSystem / CSchemaSystemTypeScope / CSchemaClassInfo, so vtable indices and
// struct layouts follow the SDK instead of being hardcoded here.
extern ISchemaSystem* g_pCSchemaSystem;

int32_t GetServerOffset(const char* pszClassName, const char* pszPropName);

#define SCHEMA_FIELD(type, className, propName)                                                        \
    std::add_lvalue_reference_t<type> propName()                                                       \
    {                                                                                                  \
        static const int32_t offset = GetServerOffset(#className, #propName);                          \
        if(offset == -1)                                                                               \
        {                                                                                              \
            /* field not found: never write through this-1 */                                          \
            static std::remove_cv_t<std::remove_reference_t<type>> dummy{};                            \
            return dummy;                                                                              \
        }                                                                                              \
        return *reinterpret_cast<std::add_pointer_t<type>>(reinterpret_cast<intptr_t>(this) + offset); \
    }

#endif //SCHEMASYSTEM_H
