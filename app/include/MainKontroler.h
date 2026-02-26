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
    void draw_veliki_strumf();
    void draw_bubalo();
    void draw_gargamel();
    void draw_kuca();
    void update_camera();
    void update() override;
    void begin_draw() override;
    void draw() override;
    void end_draw() override;

    bool prikazi_gargamela = false;
    bool prikazi_velikog_strumfa = true;
    bool prikazi_strumfetu = true;
    bool prikazi_bubala = true;
    bool pokreni_velikog_strumfa = false;
    float ugao_velikog_strumfa = -45.0f;
    float pozicija_velikog_strumfa = 0.0f;

public:
    std::string_view name() const override {
        return "app::MainKontroler";
    }
};
}// namespace app

#endif//MAINKONTROLER_H
