#include <iostream>
#include "StateOwner.h"
#include "State.h"

//----------------------------------------
// 現在のStateのUpdateを呼び出す
void StateOwner::Update()
{
    if(current_state_)
    {
        current_state_->Update();
    }
}

//----------------------------------------
// Stateの変更を行う
void StateOwner::ChangeState(const std::string &name)
{
    if(current_state_) 
    {
        current_state_->OnExit();
    }

    try
    {
        auto iter = state_map_.find(name);
        if(iter != state_map_.end())
        {
            current_state_ = iter->second;
            current_state_->OnEnter();
        }
    }
    catch(const std::exception &e)
    {
        std::cerr 
            << "Failure to ChangeState: " 
            << e.what() 
            << std::endl;
        current_state_ = nullptr;
    }
}

//----------------------------------------
// Stateの新規登録
void StateOwner::RegisterState(State* state)
{
    state_map_.emplace(state->GetName(), state);
}