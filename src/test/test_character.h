#ifndef TEST_CHARACTER_H
#define TEST_CHARACTER_H

#include <godot_cpp/core/class_db.hpp>

#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/curve.hpp>
#include <godot_cpp/classes/character_body3d.hpp>

using namespace godot;

class TestCharacter: public CharacterBody3D {
    GDCLASS(TestCharacter, CharacterBody3D)

protected:
    static void _bind_methods();

public:
    virtual void _ready() override;
    virtual void _process(double delta) override;
    virtual void _physics_process(double delta) override;

    // Reflected properties
    void set_acc_curve(Ref<Curve> acc_curve) {
        _acc_curve = acc_curve;
    }
    Ref<Curve> get_acc_curve() const {
        return _acc_curve;
    }

    void set_dec_curve(Ref<Curve> dec_curve) {
        _dec_curve = dec_curve;
    }
    Ref<Curve> get_dec_curve() const {
        return _dec_curve;
    }

private: // Members

    // Misc
    Input* _player_input = nullptr;

    // Physics
    Vector3 _dir;
    float _alpha = 0;

    Ref<Curve> _acc_curve;
    Ref<Curve> _dec_curve;

};

#endif // TEST_CHARACTER_H