#pragma once
#include <unordered_map>
#include <string>

//========================================
// State所有者クラス
//========================================
class StateOwner
{
protected:
    std::unordered_map<std::string, class State*> state_map_;
    class State* current_state_;

public:
    void Update();
    void ChangeState(const std::string &name);
    void RegisterState(class State* state);
};