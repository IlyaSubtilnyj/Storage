#pragma once

#include <memory>
#include <BNode.hpp>
using namespace std;

class ReadableBNodeInterface {
    
    public: virtual shared_ptr<const uint8_t*> Get() const = 0;

    //header
    protected: using _M_NKeysCount  = uint16_t;
    protected: using _M_Pointer     = uint64_t;
    protected: using _M_Index       = uint16_t;
    protected: using _M_Offset      = uint16_t;
    protected: using _M_KeyLength   = uint16_t;
    protected: using _M_ValLength   = uint16_t;

    //pointers
    public: virtual _M_Pointer GetPtr(_M_Index idx) const = 0;
    
    //offset list
    public: virtual _M_Offset OffsetPos(_M_Index idx) const = 0;
    public: virtual _M_Offset GetOffset(_M_Index idx) const = 0;

    //header
    public: virtual BNodeType       Type() const = 0;
    public: virtual _M_NKeysCount   Keys() const = 0;

    //key-values
    public: virtual _M_Offset KVPos(_M_Index idx) const = 0;
    public: virtual vector<uint8_t> GetKey(_M_Index idx) const = 0;
    public: virtual vector<uint8_t> GetVal(_M_Index idx) const = 0;

    //node size in bytes
    public: virtual _M_Offset Bytes() const = 0;
};