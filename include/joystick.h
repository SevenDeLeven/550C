#ifndef JOYSTICK_H
#define JOYSTICK_H

class JoystickButton {
private:
  unsigned char m_joystick;
  unsigned char m_group;
  unsigned char m_button;
public:
  JoystickButton(unsigned char joystick, unsigned char group, unsigned char button);
  virtual ~JoystickButton();
  bool isPressed();
};




class JoystickToggleButton {
private:
  unsigned char m_joystick;
  unsigned char m_group;
  unsigned char m_button;
  bool m_toggled;
  bool m_prev;
  bool m_curPressed;
  bool m_pressed;
  bool m_released;
public:
  JoystickToggleButton(unsigned char joystick, unsigned char group, unsigned char button);
  virtual ~JoystickToggleButton();
  void update();
  bool getToggled();
  bool getPressed();
  bool getReleased();
  bool getCurrentlyPressed();
};



class JoystickButtonGroup {
private:
  unsigned char m_joystick;
  unsigned char m_group;
  int m_prevTotal;
  bool m_pressed;
  bool m_reversed;
public:
  JoystickButtonGroup(unsigned char joystick, unsigned char group);
  virtual ~JoystickButtonGroup();
  void update();
  void reverse();
  void setReversed(bool reversed);
  bool getReversed();
  int getTotal();
  bool getPressed();
};



class JoystickAnalog {
private:
  unsigned char m_joystick;
  unsigned char m_axis;
public:
  JoystickAnalog(unsigned char joystick, unsigned char axis);
  virtual ~JoystickAnalog();
  int getValue();
};

#endif
