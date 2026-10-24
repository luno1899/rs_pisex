#include "schemasystem.h"
#include "utils.hpp"
#include <cstring>

int32_t GetServerOffset(const char* pszClassName, const char* pszPropName)
{
    if (!g_pCSchemaSystem)
        return -1;

    static CSchemaSystemTypeScope* pServerTypeScope = nullptr;
    if (!pServerTypeScope)
        pServerTypeScope = g_pCSchemaSystem->FindTypeScopeForModule(WIN_LINUX("server.dll", "libserver.so"));
    if (!pServerTypeScope)
        return -1;

    CSchemaClassInfo* pClassInfo = pServerTypeScope->FindDeclaredClass(pszClassName).Get();
    if (!pClassInfo)
        return -1;

    for (int i = 0; i < pClassInfo->m_nFieldCount; i++)
    {
        auto& field = pClassInfo->m_pFields[i];
        if (std::strcmp(field.m_pszName, pszPropName) == 0)
            return field.m_nSingleInheritanceOffset;
    }

    return -1;
}
