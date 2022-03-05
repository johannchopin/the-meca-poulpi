class States
{
public:
  States();
  const char *states[7] = {"meditation", "sport", "water", "tasks", "sleepy", "do_sport", "do_meditation"};
  const char *getCurrent();
  void goToNext();
  int getStatesAmount();
  void setState(char const *state);
  void loop();

private:
  int current = 0;
  unsigned long lastStateChangeDebounceTime = 0;
  unsigned long debounceStateChangeDelay = 3000; // 3 seconds
};
