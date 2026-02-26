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
    void m_draw_strumfeta();
    void m_draw_veliki_strumf();
    void m_draw_bubalo();
    void m_draw_gargamel();
    void m_draw_kuca();
    void update_camera();
    void update() override;
    void begin_draw() override;
    void draw() override;
    void end_draw() override;

    bool m_prikazi_gargamela = false;
    bool m_prikazi_velikog_strumfa = true;
    bool m_prikazi_strumfetu = true;
    bool m_prikazi_bubala = true;
    bool m_pokreni_velikog_strumfa = false;
    float m_ugao_velikog_strumfa = -45.0f;
    float m_pozicija_velikog_strumfa = 0.0f;

public:
    std::string_view name() const override {
        return "app::MainKontroler";
    }
};
}// namespace app

#endif//MAINKONTROLER_H
