//
// Created by matfrg on 11/12/25.
//

#ifndef GUIKONTROLER_H
#define GUIKONTROLER_H
#include <engine/core/Controller.hpp>

namespace app {

class GUIKontroler : public engine::core::Controller {
public:
    std::string_view name() const override {
        return "app::GUIKontroler";
    }

private:
    void initialize() override;
    void poll_events() override;
    void draw() override;
};


} // app

#endif //GUIKONTROLER_H
