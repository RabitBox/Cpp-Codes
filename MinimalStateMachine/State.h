#pragma once
#include <string>

//========================================
// State基底クラス
//========================================
class State
{
protected:
    class StateOwner* owner_;

public:
    virtual void OnEnter() = 0;
    virtual void Update() = 0;
    virtual void OnExit() = 0;
    virtual const std::string GetName() const = 0;
};