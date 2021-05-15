#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>

namespace hk
{
  class HK_UTILITY_EXPORT UUID
  {
  public:

    UUID();

    UUID(const UUID& _uuid);

    virtual ~UUID();

    virtual String&
    getString() const;

    virtual UUID&
    operator=(const UUID& _uiid);

    virtual bool
    operator==(const UUID& _uuid) const;

    virtual bool
    operator!=(const UUID& _uuid) const;

  private:

    static String
    _Generate();

    /**
    * UUUID value.
    */
    String _m_uuid;
  };
}