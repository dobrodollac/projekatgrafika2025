//
// Created by matfrg on 11/9/25.
//

#ifndef MAINKONTROLER_H
#define MAINKONTROLER_H
#include <engine/core/Controller.hpp>

namespace app {

class MainKontroler : public engine::core::Controller {
    void initialize() override;
    bool loop() override;
    void draw_strumfeta();
    void draw_velikiStrumf();
    void draw_bubalo();
    void draw_gargamel();
    void update_camera();
    void update() override;
    void begin_draw() override;
    void draw() override;
    void end_draw() override;

public:
    std::string_view name() const override {
        return "app::MainKontroler";
    }
};
}// namespace app

#endif//MAINKONTROLER_H
