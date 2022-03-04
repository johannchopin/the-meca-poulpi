class States {
  public:
    States();
    const char* states[7] = {"meditation", "sport", "water", "tasks", "sleepy", "do_sport", "do_meditation"};
    const char* getCurrent();
    void goToNext();
    int getStatesAmount();

  private:
    int current = 0;
};
