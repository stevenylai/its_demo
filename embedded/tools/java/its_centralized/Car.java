class Car {
  public int id;
  public boolean stopped;
  public Road belongs;
  public int speed;
  public Car (int id, Road belongs) {
    this.id = id;
    this.belongs = belongs;
    this.stopped = false;
  }
}
