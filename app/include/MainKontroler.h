//
// Created by matfrg on 11/9/25.
//

#ifndef MAINKONTROLER_H
#define MAINKONTROLER_H
#include <engine/core/Controller.hpp>

namespace app {

class MainKontroler : public engine::core::Controller{
    void glClearColor(float x, float x1, float x2, float x3);
    void initialize() override;
    bool loop() override;

public:
    std::string_view name() const override {
        return "app::MainKontroler";
    }
};
} // app

#endif //MAINKONTROLER_H
