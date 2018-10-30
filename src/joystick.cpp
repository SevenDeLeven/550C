#include "API.h"
#include "joystick.h"

JoystickButton::JoystickButton(unsigned char joystick, unsigned char group, unsigned char button) {
  this->m_joystick = joystick;
  this->m_group = group;
  this->m_button = button;
}

JoystickButton::~JoystickButton(){

}

bool JoystickButton::isPressed() {
  return joystickGetDigital(this->m_joystick, this->m_group, this->m_button);
}



JoystickToggleButton::JoystickToggleButton(unsigned char joystick, unsigned char group, unsigned char button) {
  this->m_prev = false;
  this->m_toggled = false;
  this->m_curPressed = false;
  this->m_pressed = false;
  this->m_released = false;
  this->m_joystick = joystick;
  this->m_group = group;
  this->m_button = button;
}

JoystickToggleButton::~JoystickToggleButton() {

}

void JoystickToggleButton::update() {
  this->m_curPressed = joystickGetDigital(this->m_joystick, this->m_group, this->m_button);

  if (this->m_prev != this->m_curPressed) {
    this->m_pressed = this->m_curPressed;
    this->m_released = this->m_prev;
    if (this->m_pressed) {
      this->m_toggled = !this->m_toggled;
    }
  }

  this->m_prev = this->m_curPressed;
}

bool JoystickToggleButton::getToggled() {
  return this->m_toggled;
}

bool JoystickToggleButton::getCurrentlyPressed() {
  return this->m_curPressed;
}

bool JoystickToggleButton::getPressed() {
  return this->m_pressed;
}

bool JoystickToggleButton::getReleased() {
  return this->m_released;
}





JoystickButtonGroup::JoystickButtonGroup(unsigned char joystick, unsigned char group) {
  this->m_joystick = joystick;
  this->m_group = group;
  this->m_reversed = false;
}

JoystickButtonGroup::~JoystickButtonGroup() {

}

void JoystickButtonGroup::reverse() {
  this->m_reversed = !this->m_reversed;
}

void JoystickButtonGroup::setReversed(bool reversed) {
  this->m_reversed = reversed;
}

bool JoystickButtonGroup::getReversed() {
  return this->m_reversed;
}

int JoystickButtonGroup::getTotal() {
  return (joystickGetDigital(this->m_joystick, this->m_group, JOY_UP) - joystickGetDigital(this->m_joystick, this->m_group, JOY_DOWN)) * (this->m_reversed ? -1 : 1);
}




JoystickAnalog::JoystickAnalog(unsigned char joytick, unsigned char axis) {
  this->m_joystick = joystick;
  this->m_axis = axis;
}

JoystickAnalog::~JoystickAnalog() {

}

int JoystickAnalog::getValue() {
  return joystickGetAnalog(this->m_joystick, this->m_axis);
}
