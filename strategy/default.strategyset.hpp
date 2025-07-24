#include <Cat/model/strategySet.hpp>
#include <Cat/model/action.hpp>
#include <fstream>
#include "../behavior/executor.action.hpp"

class DefaultStrategy : public CAT::Strategy {

public: 

    void create() override {
        auto blink = std::make_shared<Blink>();
        this->addAction(blink);
    }
};