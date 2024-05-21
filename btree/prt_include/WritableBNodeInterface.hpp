#pragma once

#include <BNode.hpp>
#include <ReadableBNodeInterface.hpp>

class WritableBNodeInterface: public ReadableBNodeInterface {

    //header
    public: virtual void SetHeader(BNodeType type, _M_NKeysCount keys_count) = 0;

    //pointers
    public: virtual void SetPtr(_M_Index idx, _M_Pointer val) = 0;

    //offset list
    public: virtual void SetOffset(_M_Index idx, _M_Offset offset) = 0;
};