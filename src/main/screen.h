class Screen
{
public:
  Screen(){};
  void loop(PoulpiState state);
  void setup(PoulpiState state);
  void colorBackground();
  int pin;
private:
  PoulpiState currentState;
  void onStateChange();
};
