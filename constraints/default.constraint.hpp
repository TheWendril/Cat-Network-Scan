#include <Cat/constraintModel.hpp>
#include "../models/apnum.model.hpp"

class AConstraint : public CAT::ConstraintModel {

    public:

    bool check(CAT::Knowledge* knowledge) override {
        auto currentState = std::static_pointer_cast<AP_NUM>(knowledge->getCurrentState());
        if (!currentState) {
            return false;
        }

        auto history = knowledge->getDataHistory();
        if (history.size() < 2) {
            return false;
        }

        auto it = std::next(history.begin(), 1);
        auto lastState = std::static_pointer_cast<AP_NUM>(*it);
        if (!lastState) {
            return false;
        }

        if(currentState->ap_num != lastState->ap_num)
            printf("Alteração na rede detectada, chamando executor...\n");

        return currentState->ap_num == lastState->ap_num;
    }
};
