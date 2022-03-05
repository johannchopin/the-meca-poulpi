class Screen
{
public:
  Screen(){};
  void loop(char *state);
  void setup(char *state);
  void colorBackground();
  int pin;
private:
  char *currentState;
  void onStateChange();
};
