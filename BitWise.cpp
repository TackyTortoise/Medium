#include <iostream>
#include <assert.h>

enum class EFlagValue
{
    Flag1 = 1 << 0, // 1
    Flag2 = 1 << 1, // 2
    Flag3 = 1 << 2, // 4
    Flag4 = 1 << 3, // 8
    Flag5 = 1 << 4, // 16
    Flag6 = 1 << 5, // 32
    Flag7 = 1 << 6, // 64
    Flag8 = 1 << 7  // 128
};

struct BitFlag
{
    //Sets flag to true
    void SetFlag(EFlagValue flag)
    {
        m_FlagValue |= (int)flag;
    }

    //Sets flag to false
    void UnsetFlag(EFlagValue flag)
    {
        m_FlagValue &= ~(int)flag;
    }

    //Sets a flag value from true to false and vice versa
    void FlipFlag(EFlagValue flag)
    {
        m_FlagValue ^= (int)flag;
    }

    //Check whether a flag is set to true
    bool HasFlag(EFlagValue flag)
    {
        return (m_FlagValue & (int)flag) == (int)flag;
    }

    bool HasAnyFlag(EFlagValue multiFlag)
    {
        return (m_FlagValue & (int)multiFlag) != 0;
    }

    uint8_t m_FlagValue = 0;
};

void main()
{
    BitFlag flag;

    //Set flag
    flag.SetFlag(EFlagValue::Flag1); //Flag = 1 (00000001)
    assert(flag.HasFlag(EFlagValue::Flag1));

    //Unset flag
    flag.UnsetFlag(EFlagValue::Flag1); //Flag = 0 (00000000)
    assert(!flag.HasFlag(EFlagValue::Flag1));

    //Set multiple flags at once
    flag.SetFlag((EFlagValue)((int)EFlagValue::Flag1 | (int)EFlagValue::Flag2)); //Flag = 3 (00000011)
    assert(flag.HasFlag(EFlagValue::Flag1));
    assert(flag.HasFlag(EFlagValue::Flag2));
    assert(flag.HasFlag((EFlagValue)((int)EFlagValue::Flag1 | (int)EFlagValue::Flag2)));
    assert(!flag.HasFlag((EFlagValue)((int)EFlagValue::Flag1 | (int)EFlagValue::Flag4)));
    assert(flag.HasAnyFlag((EFlagValue)((int)EFlagValue::Flag1 | (int)EFlagValue::Flag4)));

    //Flip flag 4 from 0 to 1
    flag.FlipFlag(EFlagValue::Flag4); //Flag = 11 (00001011)
    assert(flag.HasFlag(EFlagValue::Flag4));

    //Flip flag 2 from 1 to 0
    flag.FlipFlag(EFlagValue::Flag2); //Flag = 9 (00001001)
    assert(!flag.HasFlag(EFlagValue::Flag2));    
}