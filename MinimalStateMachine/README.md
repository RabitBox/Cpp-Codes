# MinimalStateMachine
極小なステートマシン的な実装。  
本当に最低限な実装しかしていないので、使うときは書き換え必須。

# How to use
``` cpp
// ステートを作成
class Stand : public State{};
class Walk : public State{};
class Run : public State{};

// ステート所有者のインスタンスを作成
StateOwner* owner = new StateOwner();

// 所有者にステートを登録
owner->RegisterState(new Stand());
owner->RegisterState(new Walk());
owner->RegisterState(ner Run());

// ステートの変更
owner->ChangeState("Run");

// 現在のステートでの更新
owner->Update();
```
