#include <iostream>
#include <vector>


// ======= VERSION 1 =======

class Event {
public:
    virtual std::string GetName() const = 0;
};

class State {
public:
    virtual void HandleEvent(const Event& event) = 0;
    virtual State* GetNextState() const = 0;
};

template <typename StateType, typename EventType>
class StateMachine {
public:
    explicit StateMachine(StateType* initial_state) : current_state_(initial_state) {}
    void HandleEvent(EventType* event) {
        current_state_ = current_state_->HandleEvent(event);
    }

    [[nodiscard]] StateType* GetCurrentState() const { return current_state_; }
private:
    std::vector<StateType> states_;
    StateType* current_state_;
};


int main() {

    return 0;
}
