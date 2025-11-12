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
    void draw_kuca();
    void update_camera();
    void update() override;
    void begin_draw() override;
    void draw() override;
    void end_draw() override;
    bool prikaziGargamela = false;
    bool prikaziVelikogStrumfa = true;
    bool prikaziStrumfetu = true;
    bool prikaziBubala = true;
    bool prethodnoG = false;
    bool prethodnoE = false;
    bool pokreniVelikogStrumfa = false;
    float ugaoVelikogStrumfa = -45.0f;
    float pozicijaVelikogStrumfa = 0.0f;

public:
    std::string_view name() const override {
        return "app::MainKontroler";
    }
};
}// namespace app

#endif//MAINKONTROLER_H
