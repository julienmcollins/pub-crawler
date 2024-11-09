#include "test_character.h"

#include <godot_cpp/variant/utility_functions.hpp>

void TestCharacter::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_acc_curve"), &TestCharacter::get_acc_curve);
    ClassDB::bind_method(D_METHOD("set_acc_curve", "acc_curve"), &TestCharacter::set_acc_curve);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "acc_curve"), "set_acc_curve", "get_acc_curve");

    ClassDB::bind_method(D_METHOD("get_dec_curve"), &TestCharacter::get_dec_curve);
    ClassDB::bind_method(D_METHOD("set_dec_curve", "dec_curve"), &TestCharacter::set_dec_curve);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "dec_curve"), "set_dec_curve", "get_dec_curve");
}

void TestCharacter::_ready() {
    _player_input = Input::get_singleton();

    _acc_curve = ResourceLoader::get_singleton()->load(_acc_curve->get_path());
    _dec_curve = ResourceLoader::get_singleton()->load(_dec_curve->get_path());
}

void TestCharacter::_process(double delta) {
}

void TestCharacter::_physics_process(double delta) {
    _dir = Vector3(
        _player_input->get_action_strength("move_right") - _player_input->get_action_strength("move_left"),
        0,
        _player_input->get_action_strength("move_down") - _player_input->get_action_strength("move_up")
    );

    if (!_dir.is_zero_approx()) { // We're accelerating so use the curve to figure out
        float acc_val = _acc_curve->sample(_alpha);
        Vector3 mov = _dir * 100.0f * delta; //* acc_val;
        set_velocity(mov);
        move_and_slide();
        _alpha = Math::min(_alpha + delta, 1.0);
        // UtilityFunctions::print("Accelerating! acc_val = ", acc_val, ", alpha = ", _alpha);
    } else {
        float dec_val = _dec_curve->sample(_alpha);
        Vector3 mov = -_dir * 100.0f * delta; //* dec_val;
        set_velocity(mov);
        move_and_slide();
        _alpha = Math::max(_alpha - delta, 0.0);
        // UtilityFunctions::print("Decelerating! acc_val = ", dec_val, ", alpha = ", _alpha);
    }
}